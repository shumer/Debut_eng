<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Page 404'),
  'description' => t('Debut Common: Page 404'),
  'content_types' => 'debut_common_page_404',
  'single' => TRUE,
  'render callback' => 'debut_common_page_404_content_type_render',
  'edit form' => 'debut_common_page_404_content_type_edit_form',
  'admin title' => 'debut_common_page_404_content_type_admin_title',
  'hook theme' => 'debut_common_page_404_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
);

/**
 * Render callback.
 */
function debut_common_page_404_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();

  $_html['title'] = !empty($conf['override_title_text']) ? $conf['override_title_text'] : t('Page not found');
  $_html['text'] = $conf['text_block'];

  $data['_html'] = $_html;
  $block->content = theme('debut_common_page_404', $data);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_page_404_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $form['conf']['text_block'] = array(
    '#type'  => 'textarea',
    '#title' => t('Text for page'),
    '#default_value' => !empty($conf['text_block']) ? $conf['text_block'] : '',
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_page_404_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_page_404_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut: Page 404');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_page_404_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_page_404'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-page-404',
    'variables' => array('params' => array()),
  );
}
