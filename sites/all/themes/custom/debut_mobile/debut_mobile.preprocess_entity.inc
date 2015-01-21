<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 * Preprocess node__press_about_debut__listing.
 */
function debut_mobile_preprocess_node__news__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = check_plain($node->title);
  $_html['text']  = debut_mobile_render($content, 'field_news_full_text');

  // Publication date.
  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['field_publication_date'] = $published;
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess node__documents__full.
 */
function debut_mobile_preprocess_node__documents__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['field_document_body'] = debut_mobile_render($content, 'field_document_body');
  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['field_publication_date'] = $published;
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess node__press_about_debut__full.
 */
function debut_mobile_preprocess_node__press_about_debut__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['field_publication_date'] = $published;
  $_html['field_press_text'] = debut_mobile_render($content, 'field_press_text');

  $publication_link = qtools_api__field_get_item('node', $node, 'field_press_publication_link', 0, 'value');
  $publication_text = qtools_api__field_get_item('node', $node, 'field_press_publication_text', 0, 'value');
  $author = debut_mobile_render($content, 'field_press_author');

  if (!empty($publication_link) && !empty($publication_text)) {
    $_html['press_link'] = l($publication_text, $publication_link, array(
      'absolute' => TRUE,
      'html' => true,
    ));
  }
  elseif (!empty($publication_text)) {
    $_html['press_link'] = $publication_text;
  }

  if (!empty($author)) {
    $_html['author'] = $author;
  }

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess node__debut_jury__block.
 */
function debut_mobile_preprocess_node__debut_jury__block(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = l($node->title, 'node/' . $node->nid);
  $_html['field_jury_citation'] = debut_mobile_render($content, 'field_jury_citation');
  $_html['field_jury_image'] = debut_mobile_render($content, 'field_jury_image');
  if (empty($_html['field_jury_image'])) {
    $image = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo_block.jpg';
    $_html['field_jury_image'] = theme('image', array('path' => $image));
  }
}

/**
 * Preprocess debut_prize_person__block.
 */
function debut_mobile_preprocess_node__debut_prize_person__block(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = l($node->title, 'node/' . $node->nid);
  $_html['field_person_info'] = debut_mobile_render($content, 'field_person_info');
  $_html['field_person_image'] = debut_mobile_render($content, 'field_person_image');
  if (empty($_html['field_person_image'])) {
    $image = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo_block.jpg';
    $_html['field_person_image'] = theme('image', array('path' => $image));
  }
}

/**
 * Preprocess node__press_about_debut__listing.
 */
function debut_mobile_preprocess_node__press_about_debut__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['field_press_text'] = debut_common_trim(debut_mobile_render($content, 'field_press_text'), 350);
  $_html['field_publication_date'] = debut_mobile_render($content, 'field_publication_date');

  $publication_link = qtools_api__field_get_item('node', $node, 'field_press_publication_link', 0, 'value');
  $publication_text = qtools_api__field_get_item('node', $node, 'field_press_publication_text', 0, 'value');
  $author = debut_mobile_render($content, 'field_press_author');

  if (!empty($publication_link) && !empty($publication_text)) {
    $_html['press_link'] = l($publication_text, $publication_link, array(
      'absolute' => TRUE,
      'html' => true,
    ));
  }
  elseif (!empty($publication_text)) {
    $_html['press_link'] = $publication_text;
  }

  if (!empty($author)) {
    $_html['author'] = $author;
  }

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess views debut_view_list_press_about_debut__default.
 */
function debut_mobile_preprocess_views_debut_view_list_press_about_debut__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess view mode full for debut_jury node.
 */
function debut_mobile_preprocess_node__debut_jury__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and jury image.
  $_html['title'] = check_plain($node->title);

  // Check if photo present.
  if (!empty($content['field_jury_image'])) {
    $image = debut_mobile_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '200px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }
  $_html['image'] = $image;

  // Get jury tags.
  $tags_field = qtools_api__field_get_item('node', $node, 'field_jury_tags');
  foreach ($tags_field as $tag) {
    $tag = taxonomy_term_load($tag['target_id']);
    $_html['tags'][] = '<span class="tag">' . strtolower($tag->name) . '</span>';
  }

  // Get profile.
  $_html['field_jury_profile_short'] = debut_mobile_render($content, 'field_jury_profile_short');
  $_html['field_jury_body'] = debut_mobile_render($content, 'field_jury_body');

  // Get jury_self.
  $_html['field_jury_self_short'] = debut_mobile_render($content, 'field_jury_self_short');
  $_html['field_jury_self_long'] = debut_mobile_render($content, 'field_jury_self_long');

  // Help resources.
  $_html['field_person_resources'] = debut_mobile_render($content, 'field_person_resources');

  $_html['social_links'] = theme('debut_mobile_social_links');

  $_data['nid'] = $node->nid;
}
