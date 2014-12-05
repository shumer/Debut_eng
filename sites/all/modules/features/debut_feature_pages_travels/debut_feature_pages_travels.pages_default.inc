<?php
/**
 * @file
 * debut_feature_pages_travels.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_travels_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'travels';
  $page->task = 'page';
  $page->admin_title = 'Travels';
  $page->admin_description = '';
  $page->path = 'travels';
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
  $handler->name = 'page_travels_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'travels';
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
  $display->uuid = '8555a507-24a2-49a9-8bbb-af1e6f96c31b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a9257a5-30a1-4b17-a4db-9a182f26d7b2';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Поездки',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2a9257a5-30a1-4b17-a4db-9a182f26d7b2';
    $display->content['new-2a9257a5-30a1-4b17-a4db-9a182f26d7b2'] = $pane;
    $display->panels['content_center'][0] = 'new-2a9257a5-30a1-4b17-a4db-9a182f26d7b2';
    $pane = new stdClass();
    $pane->pid = 'new-166004cd-2ce3-4e40-8442-faecb24e9e86';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_travels',
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
    $pane->uuid = '166004cd-2ce3-4e40-8442-faecb24e9e86';
    $display->content['new-166004cd-2ce3-4e40-8442-faecb24e9e86'] = $pane;
    $display->panels['content_center'][1] = 'new-166004cd-2ce3-4e40-8442-faecb24e9e86';
    $pane = new stdClass();
    $pane->pid = 'new-cc237cc7-4e56-4ca3-aa9c-4c929440acd3';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_travels_listing';
    $pane->subtype = 'debut_common_travels_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'cc237cc7-4e56-4ca3-aa9c-4c929440acd3';
    $display->content['new-cc237cc7-4e56-4ca3-aa9c-4c929440acd3'] = $pane;
    $display->panels['content_center'][2] = 'new-cc237cc7-4e56-4ca3-aa9c-4c929440acd3';
    $pane = new stdClass();
    $pane->pid = 'new-0bf68a6c-47c4-499e-a25d-ed938ef8c098';
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
    $pane->uuid = '0bf68a6c-47c4-499e-a25d-ed938ef8c098';
    $display->content['new-0bf68a6c-47c4-499e-a25d-ed938ef8c098'] = $pane;
    $display->panels['content_left'][0] = 'new-0bf68a6c-47c4-499e-a25d-ed938ef8c098';
    $pane = new stdClass();
    $pane->pid = 'new-92d76624-dba9-47bf-a909-dec0bd378fb3';
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
    $pane->uuid = '92d76624-dba9-47bf-a909-dec0bd378fb3';
    $display->content['new-92d76624-dba9-47bf-a909-dec0bd378fb3'] = $pane;
    $display->panels['top'][0] = 'new-92d76624-dba9-47bf-a909-dec0bd378fb3';
    $pane = new stdClass();
    $pane->pid = 'new-0c840ea3-4900-4e9a-9306-acf896340db8';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0c840ea3-4900-4e9a-9306-acf896340db8';
    $display->content['new-0c840ea3-4900-4e9a-9306-acf896340db8'] = $pane;
    $display->panels['top'][1] = 'new-0c840ea3-4900-4e9a-9306-acf896340db8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['travels'] = $page;

  return $pages;

}
