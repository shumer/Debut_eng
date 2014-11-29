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
    case DEBUT_IMPORT_PHOTO_IMPORTER:
    case DEBUT_IMPORT_TRAVELS_DESCRIPTION_IMPORTER:
    case DEBUT_IMPORT_TRAVELS_IMPORTER:
    case DEBUT_IMPORT_MC_TEXT_IMPORTER:
    case DEBUT_IMPORT_AUTHOR_TAX_IMPORTER:
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
function debut_import_update_filepath(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['filepath'])) {
      $item['filepath'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['filepath'];
    }
  }
}

/**
 * Actions for photo import.
 */
function debut_import_photo_import_actions($source, &$entity, $item) {

  // Get data for update.
  $f_data = unserialize($item['photo_data']);

  // Get and copy image.
  $filepath = $item['filepath'];
  $filename = $item['filename'];
  $path = explode('/', $filepath);
  $file_name = end($path);
  $file_data = file_get_contents($filepath);
  $directory = 'public://photoreports/';
  file_prepare_directory($directory, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY);
  $file = file_save_data($file_data, $directory . $file_name, FILE_EXISTS_REPLACE);
  $new_file = (array)$file;

  // Set attributes.
  $new_file['filename'] = $filename;
  $new_file['alt'] = $f_data['alt'];
  $new_file['title'] = $f_data['title'];

  $entity->field_photo_listing_photo[LANGUAGE_NONE][] = $new_file;

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = date('Y-m-d H:i:s', $item['node_created']);
}

/**
 * Actions for term import.
 */
function debut_import_term_import_actions($source, &$entity, $item) {
 $entity->tid = $item['tid'];

}
