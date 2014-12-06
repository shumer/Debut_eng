<?php
/**
 * @file
 * debut_feature_importer_debut_persons.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function debut_feature_importer_debut_persons_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'debut_persons_import';
  $feeds_importer->config = array(
    'name' => 'Debut Persons Import',
    'description' => 'Debut Persons Import',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'nid',
          'xpathparser:1' => 'title',
          'xpathparser:2' => 'field_person_name',
          'xpathparser:3' => 'field_person_surname',
          'xpathparser:4' => 'field_person_info',
          'xpathparser:5' => 'field_person_image_filepath',
          'xpathparser:6' => 'field_person_image_title',
          'xpathparser:7' => 'field_person_image_alt',
          'xpathparser:8' => 'field_person_tags',
          'xpathparser:9' => 'field_person_biography_short',
          'xpathparser:10' => 'field_person_biography',
          'xpathparser:11' => 'field_person_autocomment_short',
          'xpathparser:12' => 'field_person_autocomment',
          'xpathparser:13' => 'group_person_bibliography/field_person_biography_title',
          'xpathparser:14' => 'group_person_bibliography/field_person_biography_text',
          'xpathparser:15' => 'field_person_resources',
          'xpathparser:16' => 'field_person_linked_video',
          'xpathparser:17' => 'field_person_audio',
          'xpathparser:18' => 'field_person_awards',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
        ),
        'context' => '//node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
          ),
        ),
        'allow_override' => 0,
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
            'source' => 'xpathparser:0',
            'target' => 'nid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_person_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_person_surname',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_person_info',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_person_image',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'Temporary target 2',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_person_tags:etid',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_person_biography_short',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_person_biography',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_person_autocomment_short',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_person_autocomment',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:13',
            'target' => 'Temporary target 3',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:14',
            'target' => 'Temporary target 4',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_person_resources',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_person_linked_video:etid',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_person_audio',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_person_awards:etid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'debut_prize_person',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['debut_persons_import'] = $feeds_importer;

  return $export;
}
