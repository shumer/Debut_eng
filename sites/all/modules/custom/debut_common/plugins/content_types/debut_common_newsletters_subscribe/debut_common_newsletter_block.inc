<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Newsletters block'),
  'description' => t('Debut Common: Newsletters block'),
  'content_types' => 'debut_common_newsletter_block',
  'render callback' => 'debut_common_newsletter_block_content_type_render',
  'edit form' => 'debut_common_newsletter_block_content_type_edit_form',
  'admin title' => 'debut_common_newsletter_block_content_type_admin_title',
  'hook theme' => 'debut_common_newsletter_block_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
);

/**
 * Render callback.
 */
function debut_common_newsletter_block_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = NULL;
  $_html = array();
  $_data = array();

  $title = t('Newsletters');
  if (!empty($conf['override_title'])) {
    $title = (!empty($conf['override_title_text'])) ? $conf['override_title_text'] : $title;
  }

  variable_set('debut_common_newsletter_block_tid', $conf['newsletters']);

  $_html['title'] = $title;
  $_data['url'] = url('debut_common/ajax/debut_common_newsletter_subscribe');

  $data['_html'] = $_html;
  $data['_data'] = $_data;
  $block->content = theme('debut_common_newsletter_block', $data);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_newsletter_block_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $newsletters = simplenews_category_list();
  $options = array();
  foreach ($newsletters as $c_id => $c_name) {
    $options[$c_id] = $c_name;
  }

  $form['conf']['newsletters'] = array(
    '#type' => 'select',
    '#title' => t('Select wich newletters to subscribe.'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => (!empty($conf['newsletters'])) ? $conf['newsletters'] : '',
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_newsletter_block_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_newsletter_block_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Newsletters block');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_newsletter_block_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_newsletter_block'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-newsletter-block',
    'variables' => array('params' => array()),
  );
}
