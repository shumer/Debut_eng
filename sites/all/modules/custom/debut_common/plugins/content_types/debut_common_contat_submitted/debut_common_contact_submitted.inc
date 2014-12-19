<?php
/**
 * @file
 * Breadcrumbs CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('Debut Common: Contact Us Submitted'),
  'description' => t('Debut Common: Contact Us Submitted', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_contact_submitted',
  'single' => TRUE,
  'render callback' => 'debut_common_contact_submitted_content_type_render',
  'edit form' => 'debut_common_contact_submitted_content_type_edit_form',
  'admin title' => 'debut_common_contact_submitted_content_type_admin_title',
  'hook theme' => 'debut_common_contact_submitted_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
);

/**
 * Implements hook_content_type_render().
 */
function debut_common_contact_submitted_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = NULL;
  $data = array();

  admin_menu_suppress();

  // Clear status messages.
  drupal_get_messages(NULL, TRUE);

  $data['_html']['message'] = $conf['confirm_text'];

  $block->content = theme('debut_common_contact_submitted', $data);
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_contact_submitted_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_contact_submitted'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-contact-submitted',
    'variables' => array('params' => array()),
  );
}

/**
 * Implements hook_content_type_edit_form().
 */
function debut_common_contact_submitted_content_type_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration', array(), array('context' => 'Debut: admin area')),
    '#tree' => TRUE,
  );

  // Custom bc for static pages.
  $form['conf']['confirm_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Confirmation text', array(), array('context' => 'Debut: admin area')),
    '#description' => t('Confirmation text.', array(), array('context' => 'Debut: admin area')),
    '#default_value' => !empty($conf['confirm_text']) ? $conf['confirm_text'] : '',
  );

  return $form;
}

/**
 * Implements hook_edit_form_submit().
 */
function debut_common_contact_submitted_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_contact_submitted_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Contact Us Submitted', array(), array('context' => 'Debut: admin area'));
}
