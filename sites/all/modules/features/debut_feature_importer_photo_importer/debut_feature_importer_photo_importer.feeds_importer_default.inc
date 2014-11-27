<?php
/**
 * @file
 * debut_feature_importer_photo_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function debut_feature_importer_photo_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'debut_photo_reports_importer';
  $feeds_importer->config = array(
    'name' => 'Debut photo reports importer',
    'description' => 'Debut photo reports importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsSQLFetcher',
      'config' => array(
        'databases' => array(
          'pd_old' => 'pd_old',
          'default' => 0,
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSQLParser',
      'config' => array(
        'query' => 'SELECT node.nid AS nid,
node.changed AS node_changed,
node.created AS node_created,
node.title AS node_title,
node.status AS node_status,
node.type AS node_type,
filepath,
filename,
node_data_field_photo_listing_photo.field_photo_listing_photo_data AS photo_data
 FROM node node 
 LEFT JOIN content_field_photo_listing_photo node_data_field_photo_listing_photo ON node.vid = node_data_field_photo_listing_photo.vid
 LEFT JOIN files ON files.fid = node_data_field_photo_listing_photo.field_photo_listing_photo_fid
 WHERE node.type in (\'photo_listing\')
   ORDER BY node.created ASC',
        'database' => 'pd_old',
        'mapping' => array(
          'filename' => 'filename',
          'filepath' => 'filepath',
          'nid' => 'nid',
          'node_changed' => 'node_changed',
          'node_created' => 'node_created',
          'node_status' => 'node_status',
          'node_title' => 'node_title',
          'node_type' => 'node_type',
          'photo_data' => 'photo_data',
        ),
        'results' => '',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'nid',
            'target' => 'nid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'node_title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'node_status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'node_created',
            'target' => 'created',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'photo_listing',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['debut_photo_reports_importer'] = $feeds_importer;

  return $export;
}
