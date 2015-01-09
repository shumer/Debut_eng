<?php
/**
 *
 * @file
 * Persons list CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Persons list', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Persons list', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_persons_list',
  'single' => TRUE,
  'render callback' => 'debut_common_persons_list_content_type_render',
  'edit form' => 'debut_common_persons_list_content_type_edit_form',
  'admin title' => 'debut_common_persons_list_content_type_admin_title',
  'hook theme' => 'debut_common_persons_list_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_persons_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  
  $path = $_GET['q'];
  $path = explode('/', $path);
  if (!empty($path[1]) && (strlen($path[1]) < 3)) {
    $_html['persons_list'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_LIST_BY_LETTER, 'default', addslashes($path[1]));
  }
  else {
    $_html['persons_list'] = '';
  }

  $data['_html'] = $_html;
  $block->content = theme('debut_common_persons_list', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_persons_list_content_type_edit_form($form, &$form_state) {
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
function debut_common_persons_list_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_persons_list_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Persons list', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_persons_list_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_persons_list'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-persons-list',
    'variables' => array('params' => array()),
  );
}
