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
    case DEBUT_IMPORT_JURY_IMPORTER:
    case DEBUT_IMPORT_PERSONS_IMPORTER:
    case DEBUT_IMPORT_BOOK_IMPORTER:
    case DEBUT_IMPORT_IBOOK_IMPORTER:
    case DEBUT_IMPORT_INTERVIEW_IMPORTER:
    case DEBUT_IMPORT_NOBEL_IMPORTER:
    case DEBUT_IMPORT_MC_IMPORTER:
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

/**
 * Set path for import video image.
 */
function debut_import_update_jury_filepath(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['xpathparser:12'])) {
      $item['xpathparser:12'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['xpathparser:12'];
    }
  }
}

/**
 * Actions for person import.
 */
function debut_import_update_presons_filepath(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['xpathparser:5'])) {
      $item['xpathparser:5'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['xpathparser:5'];
    }
  }
}

/**
 * Actions for person import.
 */
function debut_import_person_import_actions($source, &$entity, $item) {
  $entity->field_person_image[LANGUAGE_NONE][0]['title'] = $entity->{'Temporary target 1'};
  $entity->field_person_image[LANGUAGE_NONE][0]['alt'] = $entity->{'Temporary target 2'};

  // Clear old field collection items if exists.
  $fc_items_old = qtools_api__field_get_item('node', $entity, 'field_person_bibliography', NULL, 'value');
  if (!empty($fc_items_old)) {
    foreach ($fc_items_old as $fc_id) {
      $fc_item = entity_load_single('field_collection_item', $fc_id);
      if ($fc_item) {
        // We delete FC manually because delete() method invoke host entity save action and we didn't want to do this.
        entity_get_controller('field_collection_item')->delete(array($fc_id));
      }
      unset($entity->field_person_bibliography[LANGUAGE_NONE][$delta]);
    }
  }

  if (!empty($entity->{'Temporary target 3'})) {
    // Create new field collection items.
    foreach ($entity->{'Temporary target 3'} as $key => $b_title) {
      $b_text = $entity->{'Temporary target 4'}[$key];

      // As we translate FC as whole entity, all field inside it are not translatable. So use LANGUAGE_NONE.
      $fc_item = entity_create('field_collection_item', array('field_name' => 'field_person_bibliography'));
      $fc_item->setHostEntity($entity->feeds_item->entity_type, $entity);
      $fc_item->field_person_biography_title[LANGUAGE_NONE][0]['value'] = $b_title;
      $fc_item->field_person_biography_text[LANGUAGE_NONE][0]['value'] = $b_text;
      $fc_item->save(TRUE);
    }
  }
}

/**
 * Set path for import video image.
 */
function debut_import_update_book_filepath(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['xpathparser:4'])) {
      $item['xpathparser:4'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['xpathparser:4'];
    }
    if (!empty($item['xpathparser:5'])) {
      $item['xpathparser:5'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['xpathparser:5'];
    }
  }
}

/**
 * Actions for person import.
 */
function debut_import_book_import_actions($source, &$entity, $item) {

  // Clear old field collection items if exists.
  $fc_items_old = qtools_api__field_get_item('node', $entity, 'field_book_content', NULL, 'value');
  if (!empty($fc_items_old)) {
    foreach ($fc_items_old as $delta => $fc_id) {
      $fc_item = entity_load_single('field_collection_item', $fc_id);
      if ($fc_item) {
        // We delete FC manually because delete() method invoke host entity save action and we didn't want to do this.
        entity_get_controller('field_collection_item')->delete(array($fc_id));
      }
      unset($entity->field_book_content[LANGUAGE_NONE][$delta]);
    }
  }

  if (!empty($entity->{'Temporary target 1'})) {
    if (!is_array($entity->{'Temporary target 1'})) {
      $entity->{'Temporary target 1'} = array($entity->{'Temporary target 1'});
      $entity->{'Temporary target 2'} = array($entity->{'Temporary target 2'});
    }

    // Create new field collection items.
    foreach ($entity->{'Temporary target 1'} as $key => $b_author) {
      $b_text = $entity->{'Temporary target 2'}[$key];

      // As we translate FC as whole entity, all field inside it are not translatable. So use LANGUAGE_NONE.
      $fc_item = entity_create('field_collection_item', array('field_name' => 'field_book_content'));
      $fc_item->setHostEntity($entity->feeds_item->entity_type, $entity);
      $fc_item->field_book_author[LANGUAGE_NONE][0]['target_id'] = $b_author;
      if (!empty($b_text)) {
        $fc_item->field_book_author_texts[LANGUAGE_NONE][0]['value'] = $b_text;
      }
      $fc_item->save(TRUE);
    }
  }
}


/**
 * Set path for import video image.
 */
function debut_import_update_ibook_filepath(&$result) {
  foreach ($result->items as &$item) {
    if (!empty($item['xpathparser:4'])) {
      $item['xpathparser:4'] = DEBUT_IMPORT_SOURCE_MEDIA_PATH . $item['xpathparser:4'];
    }
  }
}

/**
 * Update publictaion date.
 */
function debut_import_nobel_set_publication_date($source, &$entity, $item) {

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = $item['xpathparser:3'];
}

/**
 * Update publictaion date.
 */
function debut_import_mc_set_publication_date($source, &$entity, $item) {

  // Set publication date.
  $entity->field_publication_date[LANGUAGE_NONE][0]['value'] = $item['xpathparser:6'];
}
