<?php
/**
 * @file
 * debut_feature_ct_interview.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_feature_ct_interview_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function debut_feature_ct_interview_node_info() {
  $items = array(
    'interview' => array(
      'name' => t('Интервью'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
