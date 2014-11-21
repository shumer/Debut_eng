<?php
/**
 * @file
 * Module logic and API.
 */

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
 *   (string) lazy_load
 */
function site_common_js_add($name = '', $force = FALSE, $settings = array()) {

  // Get path and added scripts list.
  $added_list = &drupal_static(__FUNCTION__ . '_list', array());
  $js_path = drupal_get_path('module', 'site_common') . '/js/site-common.' . str_replace('_', '-', $name) . '.js';

  // Add required script.
  if (!empty($name) && empty($added_list[$js_path])) {

    // Add requirements.
    qtools_api__js_add('base');

    // Add js.
    drupal_add_js($js_path);
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

/**
 * Get specific field delta.
 */
function site_common_field_get_item($entity_type, $entity, $field_name, $deltas = NULL, $key = NULL, $langcode = NULL) {

  // Check that node contain this firld.
  if (empty($entity) || !is_object($entity) || !property_exists($entity, $field_name)) {
    return NULL;
  }

  // Get items.
  $items = field_get_items($entity_type, $entity, $field_name, $langcode);

  if (empty($items)) {
    if (is_numeric($deltas)) {
      return;
    }
    else {
      return array();
    }
  }

  if (is_numeric($deltas)) {
    $_return_delta = $deltas;
    $deltas = array($deltas);
  }
  else {
    $deltas = !empty($deltas)
      ? $deltas
      : array_keys($items);
  }
  $return = array();

  // Get all items.
  foreach ($deltas as $delta) {
    if (!empty($items[$delta])) {
      if ($key === NULL) {
        $return[$delta] = $items[$delta];
      }
      else {
        $return[$delta] = !empty($items[$delta][$key])
          ? $items[$delta][$key]
          : NULL;
      }
    }
    else {
      $return[$delta] = NULL;
    }
  }

  if (isset($_return_delta)) {
    $return = !empty($return[$_return_delta])
      ? $return[$_return_delta]
      : NULL;
  }
  return $return;
}

/**
 * Get view results and clean up view.
 */
function site_common_views_get_view_result($name, $display_id = NULL) {
  $args = func_get_args();
  // Remove $name.
  array_shift($args);
  if (count($args)) {
    // Remove $display_id.
    array_shift($args);
  }

  $view = views_get_view($name);
  if (is_object($view)) {
    if (is_array($args)) {
      $view->set_arguments($args);
    }
    if (is_string($display_id)) {
      $view->set_display($display_id);
    }
    else {
      $view->init_display();
    }
    $view->pre_execute();
    $view->execute();
    $result = $view->result;
    $view->destroy();
    return $result;
  }
  else {
    return array();
  }
}
