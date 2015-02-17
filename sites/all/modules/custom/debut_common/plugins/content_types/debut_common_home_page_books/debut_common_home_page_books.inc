<?php
/**
 * @file
 *
 * CCT plugin file.
 */
$plugin = array(
  'title' => t('Debut Common: Home page books'),
  'description' => t('Debut Common: Home page books'),
  'content_types' => 'debut_common_home_page_books',
  'single' => TRUE,
  'render callback' => 'debut_common_home_page_books_content_type_render',
  'edit form' => 'debut_common_home_page_books_content_type_edit_form',
  'admin title' => 'debut_common_home_page_books_content_type_admin_title',
  'hook theme' => 'debut_common_home_page_books_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_home_page_books_content_type_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = NULL;
  $_html = array();

  $_html['books'] = views_embed_view(DEBUT_COMMON_VIEW_BOOKS_HOME_PAGE);

  $_html['books_link'] = l('<span class="links"></span>', DEBUT_COMMON_PAGE_BOOKS_LIST, array('html' => TRUE));

  $_html['books_link_mobile'] = l(t('Books'), DEBUT_COMMON_PAGE_BOOKS_LIST, array('html' => TRUE));
  $data = array (
    '_html' => $_html,
  );

  $block->content = theme('debut_common_home_page_books', $data);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_home_page_books_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_home_page_books_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_home_page_books_content_type_admin_title($subtype, $conf, $context) {
  return t('Home page books');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_home_page_books_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_home_page_books'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-home-page-books',
    'variables' => array('params' => array()),
  );
}
