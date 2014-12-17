<?php
/**
 * @file
 * debut_feature_pages_prize_jury.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_prize_jury_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'prize_jury';
  $page->task = 'page';
  $page->admin_title = 'Жюри премии';
  $page->admin_description = '';
  $page->path = 'prize_jury';
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
  $handler->name = 'page_prize_jury_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'prize_jury';
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
  $display->uuid = 'b3aafc48-cc8b-406e-8838-a36bfa053bcd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f18abd22-5a21-4581-b9df-86221bc61c11';
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
    $pane->uuid = 'f18abd22-5a21-4581-b9df-86221bc61c11';
    $display->content['new-f18abd22-5a21-4581-b9df-86221bc61c11'] = $pane;
    $display->panels['content_left'][0] = 'new-f18abd22-5a21-4581-b9df-86221bc61c11';
    $pane = new stdClass();
    $pane->pid = 'new-4829f5ba-623b-4b08-a1df-e96e4a69cabb';
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
    $pane->uuid = '4829f5ba-623b-4b08-a1df-e96e4a69cabb';
    $display->content['new-4829f5ba-623b-4b08-a1df-e96e4a69cabb'] = $pane;
    $display->panels['content_left'][1] = 'new-4829f5ba-623b-4b08-a1df-e96e4a69cabb';
    $pane = new stdClass();
    $pane->pid = 'new-4204ea79-8c7b-4582-af7c-eac7b27151ee';
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
    $pane->uuid = '4204ea79-8c7b-4582-af7c-eac7b27151ee';
    $display->content['new-4204ea79-8c7b-4582-af7c-eac7b27151ee'] = $pane;
    $display->panels['content_left'][2] = 'new-4204ea79-8c7b-4582-af7c-eac7b27151ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['prize_jury'] = $page;

  return $pages;

}
