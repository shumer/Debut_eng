<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Home page news'),
  'description' => t('Debut Common: Home page news'),
  'content_types' => 'debut_common_home_page_news',
  'single' => TRUE,
  'render callback' => 'debut_common_home_page_news_content_type_render',
  'edit form' => 'debut_common_home_page_news_content_type_edit_form',
  'admin title' => 'debut_common_home_page_news_content_type_admin_title',
  'hook theme' => 'debut_common_home_page_news_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => FALSE,
);

/**
 * Render callback.
 */
function debut_common_home_page_news_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();

  $_html['news'] = views_embed_view(DEBUT_COMMON_VIEW_NEWS_HOME_PAGE);

  $_html['news_link'] = l(t('Архив новостей'), 'news_list');

  $data = array (
    '_html' => $_html,
  );

  $block->content = theme('debut_common_home_page_news', $data);

  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_home_page_news_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_home_page_news_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_home_page_news_content_type_admin_title($subtype, $conf, $context) {
  return t('Home page news');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_home_page_news_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_home_page_news'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-home-page-news',
    'variables' => array('params' => array()),
  );
}
