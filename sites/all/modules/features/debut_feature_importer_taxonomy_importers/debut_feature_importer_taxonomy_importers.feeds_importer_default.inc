<?php
/**
 * @file
 * debut_feature_importer_taxonomy_importers.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function debut_feature_importer_taxonomy_importers_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'debut_prize_authors_taxonomy_import';
  $feeds_importer->config = array(
    'name' => 'Debut Prize authors taxonomy import',
    'description' => '',
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
        'query' => 'SELECT term_data.tid AS tid,
term_data.name AS term_data_name,
term_data.vid AS term_data_vid
 FROM term_data term_data 
 WHERE term_data.vid in (\'1\')',
        'database' => 'pd_old',
        'mapping' => array(
          'term_data_name' => 'term_data_name',
          'term_data_vid' => 'term_data_vid',
          'tid' => 'tid',
        ),
        'results' => '',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'term_data_name',
            'target' => 'name',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'writers_tags',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['debut_prize_authors_taxonomy_import'] = $feeds_importer;

  return $export;
}
