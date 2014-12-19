<?php
/**
 * @file
 * Page callbacks.
 */

/**
 * Callback on calendar ajax request..
 */
function debut_common_page_ajax_site_calendar_callback() {
  global $user;
  $commands = array();

  $date = isset($_GET['date']) ? check_plain($_GET['date']) : '';
  $valid_date = debut_common_validate_date($date);

  if ($valid_date) {
    $changes = debut_common_create_changes_list($date);
    $commands[] = ajax_command_html('.debut_common_site_calendar_text', $changes);
  }

  // Cleanup status messages.
  $msgs = theme('status_messages');
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Callback on calendar ajax request..
 */
function debut_common_page_ajax_newsletter_subscribe_callback() {
  global $user;
  $commands = array();

  if (isset($_POST['email'])) {
    $email = $_POST['email'];
    if (valid_email_address($email)) {
      simplenews_subscribe_user($mail, DEBUT_COMMON_TID_NEWSLETTERS, TRUE, 'newsleeter form');
      drupal_set_message(t('You was subscribed successfully. Confirmation message sended to your email address.'));
    }
  }

  $messages = theme('status_messages');
  $commands[] = ajax_command_html('.messages-container', $messages);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Close popup window.
 */
function debut_common_page_js_parent_close() {

  $echo = '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr"><head>
    <script type="text/javascript">
    if (self != parent) {
      try {
        parent.jQuery.fancybox.close();
      }
      catch(ex) {
      }
    }
    </script></head><body style="background: none repeat scroll 0 0 transparent;"></body></html>';
  print $echo;

  // Prevent anything else.
  die;
}

/**
 * Reload parent windoe object.
 *
 * Prints JS that will reload parent window object.
 */
function debut_common_page_js_parent_reload() {
  global $is_https;
  $trail = func_get_args();

  $location = !empty($_REQUEST['destination'])
    ? '\'' . url($_REQUEST['destination'], array('absolute' => TRUE)) . '\''
    : 'href[0]';
  if (!empty($trail)) {
    $fragment = !empty($_REQUEST['fragment'])
      ? $_REQUEST['fragment']
      : '';
    $location = '\'' . url(implode('/', $trail), array('absolute' => TRUE, 'fragment' => $fragment)) . '\'';
  }

  // Combine reload command.
  if ($location == 'href[0]') {
    $command = 'parent.location.reload(true)';
  }
  else {
    $command = 'parent.location.href = ' . $location;
  }

  $echo = '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr"><head>
    <script type="text/javascript">
    if (self != parent) {
      var href = parent.location.href.split(\'#\');
      ' . $command . ';
    }
    </script></head></html>';
  print $echo;

  // Prevent anything else.
  die;
}
