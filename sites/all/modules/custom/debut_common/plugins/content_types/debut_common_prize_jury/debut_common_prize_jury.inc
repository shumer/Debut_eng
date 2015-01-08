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
  'title' => t('Debut Common: Prize jury block'),
  'description' => t('Debut Common: Prize jury block'),
  'content_types' => 'debut_common_prize_jury',
  'single' => TRUE,
  'render callback' => 'debut_common_prize_jury_content_type_render',
  'edit form' => 'debut_common_prize_jury_content_type_edit_form',
  'admin title' => 'debut_common_prize_jury_content_type_admin_title',
  'hook theme' => 'debut_common_prize_jury_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Admin title callback.
 */
function debut_common_prize_jury_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Prize jury block');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_prize_jury_content_type_edit_form($form, &$form_state) {

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
function debut_common_prize_jury_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the userbar content type.
 */
function debut_common_prize_jury_content_type_render($subtype, $_conf, $panel_args, $context) {

  $_html['node'] = views_embed_view(DEBUT_COMMON_VIEW_QUERY_RANDOM_PRIZE_JURY);

  $_html['title'] = t('Prize jury');

  // Prepare data to display.
  $data = array(
    '_html' => $_html,
  );
  $block = new stdClass();
  $block->content = theme('debut_common_prize_jury', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_prize_jury_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_prize_jury'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-prize-jury',
    'variables' => array('params' => array()),
  );
}
