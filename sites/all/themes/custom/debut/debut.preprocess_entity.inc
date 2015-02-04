<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 * Preprocess simplenews_confirm_removal_form.
 */
function debut_preprocess_form__simplenews_confirm_removal_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['question'] = debut_render($form, 'question');
  $_html['description'] = debut_render($form, 'description');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess simplenews_confirm_add_form.
 */
function debut_preprocess_form__simplenews_confirm_add_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['question'] = debut_render($form, 'question');
  $_html['description'] = debut_render($form, 'description');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess node__video__home_page.
 */
function debut_preprocess_node__video__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/' . $node->nid);

  // Preview picture.
  $image = debut_render($content, 'field_video_image');
  $_html['field_video_image'] = l($image, 'node/' . $node->nid, array(
    'html' => TRUE,
  ));
}

/**
 * Preprocess node__news__home_page.
 */
function debut_preprocess_node__ibooks__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l('', 'node/' . $node->nid . '/popup', array(
    'attributes' => array(
      'class' => array('show-popup-book'),
    )
  ));

  // Image render.
  $image = debut_render($content, 'field_book_image');
  $_html['field_book_image'] = $image;
}

/**
 * Preprocess node__news__home_page.
 */
function debut_preprocess_node__books__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l('', 'node/' . $node->nid . '/popup', array(
    'attributes' => array(
      'class' => array('show-popup-book'),
    )
  ));

  // Image render.
  $image = debut_render($content, 'field_book_image');
  $_html['field_book_image'] = $image;
}

/**
 * Preprocess node__news__home_page.
 */
function debut_preprocess_node__news__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['field_news_annonce'] = debut_render($content, 'field_news_annonce');;
  $_html['field_publication_date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess node__debut_jury__block.
 */
function debut_preprocess_node__debut_jury__block(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = l($node->title, 'node/' . $node->nid);
  $_html['field_jury_citation'] = debut_render($content, 'field_jury_citation');
  $_html['field_jury_image'] = debut_render($content, 'field_jury_image');
  if (empty($_html['field_jury_image'])) {
    $image = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $_html['field_jury_image'] = theme('image', array('path' => $image));
  }
}

/**
 * Preprocess debut_prize_person__block.
 */
function debut_preprocess_node__debut_prize_person__block(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['title'] = l($node->title, 'node/' . $node->nid);
  $_html['field_person_info'] = debut_render($content, 'field_person_info');
  $_html['field_person_image'] = debut_render($content, 'field_person_image');
  if (empty($_html['field_person_image'])) {
    $image = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $_html['field_person_image'] = theme('image', array('path' => $image));
  }
}

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
  $_html['text'] = debut_render($content, 'field_news_annonce');
  $_html['news_date'] = debut_render($content, 'field_publication_date');
}

/**
 * Preprocess view mode search for news node.
 */
function debut_preprocess_node__news__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_render($content, 'field_news_annonce');
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
 * Preprocess view mode search for documents node.
 */
function debut_preprocess_node__documents__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];

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
 * Preprocess view mode search for press_about_debut node.
 */
function debut_preprocess_node__press_about_debut__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['body'] = debut_render($content, 'field_press_text');

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
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
 * Preprocess node__master_class_text__full.
 */
function debut_preprocess_node__master_class_text__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
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
  $_html['text'] = debut_render($content, 'field_master_class_text_body');
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
 * Preprocess travel_description_search.
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
 * Preprocess video_listing.
 *
 * Displayes playeble youtube iframe.
 */
function debut_preprocess_node__video__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_render($content, 'field_video_body');

  // Preview picture.
  $field = qtools_api__field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_embed_src($field);
  $_data['src'] = $src;
  $_data['id'] = $node->nid;

  if (!empty($src)) {
    $_html['player'] = theme('debut_common_embed_player', array('_data' => $_data));
  }
}

/**
 * Preprocess video_search.
 */
function debut_preprocess_node__video__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));
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
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
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

  $images = array();
  foreach ($photo_field['#items'] as $i => $item) {
    $class = ($i % 2) ? 'first' : 'last';
    $title = check_plain($item['title']);
    $images[] = drupal_render($photo_field[$i]) . '<div class="image-title">' . $title . '</div>';
  }
  $_html['images'] = theme('item_list', array(
    'items' => $images,
    'type' => 'ul',
    'attributes'=> array(
      'class' => array('slides'),
    ),
  ));
}

/**
 * Preprocess photo_listing_search.
 */
function debut_preprocess_node__photo_listing__search(&$variables) {
  debut_preprocess_node__photo_listing__listing($variables);
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
  $_html['image'] = debut_render($content, 'field_book_image');

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
      foreach ($stories as $key => $item) {
        $item = trim($item);
        if (empty($item)) {
          unset($stories[$key]);
        }
      }
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
 * Preprocess books_listing.
 */
function debut_preprocess_node__books__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));

  // Check if photo present.
  $image = debut_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

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
  else {
    $_html['authors'] = '';
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

  admin_menu_suppress();
  $classes['popup'] = !empty($classes['popup'])
    ? $classes['popup'] . ' popup-b popup-commenter popup-video'
    : 'popup-b popup-commenter popup-video';

  // Caption.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image render.
  $image = debut_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

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
    $image = debut_render($content, 'field_jury_image');
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
    $image = debut_render($content, 'field_person_image');
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
 * Preprocess ibooks_full.
 */
function debut_preprocess_node__ibooks__full(&$variables) {
  global $base_url;

  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = check_plain($node->title);

  // Image render.
  $image = debut_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_render($content, 'field_book_publication');

  // link for read on-line.
  $_html['ilink'] = NULL;
  $link = qtools_api__field_get_item('node', $node, 'field_ibook_link', 0, 'value');
  if (!empty($link)) {
    $_html['ilink'] = l(t('Read online'), $base_url . $link, array(
      'attributes' => array('class' => 'ebook'),
    ));
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
      foreach ($stories as $key => $item) {
        $item = trim($item);
        if (empty($item)) {
          unset($stories[$key]);
        }
      }
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

    $_html['authors'] = $authors;
  }

  $_html['stories_type'] = qtools_api__field_get_item('node', $node, 'field_book_stories_type', 0, 'value');
}

/**
 * Preprocess ibooks_listing.
 */
function debut_preprocess_node__ibooks__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));

  // Image render.
  $image = debut_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

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
  else {
    $_html['authors'] = '';
  }
}

/**
 * Preprocess books_popup.
 */
function debut_preprocess_node__ibooks__popup(&$variables) {
  debut_preprocess_node__books__popup($variables);
}

/**
 * Preprocess ibooks_search.
 */
function debut_preprocess_node__ibooks__search(&$variables) {
  debut_preprocess_node__ibooks__listing($variables);
}

/**
 * Preprocess view mode full for nobel_speech node.
 */
function debut_preprocess_node__nobel_speech__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = '';

  $_html['press_date'] = debut_render($content, 'field_publication_date');
  $_html['body'] = debut_render($content, 'field_nobel_speech_body');

  // Author.
  $nid = qtools_api__field_get_item('node', $node, 'field_nobel_speech_author', 0, 'target_id');
  if (!empty($nid)) {
    $auth_node = cache_common_load_node($nid);

    if ($node->title != $auth_node->title) {
      $_html['title'] = check_plain($node->title);
    }

    $uri = qtools_api__field_get_item('node', $auth_node, 'field_person_image', 0, 'uri');
    if (!empty($uri)) {
      $image = theme('image_style', array(
        'path' => $uri,
        'style_name' => 'debut_person_page_photo',
        'alt' => $auth_node->title,
        'title' => $auth_node->title,
      ));
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

    $_html['image_legende'] = qtools_api__field_get_item('node', $auth_node, 'field_person_image', 0, 'title');
    $_html['image'] = $image;
    $_html['author'] = l($auth_node->title, 'node/' . $auth_node->nid);
  }
}

/**
 * Preprocess view mode listing for nobel_speech_listing node.
 */
function debut_preprocess_node__nobel_speech__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['press_date'] = debut_render($content, 'field_publication_date');

  $nid = qtools_api__field_get_item('node', $node, 'field_nobel_speech_author', 0, 'target_id');
  if (!empty($nid)) {
    $auth_node = cache_common_load_node($nid);
    $_html['author'] = check_plain($auth_node->title);
  }
}

/**
 * Preprocess view mode full for debut_prize_person node.
 */
function debut_preprocess_node__debut_prize_person__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];


  // Theme title and person image.
  $_html['title'] = check_plain($node->title);

  // Check if photo present.
  if (!empty($content['field_person_image'])) {
    $image = debut_render($content, 'field_person_image');
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
  $_html['image_legende'] = qtools_api__field_get_item('node', $node, 'field_person_image', 0, 'title');

  // Get person tags.
  $tags_field = qtools_api__field_get_item('node', $node, 'field_person_tags');
  foreach ($tags_field as $tag) {
    $tag = taxonomy_term_load($tag['target_id']);
    $_html['tags'][] = '<span class="tag">' . strtolower($tag->name) . '</span>';
  }

  // Get biography.
  $_html['biography_short'] = debut_render($content, 'field_person_biography_short');
  $_html['biography'] = debut_render($content, 'field_person_biography');

  // Get autocomment.
  $_html['autocomment_short'] = debut_render($content, 'field_person_autocomment_short');
  $_html['autocomment'] = debut_render($content, 'field_person_autocomment');

  // Get bibliography.
  $_html['bibliography'] = debut_render($content, 'field_person_bibliography');

  // Add Nobel speech item.
  $result = views_get_view_result(DEBUT_COMMON_VIEW_GET_NOBEL_SPEECH_BY_AUTHOR, 'default', $node->nid);
  $_data['nobel'] = array();
  if (!empty($result)) {
    $nobel = array();
    $nobel['title'] = t('«Нобелевские речи»');
    $nobel['short'] = '';
    foreach ($result as $item) {
      $n_node = cache_common_load_node($item->nid);
      $nobel['short'] .= '<p>' . l($n_node->title, 'node/' . $n_node->nid) . '</p>';
    }
    $_data['nobel'][] = $nobel;
  }

  // Help resources.
  $_html['resources'] = debut_render($content, 'field_person_resources');

  // Linked video.
  $_html['video'] = debut_render($content, 'field_person_linked_video');
}

/**
 * Preprocess view mode teaser for debut_prize_person node.
 */
function debut_preprocess_node__debut_prize_person__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_person_image'])) {
    $image = debut_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '150px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode listing for debut_prize_person node.
 */
function debut_preprocess_node__debut_prize_person__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];

  $_html['num'] = $node->_delta + 1;
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode search for debut_prize_person node.
 */
function debut_preprocess_node__debut_prize_person__search(&$variables) {
  debut_preprocess_node__debut_prize_person__teaser($variables);
}

/**
 * Preprocess view mode compact for debut_prize_person node.
 */
function debut_preprocess_node__debut_prize_person__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_person_image'])) {
    $image = debut_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '150px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Field collection field_person_bibliography preprocess full.
 */
function debut_preprocess_field_collection_item__field_person_bibliography__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_data['id'] = rand(0, 100500);

  $field = debut_get('field_person_biography_text', $content);
  $value = $field['#items'][0]['value'];
  $text = debut_common_remove_double_quot($value);

  $biography = explode("</p>", rtrim($text));

  $_html['title'] = debut_render($content, 'field_person_biography_title');
  $_html['short'] = implode("</p>", array_splice($biography, 0, 2));
  $_html['hidden'] = implode("</p>", $biography);
}

/**
 * Preprocess view mode full for debut_jury node.
 */
function debut_preprocess_node__debut_jury__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and jury image.
  $_html['title'] = check_plain($node->title);

  // Check if photo present.
  if (!empty($content['field_jury_image'])) {
    $image = debut_render($content, 'field_jury_image');
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
  $_html['profile_short'] = debut_render($content, 'field_jury_profile_short');
  $_html['profile'] = debut_render($content, 'field_jury_body');

  // Get jury_self.
  $_html['jury_self_short'] = debut_render($content, 'field_jury_self_short');
  $_html['jury_self'] = debut_render($content, 'field_jury_self_long');

  // Help resources.
  $_html['resources'] = debut_render($content, 'field_person_resources');
}

/**
 * Preprocess view mode teaser for debut_jury node.
 */
function debut_preprocess_node__debut_jury__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_jury_image'])) {
    $image = debut_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '150px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

}

/**
 * Preprocess view mode listing for debut_jury node.
 */
function debut_preprocess_node__debut_jury__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];

  // Title.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode compact for debut_prize_person node.
 */
function debut_preprocess_node__debut_jury__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_jury_image'])) {
    $image = debut_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '150px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode search for debut_jury node.
 */
function debut_preprocess_node__debut_jury__search(&$variables) {
  debut_preprocess_node__debut_jury__teaser($variables);
}

/**
 * Preprocess view mode full for master class node.
 */
function debut_preprocess_node__master_class__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $text_filed = qtools_api__field_get_item('node', $node, 'field_master_class_text');
  if (!empty($text_filed)) {
    $texts = array();
    foreach ($text_filed as $item) {
      $textnode = cache_common_load_node($item['target_id']);
      $text = cache_common_entity_render('node', $textnode, 'listing');
      $texts[] = $text;
    }
    $_html['texts'] = theme('item_list', array(
      'items' => $texts,
      'type' => 'ul',
      'attributes'=> array(
        'class' => array('text-listing'),
      ),
    ));
  }

  $_html['master'] = debut_render($content, 'field_master_class_master');

  // Theme interview.
  $_html['interviews'] = debut_render($content, 'field_master_class_interview');

  $_html['body'] = debut_render($content, 'field_master_class_description');
  $_html['title'] = check_plain($node->title);
}

/**
 * Preprocess master_class_section_search.
 */
function debut_preprocess_node__master_class__search(&$variables) {
  debut_preprocess_node__master_class__teaser($variables);
}

/**
 * Preprocess view mode full for documents node.
 */
function debut_preprocess_node__master_class__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $text_filed = qtools_api__field_get_item('node', $node, 'field_master_class_text');
  if (!empty($text_filed)) {
    $texts = array();
    foreach ($text_filed as $item) {
      $textnode = cache_common_load_node($item['target_id']);
      $text = cache_common_entity_render('node', $textnode, 'listing');
      $texts[] = $text;
    }
    $_html['texts'] = theme('item_list', array(
      'items' => $texts,
      'type' => 'ul',
      'attributes'=> array(
        'class' => array('text-listing'),
      ),
    ));
  }

  // Theme Master node.
  $auth_field = qtools_api__field_get_item('node', $node, 'field_master_class_master', 0, 'target_id');
  if (!empty($auth_field)) {
    $auth_node = cache_common_load_node($auth_field);
    $_html['master'] = l($auth_node->title, 'node/' . $auth_node->nid, array('html' => TRUE));
  }

  // Theme interview.
  $_html['interviews'] = debut_render($content, 'field_master_class_interview');

}

/**
 * Preprocess view mode full for interview node.
 */
function debut_preprocess_node__interview__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['author'] = debut_render($content, 'field_interview_author');
  $_html['body'] = debut_render($content, 'field_interview_body');
}

/**
 * Preprocess interview_search.
 */
function debut_preprocess_node__interview__search(&$variables) {
  debut_preprocess_node__interview__compact($variables);
}

/**
 * Preprocess view mode listing for interview node.
 */
function debut_preprocess_node__interview__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

function debut_preprocess_node__interview__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $uri = '';

  $auth_field = qtools_api__field_get_item('node', $node, 'field_interview_author', 0, 'target_id');
  if (!empty($auth_field)) {
    $auth_node = cache_common_load_node($auth_field);
    $uri = qtools_api__field_get_item('node', $auth_node, 'field_person_image', 0, 'uri');
  }
  if (!empty($uri)) {
    $image = theme('image_style', array(
      'path' => $uri,
      'style_name' => 'debut_person_alphabet_page',
      'alt' => $auth_node->title,
      'title' => $auth_node->title,
    ));
  }
  else {
    $path = drupal_get_path('theme', 'debut') . '/html/images/content/no_photo.jpg';
    $params = array(
      'path' => $path,
      'alt' => $node->title,
      'title' => $node->title,
      'width' => '150px',
      'attributes' => array('class' => array('image-class')),
      'getsize' => FALSE,
    );
    $image =  theme('image', $params);
  }

  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}
