<?php
/**
 * @file
 * Drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function site_common_drush_command() {
  $items = array();

  $items['site-common-env'] = array(
    'description' => 'Reconfigure current environment based on settins.php file.',
    'callback'    => 'site_common_drush_env',
    'arguments' => array(),
    'examples' => array(
      'drush site-common-env' => 'Reconfigure current environment based on settins.php file.',
    ),
  );

  return $items;
}

/**
 * Environment configuration dispatcher.
 */
function site_common_drush_env() {
  global $site_common_env;
  $log = function_exists('drush_log') ? 'drush_log' : 'site_common_drush_log';

  // Exit if no config supplied.
  if (empty($site_common_env)) {
    $log(t('No environment configured in settings.php, abort.', 'error'));
    return;
  }

  // At this point we have our configuration.
  $intro = t('Found following config sections: @conf', array(
    '@conf' => implode(', ', array_keys($site_common_env)),
  ));
  $log($intro, 'ok');

  // Dispatch all config sections.
  foreach ($site_common_env as $module => $config) {
    $function = $module . '_env_restore';

    // Run specific function for each config snippet.
    foreach ($config as $type => $data) {
      $error = '';
      $msg_string = $module . '[' . $type . ']';

      // check if hadler function exists and run it.
      if (function_exists($function)) {
        $error = $function($type, $data);
      }
      else {
        $error = t('function !name not found!', array(
          '!name' => $function,
        ));
      }

      // If we have error build proper message.
      if (!empty($error)) {
        $msg_type = 'error';
        $msg_string .= ' -> ' . $error;
      }
      else {
        $msg_type = 'ok';
      }
      $log(t('Processing: !msg_string'. PHP_EOL .'!conf', array(
        '!msg_string' => $msg_string,
        '!conf' => print_r($data, TRUE),
      )), $msg_type);
    }
  }
}

/**
 * Simple log function, see drush_log().
 */
function site_common_drush_log($message, $type = 'notice', $error = NULL) {
  print '[' . strtoupper($type) . '] ' . $message . PHP_EOL;
}

/**
 * Restore function.
 */
function site_common_env_restore($type, $settings) {

  switch ($type) {
    case 'search_api':
      $error = _site_common_env_restore_search_api($settings);
      break;
    case 'variables':
      $error = _site_common_env_restore_variables($settings);
      break;
    case 'admin':
      $error = _site_common_env_restore_admin($settings);
      break;
    default:
      $error = t('unsupported conf type [@type]', array('@type' => $type));
    end;
  }

  return $error;
}

/**
 * Restore admin user properties.
 */
function _site_common_env_restore_admin($settings) {
  // Settings given is an edit array.
  $user = user_load(1);
  user_save($user, $settings);
}

/**
 * Restore search api server configuration.
 */
function _site_common_env_restore_variables($settings) {
  // Just update all variables given.
  foreach ($settings as $name => $value) {
    variable_set($name, $value);
  }
}

/**
 * Restore search api server configuration.
 */
function _site_common_env_restore_search_api($settings) {

  // Init variable.
  $error = array();

  // Restore each provided server.
  foreach ($settings as $server_name => $configuration) {
    $server = search_api_server_load($server_name);
    if (empty($server)) {
      $error[] = t('SearchAPI Server [@name] not found', array(
        '@name' => $server_name,
      ));
    }
    else {
      $server->update(array('options' => $configuration));
    }
  }

  // Return list of errors if any.
  return implode(', ', $error);
}
