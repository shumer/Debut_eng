<?php
/**
 * @file
 * debut_feature_pages_persons_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_persons_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'persons_list';
  $page->task = 'page';
  $page->admin_title = 'Лица премии (алфавит)';
  $page->admin_description = '';
  $page->path = 'persons_list/%letter';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'letter' => array(
      'id' => 1,
      'identifier' => 'Строка',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_persons_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'persons_list';
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
  $display->uuid = '4734bfe4-dc9f-4870-ad4a-63cfdeeeb1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Лица премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5de18652-48df-43d8-92d3-d4475ce74273';
    $display->content['new-5de18652-48df-43d8-92d3-d4475ce74273'] = $pane;
    $display->panels['content_center'][0] = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane = new stdClass();
    $pane->pid = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $display->content['new-c7dd38d9-d0c7-4833-ab66-2c26669115fe'] = $pane;
    $display->panels['content_center'][1] = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane = new stdClass();
    $pane->pid = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_persons_list';
    $pane->subtype = 'debut_common_persons_list';
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
    $pane->uuid = '2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $display->content['new-2bbd93a8-288b-48ca-8dff-146d0f610f09'] = $pane;
    $display->panels['content_center'][2] = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane = new stdClass();
    $pane->pid = 'new-ebc73712-f85d-4713-88ed-2f03625974f8';
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
    $pane->uuid = 'ebc73712-f85d-4713-88ed-2f03625974f8';
    $display->content['new-ebc73712-f85d-4713-88ed-2f03625974f8'] = $pane;
    $display->panels['content_left'][0] = 'new-ebc73712-f85d-4713-88ed-2f03625974f8';
    $pane = new stdClass();
    $pane->pid = 'new-e6d64dbf-9fef-46a1-b2e1-771de4f91751';
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
    $pane->uuid = 'e6d64dbf-9fef-46a1-b2e1-771de4f91751';
    $display->content['new-e6d64dbf-9fef-46a1-b2e1-771de4f91751'] = $pane;
    $display->panels['content_left'][1] = 'new-e6d64dbf-9fef-46a1-b2e1-771de4f91751';
    $pane = new stdClass();
    $pane->pid = 'new-b1c085a5-3708-4c02-938c-68d028cd10c1';
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
    $pane->uuid = 'b1c085a5-3708-4c02-938c-68d028cd10c1';
    $display->content['new-b1c085a5-3708-4c02-938c-68d028cd10c1'] = $pane;
    $display->panels['content_left'][2] = 'new-b1c085a5-3708-4c02-938c-68d028cd10c1';
    $pane = new stdClass();
    $pane->pid = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Лица премии|prize_persons|1
@arg1',
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
    $pane->uuid = 'a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $display->content['new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6'] = $pane;
    $display->panels['top'][0] = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $pane = new stdClass();
    $pane->pid = 'new-0556a126-e5ce-4a68-b557-9508ab5c151b';
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
    $pane->uuid = '0556a126-e5ce-4a68-b557-9508ab5c151b';
    $display->content['new-0556a126-e5ce-4a68-b557-9508ab5c151b'] = $pane;
    $display->panels['top'][1] = 'new-0556a126-e5ce-4a68-b557-9508ab5c151b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['persons_list'] = $page;

  return $pages;

}
