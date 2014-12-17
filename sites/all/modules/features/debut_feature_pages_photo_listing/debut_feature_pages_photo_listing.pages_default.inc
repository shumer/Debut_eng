<?php
/**
 * @file
 * debut_feature_pages_photo_listing.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_photo_listing_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'photo_listing';
  $page->task = 'page';
  $page->admin_title = 'Фоторепортажи';
  $page->admin_description = '';
  $page->path = 'photo_listing';
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
  $handler->name = 'page_photo_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'photo_listing';
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
  $display->uuid = '20b01d75-d479-4d1f-b8a0-7599a06d2a00';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b0c7534c-b1da-4925-8d8d-3a1416f15888';
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
    $pane->uuid = 'b0c7534c-b1da-4925-8d8d-3a1416f15888';
    $display->content['new-b0c7534c-b1da-4925-8d8d-3a1416f15888'] = $pane;
    $display->panels['content_left'][0] = 'new-b0c7534c-b1da-4925-8d8d-3a1416f15888';
    $pane = new stdClass();
    $pane->pid = 'new-665b861e-baa3-4afd-8a53-df023674ea5e';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'ИЗМЕНЕНИЯ НА САЙТЕ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '665b861e-baa3-4afd-8a53-df023674ea5e';
    $display->content['new-665b861e-baa3-4afd-8a53-df023674ea5e'] = $pane;
    $display->panels['content_left'][1] = 'new-665b861e-baa3-4afd-8a53-df023674ea5e';
    $pane = new stdClass();
    $pane->pid = 'new-a3df1d7a-df53-4823-9897-5285e3836469';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_contact_us';
    $pane->subtype = 'debut_common_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'СВЯЗАТЬСЯ С НАМИ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a3df1d7a-df53-4823-9897-5285e3836469';
    $display->content['new-a3df1d7a-df53-4823-9897-5285e3836469'] = $pane;
    $display->panels['content_left'][2] = 'new-a3df1d7a-df53-4823-9897-5285e3836469';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['photo_listing'] = $page;

  return $pages;

}
