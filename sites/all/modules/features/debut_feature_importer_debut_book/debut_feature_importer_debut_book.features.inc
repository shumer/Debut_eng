<?php
/**
 * @file
 * debut_feature_importer_debut_book.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_feature_importer_debut_book_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
