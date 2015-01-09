<?php
/**
 * @file
 * debut_feature_view_modes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function debut_feature_view_modes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'node' => array(
      'listing' => array(
        'label' => 'listing',
        'custom settings' => 1,
      ),
      'frame' => array(
        'label' => 'Рамка',
        'custom settings' => 1,
      ),
      'search' => array(
        'label' => 'search',
        'custom settings' => 1,
      ),
      'block' => array(
        'label' => 'Block',
        'custom settings' => 1,
      ),
      'home_page' => array(
        'label' => 'Home page',
        'custom settings' => 1,
      ),
      'compact' => array(
        'label' => 'Compact',
        'custom settings' => 1,
      ),
      'popup' => array(
        'label' => 'Popup',
        'custom settings' => 1,
      ),
    ),
    'field_collection_item' => array(
      'book' => array(
        'label' => 'book',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}
