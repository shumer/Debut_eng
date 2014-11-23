<?php
/**
 * @file
 * Logic and API.
 */

/**
 * Check for required import running.
 */
function debut_import_import_id_check($source) {
  switch ($source->importer->id) {
    case DEBUT_IMPORT_NEWS_IMPORTER:
      $result = TRUE;
      break;
    default:
      $result = FALSE;
      break;
  }
  return $result;
}

/**
 * Actions on news import after parse.
 */
function debut_import_news_presave($source, &$entity, $item) {

  // Set publication date.
  $entity->field_news_publication_date[LANGUAGE_NONE][0]['value'] = $item['node_data_field_publication_date_field_publication_date_valu'];
}
