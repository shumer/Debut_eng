<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Site calendar'),
  'description' => t('Debut Common: Site calendar'),
  'content_types' => 'debut_common_site_calendar',
  'single' => TRUE,
  'render callback' => 'debut_common_site_calendar_content_type_render',
  'edit form' => 'debut_common_site_calendar_content_type_edit_form',
  'admin title' => 'debut_common_site_calendar_content_type_admin_title',
  'hook theme' => 'debut_common_site_calendar_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
);

/**
 * Render callback.
 */
function debut_common_site_calendar_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_data = array();
  $_html = array();
  $days = array();

  $change_dates = debut_site_changes_get_stats(strtotime('-1 year'));

  if (!empty($change_dates)) {
    foreach ($change_dates as $day) {
      $days[] = $day['date'];
    }
  }

  // Get min date for calendar.
  $min_date = '-1Y';
  drupal_add_js(array('debut_common_site_calendar' => array('min_date' => $min_date)), 'setting');

  // Set max date.
  $max_date = date('Y-m-d', strtotime('-1 second', strtotime('+1 month', strtotime(date('m') . '/01/' . date('Y') . ' 00:00:00'))));
  drupal_add_js(array('debut_common_site_calendar' => array('max_date' => $max_date)), 'setting');

  // Prepare arays with monthes and days for calendar.
  for ($i = 1; $i < 13; $i++) {
    $calendar_monthes[] = t(date('F', mktime(0, 0, 0, $i, 1)));
    $calendar_monthes_short[] = drupal_substr(t(date('F', mktime(0, 0, 0, $i, 1))), 0, 3);
  }

  $days_array = array('Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday');
  for ($i = 0; $i < 7; $i++) {
    $calendar_days[]       = t($days_array[$i]);
    $calendar_days_short[] = drupal_substr(t($days_array[$i]), 0, 3);
  }
  $calendar_days_min = array('BC', 'ПН', 'ВТ', 'СР', 'ЧТ', 'ПТ', 'СБ');

  // Add data for calendar.
  drupal_add_js(array('debut_common_site_calendar' => array('days' => $days)), 'setting');
  drupal_add_js(array('debut_common_site_calendar' => array('calendar_monthes' => $calendar_monthes)), 'setting');
  drupal_add_js(array('debut_common_site_calendar' => array('calendar_days_min' => $calendar_days_min)), 'setting');
  drupal_add_js(array('debut_common_site_calendar' => array('calendar_monthes_short' => $calendar_monthes_short)), 'setting');
  drupal_add_js(array('debut_common_site_calendar' => array('calendar_days_short' => $calendar_days_short)), 'setting');
  drupal_add_js(array('debut_common_site_calendar' => array('calendar_days' => $calendar_days)), 'setting');

  // Add js for processing actions.
  drupal_add_js(drupal_get_path('module', 'debut_blocks') .'/theme/debut_common_site_calendar.js', 'module', 'header');

  $_html['title'] = t('Site changes');
  if (!empty($conf['override_title'])) {
    $_html['title'] = (!empty($conf['override_title_text'])) ? $conf['override_title_text'] : $_html['title'];
  }

  // Get list of changes for current day.
  $links = debut_common_create_changes_list(date('m/d/y', time('now')));
  $_html['links'] = $links;

  // Ajax url.
  $_data['ajax_url'] = url('debut_common/ajax/debut_common_site_calendar');
  $data['_data'] = $_data;
  $data['_html'] = $_html;

  $block->content = theme('debut_common_site_calendar', $data);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_site_calendar_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_site_calendar_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_site_calendar_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Site calendar');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_site_calendar_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_site_calendar'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-site-calendar',
    'variables' => array('params' => array()),
  );
}
