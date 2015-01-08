<?php
/**
 * @file
 * debut_feature_pages_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Главная';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
      'top' => NULL,
      'content_pre' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5361d65f-0bba-411a-9fd6-c96a229bf1d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
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
    $pane->uuid = 'f1606c7d-a933-483e-8950-ac6baec77f29';
    $display->content['new-f1606c7d-a933-483e-8950-ac6baec77f29'] = $pane;
    $display->panels['content_left'][0] = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
    $pane = new stdClass();
    $pane->pid = 'new-127be3fc-6a62-4191-87e3-0c503b4c8c84';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Изменения на сайте',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '127be3fc-6a62-4191-87e3-0c503b4c8c84';
    $display->content['new-127be3fc-6a62-4191-87e3-0c503b4c8c84'] = $pane;
    $display->panels['content_left'][1] = 'new-127be3fc-6a62-4191-87e3-0c503b4c8c84';
    $pane = new stdClass();
    $pane->pid = 'new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_contact_us';
    $pane->subtype = 'debut_common_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Связаться с нами',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
    $display->content['new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65'] = $pane;
    $display->panels['content_left'][2] = 'new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
    $pane = new stdClass();
    $pane->pid = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $display->content['new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32'] = $pane;
    $display->panels['content_right'][0] = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $pane = new stdClass();
    $pane->pid = 'new-a3207211-1982-404c-86f1-fa939638f858';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_newsletter_block';
    $pane->subtype = 'debut_common_newsletter_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'newsletters' => '980',
      'override_title' => 1,
      'override_title_text' => 'РАССЫЛКА',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a3207211-1982-404c-86f1-fa939638f858';
    $display->content['new-a3207211-1982-404c-86f1-fa939638f858'] = $pane;
    $display->panels['content_right'][1] = 'new-a3207211-1982-404c-86f1-fa939638f858';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
