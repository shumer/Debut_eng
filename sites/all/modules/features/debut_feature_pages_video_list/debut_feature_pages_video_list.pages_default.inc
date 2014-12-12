<?php
/**
 * @file
 * debut_feature_pages_video_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_video_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'video_list';
  $page->task = 'page';
  $page->admin_title = 'Video list';
  $page->admin_description = '';
  $page->path = 'video_list';
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
  $handler->name = 'page_video_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'video_list';
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
  $display->uuid = '4e6e8d5c-c4d5-4fcb-ab82-d41dcaff8f9d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4645ded4-e094-49d0-b654-c2c77c601afd';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Видео',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4645ded4-e094-49d0-b654-c2c77c601afd';
    $display->content['new-4645ded4-e094-49d0-b654-c2c77c601afd'] = $pane;
    $display->panels['content_center'][0] = 'new-4645ded4-e094-49d0-b654-c2c77c601afd';
    $pane = new stdClass();
    $pane->pid = 'new-493b3250-6c0d-4103-8330-b0e01bdea9e9';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_video',
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
    $pane->uuid = '493b3250-6c0d-4103-8330-b0e01bdea9e9';
    $display->content['new-493b3250-6c0d-4103-8330-b0e01bdea9e9'] = $pane;
    $display->panels['content_center'][1] = 'new-493b3250-6c0d-4103-8330-b0e01bdea9e9';
    $pane = new stdClass();
    $pane->pid = 'new-0030303a-fcff-48d3-9741-38f6aba23157';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_video_listing';
    $pane->subtype = 'debut_common_video_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0030303a-fcff-48d3-9741-38f6aba23157';
    $display->content['new-0030303a-fcff-48d3-9741-38f6aba23157'] = $pane;
    $display->panels['content_center'][2] = 'new-0030303a-fcff-48d3-9741-38f6aba23157';
    $pane = new stdClass();
    $pane->pid = 'new-ffd954ee-7a54-4be6-b98d-4b614c3b3fec';
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
    $pane->uuid = 'ffd954ee-7a54-4be6-b98d-4b614c3b3fec';
    $display->content['new-ffd954ee-7a54-4be6-b98d-4b614c3b3fec'] = $pane;
    $display->panels['content_left'][0] = 'new-ffd954ee-7a54-4be6-b98d-4b614c3b3fec';
    $pane = new stdClass();
    $pane->pid = 'new-6f70586b-63f4-4ad7-905f-d1451a1be2c0';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '6f70586b-63f4-4ad7-905f-d1451a1be2c0';
    $display->content['new-6f70586b-63f4-4ad7-905f-d1451a1be2c0'] = $pane;
    $display->panels['top'][0] = 'new-6f70586b-63f4-4ad7-905f-d1451a1be2c0';
    $pane = new stdClass();
    $pane->pid = 'new-b867941b-2030-4d92-a470-6601b18ee7ab';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Видео',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b867941b-2030-4d92-a470-6601b18ee7ab';
    $display->content['new-b867941b-2030-4d92-a470-6601b18ee7ab'] = $pane;
    $display->panels['top'][1] = 'new-b867941b-2030-4d92-a470-6601b18ee7ab';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['video_list'] = $page;

  return $pages;

}
