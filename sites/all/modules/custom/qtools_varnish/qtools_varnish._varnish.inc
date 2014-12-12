<?php
/**
 * @file
 * Module api and logic.
 *
 * Most of those functions are taken from Varnish module (https://www.drupal.org/project/varnish)
 * So all creadits for content of this file should go to original developer.
 * But those are internal function that are subject to change so we reimplement them here
 * instead of keep that module in deps.
 */


/**
 * Helper function to parse the host from the global $base_url
 */
function qtools_varnish__varnish_get_host() {
  global $base_url;
  $parts = parse_url($base_url);
  return $parts['host'];
}

function qtools_varnish__varnish_execute_command($client, $command) {
  // Send command and get response.
  $result = socket_write($client, "$command\n");
  $status = qtools_varnish__varnish_read_socket($client);
  if ($status['code'] != 200) {
    watchdog('varnish', 'Recieved status code @code running %command. Full response text: @error', array('@code' => $status['code'], '%command' => $command, '@error' => $status['msg']), WATCHDOG_ERROR);
    return FALSE;
  }
  else {
    // Successful connection.
    return $status;
  }
}

/**
 * Low-level socket read function.
 *
 * @params
 *   $client an initialized socket client
 *
 *   $retty how many times to retry on "temporarily unavalble" errors
 */
function qtools_varnish__varnish_read_socket($client, $retry = 2) {
  // Status and length info is always 13 characters.
  $header = socket_read($client, 13, PHP_BINARY_READ);
  if ($header == FALSE) {
    $error = socket_last_error();
    // 35 = socket-unavailable, so it might be blocked from our write.
    // This is an acceptable place to retry.
    if ($error == 35 && $retry > 0) {
      return qtools_varnish__varnish_read_socket($client, $retry-1);
    }
    else {
      watchdog('varnish', 'Socket error: @error', array('@error' => socket_strerror($error)), WATCHDOG_ERROR);
      return array(
        'code' => $error,
        'msg' => socket_strerror($error),
      );
    }
  }
  $msg_len = (int)substr($header, 4, 6) + 1;
  $status = array(
    'code' => substr($header, 0, 3),
    'msg' => socket_read($client, $msg_len, PHP_BINARY_READ)
  );
  return $status;
}

/**
 * Helper function that sends commands to Varnish.
 * Utilizes sockets to talk to varnish terminal.
 */
function qtools_varnish__varnish_terminal_run($commands) {
  if (!extension_loaded('sockets')) {
    // Prevent fatal errors if people don't have requirements.
    return FALSE;
  }
  // Convert single commands to an array so we can handle everything in the same way.
  if (!is_array($commands)) {
    $commands = array($commands);
  }
  $ret = array();
  $terminals = explode(' ', _qtools_varnish_settings('connection', 'control_terminal', '127.0.0.1:6082'));
  // The variable varnish_socket_timeout defines the timeout in milliseconds.
  $timeout = _qtools_varnish_settings('connection', 'socket_timeout', 100);
  $seconds = (int)($timeout / 1000);
  $microseconds = (int)($timeout % 1000 * 1000);
  foreach ($terminals as $terminal) {
    list($server, $port) = explode(':', $terminal);
    $client = socket_create(AF_INET, SOCK_STREAM, getprotobyname('tcp'));
    socket_set_option($client, SOL_SOCKET, SO_SNDTIMEO, array('sec' => $seconds, 'usec' => $microseconds));
    socket_set_option($client, SOL_SOCKET, SO_RCVTIMEO, array('sec' => $seconds, 'usec' => $microseconds));
    if (@!socket_connect($client, $server, $port)) {
      watchdog('varnish', 'Unable to connect to server socket @server:@port: %error', array(
        '@server' => $server,
        '@port' => $port,
        '%error' => socket_strerror(socket_last_error($client))
        ), WATCHDOG_ERROR);
      $ret[$terminal] = FALSE;
      // If a varnish server is unavailable, move on to the next in the list.
      continue;
    }
    // If there is a CLI banner message (varnish >= 2.1.x), try to read it and move on.
    if(floatval(variable_get('varnish_version', 2.1)) > 2.0) {
      $status = qtools_varnish__varnish_read_socket($client);
      // Do we need to authenticate?
      if ($status['code'] == 107) { // Require authentication
        $secret = _qtools_varnish_settings('connection', 'control_key', '');
        $challenge = substr($status['msg'], 0, 32);
        $pack = $challenge . "\x0A" . $secret . "\x0A" . $challenge . "\x0A";
        $key = hash('sha256', $pack);
        socket_write($client, "auth $key\n");
        $status = qtools_varnish__varnish_read_socket($client);
        if ($status['code'] != 200) {
          watchdog('varnish', 'Authentication to server failed!', array(), WATCHDOG_ERROR);
        }
      }
    }
    foreach ($commands as $command) {
      if ($status = qtools_varnish__varnish_execute_command($client, $command)) {
        $ret[$terminal][$command] = $status;
      }
    }
  }
  return $ret;
}

/**
 * Get the status (up/down) of each of the varnish servers.
 *
 * @return An array of server statuses, keyed by varnish terminal addresses.
 */
function qtools_varnish__varnish_get_status() {
  // use a static-cache so this can be called repeatedly without incurring
  // socket-connects for each call.
  static $results = NULL;
  if (is_null($results)) {
    $results = array();
    $status = qtools_varnish__varnish_terminal_run(array('status'));
    $terminals = explode(' ', _qtools_varnish_settings('connection', 'control_terminal', '127.0.0.1:6082'));
    foreach ($terminals as $terminal) {
      $stat = array_shift($status);
      $results[$terminal] = ($stat['status']['code'] == 200);
    }
  }
  return $results;
}
