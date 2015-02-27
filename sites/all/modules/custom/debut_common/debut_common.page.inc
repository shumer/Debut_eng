<?php
/**
 * @file
 * Page callbacks.
 */

/**
 * Callback on calendar ajax request..
 */
function debut_common_page_ajax_site_calendar_callback() {
  global $user;
  $commands = array();

  $date = isset($_GET['date']) ? check_plain($_GET['date']) : '';
  $valid_date = debut_common_validate_date($date);

  if ($valid_date) {
    $changes = debut_common_create_changes_list($date);
    $commands[] = ajax_command_html('.debut_common_site_calendar_text', $changes);
  }

  // Cleanup status messages.
  $msgs = theme('status_messages');
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Callback on calendar ajax request..
 */
function debut_common_page_ajax_newsletter_subscribe_callback() {
  global $user;
  $commands = array();

  if (isset($_POST['email'])) {
    $email = $_POST['email'];
    if (valid_email_address($email)) {
      $result = simplenews_subscriber_load_by_mail($email);
      $subscribed = FALSE;
      if (!empty($result)) {
        if (!empty($result->tids)) {
          drupal_set_message(t('You already subscribed!'), 'warning');
          $subscribed = TRUE;
        }
      }
      if (!$subscribed) {
        simplenews_subscribe_user($email, DEBUT_COMMON_TID_NEWSLETTERS, TRUE, 'newsletter form');
        drupal_set_message(t('You was subscribed successfully. Confirmation message sended to your email address.'));
      }
    }
  }

  $messages = theme('status_messages');
  $commands[] = ajax_command_html('.messages-container', $messages);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Close popup window.
 */
function debut_common_page_js_parent_close() {

  $echo = '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr"><head>
    <script type="text/javascript">
    if (self != parent) {
      try {
        parent.jQuery.fancybox.close();
      }
      catch(ex) {
      }
    }
    </script></head><body style="background: none repeat scroll 0 0 transparent;"></body></html>';
  print $echo;

  // Prevent anything else.
  die;
}

/**
 * Reload parent windoe object.
 *
 * Prints JS that will reload parent window object.
 */
function debut_common_page_js_parent_reload() {
  global $is_https;
  $trail = func_get_args();

  $location = !empty($_REQUEST['destination'])
    ? '\'' . url($_REQUEST['destination'], array('absolute' => TRUE)) . '\''
    : 'href[0]';
  if (!empty($trail)) {
    $fragment = !empty($_REQUEST['fragment'])
      ? $_REQUEST['fragment']
      : '';
    $location = '\'' . url(implode('/', $trail), array('absolute' => TRUE, 'fragment' => $fragment)) . '\'';
  }

  // Combine reload command.
  if ($location == 'href[0]') {
    $command = 'parent.location.reload(true)';
  }
  else {
    $command = 'parent.location.href = ' . $location;
  }

  $echo = '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr"><head>
    <script type="text/javascript">
    if (self != parent) {
      var href = parent.location.href.split(\'#\');
      ' . $command . ';
    }
    </script></head></html>';
  print $echo;

  // Prevent anything else.
  die;
}

/**
 * Callback on calendar ajax request..
 */
function debut_common_persons_view_more($shift = 0) {
  global $user;
  $commands = array();

  $counter = 0; // Counter.
  $interval = 3; // Count of grouping prizes.
  $prizes = array();
  $voc = taxonomy_vocabulary_machine_name_load(DEBUT_COMMON_VOC_PERSON_PRIZES);
  $vocabulary = taxonomy_get_tree($voc->vid);
  $terms_count = count($vocabulary);
  
  $vocabulary = array_slice($vocabulary, $shift, 6);
  $max_count = DEBUT_COMMON_MAX_PERSONS_NOMINEES_SHOW;

  foreach ($vocabulary as $term) {
    if ($counter >= $max_count) {
      break;
    }

    $row = floor($counter/$interval);
    $key = md5(uniqid(rand(),1));

    if ($counter % $interval == 0) {
      $prizes[$row]['data'][$term->tid]['html'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_NOMINEES_LIST_TEASER, 'default', $term->tid);
      $prizes[$row]['data'][$term->tid]['class'] = 'full';
      $prizes[$row]['data'][$term->tid]['id'] = $key;

      $prizes[$row]['captions'][$term->tid]['title'] = $term->name;
      $prizes[$row]['captions'][$term->tid]['ref-id'] = $key;
      $prizes[$row]['captions'][$term->tid]['class'] = 'caption js-prizes-show active-link';
    }
    else {
      $prizes[$row]['data'][$term->tid]['html'] = views_embed_view(DEBUT_COMMON_VIEW_GET_PERSONS_NOMINEES_LIST, 'default', $term->tid);
      $prizes[$row]['data'][$term->tid]['class'] = 'prem_list';
      $prizes[$row]['data'][$term->tid]['title'] = $term->name;
      $prizes[$row]['data'][$term->tid]['id'] = $key;

      if (debut_common_is_mobile() || qtools_api__developer()) {
        $title = explode(' ', $term->name);
        $prizes[$row]['captions'][$term->tid]['title'] = $title[0];
      }
      else {
        $prizes[$row]['captions'][$term->tid]['title'] = $term->name;        
      }
      $prizes[$row]['captions'][$term->tid]['ref-id'] = $key;
      $prizes[$row]['captions'][$term->tid]['class'] = 'js-prizes-show';
    }

    $counter++;
  }

  // Check if we need to show more button.
  $_data['show_more'] = FALSE;
  if ($terms_count > ($counter + $shift)) {
    $_data['show_more'] = TRUE;
    $shift = $shift + $max_count;
    $_data['show_more_url'] = url('debut_common/ajax/debut_common_persons_view_more/' . $shift);
  }
  $_data['prizes'] = $prizes;
  $data['_data'] = $_data;

  $html = theme('debut_common_persons_view_more', $data);
  $commands[] = ajax_command_append('.persons-list .view-more-target', $html);

  // Cleanup status messages.
  $msgs = theme('status_messages');
  return array('#type' => 'ajax', '#commands' => $commands);
}
