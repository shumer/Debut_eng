<?php
/**
 * @file
 * debut_feature_pages_news_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_news_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_list';
  $page->task = 'page';
  $page->admin_title = 'News list';
  $page->admin_description = '';
  $page->path = 'news_list';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news_list';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'debut_content_3col_toped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'content_pre' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '894c4b98-8936-4a33-961b-69de48d888ef';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-658fa60b-19db-41d0-8353-c8e129d33f65';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Новости',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '658fa60b-19db-41d0-8353-c8e129d33f65';
    $display->content['new-658fa60b-19db-41d0-8353-c8e129d33f65'] = $pane;
    $display->panels['content_center'][0] = 'new-658fa60b-19db-41d0-8353-c8e129d33f65';
    $pane = new stdClass();
    $pane->pid = 'new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_news',
      'pre_text' => '',
      'post_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $display->content['new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9'] = $pane;
    $display->panels['content_center'][1] = 'new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $pane = new stdClass();
    $pane->pid = 'new-5b5fd5ee-82d7-498b-ab4f-9296f2de4200';
    $pane->panel = 'content_center';
    $pane->type = 'views';
    $pane->subtype = 'debut_view_list_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5b5fd5ee-82d7-498b-ab4f-9296f2de4200';
    $display->content['new-5b5fd5ee-82d7-498b-ab4f-9296f2de4200'] = $pane;
    $display->panels['content_center'][2] = 'new-5b5fd5ee-82d7-498b-ab4f-9296f2de4200';
    $pane = new stdClass();
    $pane->pid = 'new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'empty',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
    $display->content['new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28'] = $pane;
    $display->panels['content_left'][0] = 'new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
    $pane = new stdClass();
    $pane->pid = 'new-1b53c90c-020e-4bb7-9544-007091831100';
    $pane->panel = 'top';
    $pane->type = 'debut-common-breadcrumb';
    $pane->subtype = 'debut-common-breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'empty',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1b53c90c-020e-4bb7-9544-007091831100';
    $display->content['new-1b53c90c-020e-4bb7-9544-007091831100'] = $pane;
    $display->panels['top'][0] = 'new-1b53c90c-020e-4bb7-9544-007091831100';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_list'] = $page;

  return $pages;

}
