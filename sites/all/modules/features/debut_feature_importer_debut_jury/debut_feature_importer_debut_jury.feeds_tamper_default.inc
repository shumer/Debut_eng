<?php
/**
 * @file
 * debut_feature_importer_debut_jury.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function debut_feature_importer_debut_jury_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'debut_jury_import-xpathparser_10-explode';
  $feeds_tamper->importer = 'debut_jury_import';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ';',
    'limit' => '',
    'real_separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['debut_jury_import-xpathparser_10-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'debut_jury_import-xpathparser_11-explode';
  $feeds_tamper->importer = 'debut_jury_import';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ';',
    'limit' => '',
    'real_separator' => ';',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['debut_jury_import-xpathparser_11-explode'] = $feeds_tamper;

  return $export;
}
