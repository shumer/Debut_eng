<?php
/**
 * @file
 * debut_feature_pages_page_404.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_page_404_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_404';
  $page->task = 'page';
  $page->admin_title = 'Страница 404 (Контент не найден)';
  $page->admin_description = '';
  $page->path = 'page_404';
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
  $handler->name = 'page_page_404_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_404';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Desktop',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'theme',
          'settings' => array(
            'theme' => 'debut',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'qtools_varnish_page_cache_form' => array(
      'ttl' => '604800',
      'save_to_features' => 1,
    ),
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
  $display->uuid = '43f93afb-1ad7-4fcc-89a3-41c795d3f401';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_page_404';
    $pane->subtype = 'debut_common_page_404';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text_block' => '<h1>Страница 404</h1>
<p>Страница, которую Вы искали, не существует. Проверьте правильность введенного адреса.</p>',
      'override_title' => 1,
      'override_title_text' => 'Запрашиваемая страница не найдена',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $display->content['new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c'] = $pane;
    $display->panels['content_center'][0] = 'new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $pane = new stdClass();
    $pane->pid = 'new-a6b5942f-225a-4d73-b408-2b64a960be11';
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
    $pane->uuid = 'a6b5942f-225a-4d73-b408-2b64a960be11';
    $display->content['new-a6b5942f-225a-4d73-b408-2b64a960be11'] = $pane;
    $display->panels['content_left'][0] = 'new-a6b5942f-225a-4d73-b408-2b64a960be11';
    $pane = new stdClass();
    $pane->pid = 'new-527590d2-d4f8-4597-af95-fbb206b421f0';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '404',
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
    $pane->uuid = '527590d2-d4f8-4597-af95-fbb206b421f0';
    $display->content['new-527590d2-d4f8-4597-af95-fbb206b421f0'] = $pane;
    $display->panels['top'][0] = 'new-527590d2-d4f8-4597-af95-fbb206b421f0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_page_404_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'page_404';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Mobile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'theme',
          'settings' => array(
            'theme' => 'debut_mobile',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'qtools_varnish_page_cache_form' => array(
      'ttl' => '604800',
      'save_to_features' => 1,
    ),
  );
  $display = new panels_display();
  $display->layout = 'site_content_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content_pre' => NULL,
      'content_left' => NULL,
      'content_center' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '43f93afb-1ad7-4fcc-89a3-41c795d3f401';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-527590d2-d4f8-4597-af95-fbb206b421f0';
    $pane->panel = 'content';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '404',
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
    $pane->uuid = '527590d2-d4f8-4597-af95-fbb206b421f0';
    $display->content['new-527590d2-d4f8-4597-af95-fbb206b421f0'] = $pane;
    $display->panels['content'][0] = 'new-527590d2-d4f8-4597-af95-fbb206b421f0';
    $pane = new stdClass();
    $pane->pid = 'new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $pane->panel = 'content';
    $pane->type = 'debut_common_page_404';
    $pane->subtype = 'debut_common_page_404';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text_block' => '<h1>Страница 404</h1>
<p>Страница, которую Вы искали, не существует. Проверьте правильность введенного адреса.</p>',
      'override_title' => 1,
      'override_title_text' => 'Запрашиваемая страница не найдена',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $display->content['new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c'] = $pane;
    $display->panels['content'][1] = 'new-8e13b0cf-f93a-4880-90d3-dc015cb1d93c';
    $pane = new stdClass();
    $pane->pid = 'new-67d09502-8b98-4ade-9f1c-358fb8b911a8';
    $pane->panel = 'content';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
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
    $pane->uuid = '67d09502-8b98-4ade-9f1c-358fb8b911a8';
    $display->content['new-67d09502-8b98-4ade-9f1c-358fb8b911a8'] = $pane;
    $display->panels['content'][2] = 'new-67d09502-8b98-4ade-9f1c-358fb8b911a8';
    $pane = new stdClass();
    $pane->pid = 'new-e2a31b6a-e1db-4c94-b426-f57819c4be30';
    $pane->panel = 'content';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e2a31b6a-e1db-4c94-b426-f57819c4be30';
    $display->content['new-e2a31b6a-e1db-4c94-b426-f57819c4be30'] = $pane;
    $display->panels['content'][3] = 'new-e2a31b6a-e1db-4c94-b426-f57819c4be30';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_404'] = $page;

  return $pages;

}
