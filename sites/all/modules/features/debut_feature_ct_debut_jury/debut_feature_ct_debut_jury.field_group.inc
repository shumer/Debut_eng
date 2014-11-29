<?php
/**
 * @file
 * debut_feature_ct_debut_jury.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function debut_feature_ct_debut_jury_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|debut_jury|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_jury';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_name',
      1 => 'field_person_surname',
      2 => 'field_jury_image',
      3 => 'field_jury_citation',
      4 => 'field_jury_profile_short',
      5 => 'field_jury_body',
      6 => 'field_jury_self_short',
      7 => 'field_jury_self_long',
      8 => 'field_person_resources',
      9 => 'field_jury_tags',
      10 => 'field_jury_years',
      11 => 'title',
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
  $export['group_general|node|debut_jury|form'] = $field_group;

  return $export;
}
