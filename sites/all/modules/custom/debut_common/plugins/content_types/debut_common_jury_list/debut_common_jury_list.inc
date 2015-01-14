<?php
/**
 *
 * @file
 * Jury list CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Jury list', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Jury list', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_jury_list',
  'single' => TRUE,
  'render callback' => 'debut_common_jury_list_content_type_render',
  'edit form' => 'debut_common_jury_list_content_type_edit_form',
  'admin title' => 'debut_common_jury_list_content_type_admin_title',
  'hook theme' => 'debut_common_jury_list_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_jury_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  
  $path = $_GET['q'];

  if (isset($_GET['field_jury_years_value']) && is_numeric($_GET['field_jury_years_value'])) {
    $term_id = $_GET['field_jury_years_value'];
    $_html['jury_list_teaser'] = views_embed_view(DEBUT_COMMON_VIEW_GET_JURY_LIST, 'default', $term_id);  
  }
  else {
    $_html['jury_list_teaser'] = views_embed_view(DEBUT_COMMON_VIEW_GET_JURY_LIST, 'default');
    $_html['jury_list_listing'] = views_embed_view(DEBUT_COMMON_VIEW_GET_JURY_LIST, 'listing_view_mode');
  }

  $data['_html'] = $_html;
  $block->content = theme('debut_common_jury_list', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_jury_list_content_type_edit_form($form, &$form_state) {
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
function debut_common_jury_list_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_jury_list_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Jury list', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_jury_list_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_jury_list'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-jury-list',
    'variables' => array('params' => array()),
  );
}
