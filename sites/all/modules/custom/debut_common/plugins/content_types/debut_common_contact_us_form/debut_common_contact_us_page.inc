<?php
/**
 *
 * @file
 *   CCT inc file.
 */

$plugin = array(
  'title' => t('Debut Common: Contact us form'),
  'description' => t('Debut Common: Contact us form'),
  'content_types' => 'debut_common_contact_us_page',
  'single' => TRUE,
  'render callback' => 'debut_common_contact_us_page_content_type_render',
  'edit form' => 'debut_common_contact_us_page_content_type_edit_form',
  'admin title' => 'debut_common_contact_us_page_content_type_admin_title',
  'hook theme' => 'debut_common_contact_us_page_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
);

/**
 * Admin title callback.
 */
function debut_common_contact_us_page_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Contact us form.');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_contact_us_page_content_type_edit_form($form, &$form_state) {
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
function debut_common_contact_us_page_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the userbar content type.
 */
function debut_common_contact_us_page_content_type_render($subtype, $_conf, $panel_args, $context) {
  $data = array();
  $_html = array();

  // Suppress admin menu in popup.
  admin_menu_suppress();

  // Get contac us form.
  $form = drupal_get_form('debut_common_contact_us_form');
  $_html['form'] = drupal_render($form);

  // Set title.
  $title = (!empty($conf['override_title_text']))
    ? $conf['override_title_text']
    : t('Contact us');
  $_html['title'] = $title;

  $_html['messages'] = theme('status_messages');

  $data['_html'] = $_html;

  $block = new stdClass();
  $block->content = theme('debut_common_contact_us_page', $data);
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_contact_us_page_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_contact_us_page'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-contact-us-page',
    'variables' => array('params' => array()),
  );
}
