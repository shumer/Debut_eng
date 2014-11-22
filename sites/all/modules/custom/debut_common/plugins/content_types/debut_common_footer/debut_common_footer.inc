<?php
/**
 *
 * @file
 * Footer CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('Debut Common: Footer', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Footer', array(), array('context' => 'Debut: admin area')),
  'content_types' => '<strong>debut_common_footer</strong>',
  'single' => TRUE,
  'render callback' => 'debut_common_footer_content_type_render',
  'edit form' => 'debut_common_footer_content_type_edit_form',
  'admin title' => 'debut_common_footer_content_type_admin_title',
  'hook theme' => 'debut_common_footer_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
);

/**
 * Admin title callback.
 */
function debut_common_footer_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Footer');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_footer_content_type_edit_form($form, $form_state) {
  $conf = $form_state['conf'];

  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $menus = array();
  $menus[] = t('None');
  $menus += menu_get_menus();

  $form['conf']['footer_menu'] = array(
    '#type' => 'select',
    '#title' => t('Select menu for footer'),
    '#options' => $menus,
    '#required' => TRUE,
    '#default_value' => (!empty($conf['footer_menu'])) ? $conf['footer_menu'] : '',
  );

  $form['conf']['first_text_block'] = array(
    '#type'  => 'textarea',
    '#title' => t('First text block'),
    '#default_value' => !empty($conf['first_text_block']) ? $conf['first_text_block'] : '',
  );

  $form['conf']['second_text_block'] = array(
    '#type'  => 'textarea',
    '#title' => t('Second text block'),
    '#default_value' => !empty($conf['second_text_block']) ? $conf['second_text_block'] : '',
  );

  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_footer_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the footer content type.
 */
function debut_common_footer_content_type_render($subtype, $conf, $panel_args, $context) {
  $data = array();
  $_html = array();

  $menu = $conf['footer_menu'];
  $footmenu = menu_tree_all_data($menu);
  $footer_links = array();

  if (!empty($footmenu)) {
    foreach ($footmenu as $footmenu_id => $item) {
      $path = $item['link']['href'];
      $footer_links[] = array(
        'data' => l(t($item['link']['title']), $path),
        'class' => '',
      );
    }
  }
  $_html['footer_links'] = theme('item_list', $footer_links);

  // Get last update time.
  $update_time = db_select('node', 'n')
    ->fields('n', array('changed'))
    ->condition('n.status', 1)
    ->orderBy('n.changed', 'DESC')
    ->range(0, 1)
    ->execute()
    ->fetchField();
  if (!$update_time) {
    $update_time = time();
  }
  $_html['last_updated_date'] = drupal_strtolower(format_date($update_time, 'custom', 'd F Y'));

  // Text part.
  $_html['first_text_block'] = $conf['first_text_block'];
  $_html['second_text_block'] = $conf['second_text_block'];

  $data['_html'] = $_html;

  $block = new stdClass();
  $block->content = theme('debut_common_footer', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_footer_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_footer'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-footer',
    'variables' => array('params' => array()),
  );
}