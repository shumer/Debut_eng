<?php
/**
 * @file
 * debut_feature_ct_photo_listing.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function debut_feature_ct_photo_listing_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_photo_listing_photo'
  $field_bases['field_photo_listing_photo'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_photo_listing_photo',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
