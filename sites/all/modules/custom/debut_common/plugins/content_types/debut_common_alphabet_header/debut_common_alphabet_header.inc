<?php
/**
 *
 * @file
 * Alphabet header CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Alphabet header', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Alphabet header', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_alphabet_header',
  'single' => TRUE,
  'render callback' => 'debut_common_alphabet_header_content_type_render',
  'edit form' => 'debut_common_alphabet_header_content_type_edit_form',
  'admin title' => 'debut_common_alphabet_header_content_type_admin_title',
  'hook theme' => 'debut_common_alphabet_header_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_alphabet_header_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  $alphabet = array();
  $active_id = '';

  $path = $_GET['q'];
  $path = explode('/', $path);
  if (!empty($path[1]) && (strlen($path[1]) < 3)) {
    $_GET['field_person_surname_value'] = $path[1];
    $title = drupal_get_title();
    $letter = drupal_strtoupper($path[1]);
    drupal_set_title($letter . $title);
  }

  $vocabulary = taxonomy_get_tree($conf['alphabet']);
  $i = 0;
  foreach ($vocabulary as $term) {
    $alphabet[] = l($term->name, $conf['page'] . '/' . drupal_strtolower($term->name));
    if (!empty(!empty($path[1]))) {
      if (drupal_strtoupper($term->name) == $letter) {
        $active_id = $i;
      }
      $i++;
    }
  }

  $variables = array(
    'items' => $alphabet,
    'title' => '',
    'type' => 'ul',
    'attributes' => array('class' => array('letter-slides')
  ));
  
  $_html['alphabet'] = theme('item_list', $variables);
  
  if (debut_common_is_mobile() || qtools_api__developer()) {
    if (!empty($active_id)) { 
      $startAt = ceil($active_id/DEBUT_COMMON_JURY_PAGE_LETTER_COUNT_SHOW) - 1;
    }
    else {
      $startAt = 0;
    }
    drupal_add_js(array('debut_common_alphabet_header' => array('flexslider_alphabet_list_startAt' => $startAt)), 'setting');
    drupal_add_js(array('debut_common_alphabet_header' => array('flexslider_alphabet_list_items_count' => DEBUT_COMMON_JURY_PAGE_LETTER_COUNT_SHOW)), 'setting');
  }
  
  $data['_html'] = $_html;
  $block->content = theme('debut_common_alphabet_header', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_alphabet_header_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $alphabet = array();
  $vocs = taxonomy_get_vocabularies();
  foreach ($vocs as $voc) {
    $alphabet[$voc->vid] = $voc->name;
  }

  $form['conf']['alphabet'] = array(
    '#type' => 'select',
    '#title' => t('Alphabet'),
    '#options' => $alphabet,
    '#default_value' => (!empty($conf['alphabet'])) ? $conf['alphabet'] : '',
  );
  
  $form['conf']['page'] = array(
    '#type' => 'textfield',
    '#title' => t('Page url'),
    '#default_value' => (!empty($conf['page'])) ? $conf['page'] : '',
    '#required' => true,
  );

  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_alphabet_header_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_alphabet_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Alphabet header', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_alphabet_header_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_alphabet_header'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-alphabet-header',
    'variables' => array('params' => array()),
  );
}
