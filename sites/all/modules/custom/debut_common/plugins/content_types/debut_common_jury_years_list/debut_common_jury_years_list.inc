<?php
/**
 *
 * @file
 * Jury Years list CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Jury Years list', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Jury Years list', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_jury_years_list',
  'single' => TRUE,
  'render callback' => 'debut_common_jury_years_list_content_type_render',
  'edit form' => 'debut_common_jury_years_list_content_type_edit_form',
  'admin title' => 'debut_common_jury_years_list_content_type_admin_title',
  'hook theme' => 'debut_common_jury_years_list_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_jury_years_list_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  $alphabet = array();
  $active_name = '';

  $terms = taxonomy_get_tree($conf['voc']);

  if (!isset($_GET['field_jury_years_value'])) {
    $_GET['field_jury_years_value'] = 'All';
  }

  foreach ($terms as $term) {
    if ($_GET['field_jury_years_value'] == $term->tid) {
      $class = 'active-link';
      $active_name = $term->name;
    }
    else {
      $class = '';
    }
    $years[$term->name] = l($term->name, 'prize_jury', array(
      'query' => array('field_jury_years_value' => $term->tid),
      'attributes' => array(
        'class' => array($class),
      ),
    ));
  }
  krsort($years);
  $data['years'] = $years;

  if (debut_common_is_mobile() || qtools_api__developer()) {
    if (!empty($active_name)) {
      $order_num = array_search($active_name, array_keys($years));
      $startAt = ceil($order_num/DEBUT_COMMON_JURY_PAGE_YEARS_COUNT_SHOW) - 1;
    }
    else {
      $startAt = 0;
    }
    drupal_add_js(array('debut_common_jury_years' => array('flexslider_years_list_startAt' => $startAt)), 'setting');
    drupal_add_js(array('debut_common_jury_years' => array('flexslider_years_list_items_count' => DEBUT_COMMON_JURY_PAGE_YEARS_COUNT_SHOW)), 'setting');
  }
  
  $block->content = theme('debut_common_jury_years_list', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_jury_years_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $vocs = taxonomy_get_vocabularies();

  $options = array();
  foreach ($vocs as $voc) {
    $options[$voc->vid] = $voc->name ;
  }

  $form['conf']['voc'] = array(
    '#type' => 'select',
    '#title' => t('Select vocabulary to get data.'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => (!empty($conf['voc'])) ? $conf['voc'] : '',
  );

  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_jury_years_list_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_jury_years_list_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Jury Years list', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_jury_years_list_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_jury_years_list'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-jury-years-list',
    'variables' => array('params' => array()),
  );
}
