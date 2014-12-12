<?php
/**
 * @file
 * Module logic and API.
 */

/**
 * Add asynk js if it is not already added.
 *
 * If script is already added, nothing ill be changed.
 */
function site_common_add_asynk_js($js_file) {
  $js_list = drupal_add_js();

  // If this file is not yet added we add it as asynk load.
  // @see site_common_preprocess_html().
  if (empty($js_list[$js_file])) {
    $js_file = url($js_file, array('absolute' => TRUE));
    drupal_add_js($js_file, array('asynk' => TRUE));
  }
}

/**
 * Check if this request is done using
 */
function site_common_is_xmlhttp() {
  if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
    return TRUE;
  }
}

/**
 * Return module settings.
 */
function _site_common_settings($block, $setting, $default = NULL) {
  $settings = variable_get('site_common_settings');
  if (isset($settings[$block])) {
    return isset($settings[$block][$setting])
      ? $settings[$block][$setting]
      : $default;
  }
  return $default;
}

/**
 * Include site common js.
 *
 * @param $name
 *   (string) jquery_mobile
 */
function site_common_js_add($name = '', $force = FALSE, $settings = array()) {

  // Get path and added scripts list.
  $options = NULL;
  $added_list = &drupal_static(__FUNCTION__ . '_list', array());
  $js_path = drupal_get_path('module', 'site_common') . '/js/site-common.' . str_replace('_', '-', $name) . '.js';

  // Add required script.
  if (!empty($name) && empty($added_list[$js_path])) {

    // Add requirements.
    qtools_api__js_add('base');

    // For JQM we need to load all drupal default scripts ahead of time.
    if ($name == 'jquery_mobile') {

      // If this file added, it is present on every page.
      $options['every_page'] = TRUE;

      // Invoke resource preload hook.
      module_invoke_all('site_common_preload_resources');
    }

    // Add Ajax requirements.
    if ($name == 'ajax') {
      // Add qtools libs.
      qtools_api__js_add('ajax');
      qtools_api__js_add('autocomplete');
    }

    // Add js.
    drupal_add_js($js_path, $options);
    drupal_add_js(array(
      'site_common' => array(
        $name => $settings,
      )
    ), 'setting');
    $added_list[] = $js_path;
  }
}

/**
 * Safe representation fo given string.
 */
function site_common_safe_string($string, $tags = '') {
  if (empty($tags)) {
    $string = strip_tags($string);
  }
  else {
    $string = filter_xss(strip_tags($string, $tags));
  }
  return $string;
}

/**
 * Render tag with given attributes.
 */
function site_common_render_tag($tag = 'div', array $attributes = array()) {

  // Extract tag data.
  if (!empty($attributes['data'])) {
    $data = $attributes['data'];
    unset($attributes['data']);
  }
  else {
    $data = '';
  }

  // Print tag.
  $output = '<' . $tag . ' ' . drupal_attributes($attributes) . '>' . $data . '</' . $tag .'>';

  return $output;
}

/**
 * Build ajax call command.
 * @param $type
 *   (string) Command type: call/view/form
 * @param $key
 *   (string) Depends on command url/view_name/form_id
 */
function site_common_ajax_command($type, $key, $data = array(), $name = '', $method = 'post', $spam = 5000) {
  return array(
    'command' => 'site_common_ajax',
    'type' => $type,
    'key' => $key,
    'data' => $data,
    'name' => $name,
    'method' => $method,
    'spam' => $spam,
  );
}

/**
 * Ajax command to print data to console.
 */
function site_common_ajax_command_log($title, $data) {
  return array(
    'command' => 'site_common_log',
    'title' => $title,
    'data' => $data,
  );
}

/**
 * Check if user has specified role.
 */
function site_common_user_has_role($role, $account = NULL) {
  global $user;

  $has_role = FALSE;

  // Choose account to test against.
  if (empty($account)) {
    $account = $user;
  }

  $roles = $account->roles;
  if (in_array($role, $roles) || !empty($roles[$role])) {
    $has_role = TRUE;
  }
  return $has_role;
}
