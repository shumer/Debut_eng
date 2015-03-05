<?php
/**
 * Provide context plugin.
 */

$plugin = array(
  'title'       => t('Expose Year Filter context'),
  'description' => t('View expose filter context'),
  'context'     => 'debut_common_year_filter_context_create',
  'edit form'   => 'debut_common_year_filter_context_settings_form',
  'keyword'     => 'year_filter',
  'context name'=> 'year_filter_context',
  'convet'      => 'debut_common_year_filter_context_convert',
);

/**
 * Context.
 */
function debut_common_year_filter_context_create($empty, $data = NULL, $conf = FALSE) {

  $cid = 'debut_common_' . $data['view'] . '_year_list';
  $cache = cache_get($cid);
  $cache = !empty($cache) ? $cache->data : FALSE;

  if (empty($cache)) {
    $view = qtools_api__views_get_result($data['view'], 'year_list');
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
  }
  else {
    $years = $cache;
  }

  $year = array_shift($years);

  $query = array(
    'sort_by' => 'field_publication_date_value',
    'sort_order' => 'DESC'
  );

  $args = array($year);

  $data = array(
    'query' => $query,
    'args' => $args,
  );

  $context = new ctools_context('year_filter_context');
  $context->plugin = 'year_filter_context';

  $context->data = $data;

  return $context;
}

/**
 * Settings form for context plugin.
 */
function debut_common_year_filter_context_settings_form($form, &$form_state) {
  $conf = &$form_state['conf'];

  $views = views_get_all_views();

  $options = array();
  foreach ($views as $view) {
    if (count($view->display) > 1) {
      $options[$view->name] = $view->human_name . ' (' . $view->name . ')';
    }
  }

  $form['view'] = array(
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
 * Submit handler for plugin settings form.
 */
function debut_common_year_filter_context_settings_form_submit($form, &$form_state) {
  $form_state['conf']['view'] = $form_state['values']['view'];
}

/**
 * Convert a context into a string.
 */
function debut_common_year_filter_context_convert($context, $type) {
  return $context->data;
}
