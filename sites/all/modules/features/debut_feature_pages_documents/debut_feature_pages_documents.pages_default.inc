<?php
/**
 * @file
 * debut_feature_pages_documents.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_documents_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'documents';
  $page->task = 'page';
  $page->admin_title = 'Documents';
  $page->admin_description = '';
  $page->path = 'documents_list';
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
  $handler->name = 'page_documents_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'documents';
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
  $display->uuid = '0a9c90e8-54d3-48d9-aa9f-2ba4a38513c7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-94c95136-5708-4561-9631-dd801ced1375';
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
    $pane->uuid = '94c95136-5708-4561-9631-dd801ced1375';
    $display->content['new-94c95136-5708-4561-9631-dd801ced1375'] = $pane;
    $display->panels['content_left'][0] = 'new-94c95136-5708-4561-9631-dd801ced1375';
    $pane = new stdClass();
    $pane->pid = 'new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Документы',
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
    $pane->uuid = '80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $display->content['new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7'] = $pane;
    $display->panels['top'][0] = 'new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $pane = new stdClass();
    $pane->pid = 'new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
    $display->content['new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6'] = $pane;
    $display->panels['top'][1] = 'new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['documents'] = $page;

  return $pages;

}
