<?php
/**
 * @file
 * debut_feature_pages_page_403.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_page_403_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_403';
  $page->task = 'page';
  $page->admin_title = 'Страница 403 (Доступ запрещен)';
  $page->admin_description = '';
  $page->path = 'page_403';
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
  $handler->name = 'page_page_403_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_403';
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
  $display->layout = 'debut_content_2col_toped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_pre' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '31979644-91aa-42e1-8663-2da701549c3d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f44299d4-e89e-450f-b219-98e4c7a7fd3d';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_page_404';
    $pane->subtype = 'debut_common_page_404';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text_block' => '<h1>Страница 403</h1>
<p>Вы попали на страницу к которой у Вас нет доступа. Войдите на сайт или обратитесь к администратору</p>',
      'override_title' => 1,
      'override_title_text' => 'У вас нет доступа к этой странице',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f44299d4-e89e-450f-b219-98e4c7a7fd3d';
    $display->content['new-f44299d4-e89e-450f-b219-98e4c7a7fd3d'] = $pane;
    $display->panels['content_center'][0] = 'new-f44299d4-e89e-450f-b219-98e4c7a7fd3d';
    $pane = new stdClass();
    $pane->pid = 'new-a2bc9935-4959-40d5-8260-f5537d5420c0';
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
    $pane->uuid = 'a2bc9935-4959-40d5-8260-f5537d5420c0';
    $display->content['new-a2bc9935-4959-40d5-8260-f5537d5420c0'] = $pane;
    $display->panels['content_left'][0] = 'new-a2bc9935-4959-40d5-8260-f5537d5420c0';
    $pane = new stdClass();
    $pane->pid = 'new-6d0ffabc-c875-42d4-b9da-8149230aa41f';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '403',
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
    $pane->uuid = '6d0ffabc-c875-42d4-b9da-8149230aa41f';
    $display->content['new-6d0ffabc-c875-42d4-b9da-8149230aa41f'] = $pane;
    $display->panels['top'][0] = 'new-6d0ffabc-c875-42d4-b9da-8149230aa41f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6d0ffabc-c875-42d4-b9da-8149230aa41f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_403'] = $page;

  return $pages;

}
