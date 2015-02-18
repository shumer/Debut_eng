<?php
/**
 * @file
 * Preprocess functions.
 */

/**
 *
 * Preprocess view mode teaser for press_photo__listing node.
 */
function debut_mobile_preprocess_node__photo_listing__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $visible_image_count = 4;

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $photo_field = debut_mobile_get('field_photo_listing_photo', $content);

  $images = array();
  $_data['node_class'] = 'single';
  $_data['class'] = '';
  $_data['wrapper_class'] = '';
  foreach ($photo_field['#items'] as $i => $item) {
    if ($i >= $visible_image_count) {
      break;
    }
    $title = check_plain($item['title']);
    $image = drupal_render($photo_field[$i]) . '<div class="image-title">' . $title . '</div>';
    $images[] = $image;
  }
  if (count($images) > 1) {
    $_data['class'] = 'flexslider';
    $_data['wrapper_class'] = $node->nid;
    $_data['node_class'] = 'multiply';
  }
  $_html['images'] = theme('item_list', array(
    'items' => $images,
    'type' => 'ul',
    'attributes'=> array(
      'class' => array('slides'),
    ),
  ));
  $_html['node_page_link'] = l(t('View more'), 'node/' . $node->nid);

  // Publication date.
  $_html['field_publication_date'] = debut_mobile_render($content, 'field_publication_date');;
}

/**
 * Preprocess nobel_speech_search.
 */
function debut_mobile_preprocess_node__nobel_speech__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['press_date'] = debut_mobile_render($content, 'field_publication_date');

  $nid = qtools_api__field_get_item('node', $node, 'field_nobel_speech_author', 0, 'target_id');
  if (!empty($nid)) {
    $auth_node = cache_common_load_node($nid);
    $_html['author'] = check_plain($auth_node->title);
  }

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess node__documents__search.
 */
function debut_mobile_preprocess_node__documents__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }

}

/**
 * Preprocess node__press_about_debut__search.
 */
function debut_mobile_preprocess_node__press_about_debut__search(&$variables) {
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
 * Preprocess view mode search for news node.
 */
function debut_mobile_preprocess_node__news__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_mobile_render($content, 'field_news_annonce');
  $_html['news_date'] = debut_mobile_render($content, 'field_publication_date');
}

/**
 * Preprocess node__video__home_page.
 */
function debut_mobile_preprocess_node__video__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $title = truncate_utf8($node->title, 50, TRUE, TRUE);
  $_html['title'] = l($title, 'node/' . $node->nid);

  // Preview picture.
  $image = debut_mobile_render($content, 'field_video_image');
  $_html['field_video_image'] = l($image, 'node/' . $node->nid, array(
    'html' => TRUE,
  ));
}

/**
 * Preprocess node__news__home_page.
 */
function debut_mobile_preprocess_node__ibooks__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array(
    'attributes' => array(
      'class' => array('show-popup-book'),
    )
  ));

  // Image render.
  $image = debut_mobile_render($content, 'field_book_image');
  $_html['field_book_image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_mobile_render($content, 'field_book_short_description');

}

/**
 * Preprocess node__news__home_page.
 */
function debut_mobile_preprocess_node__books__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array(
    'attributes' => array(
      'class' => array('show-popup-book'),
    )
  ));

  // Image render.
  $image = debut_mobile_render($content, 'field_book_image');
  $_html['field_book_image'] =  l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_mobile_render($content, 'field_book_short_description');
}

/**
 * Preprocess node__news__home_page.
 */
function debut_mobile_preprocess_node__news__home_page(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['field_news_annonce'] = debut_mobile_render($content, 'field_news_annonce');;
  $_html['field_publication_date'] = debut_mobile_render($content, 'field_publication_date');
}

/**
 * Preprocess views debut_view_persons_list__default.
 */
function debut_mobile_preprocess_views_debut_view_persons_list__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_photos__default.
 */
function debut_mobile_preprocess_views_debut_view_list_photos__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 *
 * Preprocess view mode teaser for press_photo__listing node.
 */
function debut_mobile_preprocess_node__photo_listing__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $visible_image_count = 4;

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $photo_field = debut_mobile_get('field_photo_listing_photo', $content);

  $images = array();
  $_data['node_class'] = 'single';
  $_data['class'] = '';
  $_data['wrapper_class'] = '';
  foreach ($photo_field['#items'] as $i => $item) {
    if ($i >= $visible_image_count) {
      break;
    }
    $title = check_plain($item['title']);
    $image = drupal_render($photo_field[$i]) . '<div class="image-title">' . $title . '</div>';
    $images[] = $image;
  }
  if (count($images) > 1) {
    $_data['class'] = 'flexslider';
    $_data['wrapper_class'] = $node->nid;
    $_data['node_class'] = 'multiply';
  }
  $_html['images'] = theme('item_list', array(
    'items' => $images,
    'type' => 'ul',
    'attributes'=> array(
      'class' => array('slides'),
    ),
  ));
  $_html['node_page_link'] = l(t('View more'), 'node/' . $node->nid);

  // Publication date.
  $_html['field_publication_date'] = debut_mobile_render($content, 'field_publication_date');;
}

/**
 * Preprocess view mode full for press_photo_listing node.
 */
function debut_mobile_preprocess_node__photo_listing__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);

  $photo_field = debut_mobile_get('field_photo_listing_photo', $content);

  $images = array();
  foreach ($photo_field['#items'] as $i => $item) {
    $title = check_plain($item['title']);
    $class = ($i % 2) ? 'first' : 'last';
    $images[] = drupal_render($photo_field[$i]) . '<div class="image-title">' . $title . '</div>';
  }

  $_html['images'] = theme('item_list', array(
    'items' => $images,
    'type' => 'ul',
    'attributes'=> array(
      'class' => array('slides'),
    ),
  ));

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess simplenews_confirm_removal_form.
 */
function debut_mobile_preprocess_form__simplenews_confirm_removal_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['question'] = debut_mobile_render($form, 'question');
  $_html['description'] = debut_mobile_render($form, 'description');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess simplenews_confirm_add_form.
 */
function debut_mobile_preprocess_form__simplenews_confirm_add_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['question'] = debut_mobile_render($form, 'question');
  $_html['description'] = debut_mobile_render($form, 'description');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess debut_common_send_manuscript_form.
 */
function debut_mobile_preprocess_form__debut_common_send_manuscript_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['name'] = debut_mobile_render($form, 'name');
  $_html['email'] = debut_mobile_render($form, 'email');
  $_html['message'] = debut_mobile_render($form, 'comment');
  $_html['file_upload'] = debut_mobile_render($form, 'file_upload');

  $_html['messages'] = theme('status_messages');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess debut_common_contact_us_form.
 */
function debut_mobile_preprocess_form__debut_common_contact_us_form(&$variables) {
  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['name'] = debut_mobile_render($form, 'contact_form_name');
  $_html['email'] = debut_mobile_render($form, 'contact_form_email');
  $_html['message'] = debut_mobile_render($form, 'contact_form_message');

  $_html['form'] = drupal_render_children($form);
}

/**
 * Preprocess node__news__full.
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
 * Preprocess node__news__listing.
 */
function debut_mobile_preprocess_node__news__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_mobile_render($content, 'field_news_annonce');
  $_html['news_date'] = debut_mobile_render($content, 'field_publication_date');

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
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
 * Preprocess node__documents__listing.
 */
function debut_mobile_preprocess_node__documents__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }

}

/**
 * Preprocess config_page__manuscript_page__full.
 */
function debut_mobile_preprocess_config_pages__manuscript_page__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Text part.
  $_html['text'] = debut_mobile_render($content, 'field_manuscript_text');
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
  $image = debut_mobile_render($content, 'field_jury_image');
  if (empty($image)) {
    $image = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo_block.jpg';
    $image = theme('image', array('path' => $image));
  }
  $_html['field_jury_image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
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
  $image = debut_mobile_render($content, 'field_person_image');
  if (empty($image)) {
    $image = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo_block.jpg';
    $image = theme('image', array('path' => $image));
  }
  $_html['field_person_image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));
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
 * Preprocess views debut_view_list_debut_view_jury_alphabet_list__default.
 */
function debut_mobile_preprocess_views_debut_view_jury_alphabet_list__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_press_about_debut__default.
 */
function debut_mobile_preprocess_views_debut_view_jury_prize_list__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_news__default.
 */
function debut_mobile_preprocess_views_debut_view_list_news__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_travels__default.
 */
function debut_mobile_preprocess_views_debut_view_list_travels__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_documents__default.
 */
function debut_mobile_preprocess_views_debut_view_list_documents__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_books__default.
 */
function debut_mobile_preprocess_views_debut_view_list_books__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_ibooks__default.
 */
function debut_mobile_preprocess_views_debut_view_list_ibooks__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_master_class__default.
 */
function debut_mobile_preprocess_views_debut_view_list_master_class__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_nobel_speach__default.
 */
function debut_mobile_preprocess_views_debut_view_list_nobel_speach__default(&$variables) {
  $view  = &$variables['view'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess views debut_view_list_video__default.
 */
function debut_mobile_preprocess_views_debut_view_list_video__default(&$variables) {
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
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
  $_html['tags'] = array();
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

/**
 * Preprocess debut_jury at frame view.
 */
function debut_mobile_preprocess_node__debut_jury__frame($variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  if (!empty($content['field_jury_image'])) {
    $image = debut_mobile_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
 * Preprocess view mode teaser for debut_jury node.
 */
function debut_mobile_preprocess_node__debut_jury__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_jury_image'])) {
    $image = debut_mobile_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
function debut_mobile_preprocess_node__debut_jury__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];

  // Title.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode compact for debut_prize_person node.
 */
function debut_mobile_preprocess_node__debut_jury__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_jury_image'])) {
    $image = debut_mobile_render($content, 'field_jury_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
function debut_mobile_preprocess_node__debut_jury__search(&$variables) {
  debut_mobile_preprocess_node__debut_jury__teaser($variables);
}

/**
 * Preprocess view mode full for nobel_speech node.
 */
function debut_mobile_preprocess_node__nobel_speech__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = '';

  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['press_date'] = $published;
  $_html['body'] = debut_mobile_render($content, 'field_nobel_speech_body');

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
        'style_name' => 'debut_person_page_photo_mobile',
        'alt' => $auth_node->title,
        'title' => $auth_node->title,
      ));
    }
    else {
      $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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

    $_html['image_legende'] = qtools_api__field_get_item('node', $auth_node, 'field_person_image', 0, 'title');
    $_html['image'] = $image;
    $_html['author'] = l($auth_node->title, 'node/' . $auth_node->nid);
  }

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess view mode listing for nobel_speech_listing node.
 */
function debut_mobile_preprocess_node__nobel_speech__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['press_date'] = debut_mobile_render($content, 'field_publication_date');

  $nid = qtools_api__field_get_item('node', $node, 'field_nobel_speech_author', 0, 'target_id');
  if (!empty($nid)) {
    $auth_node = cache_common_load_node($nid);
    $_html['author'] = check_plain($auth_node->title);
  }

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess view mode full for travel description node.
 */
function debut_mobile_preprocess_node__travel_description__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_mobile_render($content, 'field_travels_description_body');

  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['field_publication_date'] = $published;
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess view mode listing for travel description node.
 */
function debut_mobile_preprocess_node__travel_description__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['field_publication_date'] = $published;
}

/**
 * Preprocess travel_description_search.
 */
function debut_mobile_preprocess_node__travel_description__search(&$variables) {
  debut_mobile_preprocess_node__travel_description__listing($variables);
}

/**
 * Preprocess view mode full for travel node.
 */
function debut_mobile_preprocess_node__travel__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['content'] = debut_mobile_render($content, 'field_travel_travels');
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess view mode teaser for travel node.
 */
function debut_mobile_preprocess_node__travel__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['content'] = debut_mobile_render($content, 'field_travel_travels');
}

/**
 * Preprocess view mode listing for travel  node.
 */
function debut_mobile_preprocess_node__travel__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $published = t('Published !date', array('!date' => debut_mobile_render($content, 'field_publication_date')));
  $_html['date'] = $published;

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess travel_search.
 */
function debut_mobile_preprocess_node__travel__search(&$variables) {
  debut_mobile_preprocess_node__travel__teaser($variables);
}

/**
 * Preprocess view mode full for interview node.
 */
function debut_mobile_preprocess_node__interview__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['author'] = debut_mobile_render($content, 'field_interview_author');
  $_html['body'] = debut_mobile_render($content, 'field_interview_body');

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess interview_search.
 */
function debut_mobile_preprocess_node__interview__search(&$variables) {
  debut_mobile_preprocess_node__interview__compact($variables);
}

/**
 * Preprocess view mode listing for interview node.
 */
function debut_mobile_preprocess_node__interview__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

function debut_mobile_preprocess_node__interview__compact(&$variables) {
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
      'style_name' => 'debut_person_alphabet_page_mobile',
      'alt' => $auth_node->title,
      'title' => $auth_node->title,
    ));
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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

/**
 * Preprocess node__master_class_text__full.
 */
function debut_mobile_preprocess_node__master_class_text__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['text']  = debut_mobile_render($content, 'field_master_class_text_body');
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess node__master_class_text__full.
 */
function debut_mobile_preprocess_node__master_class_text__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess node__master_class_text__search.
 */
function debut_mobile_preprocess_node__master_class_text__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['text'] = debut_mobile_render($content, 'field_master_class_text_body');
}

/**
 * Preprocess view mode full for master class node.
 */
function debut_mobile_preprocess_node__master_class__full(&$variables) {
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

  $_html['master'] = debut_mobile_render($content, 'field_master_class_master');

  // Theme interview.
  $_html['interviews'] = debut_mobile_render($content, 'field_master_class_interview');

  $_html['body'] = debut_mobile_render($content, 'field_master_class_description');
  $_html['title'] = check_plain($node->title);

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess master_class_section_search.
 */
function debut_mobile_preprocess_node__master_class__search(&$variables) {
  debut_mobile_preprocess_node__master_class__teaser($variables);
}

/**
 * Preprocess view mode full for documents node.
 */
function debut_mobile_preprocess_node__master_class__teaser(&$variables) {
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
  $_html['interviews'] = debut_mobile_render($content, 'field_master_class_interview');

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Field collection field_person_bibliography preprocess full.
 */
function debut_mobile_preprocess_field_collection_item__field_person_bibliography__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_data['id'] = rand(0, 100500);

  $field = debut_mobile_get('field_person_biography_text', $content);
  $value = $field['#items'][0]['value'];
  $text = debut_common_remove_double_quot($value);

  $biography = explode("</p>", rtrim($text));

  $_html['title'] = debut_mobile_render($content, 'field_person_biography_title');
  $_html['short'] = implode("</p>", array_splice($biography, 0, 2));
  $_html['hidden'] = implode("</p>", $biography);
}

/**
 * Preprocess view mode full for debut_prize_person node.
 */
function debut_mobile_preprocess_node__debut_prize_person__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];


  // Theme title and person image.
  $_html['title'] = check_plain($node->title);

  // Check if photo present.
  if (!empty($content['field_person_image'])) {
    $image = debut_mobile_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
  $_html['biography_short'] = debut_mobile_render($content, 'field_person_biography_short');
  $_html['biography'] = debut_mobile_render($content, 'field_person_biography');

  // Get autocomment.
  $_html['autocomment_short'] = debut_mobile_render($content, 'field_person_autocomment_short');
  $_html['autocomment'] = debut_mobile_render($content, 'field_person_autocomment');

  // Get bibliography.
  $_html['bibliography'] = debut_mobile_render($content, 'field_person_bibliography');

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
  $_html['resources'] = debut_mobile_render($content, 'field_person_resources');

  // Linked video.
  $_html['video'] = debut_mobile_render($content, 'field_person_linked_video');

  $_html['social_links'] = theme('debut_mobile_social_links');
  $_data['nid'] = $node->nid;
}

/**
 * Preprocess debut_prize_person at frame view.
 */
function debut_mobile_preprocess_node__debut_prize_person__frame($variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  if (!empty($content['field_person_image'])) {
    $image = debut_mobile_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
 * Preprocess view mode teaser for debut_prize_person node.
 */
function debut_mobile_preprocess_node__debut_prize_person__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_person_image'])) {
    $image = debut_mobile_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
function debut_mobile_preprocess_node__debut_prize_person__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];

  $_html['num'] = $node->_delta + 1;
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Preprocess view mode search for debut_prize_person node.
 */
function debut_mobile_preprocess_node__debut_prize_person__search(&$variables) {
  debut_mobile_preprocess_node__debut_prize_person__teaser($variables);
}

/**
 * Preprocess view mode compact for debut_prize_person node.
 */
function debut_mobile_preprocess_node__debut_prize_person__compact(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme title and person image.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));

  // Image.
  if (!empty($content['field_person_image'])) {
    $image = debut_mobile_render($content, 'field_person_image');
  }
  else {
    $path = drupal_get_path('theme', 'debut_mobile') . '/html/images/content/no_photo.jpg';
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
 * Preprocess video_full.
 *
 * Displayes playeble youtube iframe.
 */
function debut_mobile_preprocess_node__video__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_mobile_render($content, 'field_video_body');

  // Embed Player.
  $field = qtools_api__field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_embed_src($field);
  $_data['src'] = $src;
  $_data['id'] = $node->nid;

  if (!empty($src)) {
    $_html['player'] = theme('debut_mobile_common_embed_player', array('_data' => $_data));
  }

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess video_listing.
 *
 * Displayes playeble youtube iframe.
 */
function debut_mobile_preprocess_node__video__teaser(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = check_plain($node->title);
  $_html['body'] = debut_mobile_render($content, 'field_video_body');

  // Preview picture.
  $field = qtools_api__field_get_item('node', $node, 'field_video_url', 0, 'value');
  $src = debut_common_embed_src($field);
  $_data['src'] = $src;
  $_data['id'] = $node->nid;

  if (!empty($src)) {
    $_html['player'] = theme('debut_mobile_common_embed_player', array('_data' => $_data));
  }
}

/**
 * Preprocess video_search.
 */
function debut_mobile_preprocess_node__video__search(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));
  $_html['body'] = debut_mobile_render($content, 'field_video_body');

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
 * Preprocess video_listing.
 *
 * Displayes playeble youtube iframe.
 */
function debut_mobile_preprocess_node__video__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/' . $node->nid, array('html' => TRUE));
  $_html['body'] = debut_mobile_render($content, 'field_video_body');

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

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess books_full.
 */
function debut_mobile_preprocess_node__books__full(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $authors = array();

  // Check if photo present.
  $_html['image'] = debut_mobile_render($content, 'field_book_image');

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
      'attributes' => array(
        'class' => 'pdf',
        'rel' => 'external',
      ),
    ));
  }

  $_html['title'] = check_plain($node->title);
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');
  $_html['stories_type'] = qtools_api__field_get_item('node', $node, 'field_book_stories_type', 0, 'value');

  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess books_listing.
 */
function debut_mobile_preprocess_node__books__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));

  // Check if photo present.
  $image = debut_mobile_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_mobile_render($content, 'field_book_short_description');

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

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess books_search.
 */
function debut_mobile_preprocess_node__books__search(&$variables) {
  debut_mobile_preprocess_node__books__home_page($variables);
}

/**
 * Preprocess books_popup.
 */
function debut_mobile_preprocess_node__books__popup(&$variables) {
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
  $image = debut_mobile_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_mobile_render($content, 'field_book_short_description');

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
 * Preprocess ibooks_full.
 */
function debut_mobile_preprocess_node__ibooks__full(&$variables) {
  global $base_url;

  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = check_plain($node->title);

  // Image render.
  $_html['image'] = debut_mobile_render($content, 'field_book_image');

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

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
  $_html['social_links'] = theme('debut_mobile_social_links');
}

/**
 * Preprocess ibooks_listing.
 */
function debut_mobile_preprocess_node__ibooks__listing(&$variables) {
  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Caption.
  $_html['title'] = l($node->title, 'node/'. $node->nid, array('html' => TRUE));

  // Image render.
  $image = debut_mobile_render($content, 'field_book_image');
  $_html['image'] = l($image, 'node/' . $node->nid, array('html' => TRUE));

  // Publication.
  $_html['publication'] = debut_mobile_render($content, 'field_book_publication');

  // Desription.
  $_html['description']  = debut_mobile_render($content, 'field_book_short_description');

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

  $_data['class'] = '';
  if ($node->_last) {
    $_data['class'] = 'last';
  }
}

/**
 * Preprocess books_popup.
 */
function debut_mobile_preprocess_node__ibooks__popup(&$variables) {
  debut_mobile_preprocess_node__books__popup($variables);
}

/**
 * Preprocess ibooks_search.
 */
function debut_mobile_preprocess_node__ibooks__search(&$variables) {
  debut_mobile_preprocess_node__ibooks__home_page($variables);
}
