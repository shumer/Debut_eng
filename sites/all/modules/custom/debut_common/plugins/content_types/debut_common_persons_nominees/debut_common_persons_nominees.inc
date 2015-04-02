<?php
/**
 *
 * @file
 * Persons nominees list CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Persons nominees list', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Persons nominees list', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_persons_nominees',
  'single' => TRUE,
  'render callback' => 'debut_common_persons_nominees_content_type_render',
  'edit form' => 'debut_common_persons_nominees_content_type_edit_form',
  'admin title' => 'debut_common_persons_nominees_content_type_admin_title',
  'hook theme' => 'debut_common_persons_nominees_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_persons_nominees_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();

  $_html['persons_list'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_NOMINEES_LIST_TEASER, 'default');
  $data['_html'] = $_html;

  $block->content = theme('debut_common_persons_nominees', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_persons_nominees_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $terms = array();
  $vocs = taxonomy_get_vocabularies();
  foreach ($vocs as $voc) {
    $terms[$voc->vid] = $voc->name;
  }

  $form['conf']['terms'] = array(
    '#type' => 'select',
    '#title' => t('Prizes'),
    '#options' => $terms,
    '#default_value' => (!empty($conf['terms'])) ? $conf['terms'] : '',
  );

  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_persons_nominees_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_persons_nominees_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Persons nominees list', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_persons_nominees_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_persons_nominees'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-persons-nominees',
    'variables' => array('params' => array()),
  );
}
