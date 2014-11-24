<?php
/**
 * @file
 * debut_feature_ct_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function debut_feature_ct_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|news|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_news_annonce',
      1 => 'field_news_full_text',
      2 => 'field_news_publication_date',
      3 => 'field_publication_date',
      4 => 'title',
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
  $export['group_general|node|news|form'] = $field_group;

  return $export;
}
