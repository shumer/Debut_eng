<?php
/**
 * @file
 * debut_feature_ct_debut_person.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function debut_feature_ct_debut_person_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_autocomment|node|debut_prize_person|form';
  $field_group->group_name = 'group_autocomment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_prize_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Autocomment',
    'weight' => '1',
    'children' => array(
      0 => 'field_person_autocomment_short',
      1 => 'field_person_autocomment',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-autocomment field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_autocomment|node|debut_prize_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bibliography|node|debut_prize_person|form';
  $field_group->group_name = 'group_bibliography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_prize_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bibliography',
    'weight' => '2',
    'children' => array(
      0 => 'field_person_bibliography',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-bibliography field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bibliography|node|debut_prize_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_biography|node|debut_prize_person|form';
  $field_group->group_name = 'group_biography';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_prize_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Biography',
    'weight' => '3',
    'children' => array(
      0 => 'field_person_biography_short',
      1 => 'field_person_biography',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-biography field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_biography|node|debut_prize_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|debut_prize_person|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_prize_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_person_name',
      1 => 'field_person_surname',
      2 => 'field_person_info',
      3 => 'field_person_image',
      4 => 'field_person_tags',
      5 => 'field_person_awards',
      6 => 'title',
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
  $export['group_general|node|debut_prize_person|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|debut_prize_person|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'debut_prize_person';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resources',
    'weight' => '4',
    'children' => array(
      0 => 'field_person_resources',
      1 => 'field_person_linked_video',
      2 => 'field_person_audio',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-resources field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_resources|node|debut_prize_person|form'] = $field_group;

  return $export;
}
