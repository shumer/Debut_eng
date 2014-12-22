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

  $publication_link = qtools_api__field_get_item('node', $node, 'field_press_publication_link', 0, 'value');
  $publication_text = qtools_api__field_get_item('node', $node, 'field_press_publication_text', 0, 'value');
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

  $publication_link = qtools_api__field_get_item('node', $node, 'field_press_publication_link', 0, 'value');
  $publication_text = qtools_api__field_get_item('node', $node, 'field_press_publication_text', 0, 'value');
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
  $field = qtools_api__field_get_item('node', $node, 'field_video_url', 0, 'value');
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
  $field = qtools_api__field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_embed_src($field);
  $_data['src'] = $src;
  $_data['id'] = $node->nid;

  if (!empty($src)) {
    $_html['player'] = theme('debut_common_embed_player', array('_data' => $_data));
  }
}

/**
 * Preprocess debut_common_contact_us_form.
 */
function debut_preprocess_form__debut_common_contact_us_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['name'] = drupal_render($form['contact_form_name']);
  $_html['email'] = drupal_render($form['contact_form_email']);
  $_html['message'] = drupal_render($form['contact_form_message']);
  $_html['captcha'] = drupal_render($form['captcha']);

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess view mode teaser for press_photo__listing node.
 */
function debut_preprocess_node__photo_listing__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  
  $visible_image_count = 4;

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  
  $photo_field = debut_get('field_photo_listing_photo', $content);
  
  foreach ($photo_field['#items'] as $i => $item) {
    if ($i >= $visible_image_count) {
      break;
    }
    $class = ($i % 2) ? 'first' : 'last';
    $image = drupal_render($photo_field[$i]);
    $image = l($image, 'node/' . $node->nid, array(
      'html' => TRUE,
      'attributes' => array('class' => $class),
    ));
    $_html['images'][] = $image;
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
    $image = drupal_render($photo_field[$i]);
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

/**
 * Preprocess debut_common_send_manuscript_form.
 */
function debut_preprocess_form__debut_common_send_manuscript_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['name'] = drupal_render($form['name']);
  $_html['email'] = drupal_render($form['email']);
  $_html['message'] = drupal_render($form['comment']);
  $_html['file_upload'] = drupal_render($form['file_upload']);
  $_html['captcha'] = drupal_render($form['captcha']);

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess books_full.
 */
function debut_preprocess_node__books__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $authors = array();
  
  // Check if photo present.
  $book_image = debut_get('field_book_image', $content);
  if (!empty($book_image)) {
    $image = drupal_render($book_image[0]);
    $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }

  // Authors.
  $field_content = qtools_api__field_get_item('node', $node, 'field_book_content');

  if (!empty($field_content)) {
    foreach ($field_content as $key => $val) {
      $collection = field_collection_item_load($val['value']);
      $nid = qtools_api__field_get_item('field_collection_item', $collection, 'field_book_author', 0, 'target_id');
      $authnode = cache_common_load_node($nid);
      
      $author = cache_common_entity_render('node', $authnode, 'frame');

      // Author stories.
      $stories = explode("\n", qtools_api__field_get_item('field_collection_item', $collection, 'field_book_author_texts', 0, 'value'));

      $authors[] = array(
        'author' => $author,
        'stories' => theme_item_list(array(
          'items' => $stories,
          'title' => '',
          'type' => 'ul',
          'attributes' => array('class' => 'listing'),
        )),
      );
    }
  }

  $_html['authors'] = $authors;
  
  // Prepare pdf link if we have it.
  $pdf_path = qtools_api__field_get_item('node', $node, 'field_book_pdf', 0, 'uri');
  if (!empty($pdf_path)) {
    $_html['pdf_link'] = l(t('Download PDF book version'), file_create_url($pdf_path), array(
      'attributes' => array('class' => 'pdf'),
    ));
  }

  $_html['title'] = check_plain($node->title);
  $_html['publication'] = debut_render($content, 'field_book_publication');
  $_html['stories_type'] = qtools_api__field_get_item('node', $node, 'field_book_stories_type', 0, 'value');
  
}

/**
 * Preprocess books_teaser.
 */
function debut_preprocess_node__books__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));

  // Check if photo present.
  $book_image = debut_get('field_book_image', $content);
  if (!empty($book_image)) {
    $image = drupal_render($book_image[0]);
    $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }

  // Publication.
  $_html['publication'] = debut_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_render($content, 'field_book_short_description');

  // Authors.
  $authors = array();
  $field_content = qtools_api__field_get_item('node', $node, 'field_book_content');
  if (!empty($field_content)) {
    foreach ($field_content as $key => $val) {
      $collection = field_collection_item_load($val['value']);
      $nid = qtools_api__field_get_item('field_collection_item', $collection, 'field_book_author', 0, 'target_id');
      $authnode = cache_common_load_node($nid);
      $authors[] = l($authnode->title, 'node/' . $authnode->nid);
    }
  }

  if (!empty($authors)) {
    $_html['authors'] = theme_item_list(array(
      'items' => $authors,
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => 'listing'),
    ));
  }
}

/**
 * Preprocess books_compact.
 */
function debut_preprocess_node__books__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Link.
  $_html['title'] = l('', 'node/' . $node->nid . '/popup', array(
    'attributes' => array(
      'class' => 'show-popup-book',
    )
  ));

  // Check if photo present.
  $book_image = debut_get('field_book_image', $content);
  if (!empty($book_image)) {
    $image = drupal_render($book_image[0]);
    $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }
}

/**
 * Preprocess books_popup.
 */
function debut_preprocess_node__books__popup(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  
  $classes = &ctools_static('popup_1col_classes', array());
  $classes['popup'] = !empty($classes['popup'])
    ? $classes['popup'] . ' popup-b popup-commenter popup-video'
    : 'popup-b popup-commenter popup-video';

  // Caption.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Check if photo present.
  $book_image = debut_get('field_book_image', $content);
  if (!empty($book_image)) {
    $image = drupal_render($book_image[0]);
    $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
  }

  // Publication.
  $_html['publication'] = debut_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_render($content, 'field_book_short_description');

  // Authors.
  $authors = array();
  $field_content = qtools_api__field_get_item('node', $node, 'field_book_content');
  if (!empty($field_content)) {
    foreach ($field_content as $key => $val) {
      $collection = field_collection_item_load($val['value']);
      $nid = qtools_api__field_get_item('field_collection_item', $collection, 'field_book_author', 0, 'target_id');
      $authnode = cache_common_load_node($nid);
      $authors[] = l($authnode->title, 'node/' . $authnode->nid);
    }
  }

  if (!empty($authors)) {
    $_html['authors'] = theme_item_list(array(
      'items' => $authors,
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => 'listing'),
    ));
  }
}

/**
 * Preprocess books_search.
 */
function debut_preprocess_node__books__search(&$variables) {
  debut_preprocess_node__books__listing($variables);
}

/**
 * Preprocess debut_jury at frame view.
 */
function debut_preprocess_node__debut_jury__frame($variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  if (!empty($content['field_jury_image'])) {
    $image_field = debut_get('field_jury_image', $content);
    $image = drupal_render($image_field);
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '100px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);    
  }
  
  $_html['image'] = $image;
  $_html['name'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess debut_prize_person at frame view.
 */
function debut_preprocess_node__debut_prize_person__frame($variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  if (!empty($content['field_person_image'])) {
    $image_field = debut_get('field_person_image', $content);
    $image = drupal_render($image_field);
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '100px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);    
  }
  
  $_html['image'] = $image;
  $_html['name'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}
