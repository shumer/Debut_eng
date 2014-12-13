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
