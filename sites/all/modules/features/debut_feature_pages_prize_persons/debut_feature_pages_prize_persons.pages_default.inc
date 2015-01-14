<?php
/**
 * @file
 * debut_feature_pages_prize_persons.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_prize_persons_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'prize_persons';
  $page->task = 'page';
  $page->admin_title = 'Лица премии';
  $page->admin_description = '';
  $page->path = 'prize_persons';
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
  $handler->name = 'page_prize_persons_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'prize_persons';
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
  $display->uuid = '074de625-11c4-406b-b2d7-f01e4ea86dcc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b9c55011-7446-4cd1-945c-1c2d6356cb8c';
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
    $pane->uuid = 'b9c55011-7446-4cd1-945c-1c2d6356cb8c';
    $display->content['new-b9c55011-7446-4cd1-945c-1c2d6356cb8c'] = $pane;
    $display->panels['content_center'][0] = 'new-b9c55011-7446-4cd1-945c-1c2d6356cb8c';
    $pane = new stdClass();
    $pane->pid = 'new-db65095d-141b-4ac3-b51f-227ff5757202';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
      'page' => 'persons_list',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'db65095d-141b-4ac3-b51f-227ff5757202';
    $display->content['new-db65095d-141b-4ac3-b51f-227ff5757202'] = $pane;
    $display->panels['content_center'][1] = 'new-db65095d-141b-4ac3-b51f-227ff5757202';
    $pane = new stdClass();
    $pane->pid = 'new-fa5b46aa-479c-470c-847a-dfed9286caf9';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_persons_nominees';
    $pane->subtype = 'debut_common_persons_nominees';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'terms' => '3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'fa5b46aa-479c-470c-847a-dfed9286caf9';
    $display->content['new-fa5b46aa-479c-470c-847a-dfed9286caf9'] = $pane;
    $display->panels['content_center'][2] = 'new-fa5b46aa-479c-470c-847a-dfed9286caf9';
    $pane = new stdClass();
    $pane->pid = 'new-a6572d71-3da1-4ab0-877c-3f4a5df21097';
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
    $pane->uuid = 'a6572d71-3da1-4ab0-877c-3f4a5df21097';
    $display->content['new-a6572d71-3da1-4ab0-877c-3f4a5df21097'] = $pane;
    $display->panels['content_left'][0] = 'new-a6572d71-3da1-4ab0-877c-3f4a5df21097';
    $pane = new stdClass();
    $pane->pid = 'new-0d7d19e7-c962-4631-a0af-60cda9c3f53d';
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
    $pane->uuid = '0d7d19e7-c962-4631-a0af-60cda9c3f53d';
    $display->content['new-0d7d19e7-c962-4631-a0af-60cda9c3f53d'] = $pane;
    $display->panels['content_left'][1] = 'new-0d7d19e7-c962-4631-a0af-60cda9c3f53d';
    $pane = new stdClass();
    $pane->pid = 'new-0a14bc2f-dd58-4601-88ce-84fb14e7b7fb';
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
    $pane->uuid = '0a14bc2f-dd58-4601-88ce-84fb14e7b7fb';
    $display->content['new-0a14bc2f-dd58-4601-88ce-84fb14e7b7fb'] = $pane;
    $display->panels['content_left'][2] = 'new-0a14bc2f-dd58-4601-88ce-84fb14e7b7fb';
    $pane = new stdClass();
    $pane->pid = 'new-d7ae5bd8-bfee-4d99-adb0-5dd71c43cc01';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Лица премии',
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
    $pane->uuid = 'd7ae5bd8-bfee-4d99-adb0-5dd71c43cc01';
    $display->content['new-d7ae5bd8-bfee-4d99-adb0-5dd71c43cc01'] = $pane;
    $display->panels['top'][0] = 'new-d7ae5bd8-bfee-4d99-adb0-5dd71c43cc01';
    $pane = new stdClass();
    $pane->pid = 'new-cf903618-4856-4845-b46b-c3bee1f99eba';
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
    $pane->uuid = 'cf903618-4856-4845-b46b-c3bee1f99eba';
    $display->content['new-cf903618-4856-4845-b46b-c3bee1f99eba'] = $pane;
    $display->panels['top'][1] = 'new-cf903618-4856-4845-b46b-c3bee1f99eba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['prize_persons'] = $page;

  return $pages;

}
