<?php
/**
 *
 * @file
 *   CCT inc file.
 */

/**
 * Callback function to supply a list of content types.
 */
$plugin = array(
  'title' => t('Debut Common: President info block'),
  'description' => t('Debut Common: President info block'),
  'content_types' => 'debut_common_president_info',
  'single' => TRUE,
  'render callback' => 'debut_common_president_info_content_type_render',
  'edit form' => 'debut_common_president_info_content_type_edit_form',
  'admin title' => 'debut_common_president_info_content_type_admin_title',
  'hook theme' => 'debut_common_president_info_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Admin title callback.
 */
function debut_common_president_info_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: President info block');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_president_info_content_type_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  $form['conf']['info_text'] = array(
    '#title' => t('President info text'),
    '#type' => 'textarea',
    '#default_value' => isset($conf['info_text']) ?
      $conf['info_text'] : '',
  );
  $form['conf']['more_url'] = array(
    '#title' => t('URL for detail info about president and foundation.'),
    '#type' => 'textfield',
    '#default_value' => isset($conf['more_url'])
      ? $conf['more_url']
      : 'http://fondskocha.ru/',
  );
  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_president_info_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the userbar content type.
 */
function debut_common_president_info_content_type_render($subtype, $_conf, $panel_args, $context) {
  $_html = array();

  $_html['info_text'] = t($_conf['info_text']);
  if (!empty($_conf['override_title'])) {
    $_html['title'] = (!empty($_conf['override_title_text'])) ? $_conf['override_title_text'] : t('Andrei Skoch');
  }
  $_html['more_link'] = l(t('MORE INFO'), $_conf['more_url']);

  // Prepare data to display.
  $data = array(
    '_html' => $_html,
  );
  $block = new stdClass();
  $block->content = theme('debut_common_president_info', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_president_info_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_president_info'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-president-info',
    'variables' => array('params' => array()),
  );
}
