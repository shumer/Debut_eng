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
  'title' => t('Debut Common: Prize person block'),
  'description' => t('Debut Common: Prize person block'),
  'content_types' => 'debut_common_prize_person',
  'single' => TRUE,
  'render callback' => 'debut_common_prize_person_content_type_render',
  'edit form' => 'debut_common_prize_person_content_type_edit_form',
  'admin title' => 'debut_common_prize_person_content_type_admin_title',
  'hook theme' => 'debut_common_prize_person_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Admin title callback.
 */
function debut_common_prize_person_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Prize person block');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_prize_person_content_type_edit_form($form, &$form_state) {

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
function debut_common_prize_person_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the userbar content type.
 */
function debut_common_prize_person_content_type_render($subtype, $_conf, $panel_args, $context) {

  $_html['node'] = views_embed_view(DEBUT_COMMON_VIEW_QUERY_RANDOM_PRIZE_PERSON);

  //$image = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';

  $_html['title'] = t('Prize persons');
  if (!empty($_conf['override_title'])) {
    $_html['title'] = (!empty($_conf['override_title_text'])) ? $_conf['override_title_text'] : t('Prize persons');
  }

  // Prepare data to display.
  $data = array(
    '_html' => $_html,
  );
  $block = new stdClass();
  $block->content = theme('debut_common_prize_person', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_prize_person_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_prize_person'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-prize-person',
    'variables' => array('params' => array()),
  );
}
