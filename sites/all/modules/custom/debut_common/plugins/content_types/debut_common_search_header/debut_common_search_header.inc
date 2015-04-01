<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Search header'),
  'description' => t('Debut Common: Search header'),
  'content_types' => 'debut_common_search_header',
  'single' => TRUE,
  'render callback' => 'debut_common_search_header_content_type_render',
  'admin title' => 'debut_common_search_header_content_type_admin_title',
  'hook theme' => 'debut_common_search_header_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
);

/**
 * Render callback.
 */
function debut_common_search_header_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_data = array();
  $_html = array();

  $searchphrase = check_plain(arg(1));
  $query = search_api_query('debut_search_index');
  $query->keys($searchphrase);
  $filter = $query->createFilter('OR');
  $query->filter($filter);
  $result = $query->execute();
  if ($result['result count']) {
    $result_string = t('@count results found.', array('@count' => $result['result count']));
  }
  else {
    $result_string = t('No results found. Try to give more details for search query.');
  }
  $text = t('You are searching for <i>"@searchphrase"</i>', array('@searchphrase' => $searchphrase));

  $_html['title'] = $text;
  $_html['search_overview'] = $result_string;

  $data['_data'] = $_data;
  $data['_html'] = $_html;

  $block->content = theme('debut_common_search_header', $data);

  return $block;
}

/**
 * Admin title callback.
 */
function debut_common_search_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Search header');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_search_header_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_search_header'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-search-header',
    'variables' => array('params' => array()),
  );
}