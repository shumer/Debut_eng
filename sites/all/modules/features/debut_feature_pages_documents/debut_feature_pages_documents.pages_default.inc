<?php
/**
 * @file
 * debut_feature_pages_documents.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_documents_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'documents';
  $page->task = 'page';
  $page->admin_title = 'Документы';
  $page->admin_description = '';
  $page->path = 'documents_list';
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
  $handler->name = 'page_documents_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'documents';
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
  $display->uuid = '0a9c90e8-54d3-48d9-aa9f-2ba4a38513c7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b1ac6663-9a09-487d-b4cb-a828839efd86';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Документы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1ac6663-9a09-487d-b4cb-a828839efd86';
    $display->content['new-b1ac6663-9a09-487d-b4cb-a828839efd86'] = $pane;
    $display->panels['content_center'][0] = 'new-b1ac6663-9a09-487d-b4cb-a828839efd86';
    $pane = new stdClass();
    $pane->pid = 'new-499a322a-28e0-46d5-8743-2b9ad8cd2fbc';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_documents',
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
    $pane->uuid = '499a322a-28e0-46d5-8743-2b9ad8cd2fbc';
    $display->content['new-499a322a-28e0-46d5-8743-2b9ad8cd2fbc'] = $pane;
    $display->panels['content_center'][1] = 'new-499a322a-28e0-46d5-8743-2b9ad8cd2fbc';
    $pane = new stdClass();
    $pane->pid = 'new-3b0b39c8-86ba-408d-91bb-e33905b9c756';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_documents_listing';
    $pane->subtype = 'debut_common_documents_listing';
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
    $pane->uuid = '3b0b39c8-86ba-408d-91bb-e33905b9c756';
    $display->content['new-3b0b39c8-86ba-408d-91bb-e33905b9c756'] = $pane;
    $display->panels['content_center'][2] = 'new-3b0b39c8-86ba-408d-91bb-e33905b9c756';
    $pane = new stdClass();
    $pane->pid = 'new-32823a8a-13b4-4146-b0a4-3e439420004b';
    $pane->panel = 'content_center';
    $pane->type = 'content';
    $pane->subtype = 'content';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Hide if no result',
            'php' => 'if (empty($_GET[\'sort_by\'])) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'bundle' => 'manuscript_page',
      'view_mode' => 'full',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '32823a8a-13b4-4146-b0a4-3e439420004b';
    $display->content['new-32823a8a-13b4-4146-b0a4-3e439420004b'] = $pane;
    $display->panels['content_center'][3] = 'new-32823a8a-13b4-4146-b0a4-3e439420004b';
    $pane = new stdClass();
    $pane->pid = 'new-94c95136-5708-4561-9631-dd801ced1375';
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
    $pane->uuid = '94c95136-5708-4561-9631-dd801ced1375';
    $display->content['new-94c95136-5708-4561-9631-dd801ced1375'] = $pane;
    $display->panels['content_left'][0] = 'new-94c95136-5708-4561-9631-dd801ced1375';
    $pane = new stdClass();
    $pane->pid = 'new-d276c1df-e22b-4848-8928-45f38ee5f7a8';
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
    $pane->uuid = 'd276c1df-e22b-4848-8928-45f38ee5f7a8';
    $display->content['new-d276c1df-e22b-4848-8928-45f38ee5f7a8'] = $pane;
    $display->panels['content_left'][1] = 'new-d276c1df-e22b-4848-8928-45f38ee5f7a8';
    $pane = new stdClass();
    $pane->pid = 'new-161a9c38-b4f4-450d-b862-7cc8c8f7c0be';
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
    $pane->uuid = '161a9c38-b4f4-450d-b862-7cc8c8f7c0be';
    $display->content['new-161a9c38-b4f4-450d-b862-7cc8c8f7c0be'] = $pane;
    $display->panels['content_left'][2] = 'new-161a9c38-b4f4-450d-b862-7cc8c8f7c0be';
    $pane = new stdClass();
    $pane->pid = 'new-72d64af2-90de-4201-bf8f-31661948ca22';
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
    $pane->uuid = '72d64af2-90de-4201-bf8f-31661948ca22';
    $display->content['new-72d64af2-90de-4201-bf8f-31661948ca22'] = $pane;
    $display->panels['content_right'][0] = 'new-72d64af2-90de-4201-bf8f-31661948ca22';
    $pane = new stdClass();
    $pane->pid = 'new-3f8740f2-8856-48d8-8192-82390bf03d78';
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
    $pane->uuid = '3f8740f2-8856-48d8-8192-82390bf03d78';
    $display->content['new-3f8740f2-8856-48d8-8192-82390bf03d78'] = $pane;
    $display->panels['content_right'][1] = 'new-3f8740f2-8856-48d8-8192-82390bf03d78';
    $pane = new stdClass();
    $pane->pid = 'new-e5c20577-9c52-4a12-b8e1-34d63b92558f';
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
    $pane->uuid = 'e5c20577-9c52-4a12-b8e1-34d63b92558f';
    $display->content['new-e5c20577-9c52-4a12-b8e1-34d63b92558f'] = $pane;
    $display->panels['content_right'][2] = 'new-e5c20577-9c52-4a12-b8e1-34d63b92558f';
    $pane = new stdClass();
    $pane->pid = 'new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Документы',
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
    $pane->uuid = '80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $display->content['new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7'] = $pane;
    $display->panels['top'][0] = 'new-80b752f5-a50d-4cc7-9523-89bf1cafd7b7';
    $pane = new stdClass();
    $pane->pid = 'new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
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
    $pane->uuid = 'bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
    $display->content['new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6'] = $pane;
    $display->panels['top'][1] = 'new-bbd438c7-7ad9-4518-8073-62dcf1ae32f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_documents_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'documents';
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
        'view' => 'debut_view_list_documents',
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
  $display->uuid = '8b9dd30f-d8c8-4e72-b707-abdc79ffb96f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c88bdb86-e75c-4e43-80ac-d8ed16749075';
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
    $pane->uuid = 'c88bdb86-e75c-4e43-80ac-d8ed16749075';
    $display->content['new-c88bdb86-e75c-4e43-80ac-d8ed16749075'] = $pane;
    $display->panels['content'][0] = 'new-c88bdb86-e75c-4e43-80ac-d8ed16749075';
    $pane = new stdClass();
    $pane->pid = 'new-23836f86-ca2d-47e1-bd48-7055e789e68e';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Документы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '23836f86-ca2d-47e1-bd48-7055e789e68e';
    $display->content['new-23836f86-ca2d-47e1-bd48-7055e789e68e'] = $pane;
    $display->panels['content'][1] = 'new-23836f86-ca2d-47e1-bd48-7055e789e68e';
    $pane = new stdClass();
    $pane->pid = 'new-b8d43389-6e34-40bf-804d-eb6132cd00c3';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_documents',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b8d43389-6e34-40bf-804d-eb6132cd00c3';
    $display->content['new-b8d43389-6e34-40bf-804d-eb6132cd00c3'] = $pane;
    $display->panels['content'][2] = 'new-b8d43389-6e34-40bf-804d-eb6132cd00c3';
    $pane = new stdClass();
    $pane->pid = 'new-fbcaa71d-2fc3-4c60-b9d7-ef770dd4ba8a';
    $pane->panel = 'content';
    $pane->type = 'debut_common_documents_listing';
    $pane->subtype = 'debut_common_documents_listing';
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
    $pane->uuid = 'fbcaa71d-2fc3-4c60-b9d7-ef770dd4ba8a';
    $display->content['new-fbcaa71d-2fc3-4c60-b9d7-ef770dd4ba8a'] = $pane;
    $display->panels['content'][3] = 'new-fbcaa71d-2fc3-4c60-b9d7-ef770dd4ba8a';
    $pane = new stdClass();
    $pane->pid = 'new-22a75b73-616f-447c-8fad-78887e21e6f7';
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
    $pane->uuid = '22a75b73-616f-447c-8fad-78887e21e6f7';
    $display->content['new-22a75b73-616f-447c-8fad-78887e21e6f7'] = $pane;
    $display->panels['content'][4] = 'new-22a75b73-616f-447c-8fad-78887e21e6f7';
    $pane = new stdClass();
    $pane->pid = 'new-98bc7696-acf2-4013-b766-ff5e50ed6285';
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
    $pane->uuid = '98bc7696-acf2-4013-b766-ff5e50ed6285';
    $display->content['new-98bc7696-acf2-4013-b766-ff5e50ed6285'] = $pane;
    $display->panels['content'][5] = 'new-98bc7696-acf2-4013-b766-ff5e50ed6285';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-23836f86-ca2d-47e1-bd48-7055e789e68e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['documents'] = $page;

  return $pages;

}
