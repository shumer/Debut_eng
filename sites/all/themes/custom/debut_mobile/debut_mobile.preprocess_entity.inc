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
  $_html['news_date'] = $published;
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
