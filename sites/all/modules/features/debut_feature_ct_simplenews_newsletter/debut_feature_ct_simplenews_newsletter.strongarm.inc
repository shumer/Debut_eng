<?php
/**
 * @file
 * debut_feature_ct_simplenews_newsletter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function debut_feature_ct_simplenews_newsletter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__simplenews';
  $strongarm->value = array(
    'view_modes' => array(
      'block' => array(
        'custom_settings' => FALSE,
      ),
      'home_page' => array(
        'custom_settings' => FALSE,
      ),
      'popup' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'frame' => array(
        'custom_settings' => TRUE,
      ),
      'search' => array(
        'custom_settings' => TRUE,
      ),
      'compact' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__simplenews'] = $strongarm;

  return $export;
}
