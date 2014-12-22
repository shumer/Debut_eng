<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 * Preprocess node__press_about_debut__listing.
 */
function debut_mobile_preprocess_node__press_about_debut__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['body'] = debut_mobile_render($content, 'field_press_text');
  $_html['press_date'] = debut_mobile_render($content, 'field_publication_date');

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
