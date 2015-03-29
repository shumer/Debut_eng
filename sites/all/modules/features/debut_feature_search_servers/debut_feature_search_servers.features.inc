<?php
/**
 * @file
 * debut_feature_search_servers.features.inc
 */

/**
 * Implements hook_default_search_api_server().
 */
function debut_feature_search_servers_default_search_api_server() {
  $items = array();
  $items['debut_database_search_server'] = entity_import('search_api_server', '{
    "name" : "Debut database search server",
    "machine_name" : "debut_database_search_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : { "debut_search_index" : {
          "status" : {
            "table" : "search_api_db_debut_search_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_debut_search_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_debut_search_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_debut_search_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_news_annonce:value" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_news_full_text:value" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_video_body:value" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_person_bibliography:field_name" : {
            "table" : "search_api_db_debut_search_index_field_person_bibliography_fie",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_person_bibliography:field_person_biography_title" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_debut_search_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_person_name" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_person_surname" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_person_bibliography" : {
            "table" : "search_api_db_debut_search_index_field_person_bibliography",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_press_author" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_press_publication_text" : {
            "table" : "search_api_db_debut_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_person_awards" : {
            "table" : "search_api_db_debut_search_index_field_person_awards",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
