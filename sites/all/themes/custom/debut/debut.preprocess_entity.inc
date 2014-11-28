<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 * Preprocess node__news__full.
 */
function debut_preprocess_node__news__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = check_plain($node->title);
  $_html['text']  = debut_render($content, 'field_news_full_text');

  // Publication date.
  $_html['news_date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess node__news__listing.
 */
function debut_preprocess_node__news__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_render($content, 'field_news_annonce');;
  $_html['news_date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess node__documents__full.
 */
function debut_preprocess_node__documents__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  
  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_render($content, 'field_document_body');
  $_html['documents_date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess node__documents__listing.
 */
function debut_preprocess_node__documents__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess node__press_about_debut__listing.
 */
function debut_preprocess_node__press_about_debut__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['press_date'] = debut_render($content, 'field_publication_date');
  $_html['body'] = debut_render($content, 'field_press_text');
  
  $publication_link = site_common_field_get_item('node', $node, 'field_press_publication_link', 0, 'value');
  $publication_text = site_common_field_get_item('node', $node, 'field_press_publication_text', 0, 'value');
  $author = debut_render($content, 'field_press_author');

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
