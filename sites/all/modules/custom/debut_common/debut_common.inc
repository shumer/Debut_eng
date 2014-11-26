<?php
/**
 * @file
 * Module logic and API.
 */

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

  if (drupal_strlen($node->title) > 80) {
    $node->title = debut_common_trim($node->title, 75);
  }
  switch ($node->type) {

    // Make breadcrumb for Debut person.
    case DEBUT_COMMON_TYPE_PERSONS:
      $breadcrumb[] = l(t('Prize persons'), DEBUT_COMMON_PAGE_PRIZE_PERSONS);
      $letter = $node->field_person_surname[0]['value'];
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_PERSONS . '/' . $letter);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for Debut jury.
    case DEBUT_COMMON_TYPE_JURY:
      $breadcrumb[] = l(t('Prize jury'), DEBUT_COMMON_PAGE_PRIZE_JURY);
      $letter = $node->field_person_surname[0]['value'];
      $letter = drupal_substr($letter, 0, 1);
      $breadcrumb[] = l($letter, DEBUT_COMMON_PAGE_ALPHABET_JURY. '/' . $letter);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for documents node.
    case DEBUT_COMMON_TYPE_DOCUMENTS:
      $breadcrumb[] = l(t('Documents'), DEBUT_COMMON_PAGE_DOCUMENTS_LIST);
      $date = strtotime($node->field_publication_date[0]['value']);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_DOCUMENTS_LIST, array('query' => 'field_publication_date_value[value][year]=' . $year));
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for press about prize node.
    case DEBUT_COMMON_TYPE_PRESS:
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $date = strtotime($node->field_publication_date[0]['value']);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT, array('query' => 'field_publication_date_value[value][year]=' . $year));
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for news node.
    case DEBUT_COMMON_TYPE_NEWS:
      $breadcrumb[] = l(t('News'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $publication_date = site_common_field_get_item('node', $node, 'field_publication_date', 0, 'value');
      $date = strtotime($publication_date);
      $year = date('Y', $date);
      $breadcrumb[] = l($year, DEBUT_COMMON_PAGE_NEWS_LIST, array('query' => array('field_publication_date[value][year]=' . $year)));
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for master class section node.
    case DEBUT_COMMON_TYPE_MASTER_CLASS_SECTION:
      $breadcrumb[] = l(t('Letopis Debuta'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_NEWS_LIST);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for master class text node.
    case DEBUT_COMMON_TYPE_MASTER_CLASS_TEXT:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = site_common_views_get_view_result(DEBUT_COMMON_VIEW_MASTER_CLASS, 'master_text', $node->nid);
      $master_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($master_node->title, 'node/' . $master_node->nid);
      $breadcrumb[] = $node->title;
      break;

    // Make breadcrumb for interview node.
    case DEBUT_COMMON_TYPE_INTERVIEW:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Master classes'), DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST);
      $view = site_common_views_get_view_result(DEBUT_COMMON_VIEW_MASTER_CLASS, 'interview', $node->nid);
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
      break;

    // Make breadcrumb for travel description node.
    case DEBUT_COMMON_TYPE_TRAVEL_DESCRIPTION:
      $breadcrumb[] = l(t('Letopis Debuta'), '');
      $breadcrumb[] = l(t('Travels'), DEBUT_COMMON_PAGE_TRAVELS_LIST);
      $view = site_common_views_get_view_result(DEBUT_COMMON_VIEW_TRAVELS_LIST, $node->nid);
      $travel_node = cache_common_load_node($view[0]->nid);
      $breadcrumb[] = l($travel_node->title, 'node/' . $travel_node->nid);
      $breadcrumb[] = $node->title;
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
      $current_year = $_GET['field_publication_date_value'];
      if (!empty($current_year)) {
        $current_year = $current_year['value']['year'];
        $breadcrumb[] = $current_year;
      }
      break;

    // Bc for press page.
    case DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT:
      $breadcrumb[] = l(t('Press about prize'), DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT);
      $current_year = $_GET['field_publication_date_value'];
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
