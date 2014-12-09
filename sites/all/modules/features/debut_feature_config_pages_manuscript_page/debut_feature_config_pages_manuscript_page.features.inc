<?php
/**
 * @file
 * debut_feature_config_pages_manuscript_page.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function debut_feature_config_pages_manuscript_page_default_config_pages_type() {
  $items = array();
  $items['manuscript_page'] = entity_import('config_pages_type', '{
    "type" : "manuscript_page",
    "label" : "\\u041f\\u0440\\u0430\\u0432\\u0438\\u043b\\u0430 \\u043f\\u043e\\u0434\\u0430\\u0447\\u0438 \\u0440\\u0443\\u043a\\u043e\\u043f\\u0438\\u0441\\u0435\\u0439",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/content\\/manuscript_page", "type" : "6" },
      "context" : { "group" : {
          "config_pages:language" : 0,
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "rdf_mapping" : []
  }');
  return $items;
}
