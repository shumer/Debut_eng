<?php
/**
 * @file
 * debut_feature_pages_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 'search/!text';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'text' => array(
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
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
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
  $display->uuid = '09f3605c-0c83-4256-94a9-c0e9f5ba3e0d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $pane->panel = 'content_center';
    $pane->type = 'views';
    $pane->subtype = 'debut_view_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'argument_string_1.raw',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $display->content['new-9b8cc17b-6c53-4df3-a808-1d8a1673e439'] = $pane;
    $display->panels['content_center'][0] = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $pane = new stdClass();
    $pane->pid = 'new-d5c0fdd0-f703-4a1f-b1a4-b4ea43182239';
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
    $pane->uuid = 'd5c0fdd0-f703-4a1f-b1a4-b4ea43182239';
    $display->content['new-d5c0fdd0-f703-4a1f-b1a4-b4ea43182239'] = $pane;
    $display->panels['content_left'][0] = 'new-d5c0fdd0-f703-4a1f-b1a4-b4ea43182239';
    $pane = new stdClass();
    $pane->pid = 'new-44adce78-a0f4-4a2c-97fe-c326a1ab3e98';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '44adce78-a0f4-4a2c-97fe-c326a1ab3e98';
    $display->content['new-44adce78-a0f4-4a2c-97fe-c326a1ab3e98'] = $pane;
    $display->panels['content_left'][1] = 'new-44adce78-a0f4-4a2c-97fe-c326a1ab3e98';
    $pane = new stdClass();
    $pane->pid = 'new-8acec6e2-9f5d-4632-a606-cec2d095706a';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_contact_us';
    $pane->subtype = 'debut_common_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8acec6e2-9f5d-4632-a606-cec2d095706a';
    $display->content['new-8acec6e2-9f5d-4632-a606-cec2d095706a'] = $pane;
    $display->panels['content_left'][2] = 'new-8acec6e2-9f5d-4632-a606-cec2d095706a';
    $pane = new stdClass();
    $pane->pid = 'new-2644f409-ec11-4fe8-b219-58c06463e6f8';
    $pane->panel = 'content_right';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2644f409-ec11-4fe8-b219-58c06463e6f8';
    $display->content['new-2644f409-ec11-4fe8-b219-58c06463e6f8'] = $pane;
    $display->panels['content_right'][0] = 'new-2644f409-ec11-4fe8-b219-58c06463e6f8';
    $pane = new stdClass();
    $pane->pid = 'new-5817b262-a507-471a-8ac3-4a6684e9ec7f';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5817b262-a507-471a-8ac3-4a6684e9ec7f';
    $display->content['new-5817b262-a507-471a-8ac3-4a6684e9ec7f'] = $pane;
    $display->panels['content_right'][1] = 'new-5817b262-a507-471a-8ac3-4a6684e9ec7f';
    $pane = new stdClass();
    $pane->pid = 'new-740d55ed-d07f-4225-9f4d-726214f3d263';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_newsletter_block';
    $pane->subtype = 'debut_common_newsletter_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'newsletters' => '54',
      'override_title' => 1,
      'override_title_text' => 'РАССЫЛКА',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '740d55ed-d07f-4225-9f4d-726214f3d263';
    $display->content['new-740d55ed-d07f-4225-9f4d-726214f3d263'] = $pane;
    $display->panels['content_right'][2] = 'new-740d55ed-d07f-4225-9f4d-726214f3d263';
    $pane = new stdClass();
    $pane->pid = 'new-1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Поиск
',
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
    $pane->uuid = '1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $display->content['new-1a7ce938-fb2c-440f-8068-1f8780c9e22b'] = $pane;
    $display->panels['top'][0] = 'new-1a7ce938-fb2c-440f-8068-1f8780c9e22b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d5c0fdd0-f703-4a1f-b1a4-b4ea43182239';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'search';
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '09f3605c-0c83-4256-94a9-c0e9f5ba3e0d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $pane->panel = 'content';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Поиск
@arg1
',
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
    $pane->uuid = '1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $display->content['new-1a7ce938-fb2c-440f-8068-1f8780c9e22b'] = $pane;
    $display->panels['content'][0] = 'new-1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $pane = new stdClass();
    $pane->pid = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $pane->panel = 'content';
    $pane->type = 'views';
    $pane->subtype = 'debut_view_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => 'argument_string_1.raw',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $display->content['new-9b8cc17b-6c53-4df3-a808-1d8a1673e439'] = $pane;
    $display->panels['content'][1] = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $pane = new stdClass();
    $pane->pid = 'new-2644f409-ec11-4fe8-b219-58c06463e6f8';
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
    $pane->uuid = '2644f409-ec11-4fe8-b219-58c06463e6f8';
    $display->content['new-2644f409-ec11-4fe8-b219-58c06463e6f8'] = $pane;
    $display->panels['content'][2] = 'new-2644f409-ec11-4fe8-b219-58c06463e6f8';
    $pane = new stdClass();
    $pane->pid = 'new-5817b262-a507-471a-8ac3-4a6684e9ec7f';
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
    $pane->uuid = '5817b262-a507-471a-8ac3-4a6684e9ec7f';
    $display->content['new-5817b262-a507-471a-8ac3-4a6684e9ec7f'] = $pane;
    $display->panels['content'][3] = 'new-5817b262-a507-471a-8ac3-4a6684e9ec7f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
