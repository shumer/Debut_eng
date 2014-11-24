<?php
/**
 * @file
 * debut_feature_date_formats.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_feature_date_formats_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
