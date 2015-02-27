<?php
/**
 * @file
 * debut_feature_pages_books_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_books_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'books_list';
  $page->task = 'page';
  $page->admin_title = 'Книги';
  $page->admin_description = '';
  $page->path = 'books_list';
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
  $handler->name = 'page_books_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'books_list';
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
  $display->uuid = '2720e7ac-0ff7-4473-90c6-18dd2bafa153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Книги',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $display->content['new-0c66ca9a-9a5f-4a96-980a-31050e5d0945'] = $pane;
    $display->panels['content_center'][0] = 'new-0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $pane = new stdClass();
    $pane->pid = 'new-54de0bb4-6545-4780-a85c-72724fd1d469';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_books_listing';
    $pane->subtype = 'debut_common_books_listing';
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
    $pane->uuid = '54de0bb4-6545-4780-a85c-72724fd1d469';
    $display->content['new-54de0bb4-6545-4780-a85c-72724fd1d469'] = $pane;
    $display->panels['content_center'][1] = 'new-54de0bb4-6545-4780-a85c-72724fd1d469';
    $pane = new stdClass();
    $pane->pid = 'new-361ca8ee-9483-4dd9-a5b8-3b432ef6de80';
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
    $pane->uuid = '361ca8ee-9483-4dd9-a5b8-3b432ef6de80';
    $display->content['new-361ca8ee-9483-4dd9-a5b8-3b432ef6de80'] = $pane;
    $display->panels['content_left'][0] = 'new-361ca8ee-9483-4dd9-a5b8-3b432ef6de80';
    $pane = new stdClass();
    $pane->pid = 'new-57f5b923-d18f-4f0b-a72c-07df686a0b45';
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
    $pane->uuid = '57f5b923-d18f-4f0b-a72c-07df686a0b45';
    $display->content['new-57f5b923-d18f-4f0b-a72c-07df686a0b45'] = $pane;
    $display->panels['content_left'][1] = 'new-57f5b923-d18f-4f0b-a72c-07df686a0b45';
    $pane = new stdClass();
    $pane->pid = 'new-bf2b062f-a220-4fd6-ab23-49ea1ef4c9e8';
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
    $pane->uuid = 'bf2b062f-a220-4fd6-ab23-49ea1ef4c9e8';
    $display->content['new-bf2b062f-a220-4fd6-ab23-49ea1ef4c9e8'] = $pane;
    $display->panels['content_left'][2] = 'new-bf2b062f-a220-4fd6-ab23-49ea1ef4c9e8';
    $pane = new stdClass();
    $pane->pid = 'new-b1fc68f0-4344-45ab-956e-49a2144cb759';
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
    $pane->uuid = 'b1fc68f0-4344-45ab-956e-49a2144cb759';
    $display->content['new-b1fc68f0-4344-45ab-956e-49a2144cb759'] = $pane;
    $display->panels['content_right'][0] = 'new-b1fc68f0-4344-45ab-956e-49a2144cb759';
    $pane = new stdClass();
    $pane->pid = 'new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
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
    $pane->uuid = '1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
    $display->content['new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6'] = $pane;
    $display->panels['content_right'][1] = 'new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
    $pane = new stdClass();
    $pane->pid = 'new-03ae738d-838a-4742-9e5f-dbecfb6b426d';
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
    $pane->uuid = '03ae738d-838a-4742-9e5f-dbecfb6b426d';
    $display->content['new-03ae738d-838a-4742-9e5f-dbecfb6b426d'] = $pane;
    $display->panels['content_right'][2] = 'new-03ae738d-838a-4742-9e5f-dbecfb6b426d';
    $pane = new stdClass();
    $pane->pid = 'new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Книги',
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
    $pane->uuid = '76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
    $display->content['new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0'] = $pane;
    $display->panels['top'][0] = 'new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
    $pane = new stdClass();
    $pane->pid = 'new-0c0f9057-c3f0-440f-81d4-cf594b1bcf6f';
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
    $pane->uuid = '0c0f9057-c3f0-440f-81d4-cf594b1bcf6f';
    $display->content['new-0c0f9057-c3f0-440f-81d4-cf594b1bcf6f'] = $pane;
    $display->panels['top'][1] = 'new-0c0f9057-c3f0-440f-81d4-cf594b1bcf6f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_books_list_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'books_list';
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
      'middle' => NULL,
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
  $display->uuid = '2720e7ac-0ff7-4473-90c6-18dd2bafa153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
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
    $pane->uuid = '76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
    $display->content['new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0'] = $pane;
    $display->panels['content'][0] = 'new-76ffa4c0-5179-4604-a4b4-b167dbf43fc0';
    $pane = new stdClass();
    $pane->pid = 'new-0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Книги',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $display->content['new-0c66ca9a-9a5f-4a96-980a-31050e5d0945'] = $pane;
    $display->panels['content'][1] = 'new-0c66ca9a-9a5f-4a96-980a-31050e5d0945';
    $pane = new stdClass();
    $pane->pid = 'new-54de0bb4-6545-4780-a85c-72724fd1d469';
    $pane->panel = 'content';
    $pane->type = 'debut_common_books_listing';
    $pane->subtype = 'debut_common_books_listing';
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
    $pane->uuid = '54de0bb4-6545-4780-a85c-72724fd1d469';
    $display->content['new-54de0bb4-6545-4780-a85c-72724fd1d469'] = $pane;
    $display->panels['content'][2] = 'new-54de0bb4-6545-4780-a85c-72724fd1d469';
    $pane = new stdClass();
    $pane->pid = 'new-b1fc68f0-4344-45ab-956e-49a2144cb759';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b1fc68f0-4344-45ab-956e-49a2144cb759';
    $display->content['new-b1fc68f0-4344-45ab-956e-49a2144cb759'] = $pane;
    $display->panels['content'][3] = 'new-b1fc68f0-4344-45ab-956e-49a2144cb759';
    $pane = new stdClass();
    $pane->pid = 'new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
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
    $pane->uuid = '1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
    $display->content['new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6'] = $pane;
    $display->panels['content'][4] = 'new-1fbcc8bf-8eae-453f-957d-7a9ba17764a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['books_list'] = $page;

  return $pages;

}
