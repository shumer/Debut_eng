<?php
/**
 * @file
 * debut_feature_pages_node_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function debut_feature_pages_node_view_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_http_response';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'DEFAULT',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '403',
    'destination' => '',
  );
  $export['node_view_http_response'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'News',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news' => 'news',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content_center'][0] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = 'e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $display->content['new-e44cb7a2-c070-4e9f-a483-da87736a3daa'] = $pane;
    $display->panels['content_left'][0] = 'new-e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $pane = new stdClass();
    $pane->pid = 'new-35430b46-29a3-4f2e-87bc-09b7b39ae073';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '35430b46-29a3-4f2e-87bc-09b7b39ae073';
    $display->content['new-35430b46-29a3-4f2e-87bc-09b7b39ae073'] = $pane;
    $display->panels['top'][0] = 'new-35430b46-29a3-4f2e-87bc-09b7b39ae073';
    $pane = new stdClass();
    $pane->pid = 'new-8e04114c-3fe7-4530-8fca-254a012308b8';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '8e04114c-3fe7-4530-8fca-254a012308b8';
    $display->content['new-8e04114c-3fe7-4530-8fca-254a012308b8'] = $pane;
    $display->panels['top'][1] = 'new-8e04114c-3fe7-4530-8fca-254a012308b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Document',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'documents' => 'documents',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content_center'][0] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = 'e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $display->content['new-e44cb7a2-c070-4e9f-a483-da87736a3daa'] = $pane;
    $display->panels['content_left'][0] = 'new-e44cb7a2-c070-4e9f-a483-da87736a3daa';
    $pane = new stdClass();
    $pane->pid = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '2702e824-3285-4230-9a54-acfef533dd5a';
    $display->content['new-2702e824-3285-4230-9a54-acfef533dd5a'] = $pane;
    $display->panels['top'][0] = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane = new stdClass();
    $pane->pid = 'new-eb7ff3aa-4836-4ea3-927a-aa48225412c3';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = 'eb7ff3aa-4836-4ea3-927a-aa48225412c3';
    $display->content['new-eb7ff3aa-4836-4ea3-927a-aa48225412c3'] = $pane;
    $display->panels['top'][1] = 'new-eb7ff3aa-4836-4ea3-927a-aa48225412c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Press about debut',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_about_debut' => 'press_about_debut',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = '93f5fba3-1fd0-49ae-b4d7-206a2d1b530b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-27f53bd8-32c9-4858-a5d1-9e581ab496a7';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '27f53bd8-32c9-4858-a5d1-9e581ab496a7';
    $display->content['new-27f53bd8-32c9-4858-a5d1-9e581ab496a7'] = $pane;
    $display->panels['content_center'][0] = 'new-27f53bd8-32c9-4858-a5d1-9e581ab496a7';
    $pane = new stdClass();
    $pane->pid = 'new-6d422b35-4b73-40d6-b4e1-5f7817856431';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '6d422b35-4b73-40d6-b4e1-5f7817856431';
    $display->content['new-6d422b35-4b73-40d6-b4e1-5f7817856431'] = $pane;
    $display->panels['content_left'][0] = 'new-6d422b35-4b73-40d6-b4e1-5f7817856431';
    $pane = new stdClass();
    $pane->pid = 'new-b17a67bd-9361-41d7-b270-d48d580b9d28';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = 'b17a67bd-9361-41d7-b270-d48d580b9d28';
    $display->content['new-b17a67bd-9361-41d7-b270-d48d580b9d28'] = $pane;
    $display->panels['top'][0] = 'new-b17a67bd-9361-41d7-b270-d48d580b9d28';
    $pane = new stdClass();
    $pane->pid = 'new-8de8a3d7-b3ba-4e06-bbd4-c76b7ceedbed';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '8de8a3d7-b3ba-4e06-bbd4-c76b7ceedbed';
    $display->content['new-8de8a3d7-b3ba-4e06-bbd4-c76b7ceedbed'] = $pane;
    $display->panels['top'][1] = 'new-8de8a3d7-b3ba-4e06-bbd4-c76b7ceedbed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Master class text',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'master_class_text' => 'master_class_text',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = '157a7850-e4b8-4f87-8045-48e572ba309f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-47b52023-0a90-46be-b65c-db95abc75c62';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '47b52023-0a90-46be-b65c-db95abc75c62';
    $display->content['new-47b52023-0a90-46be-b65c-db95abc75c62'] = $pane;
    $display->panels['content_center'][0] = 'new-47b52023-0a90-46be-b65c-db95abc75c62';
    $pane = new stdClass();
    $pane->pid = 'new-66c55b3c-9498-458b-8e93-fead1b1b1068';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '66c55b3c-9498-458b-8e93-fead1b1b1068';
    $display->content['new-66c55b3c-9498-458b-8e93-fead1b1b1068'] = $pane;
    $display->panels['content_left'][0] = 'new-66c55b3c-9498-458b-8e93-fead1b1b1068';
    $pane = new stdClass();
    $pane->pid = 'new-4c7cbd9c-602c-4a22-bd69-473bccece2ed';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '4c7cbd9c-602c-4a22-bd69-473bccece2ed';
    $display->content['new-4c7cbd9c-602c-4a22-bd69-473bccece2ed'] = $pane;
    $display->panels['top'][0] = 'new-4c7cbd9c-602c-4a22-bd69-473bccece2ed';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Travel description',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'travel_description' => 'travel_description',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = 'ccf7fb06-6822-42f1-b377-2a785b05cbda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $display->content['new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b'] = $pane;
    $display->panels['content_center'][0] = 'new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $pane = new stdClass();
    $pane->pid = 'new-4acbea1c-7f7a-4633-bb89-9bd380854431';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '4acbea1c-7f7a-4633-bb89-9bd380854431';
    $display->content['new-4acbea1c-7f7a-4633-bb89-9bd380854431'] = $pane;
    $display->panels['content_left'][0] = 'new-4acbea1c-7f7a-4633-bb89-9bd380854431';
    $pane = new stdClass();
    $pane->pid = 'new-dded7d14-43e7-4252-9305-da02d2b35eab';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = 'dded7d14-43e7-4252-9305-da02d2b35eab';
    $display->content['new-dded7d14-43e7-4252-9305-da02d2b35eab'] = $pane;
    $display->panels['top'][0] = 'new-dded7d14-43e7-4252-9305-da02d2b35eab';
    $pane = new stdClass();
    $pane->pid = 'new-998e75d8-8f84-4d0b-b224-bb38d5f84f80';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '998e75d8-8f84-4d0b-b224-bb38d5f84f80';
    $display->content['new-998e75d8-8f84-4d0b-b224-bb38d5f84f80'] = $pane;
    $display->panels['top'][1] = 'new-998e75d8-8f84-4d0b-b224-bb38d5f84f80';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Travels',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'travel' => 'travel',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = '1168eb33-da88-489c-8ef6-9fce18d681ee';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f4525fa9-333c-4233-bb99-b95a5a75f784';
    $pane->panel = 'content_center';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'f4525fa9-333c-4233-bb99-b95a5a75f784';
    $display->content['new-f4525fa9-333c-4233-bb99-b95a5a75f784'] = $pane;
    $display->panels['content_center'][0] = 'new-f4525fa9-333c-4233-bb99-b95a5a75f784';
    $pane = new stdClass();
    $pane->pid = 'new-049f24f5-2e09-4f20-ab4f-2e4e121b520b';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_menu';
    $pane->subtype = 'debut_common_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'browser_menu' => 'main-menu',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '049f24f5-2e09-4f20-ab4f-2e4e121b520b';
    $display->content['new-049f24f5-2e09-4f20-ab4f-2e4e121b520b'] = $pane;
    $display->panels['content_left'][0] = 'new-049f24f5-2e09-4f20-ab4f-2e4e121b520b';
    $pane = new stdClass();
    $pane->pid = 'new-0dd31db4-0435-4ca1-9fc6-85631b8319cc';
    $pane->panel = 'top';
    $pane->type = 'debut_common_social_links';
    $pane->subtype = 'debut_common_social_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '0dd31db4-0435-4ca1-9fc6-85631b8319cc';
    $display->content['new-0dd31db4-0435-4ca1-9fc6-85631b8319cc'] = $pane;
    $display->panels['top'][0] = 'new-0dd31db4-0435-4ca1-9fc6-85631b8319cc';
    $pane = new stdClass();
    $pane->pid = 'new-8b6e6326-af5d-4483-972e-59697a9c2938';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => '',
      'context' => array(
        0 => 'argument_entity_id:node_1',
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
    $pane->uuid = '8b6e6326-af5d-4483-972e-59697a9c2938';
    $display->content['new-8b6e6326-af5d-4483-972e-59697a9c2938'] = $pane;
    $display->panels['top'][1] = 'new-8b6e6326-af5d-4483-972e-59697a9c2938';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-049f24f5-2e09-4f20-ab4f-2e4e121b520b';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}
