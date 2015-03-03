<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Years list block'),
  'description' => t('Debut Common: Years list block'),
  'content_types' => 'debut_common_years_list',
  'single' => TRUE,
  'render callback' => 'debut_common_years_list_content_type_render',
  'edit form' => 'debut_common_years_list_content_type_edit_form',
  'admin title' => 'debut_common_years_list_content_type_admin_title',
  'hook theme' => 'debut_common_years_list_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'no title override' => TRUE,
  'render last'  => TRUE,
);

/**
 * Render callback.
 */
function debut_common_years_list_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  $years = array();
  $options = array();

  if (empty($conf['view'])) {
    return;
  }

  // Check for year list in cache first.
  $cid = 'debut_common_' . $conf['view'] . '_year_list';
  $cache = cache_get($cid);
  $cache = !empty($cache) ? $cache->data : FALSE;

  if (empty($cache)) {

    // If we don't have any data get in from view and store in cache.
    $view = qtools_api__views_get_result($conf['view'], 'year_list');
    foreach ($view as $item) {
      $publicataion_date = isset($item->field_publication_date)
        ? $item->field_publication_date
        : NULL;
      $date = strtotime($publicataion_date);
      if (!empty($date)) {
        $date = date('Y', $date);
        $years[$date] = $date;
      }
    }
    arsort($years);

    // Set cache for given view.
    cache_set($cid, $years);

    // Wee need to store our CID to clear cache on node update.
    $cache_var = variable_get('debut_common_cache_data', array());
    $cache_var[$cid] = $cid;
    variable_set('debut_common_cache_data', $cache_var);
  }
  else {
    $years = $cache;
  }

  $path = $_GET['q'];
  $current_page = explode('/', $path);
  $current_year = isset($panel_args[0]) ? $panel_args[0] : NULL;

  $years_list = array();
  foreach ($years as &$year) {
    $year_title = $year;

    $query = array(
      /*'field_publication_date_value[value][year]' => $year,*/
      'sort_by' => 'field_publication_date_value',
      'sort_order' => ($year == $current_year) ? 'DESC' : 'ASC',
    );
    $link = url($current_page[0] . '/' . $year, array(
      'query' => $query)
    );
    $options[$year] = $year;
    $years_list[$year] = $link;
  }

  // Send variables to client side.
  drupal_add_js(array('debut_common' => array(
    'years_list' => $years_list,
  )), 'setting');

  $select = array(
    '#title' => t('Select a year:'),
    '#name' => 'years-select',
    '#id' => 'years-select',
    '#type' => 'select',
    '#options' => $options,
    '#value' => $current_year,
    '#attributes' => array(
      'class' => array('years-select'),
      'data-role' => 'none',
    ),
  );
  $_html['options'] = drupal_render($select);
  $_data['options'] = $options;
  $_html['years'] = theme('item_list', array(
    'items' => $years,
    'title' => NULL,
    'type' => 'ul',
    'attributes' => array('class' => array('years-list')),
  ));

  $data['_html'] = $_html;
  $data['_data'] = $_data;
  $block->content = theme('debut_common_years_list', $data, $conf);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_years_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $views = views_get_all_views();

  $options = array();
  foreach ($views as $view) {
    if (count($view->display) > 1) {
      $options[$view->name] = $view->human_name . ' (' . $view->name . ')';
    }
  }

  $form['conf']['view'] = array(
    '#type' => 'select',
    '#title' => t('Select view to get data.'),
    '#description' => t('View must have display "year_list"'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => (!empty($conf['view'])) ? $conf['view'] : '',
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_years_list_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_years_list_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Years list block :: !view', array('!view' => $conf['view']));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_years_list_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_years_list'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-years-list',
    'variables' => array('params' => array()),
  );
}
