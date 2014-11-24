<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 * Preprocess article full view on search page.
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
  $publication_date = site_common_field_get_item('node', $node, 'field_publication_date', 0, 'value');
  $publication_date = strtotime($publication_date);
  $_html['news_date'] = format_date($publication_date, 'custom', 'd-m-Y');
}
