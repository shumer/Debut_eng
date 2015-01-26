<?php
/**
 *
 * @file
 * Nobel Speech listing CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Nobel Speech Listing', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Nobel Speech Listing', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_nobel_listing',
  'single' => TRUE,
  'render callback' => 'debut_common_nobel_speech_listing_content_type_render',
  'edit form' => 'debut_common_nobel_speech_listing_content_type_edit_form',
  'admin title' => 'debut_common_nobel_speech_listing_content_type_admin_title',
  'hook theme' => 'debut_common_nobel_speech_listing_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context'  => new ctools_context_required('Year Filter exposed', array('year_filter_context')),
);

/**
 * Render callback.
 */
function debut_common_nobel_speech_listing_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();

  if (!empty($panel_args)) {
    $year = $panel_args[0];
    $_html['nobel_listing'] = qtools_api__views_get_result(DEBUT_COMMON_VIEW_NOBEL_SPEECH_LISTING, 'default', array($year), $_GET, FALSE, QTOOLS_VIEWS_MODE_PREVIEW);
  }
  else {
    $default_data = $context->data;
    $_html['nobel_listing'] = qtools_api__views_get_result(DEBUT_COMMON_VIEW_NOBEL_SPEECH_LISTING, 'default', $default_data['args'], $default_data['query'], FALSE, QTOOLS_VIEWS_MODE_PREVIEW);    
  }
  
  $data['_html'] = $_html;

  $block->content = theme('debut_common_nobel_speech_listing', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_nobel_speech_listing_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_nobel_speech_listing_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_nobel_speech_listing_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Nobel Speech Listing', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_nobel_speech_listing_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_nobel_speech_listing'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-nobel-speech-listing',
    'variables' => array('params' => array()),
  );
}
