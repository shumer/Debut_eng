<?php
/**
 * @file
 * debut_feature_ct_press_about_debut.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function debut_feature_ct_press_about_debut_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|press_about_debut|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_about_debut';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_publication_date',
      1 => 'field_press_author',
      2 => 'field_press_publication_text',
      3 => 'field_press_publication_link',
      4 => 'field_press_text',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general|node|press_about_debut|form'] = $field_group;

  return $export;
}
