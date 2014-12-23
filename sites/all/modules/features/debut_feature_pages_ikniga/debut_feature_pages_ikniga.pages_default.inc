<?php
/**
 * @file
 * debut_feature_pages_ikniga.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_ikniga_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ikniga';
  $page->task = 'page';
  $page->admin_title = 'Проект iKniga';
  $page->admin_description = '';
  $page->path = 'ikniga';
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
  $handler->name = 'page_ikniga_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ikniga';
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
  $display->uuid = '08b3c02f-b9bf-4b20-9c34-ab976f74b7dd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-46e37b58-6735-4690-baa3-d38302de297d';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Проект <i>ikniga</i>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '46e37b58-6735-4690-baa3-d38302de297d';
    $display->content['new-46e37b58-6735-4690-baa3-d38302de297d'] = $pane;
    $display->panels['content_center'][0] = 'new-46e37b58-6735-4690-baa3-d38302de297d';
    $pane = new stdClass();
    $pane->pid = 'new-89a9ebf2-2015-4ff4-b555-8b490f9607bc';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_ibooks_listing';
    $pane->subtype = 'debut_common_ibooks_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '89a9ebf2-2015-4ff4-b555-8b490f9607bc';
    $display->content['new-89a9ebf2-2015-4ff4-b555-8b490f9607bc'] = $pane;
    $display->panels['content_center'][1] = 'new-89a9ebf2-2015-4ff4-b555-8b490f9607bc';
    $pane = new stdClass();
    $pane->pid = 'new-1bdd653d-7e4b-4b08-bc00-73d662a94602';
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
    $pane->uuid = '1bdd653d-7e4b-4b08-bc00-73d662a94602';
    $display->content['new-1bdd653d-7e4b-4b08-bc00-73d662a94602'] = $pane;
    $display->panels['content_left'][0] = 'new-1bdd653d-7e4b-4b08-bc00-73d662a94602';
    $pane = new stdClass();
    $pane->pid = 'new-91b8d018-e272-4d52-8bb6-a6c23bba0d1d';
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
    $pane->uuid = '91b8d018-e272-4d52-8bb6-a6c23bba0d1d';
    $display->content['new-91b8d018-e272-4d52-8bb6-a6c23bba0d1d'] = $pane;
    $display->panels['content_left'][1] = 'new-91b8d018-e272-4d52-8bb6-a6c23bba0d1d';
    $pane = new stdClass();
    $pane->pid = 'new-d8fe1612-6a73-450f-86b6-fbbe8f7f020a';
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
    $pane->uuid = 'd8fe1612-6a73-450f-86b6-fbbe8f7f020a';
    $display->content['new-d8fe1612-6a73-450f-86b6-fbbe8f7f020a'] = $pane;
    $display->panels['content_left'][2] = 'new-d8fe1612-6a73-450f-86b6-fbbe8f7f020a';
    $pane = new stdClass();
    $pane->pid = 'new-51b62952-baa1-4897-b8f1-c9f23ab1c229';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Проект iКнига',
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
    $pane->uuid = '51b62952-baa1-4897-b8f1-c9f23ab1c229';
    $display->content['new-51b62952-baa1-4897-b8f1-c9f23ab1c229'] = $pane;
    $display->panels['top'][0] = 'new-51b62952-baa1-4897-b8f1-c9f23ab1c229';
    $pane = new stdClass();
    $pane->pid = 'new-8b8289bd-6707-4fd9-be07-d7848cbdd359';
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
    $pane->uuid = '8b8289bd-6707-4fd9-be07-d7848cbdd359';
    $display->content['new-8b8289bd-6707-4fd9-be07-d7848cbdd359'] = $pane;
    $display->panels['top'][1] = 'new-8b8289bd-6707-4fd9-be07-d7848cbdd359';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ikniga'] = $page;

  return $pages;

}
