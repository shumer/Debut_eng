<?php
/**
 * @file
 * debut_feature_importer_master_class_text.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function debut_feature_importer_master_class_text_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'debut_master_class_text_importer';
  $feeds_importer->config = array(
    'name' => 'Debut master class text importer',
    'description' => 'Debut master class text importer',
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
node.created AS node_created,
node.title AS node_title,
node.language AS node_language,
node.status AS node_status,
node_revisions.body AS node_revisions_body,
node_revisions.format AS node_revisions_format
 FROM node node 
 LEFT JOIN node_revisions node_revisions ON node.vid = node_revisions.vid
 WHERE node.type in (\'master_class_text\')',
        'database' => 'pd_old',
        'mapping' => array(
          'nid' => 'nid',
          'node_created' => 'node_created',
          'node_language' => 'node_language',
          'node_revisions_body' => 'node_revisions_body',
          'node_revisions_format' => 'node_revisions_format',
          'node_status' => 'node_status',
          'node_title' => 'node_title',
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
          4 => array(
            'source' => 'node_revisions_body',
            'target' => 'field_master_class_text_body',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'master_class_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['debut_master_class_text_importer'] = $feeds_importer;

  return $export;
}
