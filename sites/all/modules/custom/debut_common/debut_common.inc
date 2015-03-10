<?php
/**
 * @file
 * Module logic and API.
 */

/**
 * Construct BC for pages.
 */
function debut_common_create_page_mobile_breadcrumbs() {
  $breadcrumb = array();
  $path = arg(0);
  $argument = arg(1);

  switch ($path) {

    // Bc for contact us page.
    case DEBUT_COMMON_PAGE_SEND_MANUSCRIPT:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Send manuscript');
      break;

    // Bc for contact us page.
    case 'nofollow':
    case 'contact_us':
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Contact us');
      break;

    // Bc for press page.
    case DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for news page.
    case DEBUT_COMMON_PAGE_NEWS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('News'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for docs page.
    case DEBUT_COMMON_PAGE_DOCUMENTS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Documents'), DEBUT_COMMON_PAGE_DOCUMENTS_LIST);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for docs page.
    case DEBUT_COMMON_PAGE_NOBEL_SPEECH:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Nobel speech'), DEBUT_COMMON_PAGE_NOBEL_SPEECH);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for travels page.
    case DEBUT_COMMON_PAGE_TRAVELS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for travels page.
    case DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Letopis Debuta');
      break;

    // Bc for video page.
    case DEBUT_COMMON_PAGE_VIDEO:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Video'), DEBUT_COMMON_PAGE_VIDEO);
      $current_year = (is_numeric($argument)) ? $argument : '';
      if (!empty($current_year)) {
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for books page.
    case DEBUT_COMMON_PAGE_BOOKS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Books'), DEBUT_COMMON_PAGE_BOOKS_LIST);
      break;

    // Bc for ibooks page.
    case DEBUT_COMMON_PAGE_IBOOKS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('iBooks'), DEBUT_COMMON_PAGE_IBOOKS_LIST);
      break;

    // Bc for jury page.
    case DEBUT_COMMON_PAGE_PRIZE_JURY:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize jury'), DEBUT_COMMON_PAGE_PRIZE_JURY);
      break;

    // Bc for person page.
    case DEBUT_COMMON_PAGE_PRIZE_PERSONS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize persons'), DEBUT_COMMON_PAGE_PRIZE_PERSONS);
      break;

    case DEBUT_COMMON_PAGE_PERSONS_LIST:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize persons'), DEBUT_COMMON_PAGE_PRIZE_PERSONS);
      if (strlen($argument) == 2) {
        $breadcrumb[] = strtoupper($argument);
      }
      break;

    case DEBUT_COMMON_PAGE_ALPHABET_JURY:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize jury'), DEBUT_COMMON_PAGE_PRIZE_JURY);
      if (strlen($argument) == 2) {
        $breadcrumb[] = strtoupper($argument);
      }
      break;

    default:
      // Get default breadcrumb.
      $breadcrumb = drupal_get_breadcrumb();
      break;
  }

  return $breadcrumb;
}

/**
 * Mobile status detection.
 */
function debut_common_is_mobile() {
  global $theme_key;
  $detect = mobile_detect_get_object();
  $is_mobile = FALSE;
  if($detect->isMobile() || $detect->isTablet()) {
    $is_mobile = TRUE;
  }

  $result = FALSE;
  if ($is_mobile) {
    $result = TRUE;
  }
  return $result;
}

/**
 * Creates mobile breadcrumb for node.
 */
function debut_common_create_node_mobile_breadcrumbs($node) {
  $breadcrumb = array();

  switch ($node->type) {
    // Make breadcrumb for news node.
    case DEBUT_COMMON_TYPE_NEWS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('News'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = t('News for !year year', array('!year' => date('Y', $date)));
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_NEWS_LIST . '/' . date('Y', $date));
      break;

    // Make breadcrumb for documents node.
    case DEBUT_COMMON_TYPE_DOCUMENTS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Documents'), DEBUT_COMMON_PAGE_DOCUMENTS_LIST);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = t('Documents for !year year', array('!year' => date('Y', $date)));
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_DOCUMENTS_LIST . '/' . date('Y', $date));
      break;

    // Make breadcrumb for press about prize node.
    case DEBUT_COMMON_TYPE_PRESS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT . '/' . date('Y', $date));
      break;

    // Make breadcrumb for Debut jury.
    case DEBUT_COMMON_TYPE_JURY:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize jury'), DEBUT_COMMON_PAGE_PRIZE_JURY);
      $letter = qtools_api__field_get_item('node', $node, 'field_person_surname', 0, 'value');
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_JURY. '/' . $letter);
      break;

    // Make breadcrumb for Debut Person.
    case DEBUT_COMMON_TYPE_PERSONS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Prize persons'), DEBUT_COMMON_PAGE_PRIZE_PERSONS);
      $letter = qtools_api__field_get_item('node', $node, 'field_person_surname', 0, 'value');
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_PERSONS . '/' . $letter);
      break;

    // Make breadcrumb for nobel_speech node.
    case DEBUT_COMMON_TYPE_NOBEL_SPEECH:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Letopis Debuta');
      $breadcrumb[] = l(t('Nobel speech'), DEBUT_COMMON_PAGE_NOBEL_SPEECH);
      break;

    // Make breadcrumb for travels node.
    case DEBUT_COMMON_TYPE_TRAVELS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Letopis Debuta');
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      break;

    // Make breadcrumb for travels node.
    case DEBUT_COMMON_TYPE_TRAVEL_DESCRIPTION:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      $view = qtools_api__views_get_result(DEBUT_COMMON_VIEW_TRAVELS_LISTING, $node->nid);
      $travel_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($travel_node->title, 'node/' . $travel_node->nid);
      break;

    // Make breadcrumb for interview node.
    case DEBUT_COMMON_TYPE_INTERVIEW:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = views_get_view_result(DEBUT_COMMON_VIEW_GET_MASTER_CLASS_BY_PARAMS, 'interview', $node->nid);
      $master_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($master_node->title, 'node/' . $master_node->nid);
      break;

    // Make breadcrumb for master_class_text node.
    case DEBUT_COMMON_TYPE_MASTER_CLASS_TEXT:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = views_get_view_result(DEBUT_COMMON_VIEW_GET_MASTER_CLASS_BY_PARAMS, 'default', $node->nid);
      $master_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($master_node->title, 'node/' . $master_node->nid);
      break;

    case DEBUT_COMMON_TYPE_MASTER_CLASS_SECTION:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = t('Letopis Debuta');
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      break;

    case DEBUT_COMMON_TYPE_VIDEO:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Video'), DEBUT_COMMON_PAGE_VIDEO);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_VIDEO . '/' . $year);
      break;

    case DEBUT_COMMON_TYPE_PHOTOS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Photo reports'), DEBUT_COMMON_TYPE_PHOTOS);
      break;

    case DEBUT_COMMON_TYPE_BOOKS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('Books'), DEBUT_COMMON_PAGE_BOOKS_LIST);
      break;

    case DEBUT_COMMON_TYPE_IBOOKS:
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
      $breadcrumb[] = l(t('iBooks'), DEBUT_COMMON_PAGE_IBOOKS_LIST);
      break;

    default:
      // Make last non link.
      $breadcrumb[] = !empty($node->field_title_short[0]['value'])
        ? $node->field_title_short[0]['value']
        : $node->title;
      break;
  }

  return $breadcrumb;
}

/**
 * Generate search url.
 */
function debut_common_search_url($keys, $absolute = TRUE) {
  return url(DEBUT_COMMON_PATH_SEARCH . '/' . urlencode($keys), array('absolute' => $absolute));
}

/**
 * Construct BC for given node context.
 */
function debut_common_create_node_breadcrumbs($node) {

  $breadcrumb = array();

  if (drupal_strlen($node->title) > 60) {
    $node->title = debut_common_trim($node->title, 55);
  }
  switch ($node->type) {

    // Make breadcrumb for Debut person.
    case DEBUT_COMMON_TYPE_PERSONS:
      $breadcrumb[] = l(t('Prize persons'), DEBUT_COMMON_PAGE_PRIZE_PERSONS);
      $letter = qtools_api__field_get_item('node', $node, 'field_person_surname', 0, 'value');
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_PERSONS . '/' . $letter);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for Debut jury.
    case DEBUT_COMMON_TYPE_JURY:
      $breadcrumb[] = l(t('Prize jury'), DEBUT_COMMON_PAGE_PRIZE_JURY);
      $letter = qtools_api__field_get_item('node', $node, 'field_person_surname', 0, 'value');
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_JURY. '/' . $letter);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for documents node.
    case DEBUT_COMMON_TYPE_DOCUMENTS:
      $breadcrumb[] = l(t('Documents'), DEBUT_COMMON_PAGE_DOCUMENTS_LIST);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_DOCUMENTS_LIST . '/' . $year);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for press about prize node.
    case DEBUT_COMMON_TYPE_PRESS:
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT . '/' . $year);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for news node.
    case DEBUT_COMMON_TYPE_NEWS:
      $breadcrumb[] = l(t('News'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_NEWS_LIST . '/' . $year);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for video node.
    case DEBUT_COMMON_TYPE_VIDEO:
      $breadcrumb[] = l(t('Video'), DEBUT_COMMON_PAGE_VIDEO);
      $publication_date = qtools_api__field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_VIDEO . '/' . $year);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for master class section node.
    case DEBUT_COMMON_TYPE_MASTER_CLASS_SECTION:
      $breadcrumb[] = l(t('Letopis Debuta'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for master class text node.
    case DEBUT_COMMON_TYPE_MASTER_CLASS_TEXT:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = views_get_view_result(DEBUT_COMMON_VIEW_GET_MASTER_CLASS_BY_PARAMS, 'default', $node->nid);
      $master_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($master_node->title, 'node/' . $master_node->nid);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for interview node.
    case DEBUT_COMMON_TYPE_INTERVIEW:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = views_get_view_result(DEBUT_COMMON_VIEW_GET_MASTER_CLASS_BY_PARAMS, 'interview', $node->nid);
      $master_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($master_node->title, 'node/' . $master_node->nid);
      $breadcrumb[] = t('Interview');
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for book node.
    case DEBUT_COMMON_TYPE_BOOKS:
      $breadcrumb[] = l(t('Books'), DEBUT_COMMON_PAGE_BOOKS_LIST);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for ibook node.
    case DEBUT_COMMON_TYPE_IBOOKS:
      $breadcrumb[] = l(t('iBooks'), DEBUT_COMMON_PAGE_IBOOKS_LIST);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for travel node.
    case DEBUT_COMMON_TYPE_TRAVELS:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for travel description node.
    case DEBUT_COMMON_TYPE_TRAVEL_DESCRIPTION:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      $view = qtools_api__views_get_result(DEBUT_COMMON_VIEW_TRAVELS_LISTING, $node->nid);
      $travel_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($travel_node->title, 'node/' . $travel_node->nid);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for nobel_speech node.
    case DEBUT_COMMON_TYPE_NOBEL_SPEECH:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Nobel speech'), DEBUT_COMMON_PAGE_NOBEL_SPEECH);
      $breadcrumb[] = $node->title;
      $edit_link = debut_common_create_node_edit_link_breadcrumbs($node);
      if (!empty($edit_link)) {
        $breadcrumb[] = $edit_link;
      }
      break;

    // Make breadcrumb for photoreporst node.
    case DEBUT_COMMON_TYPE_PHOTOS:
      $breadcrumb[] = l(t('Photoreports'), DEBUT_COMMON_PAGE_PHOTO_LIST);
      $breadcrumb[] = $node->title;
      break;

    default:
      // Make last non link.
      $breadcrumb[] = !empty($node->field_title_short[0]['value'])
        ? $node->field_title_short[0]['value']
        : $node->title;
      break;
  }

  return $breadcrumb;
}

/**
 * Trim some text.
 */
function debut_common_trim($text, $length, $elipsis = '...') {
  $text = array_filter(explode(' ', strip_tags($text)));
  $output = '';
  while ($part = array_shift($text)) {
    if (drupal_strlen($output . ' ' . $part) <= $length) {
      $output .= ' ' . $part;
    }
    else {
      $output .= $elipsis;
      break;
    }
  }
  return $output;
}

/**
 * Construct BC for pages.
 */
function debut_common_create_page_breadcrumbs() {
  $breadcrumb = array();
  $path = $_GET['q'];

  switch ($path) {

    // BC for documents page.
    case DEBUT_COMMON_PAGE_DOCUMENTS_LIST:
      $breadcrumb[] = l(t('Documents'), DEBUT_COMMON_PAGE_DOCUMENTS_LIST);
      $current_year = isset($_GET['field_publication_date_value']) ? $_GET['field_publication_date_value'] : '';
      if (!empty($current_year)) {
        $current_year = $current_year['value']['year'];
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for press page.
    case DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT:
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $current_year = isset($_GET['field_publication_date_value']) ? $_GET['field_publication_date_value'] : '';
      if (!empty($current_year)) {
        $current_year = $current_year['value']['year'];
        $breadcrumb[] = $current_year;
      }
      break;

    default:
      // Get default breadcrumb.
      $breadcrumb = drupal_get_breadcrumb();
      break;
  }

  return $breadcrumb;
}

/**
 * Process image widget.
 */
function debut_common_image_field_widget_process($element, &$form_state, $form) {
  // Change the title field to a textarea.
  $element['title']['#type'] = 'textarea';

  // Return the altered element.
  return $element;
}

/**
 * Create node edit link.
 */
function debut_common_create_node_edit_link_breadcrumbs($node) {
  $edit_link = '';

  if (node_access('update', $node)) {
    $edit_link = l(t('Edit'), 'node/' . $node->nid . '/edit');
  }

  return $edit_link;
}

/**
 * Get video embed url.
 */
function debut_common_embed_src($url) {

  // Available players base.
  $players = array(
    'youtube' => array(
      'base' => 'http://www.youtube.com/embed/',
      'regexp_parse' => '/^(?:https?\:\/\/(?:www.)?youtu(?|\.be|be\.com)\/(?|watch\?v\=|embed\/|v\/)?)([^&]+)/',
    ),
    'dailymotion' => array(
      'base' => 'http://www.dailymotion.com/embed/video/',
      'regexp_parse' => '/^(?:http\:\/\/(?:www.)?dailymotion.com\/(?:embed\/)?video\/)([^?_]+)/',
    ),
  );

  $src = $players['youtube']['base'] . $url . '?wmode=opaque';

  // Check against available players.
  foreach ($players as $player) {
    $matches = array();
    if (preg_match($player['regexp_parse'], $url, $matches) && count($matches) == 2) {
      $src = $player['base'] . $matches[1] . '?wmode=opaque';
      break;
    }
  }

  return $src;
}

/**
 * Get video image url.
 */
function debut_common_image_src($url) {

  // Available players base.
  $players = array(
    'youtube' => array(
      'base' => 'http://img.youtube.com/vi/',
      'regexp_parse' => '/^(?:https?\:\/\/(?:www.)?youtu(?|\.be|be\.com)\/(?|watch\?v\=|embed\/|v\/)?)([^&]+)/',
    ),
  );

  // Check against available players.
  foreach ($players as $player) {
    $matches = array();
    if (preg_match($player['regexp_parse'], $url, $matches) && count($matches) == 2) {
      $src = $player['base'] . $matches[1] . '/default.jpg';
      break;
    }
  }

  return $src;
}

/**
 * Check if current user if site developer.
 */
function debut_common_developer() {
  // TODO: switch based on the session settings.
  return !empty($_SESSION['debut_common_developer']);
}

/**
 *  Create links for site changes block.
 */
function debut_common_create_changes_list($date) {

  $changes = debut_site_changes_get_stats_date($date);

  if (!empty($changes)) {
    foreach ($changes as $sid => $day) {
      switch ($day['type']) {
        case DEBUT_COMMON_TYPE_PERSONS:
          $section = t('«Prize persons»');
          break;

        case DEBUT_COMMON_TYPE_NEWS:
          $section = t('«News»');
          break;

        case DEBUT_COMMON_TYPE_PRESS:
          $section = t('«Press about prize»');
          break;

        case DEBUT_COMMON_TYPE_DOCUMENTS:
          $section = t('«Documents»');
          break;

        case DEBUT_COMMON_TYPE_JURY:
          $section = t('«Prize Jury»');
          break;

        case DEBUT_COMMON_TYPE_BOOKS:
          $section = t('«Books»');
          break;

        case DEBUT_COMMON_TYPE_PHOTOS:
          $section = t('«Photos»');
          break;

        case DEBUT_COMMON_TYPE_VIDEO:
          $section = t('«Video»');
          break;

        case DEBUT_COMMON_TYPE_IBOOKS:
          $section = t('«iBooks»');
          break;

        case DEBUT_COMMON_TYPE_NOBEL_SPEECH:
          $section = t('«Nobel speech»');
          break;

        default:
          $section = t('Site');
          break;
      }
      $links[] = t('View changes in setion !section', array('!section' => l($section, 'node/' . $day['nid'])));
    }
    $links = theme('item_list', array(
      'items' => $links,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => array(
        'class' => array('pager')
      ),
    ));
  }
  else {
    $links = '<div class="empty_day">' . t('На эту дату нет обновлений.') . '</div>';
  }

  return $links;
}

/**
 * Checking for valid date.
 */
function debut_common_validate_date($date) {
  $a_date = DateTime::createFromFormat('m/d/Y', $date);
  return $a_date && $a_date->format('m/d/Y') == $date;
}

/**
 * Determinates if we are in popup.
 */
function debut_common_in_popup($set = NULL) {
  $path = explode('/', $_GET['q']);
  if ((end($path) == 'popup') || (end($path) == 'quick_view')) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Remove double " from links.
 */
function debut_common_remove_double_quot($string = NULL) {
  $result = str_replace(array('""', '"&quot;', '&quot;"', '&quot;&quot;'), '"', $string);

  return $result;
}
