<?php
/**
 * @file
 * debut_feature_search_indexes.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function debut_feature_search_indexes_default_search_api_index() {
  $items = array();
  $items['debut_search_index'] = entity_import('search_api_index', '{
    "name" : "Debut search index",
    "machine_name" : "debut_search_index",
    "description" : null,
    "server" : "debut_database_search_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "field_news_annonce:value" : { "type" : "text" },
        "field_news_full_text:value" : { "type" : "text" },
        "field_person_awards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_person_bibliography" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_person_bibliography:field_name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_person_bibliography:field_person_biography_title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_person_name" : { "type" : "text" },
        "field_person_surname" : { "type" : "text" },
        "field_press_author" : { "type" : "text" },
        "field_press_publication_text" : { "type" : "text" },
        "field_video_body:value" : { "type" : "text" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "video" : "video",
              "debut_prize_person" : "debut_prize_person",
              "news" : "news",
              "press_about_debut" : "press_about_debut"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "body:value" : true,
              "field_person_bibliography:field_person_biography_title" : true,
              "field_news_annonce:value" : true,
              "field_news_full_text:value" : true,
              "field_video_body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "body:value" : true,
              "field_person_bibliography:field_person_biography_title" : true,
              "field_news_annonce:value" : true,
              "field_news_full_text:value" : true,
              "field_video_body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "body:value" : true,
              "field_person_bibliography:field_person_biography_title" : true,
              "field_news_annonce:value" : true,
              "field_news_full_text:value" : true,
              "field_video_body:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "body:value" : true,
              "field_person_bibliography:field_person_biography_title" : true,
              "field_news_annonce:value" : true,
              "field_news_full_text:value" : true,
              "field_video_body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
