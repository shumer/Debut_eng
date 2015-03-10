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

  $counter = 0; // Counter.
  $interval = 3; // Count of grouping prizes.
  $prizes = array();

  $vocabulary = taxonomy_get_tree($conf['terms']);

  $max_count = DEBUT_COMMON_MAX_PERSONS_NOMINEES_SHOW;
  $terms_count = count($vocabulary);

  foreach ($vocabulary as $term) {
    if ($counter >= $max_count) {
      break;
    }

    $row = floor($counter/$interval);
    $key = md5(uniqid(rand(),1));

    if ($counter % $interval == 0) {
      $prizes[$row]['data'][$term->tid]['html'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_NOMINEES_LIST_TEASER, 'default', $term->tid);
      $prizes[$row]['data'][$term->tid]['class'] = 'full';
      $prizes[$row]['data'][$term->tid]['id'] = $key;

      $prizes[$row]['captions'][$term->tid]['title'] = $term->name;
      $prizes[$row]['captions'][$term->tid]['ref-id'] = $key;
      $prizes[$row]['captions'][$term->tid]['class'] = 'caption js-prizes-show active-link';
    }
    else {
      $prizes[$row]['data'][$term->tid]['html'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_NOMINEES_LIST, 'default', $term->tid);
      $prizes[$row]['data'][$term->tid]['class'] = 'prem_list';
      $prizes[$row]['data'][$term->tid]['title'] = $term->name;
      $prizes[$row]['data'][$term->tid]['id'] = $key;

      if (debut_common_is_mobile() || qtools_api__developer()) {
        $title = explode(' ', $term->name);
        $prizes[$row]['captions'][$term->tid]['title'] = $title[0];
      }
      else {
        $prizes[$row]['captions'][$term->tid]['title'] = $term->name;
      }
      $prizes[$row]['captions'][$term->tid]['ref-id'] = $key;
      $prizes[$row]['captions'][$term->tid]['class'] = 'js-prizes-show';
    }

    $counter++;
  }

  // Check if we need to show more button.
  $_data['show_more'] = FALSE;
  if ($terms_count > $counter) {
    $_data['show_more'] = TRUE;
    $_data['show_more_url'] = url('debut_common/ajax/debut_common_persons_view_more/' . $max_count);
  }
  $_data['prizes'] = $prizes;
  $data['_data'] = $_data;

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
