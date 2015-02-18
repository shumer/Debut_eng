<?php
/**
 * @file
 * debut_feature_url_patterns.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function debut_feature_url_patterns_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_books_pattern';
  $strongarm->value = 'book/[node:title]_[node:nid]';
  $export['pathauto_node_books_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_debut_jury_pattern';
  $strongarm->value = 'jury/[node:title]_[node:nid]';
  $export['pathauto_node_debut_jury_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_debut_prize_person_pattern';
  $strongarm->value = 'person/[node:title]_[node:nid]';
  $export['pathauto_node_debut_prize_person_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_documents_pattern';
  $strongarm->value = 'document/[node:title]_[node:nid]';
  $export['pathauto_node_documents_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_ibooks_pattern';
  $strongarm->value = 'ibook/[node:title]_[node:nid]';
  $export['pathauto_node_ibooks_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_interview_pattern';
  $strongarm->value = 'interview/[node:title]_[node:nid]';
  $export['pathauto_node_interview_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_master_class_pattern';
  $strongarm->value = 'master_class/[node:title]_[node:nid]';
  $export['pathauto_node_master_class_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_master_class_text_pattern';
  $strongarm->value = 'master_class/[node:title]_[node:nid]';
  $export['pathauto_node_master_class_text_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_pattern';
  $strongarm->value = 'news/[node:title]_[node:nid]';
  $export['pathauto_node_news_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_nobel_speech_pattern';
  $strongarm->value = 'nobel_speech/[node:title]_[node:nid]';
  $export['pathauto_node_nobel_speech_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = 'content/[node:title]_[node:nid]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_photo_listing_pattern';
  $strongarm->value = 'photo/[node:title]_[node:nid]';
  $export['pathauto_node_photo_listing_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_press_about_debut_pattern';
  $strongarm->value = 'press/[node:title]_[node:nid]';
  $export['pathauto_node_press_about_debut_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_simplenews_pattern';
  $strongarm->value = '';
  $export['pathauto_node_simplenews_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_travel_description_pattern';
  $strongarm->value = 'travel/[node:title]_[node:nid]';
  $export['pathauto_node_travel_description_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_travel_pattern';
  $strongarm->value = 'travel/[node:title]_[node:nid]';
  $export['pathauto_node_travel_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_video_pattern';
  $strongarm->value = 'video/[node:title]_[node:nid]';
  $export['pathauto_node_video_pattern'] = $strongarm;

  return $export;
}
