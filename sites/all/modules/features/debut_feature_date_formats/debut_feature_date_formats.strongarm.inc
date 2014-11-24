<?php
/**
 * @file
 * debut_feature_date_formats.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function debut_feature_date_formats_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_debut_date_short';
  $strongarm->value = 'd-m-Y';
  $export['date_format_debut_date_short'] = $strongarm;

  return $export;
}
