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
    $pane->pid = 'new-02c5be93-b46b-4037-b48b-1ef7ee634a26';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_search_header';
    $pane->subtype = 'debut_common_search_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '02c5be93-b46b-4037-b48b-1ef7ee634a26';
    $display->content['new-02c5be93-b46b-4037-b48b-1ef7ee634a26'] = $pane;
    $display->panels['content_center'][0] = 'new-02c5be93-b46b-4037-b48b-1ef7ee634a26';
    $pane = new stdClass();
    $pane->pid = 'new-df1f658e-f3ff-4700-ac38-54db3201660c';
    $pane->panel = 'content_center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-FiSw1bzCb7fG7gAj2GF4YyEYbgdwerZa';
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
    $pane->uuid = 'df1f658e-f3ff-4700-ac38-54db3201660c';
    $display->content['new-df1f658e-f3ff-4700-ac38-54db3201660c'] = $pane;
    $display->panels['content_center'][1] = 'new-df1f658e-f3ff-4700-ac38-54db3201660c';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $display->content['new-9b8cc17b-6c53-4df3-a808-1d8a1673e439'] = $pane;
    $display->panels['content_center'][2] = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
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
    $pane->pid = 'new-81ab48e7-1461-4c08-91b2-f7e0d3e62109';
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
    $pane->uuid = '81ab48e7-1461-4c08-91b2-f7e0d3e62109';
    $display->content['new-81ab48e7-1461-4c08-91b2-f7e0d3e62109'] = $pane;
    $display->panels['content_left'][1] = 'new-81ab48e7-1461-4c08-91b2-f7e0d3e62109';
    $pane = new stdClass();
    $pane->pid = 'new-49fe66a2-4df8-47cc-adb6-ca1c7b185d2f';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_president_info';
    $pane->subtype = 'debut_common_president_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'info_text' => '<h3>Andrei Skoch</h3><br />
President of the Pokolenie Foundation, founder of the independent literary prize Debut            <br>    <br> 
By training Andrei Skoch is a teacher and psychologist with a Ph.D. in Education. He started writing poetry during his army service. He has seven children. Originally he founded his Pokolenie Foundation to help invalid children. There was a time when he needed such help for his own children and he received it from friends. Since then charity has become an important part of his life...<br>',
      'more_url' => 'http://fondskocha.ru/',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '49fe66a2-4df8-47cc-adb6-ca1c7b185d2f';
    $display->content['new-49fe66a2-4df8-47cc-adb6-ca1c7b185d2f'] = $pane;
    $display->panels['content_right'][0] = 'new-49fe66a2-4df8-47cc-adb6-ca1c7b185d2f';
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
    $pane->pid = 'new-1a7ce938-fb2c-440f-8068-1f8780c9e22b';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Search
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
      'custombc' => 'Search
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
    $pane->pid = 'new-736907f6-54ba-4fab-8354-5270a31ec1b8';
    $pane->panel = 'content';
    $pane->type = 'debut_common_search_header';
    $pane->subtype = 'debut_common_search_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '736907f6-54ba-4fab-8354-5270a31ec1b8';
    $display->content['new-736907f6-54ba-4fab-8354-5270a31ec1b8'] = $pane;
    $display->panels['content'][1] = 'new-736907f6-54ba-4fab-8354-5270a31ec1b8';
    $pane = new stdClass();
    $pane->pid = 'new-ee4c4672-d067-43b9-bf7f-5e8f93f3b2ca';
    $pane->panel = 'content';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-FiSw1bzCb7fG7gAj2GF4YyEYbgdwerZa';
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
    $pane->uuid = 'ee4c4672-d067-43b9-bf7f-5e8f93f3b2ca';
    $display->content['new-ee4c4672-d067-43b9-bf7f-5e8f93f3b2ca'] = $pane;
    $display->panels['content'][2] = 'new-ee4c4672-d067-43b9-bf7f-5e8f93f3b2ca';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $display->content['new-9b8cc17b-6c53-4df3-a808-1d8a1673e439'] = $pane;
    $display->panels['content'][3] = 'new-9b8cc17b-6c53-4df3-a808-1d8a1673e439';
    $pane = new stdClass();
    $pane->pid = 'new-76b0b60e-2a0a-4561-9bdb-d01bea7d53ed';
    $pane->panel = 'content';
    $pane->type = 'debut_common_president_info';
    $pane->subtype = 'debut_common_president_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'info_text' => '<h3>Andrei Skoch</h3><br />
President of the Pokolenie Foundation, founder of the independent literary prize Debut            <br>    <br> 
By training Andrei Skoch is a teacher and psychologist with a Ph.D. in Education. He started writing poetry during his army service. He has seven children. Originally he founded his Pokolenie Foundation to help invalid children. There was a time when he needed such help for his own children and he received it from friends. Since then charity has become an important part of his life...<br>',
      'more_url' => 'http://fondskocha.ru/',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '76b0b60e-2a0a-4561-9bdb-d01bea7d53ed';
    $display->content['new-76b0b60e-2a0a-4561-9bdb-d01bea7d53ed'] = $pane;
    $display->panels['content'][4] = 'new-76b0b60e-2a0a-4561-9bdb-d01bea7d53ed';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5817b262-a507-471a-8ac3-4a6684e9ec7f';
    $display->content['new-5817b262-a507-471a-8ac3-4a6684e9ec7f'] = $pane;
    $display->panels['content'][5] = 'new-5817b262-a507-471a-8ac3-4a6684e9ec7f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
