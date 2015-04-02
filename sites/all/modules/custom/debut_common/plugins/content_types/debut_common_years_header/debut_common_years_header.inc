<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Years list header'),
  'description' => t('Debut Common: Years list header'),
  'content_types' => 'debut_common_years_header',
  'single' => TRUE,
  'render callback' => 'debut_common_years_header_content_type_render',
  'edit form' => 'debut_common_years_header_content_type_edit_form',
  'admin title' => 'debut_common_years_header_content_type_admin_title',
  'hook theme' => 'debut_common_years_header_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'no title override' => TRUE,
);

/**
 * Render callback.
 */
function debut_common_years_header_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();

  $title = $conf['text'];
  $current_year = isset($panel_args[0]) ? check_plain($panel_args[0]) : NULL;
  if (!empty($current_year) && is_numeric($current_year)) {
    $title = t('@title for @year year', array('@title' => $title, '@year' => $current_year));
  }

  $_html['title'] = $title;

  $data['_html'] = $_html;
  $block->content = theme('debut_common_years_header', $data, $conf);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_years_header_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $form['conf']['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Header title'),
    '#default_value' => (!empty($conf['text'])) ? $conf['text'] : '',
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_years_header_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_years_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Years list header');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_years_header_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_years_header'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-years-header',
    'variables' => array('params' => array()),
  );
}
