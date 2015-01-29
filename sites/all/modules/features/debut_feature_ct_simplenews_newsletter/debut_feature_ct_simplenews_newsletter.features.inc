<?php
/**
 * @file
 * debut_feature_ct_simplenews_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function debut_feature_ct_simplenews_newsletter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function debut_feature_ct_simplenews_newsletter_node_info() {
  $items = array(
    'simplenews' => array(
      'name' => t('Рассылка новостей'),
      'base' => 'node_content',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
