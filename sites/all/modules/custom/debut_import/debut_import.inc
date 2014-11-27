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
    case DEBUT_IMPORT_PRESS_IMPORTER:
    case DEBUT_IMPORT_VIDEO_IMPORTER:
      $result = TRUE;
      break;
    default:
      $result = FALSE;
      break;
  }
  return $result;
}

/**
 * Update publictaion date.
 */
function debut_import_set_publication_date($source, &$entity, $item) {

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = $item['node_data_field_publication_date_field_publication_date_valu'];
}

/**
 * Set path for import video image.
 */
function debut_import_set_filepath_for_video(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['filepath'])) {
      $item['filepath'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['filepath'];
    }
  }
}
