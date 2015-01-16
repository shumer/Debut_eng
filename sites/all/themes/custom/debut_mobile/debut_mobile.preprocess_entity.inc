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
