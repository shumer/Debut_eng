<?php
/**
 * @file
 * debut_feature_config_pages_manuscript_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function debut_feature_config_pages_manuscript_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'config_pages-manuscript_page-field_manuscript_text'
  $field_instances['config_pages-manuscript_page-field_manuscript_text'] = array(
    'bundle' => 'manuscript_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'config_pages',
    'field_name' => 'field_manuscript_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Text');

  return $field_instances;
}
