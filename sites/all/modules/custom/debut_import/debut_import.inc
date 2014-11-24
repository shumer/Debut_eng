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
    case DEBUT_IMPORT_DOCUMENTS_IMPORTER:
      $result = TRUE;
      break;
    default:
      $result = FALSE;
      break;
  }
  return $result;
}

/**
 * Actions on news import presave.
 */
function debut_import_news_presave($source, &$entity, $item) {

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = $item['node_data_field_publication_date_field_publication_date_valu'];
}

/**
 * Actions on documents import presave.
 */
function debut_import_documents_presave($source, &$entity, $item) {

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = $item['node_data_field_publication_date_field_publication_date_valu'];
}
