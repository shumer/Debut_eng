<?php
/**
 * @file
 * debut_feature_pages_news_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_news_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_list';
  $page->task = 'page';
  $page->admin_title = 'Новости';
  $page->admin_description = '';
  $page->path = 'news_list';
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
  $handler->name = 'page_news_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news_list';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Expose Year Filter context',
        'keyword' => 'year_filter',
        'name' => 'year_filter_context',
        'view' => 'debut_view_list_news',
        'id' => 1,
      ),
    ),
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
  $display->uuid = '894c4b98-8936-4a33-961b-69de48d888ef';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-658fa60b-19db-41d0-8353-c8e129d33f65';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Новости',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '658fa60b-19db-41d0-8353-c8e129d33f65';
    $display->content['new-658fa60b-19db-41d0-8353-c8e129d33f65'] = $pane;
    $display->panels['content_center'][0] = 'new-658fa60b-19db-41d0-8353-c8e129d33f65';
    $pane = new stdClass();
    $pane->pid = 'new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_news',
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
    $pane->uuid = 'f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $display->content['new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9'] = $pane;
    $display->panels['content_center'][1] = 'new-f65251b7-997b-43c5-a3bc-f7f291f2e6e9';
    $pane = new stdClass();
    $pane->pid = 'new-3c8dda38-e386-4392-8f55-94658186931b';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_news_listing';
    $pane->subtype = 'debut_common_news_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_year_filter_context_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3c8dda38-e386-4392-8f55-94658186931b';
    $display->content['new-3c8dda38-e386-4392-8f55-94658186931b'] = $pane;
    $display->panels['content_center'][2] = 'new-3c8dda38-e386-4392-8f55-94658186931b';
    $pane = new stdClass();
    $pane->pid = 'new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
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
    $pane->uuid = 'ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
    $display->content['new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28'] = $pane;
    $display->panels['content_left'][0] = 'new-ccf9800a-5607-4f3d-a0e4-1b96a7205b28';
    $pane = new stdClass();
    $pane->pid = 'new-ec54a060-f125-44e3-83e5-79531248f98d';
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
    $pane->uuid = 'ec54a060-f125-44e3-83e5-79531248f98d';
    $display->content['new-ec54a060-f125-44e3-83e5-79531248f98d'] = $pane;
    $display->panels['content_left'][1] = 'new-ec54a060-f125-44e3-83e5-79531248f98d';
    $pane = new stdClass();
    $pane->pid = 'new-762f6e82-dc1e-4380-b4fe-cbfa71255ef8';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_president_info';
    $pane->subtype = 'debut_common_president_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'info_text' => '<h3>Andrei Skoch</h3><br />
President of the Pokolenie Foundation, founder of the independent literary prize Debut            <br>    <br> 
By training Andrei Skoch is a teacher and psychologist with a Ph.D. in Education. He started writing poetry during his army service. He has seven children. Originally he founded his Pokolenie Foundation to help invalid children. There was a time when he needed such help for his own children and he received it from friends. Since then charity has become an important part of his life...<br>',
      'more_url' => 'http://fond-pokolenie.livejournal.com/',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '762f6e82-dc1e-4380-b4fe-cbfa71255ef8';
    $display->content['new-762f6e82-dc1e-4380-b4fe-cbfa71255ef8'] = $pane;
    $display->panels['content_right'][0] = 'new-762f6e82-dc1e-4380-b4fe-cbfa71255ef8';
    $pane = new stdClass();
    $pane->pid = 'new-14ac26f9-4a01-42f1-860d-5bdddcfafcd3';
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
    $pane->uuid = '14ac26f9-4a01-42f1-860d-5bdddcfafcd3';
    $display->content['new-14ac26f9-4a01-42f1-860d-5bdddcfafcd3'] = $pane;
    $display->panels['content_right'][1] = 'new-14ac26f9-4a01-42f1-860d-5bdddcfafcd3';
    $pane = new stdClass();
    $pane->pid = 'new-38731a91-e88e-40ac-a712-c361386f6379';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Новости',
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
    $pane->uuid = '38731a91-e88e-40ac-a712-c361386f6379';
    $display->content['new-38731a91-e88e-40ac-a712-c361386f6379'] = $pane;
    $display->panels['top'][0] = 'new-38731a91-e88e-40ac-a712-c361386f6379';
    $pane = new stdClass();
    $pane->pid = 'new-e6c83764-d6e2-4b3f-81d9-dc10421e1097';
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
    $pane->uuid = 'e6c83764-d6e2-4b3f-81d9-dc10421e1097';
    $display->content['new-e6c83764-d6e2-4b3f-81d9-dc10421e1097'] = $pane;
    $display->panels['top'][1] = 'new-e6c83764-d6e2-4b3f-81d9-dc10421e1097';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_list_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'news_list';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Expose Year Filter context',
        'keyword' => 'year_filter',
        'name' => 'year_filter_context',
        'view' => 'debut_view_list_news',
        'id' => 1,
      ),
    ),
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
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '80d899d2-647e-46b1-8b3b-b2670c3a2e1b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-287e1a77-280f-4e0f-9665-9b14a445a42a';
    $pane->panel = 'content';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '287e1a77-280f-4e0f-9665-9b14a445a42a';
    $display->content['new-287e1a77-280f-4e0f-9665-9b14a445a42a'] = $pane;
    $display->panels['content'][0] = 'new-287e1a77-280f-4e0f-9665-9b14a445a42a';
    $pane = new stdClass();
    $pane->pid = 'new-1736c2a4-adf2-4ef2-88fe-50fa1c645f6a';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Новости',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1736c2a4-adf2-4ef2-88fe-50fa1c645f6a';
    $display->content['new-1736c2a4-adf2-4ef2-88fe-50fa1c645f6a'] = $pane;
    $display->panels['content'][1] = 'new-1736c2a4-adf2-4ef2-88fe-50fa1c645f6a';
    $pane = new stdClass();
    $pane->pid = 'new-e4171d7f-1406-4c87-b61d-29febe30d1e1';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_news',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e4171d7f-1406-4c87-b61d-29febe30d1e1';
    $display->content['new-e4171d7f-1406-4c87-b61d-29febe30d1e1'] = $pane;
    $display->panels['content'][2] = 'new-e4171d7f-1406-4c87-b61d-29febe30d1e1';
    $pane = new stdClass();
    $pane->pid = 'new-89b0b0d4-32f0-42d9-b8ba-f17b3ea72884';
    $pane->panel = 'content';
    $pane->type = 'debut_common_news_listing';
    $pane->subtype = 'debut_common_news_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_year_filter_context_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '89b0b0d4-32f0-42d9-b8ba-f17b3ea72884';
    $display->content['new-89b0b0d4-32f0-42d9-b8ba-f17b3ea72884'] = $pane;
    $display->panels['content'][3] = 'new-89b0b0d4-32f0-42d9-b8ba-f17b3ea72884';
    $pane = new stdClass();
    $pane->pid = 'new-f84c147f-527a-437f-a588-dc919632587f';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f84c147f-527a-437f-a588-dc919632587f';
    $display->content['new-f84c147f-527a-437f-a588-dc919632587f'] = $pane;
    $display->panels['content'][4] = 'new-f84c147f-527a-437f-a588-dc919632587f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-287e1a77-280f-4e0f-9665-9b14a445a42a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_list'] = $page;

  return $pages;

}
