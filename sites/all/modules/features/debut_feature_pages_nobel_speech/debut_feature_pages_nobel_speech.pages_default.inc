<?php
/**
 * @file
 * debut_feature_pages_nobel_speech.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_nobel_speech_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'nobel_speech';
  $page->task = 'page';
  $page->admin_title = 'Нобелевские речи';
  $page->admin_description = '';
  $page->path = 'nobel_speech';
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
  $handler->name = 'page_nobel_speech_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'nobel_speech';
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
        'view' => 'debut_view_list_nobel_speach',
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
  $display->uuid = 'af99141a-1722-4d79-93c5-1c5ce83afe89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-96e9390f-e08c-4e8e-b8b6-c0b60407526a';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '«Нобелевские речи»',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '96e9390f-e08c-4e8e-b8b6-c0b60407526a';
    $display->content['new-96e9390f-e08c-4e8e-b8b6-c0b60407526a'] = $pane;
    $display->panels['content_center'][0] = 'new-96e9390f-e08c-4e8e-b8b6-c0b60407526a';
    $pane = new stdClass();
    $pane->pid = 'new-86e234ab-09b5-4b68-9a88-8d7ddf035b18';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_nobel_speach',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '86e234ab-09b5-4b68-9a88-8d7ddf035b18';
    $display->content['new-86e234ab-09b5-4b68-9a88-8d7ddf035b18'] = $pane;
    $display->panels['content_center'][1] = 'new-86e234ab-09b5-4b68-9a88-8d7ddf035b18';
    $pane = new stdClass();
    $pane->pid = 'new-c1c01052-3d2e-4128-8a18-24306dd4e6d2';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_nobel_listing';
    $pane->subtype = 'debut_common_nobel_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_year_filter_contexts_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c1c01052-3d2e-4128-8a18-24306dd4e6d2';
    $display->content['new-c1c01052-3d2e-4128-8a18-24306dd4e6d2'] = $pane;
    $display->panels['content_center'][2] = 'new-c1c01052-3d2e-4128-8a18-24306dd4e6d2';
    $pane = new stdClass();
    $pane->pid = 'new-7359132c-b573-4fd3-9dc6-339e04237084';
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
    $pane->uuid = '7359132c-b573-4fd3-9dc6-339e04237084';
    $display->content['new-7359132c-b573-4fd3-9dc6-339e04237084'] = $pane;
    $display->panels['content_left'][0] = 'new-7359132c-b573-4fd3-9dc6-339e04237084';
    $pane = new stdClass();
    $pane->pid = 'new-af05d23e-eac6-40f9-a4a7-78193d821a5c';
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
    $pane->uuid = 'af05d23e-eac6-40f9-a4a7-78193d821a5c';
    $display->content['new-af05d23e-eac6-40f9-a4a7-78193d821a5c'] = $pane;
    $display->panels['content_left'][1] = 'new-af05d23e-eac6-40f9-a4a7-78193d821a5c';
    $pane = new stdClass();
    $pane->pid = 'new-fc4b1cb1-e49c-4ca3-b13b-57bebf7d21cc';
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
    $pane->uuid = 'fc4b1cb1-e49c-4ca3-b13b-57bebf7d21cc';
    $display->content['new-fc4b1cb1-e49c-4ca3-b13b-57bebf7d21cc'] = $pane;
    $display->panels['content_left'][2] = 'new-fc4b1cb1-e49c-4ca3-b13b-57bebf7d21cc';
    $pane = new stdClass();
    $pane->pid = 'new-ef8d1f5d-eadb-4cfe-92dd-889bcf7f8f5c';
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
    $pane->uuid = 'ef8d1f5d-eadb-4cfe-92dd-889bcf7f8f5c';
    $display->content['new-ef8d1f5d-eadb-4cfe-92dd-889bcf7f8f5c'] = $pane;
    $display->panels['content_right'][0] = 'new-ef8d1f5d-eadb-4cfe-92dd-889bcf7f8f5c';
    $pane = new stdClass();
    $pane->pid = 'new-feed1013-65da-476c-9a47-96320684348e';
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
    $pane->uuid = 'feed1013-65da-476c-9a47-96320684348e';
    $display->content['new-feed1013-65da-476c-9a47-96320684348e'] = $pane;
    $display->panels['content_right'][1] = 'new-feed1013-65da-476c-9a47-96320684348e';
    $pane = new stdClass();
    $pane->pid = 'new-f07bf221-a2f2-434d-a5ae-41c49a8b60fe';
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
    $pane->uuid = 'f07bf221-a2f2-434d-a5ae-41c49a8b60fe';
    $display->content['new-f07bf221-a2f2-434d-a5ae-41c49a8b60fe'] = $pane;
    $display->panels['content_right'][2] = 'new-f07bf221-a2f2-434d-a5ae-41c49a8b60fe';
    $pane = new stdClass();
    $pane->pid = 'new-15c75228-9916-4f8e-9d85-ef0dd1f01101';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '«Нобелевские речи»',
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
    $pane->uuid = '15c75228-9916-4f8e-9d85-ef0dd1f01101';
    $display->content['new-15c75228-9916-4f8e-9d85-ef0dd1f01101'] = $pane;
    $display->panels['top'][0] = 'new-15c75228-9916-4f8e-9d85-ef0dd1f01101';
    $pane = new stdClass();
    $pane->pid = 'new-51c29f10-3b99-4647-a0a2-b7874e17c971';
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
    $pane->uuid = '51c29f10-3b99-4647-a0a2-b7874e17c971';
    $display->content['new-51c29f10-3b99-4647-a0a2-b7874e17c971'] = $pane;
    $display->panels['top'][1] = 'new-51c29f10-3b99-4647-a0a2-b7874e17c971';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_nobel_speech_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'nobel_speech';
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
        'view' => 'debut_view_list_nobel_speach',
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
  $display->uuid = '38037995-791e-473f-aaea-024962be36a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9420c27f-84d6-4f82-80fc-7cb03df79079';
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
    $pane->uuid = '9420c27f-84d6-4f82-80fc-7cb03df79079';
    $display->content['new-9420c27f-84d6-4f82-80fc-7cb03df79079'] = $pane;
    $display->panels['content'][0] = 'new-9420c27f-84d6-4f82-80fc-7cb03df79079';
    $pane = new stdClass();
    $pane->pid = 'new-228d883a-4e56-426c-abe4-233d09251bff';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '«Нобелевские речи»',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '228d883a-4e56-426c-abe4-233d09251bff';
    $display->content['new-228d883a-4e56-426c-abe4-233d09251bff'] = $pane;
    $display->panels['content'][1] = 'new-228d883a-4e56-426c-abe4-233d09251bff';
    $pane = new stdClass();
    $pane->pid = 'new-e522a2a9-4fbb-4af1-aa47-94788c57cc4f';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_nobel_speach',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e522a2a9-4fbb-4af1-aa47-94788c57cc4f';
    $display->content['new-e522a2a9-4fbb-4af1-aa47-94788c57cc4f'] = $pane;
    $display->panels['content'][2] = 'new-e522a2a9-4fbb-4af1-aa47-94788c57cc4f';
    $pane = new stdClass();
    $pane->pid = 'new-227ed829-3db0-4094-b2a3-e5424ad82796';
    $pane->panel = 'content';
    $pane->type = 'debut_common_nobel_listing';
    $pane->subtype = 'debut_common_nobel_listing';
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
    $pane->uuid = '227ed829-3db0-4094-b2a3-e5424ad82796';
    $display->content['new-227ed829-3db0-4094-b2a3-e5424ad82796'] = $pane;
    $display->panels['content'][3] = 'new-227ed829-3db0-4094-b2a3-e5424ad82796';
    $pane = new stdClass();
    $pane->pid = 'new-081a4c8d-8527-4ee8-aa47-e920a01c468d';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '081a4c8d-8527-4ee8-aa47-e920a01c468d';
    $display->content['new-081a4c8d-8527-4ee8-aa47-e920a01c468d'] = $pane;
    $display->panels['content'][4] = 'new-081a4c8d-8527-4ee8-aa47-e920a01c468d';
    $pane = new stdClass();
    $pane->pid = 'new-080a8b13-e58f-45be-92ae-e310b4efb5ee';
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
    $pane->uuid = '080a8b13-e58f-45be-92ae-e310b4efb5ee';
    $display->content['new-080a8b13-e58f-45be-92ae-e310b4efb5ee'] = $pane;
    $display->panels['content'][5] = 'new-080a8b13-e58f-45be-92ae-e310b4efb5ee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9420c27f-84d6-4f82-80fc-7cb03df79079';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['nobel_speech'] = $page;

  return $pages;

}
