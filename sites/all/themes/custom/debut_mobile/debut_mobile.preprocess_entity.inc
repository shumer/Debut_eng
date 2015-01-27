<?php
/**
 * @file
 * Preprocess functions.
 */

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
