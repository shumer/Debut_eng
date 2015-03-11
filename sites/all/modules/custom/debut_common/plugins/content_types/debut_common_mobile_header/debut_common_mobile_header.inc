<?php

/**
 * @file
 * Header CCT.
 */
/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('Debut Common: mobile header'),
  'description' => t('Debut Common: mobile header'),
  'content_types' => 'debut_common_mobile_header',
  'single' => TRUE,
  'render callback' => 'debut_common_mobile_header_content_type_render',
  'edit form' => 'debut_common_mobile_header_content_type_edit_form',
  'admin title' => 'debut_common_mobile_header_content_type_admin_title',
  'hook theme' => 'debut_common_mobile_header_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'render last' => TRUE,
  'no title override' => TRUE,
 );

/**
 * Implements hook_content_type_render().
 */
function debut_common_mobile_header_content_type_render($subtype, $conf, $panel_args, $context) {
  global $base_url, $user;

  $block = new stdClass();
  $_html = array();
  $_data = array();

  // Theme main menu.
  $main_menu = menu_tree(variable_get('menu_main_mobile_links_source', 'menu-main-menu-mobile'));
  $_html['main_menu'] = drupal_render($main_menu);

  // Logo.
  $_html['logo_link'] = url('', array('absolute' => TRUE));

  // Only theme status messsages if we not behind varnish.
  $_html['messages'] = qtools_varnish_enabled()
    ? '<div class="messages-target"></div>'
    : theme('status_messages');

  // Theme path for future use.
  $theme_path = drupal_get_path('theme', 'debut_mobile');

  $_html['banner'] = '';
  if (drupal_is_front_page()) {
    $banner_path = '/html/images/bgs/header.png';
  }
  else {
    $banner_path = '/html/images/bgs/header-b.png';
  }
  $_html['banner'] = theme('image', array(
    'path' => $theme_path . $banner_path,
  ));

  // Newsletter settings.
  $_data['newsletters_url'] = url('debut_common/ajax/debut_common_newsletter_subscribe');

  // Search data.
  $_html['input_value'] = '';
  $q = current_path();
  $page_path = explode('/', $q);

  if (!empty($page_path[0]) && !empty($page_path[1])) {
    if ($page_path[0] == DEBUT_COMMON_PATH_SEARCH) {
      $_html['input_value'] = check_plain($page_path[1]);
    }
  }

  // Prepare data for search form.
  $url_path = 'search';
  $page_url = url($url_path);
  drupal_add_js(array('debut_common' => array(
    'search_page_url' => $page_url,
  )), 'setting');

  // Combine values.
  $data = array(
    '_html' => $_html,
    '_data' => $_data,
  );

  $block->content = theme('debut_common_mobile_header', $data);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function debut_common_mobile_header_content_type_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#tree' => TRUE,
  );

  return $form;
}

/**
 * Implements hook_edit_form_submit().
 */
function debut_common_mobile_header_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_mobile_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: mobile header');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_mobile_header_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_mobile_header'] = array(
    'path' => $plugin['path'],
    'template' => 'debut-common-mobile-header',
    'variables' => array('params' => array()),
  );
}
