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
 * Preprocess node__press_about_debut__full.
 */
function debut_preprocess_node__press_about_debut__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
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

/**
 * Preprocess node__press_about_debut__listing.
 */
function debut_preprocess_node__press_about_debut__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['body'] = debut_render($content, 'field_press_text');
  $_html['press_date'] = debut_render($content, 'field_publication_date');  

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

/**
 * Preprocess node__master_class_text__full.
 */
function debut_preprocess_node__master_class_text__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['text']  = debut_render($content, 'field_master_class_text_body');
}

/**
 * Preprocess node__master_class_text__search.
 */
function debut_preprocess_node__master_class_text__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_common_trim(strip_tags(debut_render($content, 'field_master_class_text_body')), 150);
}

/**
 * Preprocess view mode full for travel description node.
 */
function debut_preprocess_node__travel_description__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_render($content, 'field_travels_description_body');
  $_html['date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess view mode listing for travel description node.
 */
function debut_preprocess_node__travel_description__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess travel_description_search(.
 */
function debut_preprocess_node__travel_description__search(&$variables) {
  debut_preprocess_node__travel_description__listing($variables);
}

/**
 * Preprocess view mode full for travel node.
 */
function debut_preprocess_node__travel__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  
  $_html['title'] = check_plain($node->title);
  $_html['content'] = debut_render($content, 'field_travel_travels');
}

/**
 * Preprocess view mode teaser for travel node.
 */
function debut_preprocess_node__travel__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['content'] = debut_render($content, 'field_travel_travels');
}

/**
 * Preprocess view mode listing for travel  node.
 */
function debut_preprocess_node__travel__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess travel_search.
 */
function debut_preprocess_node__travel__search(&$variables) {
  debut_preprocess_node__travel__teaser($variables);
}

/**
 * Preprocess config_page__manuscript_page__full.
 */
function debut_preprocess_config_pages__manuscript_page__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['text'] = debut_render($content, 'field_manuscript_text');
}

/**
 * Preprocess video_listing.
 *
 * Displayes playeble youtube iframe.
 */
function debut_preprocess_node__video__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['body'] = debut_render($content, 'field_video_body');

  // Preview picture.
  $field = site_common_field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_image_src('http://youtube.com/' . $field);
  
  $params = array(
    'path' => $src,
    'alt' => $node->title,
    'title' => $node->title,
    'attributes' => NULL,
    'getsize' => FALSE,
  );
  $image = theme('image', $params);
  
  $_html['image'] = l($image, 'node/' . $node->nid , array('html' => TRUE));
}

/**
 * Preprocess video_full.
 *
 * Displayes playeble youtube iframe.
 */
function debut_preprocess_node__video__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_render($content, 'field_video_body');

  // Embed Player.
  $field = site_common_field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_embed_src($field);
  $_data['src'] = $src;
  $_data['id'] = $node->nid;
  
  if (!empty($src)) {
    $_html['player'] = theme('debut_common_embed_player', array('_data' => $_data));
  }
}

/**
 * Preprocess view mode teaser for press_photo_listing node.
 */
function debut_preprocess_node__photo_listing__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $counter = 1;
  foreach ($node->field_photo_listing_photo as $item) {
    if ($counter >= 5) {
      break;
    }
    $class = ($counter % 2) ? 'first' : 'last';
    $image = '';
    $image = theme('imagecache', 'preset_314x166',  $item['filepath'], $item['data']['alt']);
    $image = l($image, 'node/' . $node->nid, array(
      'html' => TRUE,
      'attributes' => array('class' => $class),
    ));
    $_html['images'][] = $image;
    $counter++;
  }
}

/**
 * Preprocess view mode full for press_photo_listing node.
 */
function debut_preprocess_node__photo_listing__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);

  $photo_field = debut_get('field_photo_listing_photo', $content);
 
  foreach ($photo_field['#items'] as $i => $item) {
    $class = ($i % 2) ? 'first' : 'last';
    $image = debut_image_render($photo_field, NULL, $i, ' ', array('no_size' => TRUE));
    $link = l($image, file_create_url($item['uri']), array(
      'html' => TRUE,
      'attributes' => array(
        'class' => $class . ' gallery_elements',
        'rel' => 'gallery',
        'title' => $item['title']
      ),
    ));
    $_html['images'][] = $link;
  }
}

/**
 * Preprocess photo_listing_search.
 */
function debut_preprocess_node__photo_listing_search(&$variables) {
  debut_preprocess_node__photo_listing_teaser($variables);
}
