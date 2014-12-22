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
  $handler->weight = -20;
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
  $handler->weight = -22;
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
    $pane->pid = 'new-232605ac-d829-436e-9e02-b3953fc718ba';
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
    $pane->uuid = '232605ac-d829-436e-9e02-b3953fc718ba';
    $display->content['new-232605ac-d829-436e-9e02-b3953fc718ba'] = $pane;
    $display->panels['content_left'][1] = 'new-232605ac-d829-436e-9e02-b3953fc718ba';
    $pane = new stdClass();
    $pane->pid = 'new-1cddab97-7237-4dd8-bb71-2da93060c221';
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
    $pane->uuid = '1cddab97-7237-4dd8-bb71-2da93060c221';
    $display->content['new-1cddab97-7237-4dd8-bb71-2da93060c221'] = $pane;
    $display->panels['content_left'][2] = 'new-1cddab97-7237-4dd8-bb71-2da93060c221';
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
  $handler->name = 'node_view_panel_context_10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'iBooks',
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
              'ibooks' => 'ibooks',
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
  $display->uuid = 'df5178e7-2115-42b5-993d-1ea84f45e499';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6698768e-414a-4057-859e-073a53c6b5d2';
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
    $pane->uuid = '6698768e-414a-4057-859e-073a53c6b5d2';
    $display->content['new-6698768e-414a-4057-859e-073a53c6b5d2'] = $pane;
    $display->panels['content_center'][0] = 'new-6698768e-414a-4057-859e-073a53c6b5d2';
    $pane = new stdClass();
    $pane->pid = 'new-f69e16c1-f266-4d31-afda-ab643ad209e8';
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
    $pane->uuid = 'f69e16c1-f266-4d31-afda-ab643ad209e8';
    $display->content['new-f69e16c1-f266-4d31-afda-ab643ad209e8'] = $pane;
    $display->panels['content_left'][0] = 'new-f69e16c1-f266-4d31-afda-ab643ad209e8';
    $pane = new stdClass();
    $pane->pid = 'new-f360f6de-f938-4f89-9993-969df754e4a0';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Изменения на сайте',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f360f6de-f938-4f89-9993-969df754e4a0';
    $display->content['new-f360f6de-f938-4f89-9993-969df754e4a0'] = $pane;
    $display->panels['content_left'][1] = 'new-f360f6de-f938-4f89-9993-969df754e4a0';
    $pane = new stdClass();
    $pane->pid = 'new-30414660-cc78-4df9-bb9d-99a5f06d41ed';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_contact_us';
    $pane->subtype = 'debut_common_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Связаться с нами',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '30414660-cc78-4df9-bb9d-99a5f06d41ed';
    $display->content['new-30414660-cc78-4df9-bb9d-99a5f06d41ed'] = $pane;
    $display->panels['content_left'][2] = 'new-30414660-cc78-4df9-bb9d-99a5f06d41ed';
    $pane = new stdClass();
    $pane->pid = 'new-c2db2674-8cbf-4df8-9388-f291f757d808';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Проект iКнига',
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
    $pane->uuid = 'c2db2674-8cbf-4df8-9388-f291f757d808';
    $display->content['new-c2db2674-8cbf-4df8-9388-f291f757d808'] = $pane;
    $display->panels['top'][0] = 'new-c2db2674-8cbf-4df8-9388-f291f757d808';
    $pane = new stdClass();
    $pane->pid = 'new-165ffb59-ee23-4181-b88f-c60f366e688d';
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
    $pane->uuid = '165ffb59-ee23-4181-b88f-c60f366e688d';
    $display->content['new-165ffb59-ee23-4181-b88f-c60f366e688d'] = $pane;
    $display->panels['top'][1] = 'new-165ffb59-ee23-4181-b88f-c60f366e688d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
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
    $pane->pid = 'new-a3a60e16-7eb5-4b5f-b6b3-13e1938d43f0';
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
    $pane->uuid = 'a3a60e16-7eb5-4b5f-b6b3-13e1938d43f0';
    $display->content['new-a3a60e16-7eb5-4b5f-b6b3-13e1938d43f0'] = $pane;
    $display->panels['content_left'][1] = 'new-a3a60e16-7eb5-4b5f-b6b3-13e1938d43f0';
    $pane = new stdClass();
    $pane->pid = 'new-d6187a32-558a-4a8f-b987-f0daeb97c926';
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
    $pane->uuid = 'd6187a32-558a-4a8f-b987-f0daeb97c926';
    $display->content['new-d6187a32-558a-4a8f-b987-f0daeb97c926'] = $pane;
    $display->panels['content_left'][2] = 'new-d6187a32-558a-4a8f-b987-f0daeb97c926';
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
  $handler->weight = -23;
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
    $pane->pid = 'new-523cc37f-f52d-48d6-9e6e-f7612850f2da';
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
    $pane->uuid = '523cc37f-f52d-48d6-9e6e-f7612850f2da';
    $display->content['new-523cc37f-f52d-48d6-9e6e-f7612850f2da'] = $pane;
    $display->panels['content_left'][1] = 'new-523cc37f-f52d-48d6-9e6e-f7612850f2da';
    $pane = new stdClass();
    $pane->pid = 'new-4f0d4ff5-7da7-4177-850d-1caa1ff271e8';
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
    $pane->uuid = '4f0d4ff5-7da7-4177-850d-1caa1ff271e8';
    $display->content['new-4f0d4ff5-7da7-4177-850d-1caa1ff271e8'] = $pane;
    $display->panels['content_left'][2] = 'new-4f0d4ff5-7da7-4177-850d-1caa1ff271e8';
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
  $handler->weight = -24;
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
    $pane->pid = 'new-42f47b09-270e-4823-b9e2-20ec3f173757';
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
    $pane->uuid = '42f47b09-270e-4823-b9e2-20ec3f173757';
    $display->content['new-42f47b09-270e-4823-b9e2-20ec3f173757'] = $pane;
    $display->panels['content_left'][1] = 'new-42f47b09-270e-4823-b9e2-20ec3f173757';
    $pane = new stdClass();
    $pane->pid = 'new-11f01d38-b646-41b5-932d-652f3c26541e';
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
    $pane->uuid = '11f01d38-b646-41b5-932d-652f3c26541e';
    $display->content['new-11f01d38-b646-41b5-932d-652f3c26541e'] = $pane;
    $display->panels['content_left'][2] = 'new-11f01d38-b646-41b5-932d-652f3c26541e';
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
  $handler->weight = -26;
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
    $pane->pid = 'new-6a9bfc99-98bb-4b5c-8f25-279bc7ff0337';
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
    $pane->uuid = '6a9bfc99-98bb-4b5c-8f25-279bc7ff0337';
    $display->content['new-6a9bfc99-98bb-4b5c-8f25-279bc7ff0337'] = $pane;
    $display->panels['content_left'][1] = 'new-6a9bfc99-98bb-4b5c-8f25-279bc7ff0337';
    $pane = new stdClass();
    $pane->pid = 'new-574889cd-1e7f-4939-b148-ee79acfd5967';
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
    $pane->uuid = '574889cd-1e7f-4939-b148-ee79acfd5967';
    $display->content['new-574889cd-1e7f-4939-b148-ee79acfd5967'] = $pane;
    $display->panels['content_left'][2] = 'new-574889cd-1e7f-4939-b148-ee79acfd5967';
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
  $handler->weight = -25;
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
    $pane->pid = 'new-9cf68cff-3ac0-45cf-99fe-334943336bb0';
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
    $pane->uuid = '9cf68cff-3ac0-45cf-99fe-334943336bb0';
    $display->content['new-9cf68cff-3ac0-45cf-99fe-334943336bb0'] = $pane;
    $display->panels['content_left'][1] = 'new-9cf68cff-3ac0-45cf-99fe-334943336bb0';
    $pane = new stdClass();
    $pane->pid = 'new-5978c081-af06-4e3b-ab9e-d5e4f89af6e3';
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
    $pane->uuid = '5978c081-af06-4e3b-ab9e-d5e4f89af6e3';
    $display->content['new-5978c081-af06-4e3b-ab9e-d5e4f89af6e3'] = $pane;
    $display->panels['content_left'][2] = 'new-5978c081-af06-4e3b-ab9e-d5e4f89af6e3';
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

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Video',
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
              'video' => 'video',
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
  $display->uuid = '29dc1eb7-2de3-4296-9245-12b3d0aea5d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
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
    $pane->uuid = '665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
    $display->content['new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93'] = $pane;
    $display->panels['content_center'][0] = 'new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
    $pane = new stdClass();
    $pane->pid = 'new-042dd59f-f0f3-4b42-b133-64441bcfbfe2';
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
    $pane->uuid = '042dd59f-f0f3-4b42-b133-64441bcfbfe2';
    $display->content['new-042dd59f-f0f3-4b42-b133-64441bcfbfe2'] = $pane;
    $display->panels['content_left'][0] = 'new-042dd59f-f0f3-4b42-b133-64441bcfbfe2';
    $pane = new stdClass();
    $pane->pid = 'new-0a933f43-184d-4d4f-b473-d15835af6afa';
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
    $pane->uuid = '0a933f43-184d-4d4f-b473-d15835af6afa';
    $display->content['new-0a933f43-184d-4d4f-b473-d15835af6afa'] = $pane;
    $display->panels['content_left'][1] = 'new-0a933f43-184d-4d4f-b473-d15835af6afa';
    $pane = new stdClass();
    $pane->pid = 'new-f410c33c-3c85-4f9a-9d09-025b7b216908';
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
    $pane->uuid = 'f410c33c-3c85-4f9a-9d09-025b7b216908';
    $display->content['new-f410c33c-3c85-4f9a-9d09-025b7b216908'] = $pane;
    $display->panels['content_left'][2] = 'new-f410c33c-3c85-4f9a-9d09-025b7b216908';
    $pane = new stdClass();
    $pane->pid = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
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
    $pane->uuid = '2f26c4fe-12ba-4de9-8117-2444d31b53b2';
    $display->content['new-2f26c4fe-12ba-4de9-8117-2444d31b53b2'] = $pane;
    $display->panels['top'][0] = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
    $pane = new stdClass();
    $pane->pid = 'new-40e6b8b8-c3dd-4567-9733-a5ff23f7f781';
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
    $pane->uuid = '40e6b8b8-c3dd-4567-9733-a5ff23f7f781';
    $display->content['new-40e6b8b8-c3dd-4567-9733-a5ff23f7f781'] = $pane;
    $display->panels['top'][1] = 'new-40e6b8b8-c3dd-4567-9733-a5ff23f7f781';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Photos',
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
              'photo_listing' => 'photo_listing',
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
  $display->layout = 'debut_content_2col_toped';
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
  $display->uuid = '460332ad-d8c9-4559-abbc-7980f990c7ed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ab60c5bc-585c-4ca8-b386-da2677d1a658';
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
    $pane->uuid = 'ab60c5bc-585c-4ca8-b386-da2677d1a658';
    $display->content['new-ab60c5bc-585c-4ca8-b386-da2677d1a658'] = $pane;
    $display->panels['content_center'][0] = 'new-ab60c5bc-585c-4ca8-b386-da2677d1a658';
    $pane = new stdClass();
    $pane->pid = 'new-8c3c013f-0fec-4535-a3fd-5a2bf1eaea86';
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
    $pane->uuid = '8c3c013f-0fec-4535-a3fd-5a2bf1eaea86';
    $display->content['new-8c3c013f-0fec-4535-a3fd-5a2bf1eaea86'] = $pane;
    $display->panels['content_left'][0] = 'new-8c3c013f-0fec-4535-a3fd-5a2bf1eaea86';
    $pane = new stdClass();
    $pane->pid = 'new-fbef4cf8-8f3d-45bc-bc49-b39e0470fe11';
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
    $pane->uuid = 'fbef4cf8-8f3d-45bc-bc49-b39e0470fe11';
    $display->content['new-fbef4cf8-8f3d-45bc-bc49-b39e0470fe11'] = $pane;
    $display->panels['content_left'][1] = 'new-fbef4cf8-8f3d-45bc-bc49-b39e0470fe11';
    $pane = new stdClass();
    $pane->pid = 'new-2a155b4b-0b0f-4034-8490-08e6f4bbc66e';
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
    $pane->uuid = '2a155b4b-0b0f-4034-8490-08e6f4bbc66e';
    $display->content['new-2a155b4b-0b0f-4034-8490-08e6f4bbc66e'] = $pane;
    $display->panels['content_left'][2] = 'new-2a155b4b-0b0f-4034-8490-08e6f4bbc66e';
    $pane = new stdClass();
    $pane->pid = 'new-04708dd8-846f-4c7e-95a0-b9ca8df9710a';
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
    $pane->uuid = '04708dd8-846f-4c7e-95a0-b9ca8df9710a';
    $display->content['new-04708dd8-846f-4c7e-95a0-b9ca8df9710a'] = $pane;
    $display->panels['top'][0] = 'new-04708dd8-846f-4c7e-95a0-b9ca8df9710a';
    $pane = new stdClass();
    $pane->pid = 'new-0c5f6c3e-3e02-4257-933e-5e7abcd16712';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 1,
      'custombc' => 'Фоторепортажи',
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
    $pane->uuid = '0c5f6c3e-3e02-4257-933e-5e7abcd16712';
    $display->content['new-0c5f6c3e-3e02-4257-933e-5e7abcd16712'] = $pane;
    $display->panels['top'][1] = 'new-0c5f6c3e-3e02-4257-933e-5e7abcd16712';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-04708dd8-846f-4c7e-95a0-b9ca8df9710a';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Books',
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
              'books' => 'books',
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
  $display->uuid = '48184bdb-c91d-4ff7-848c-faeb25b244c1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7cf890a0-e24e-402d-b392-4d8bf413735a';
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
    $pane->uuid = '7cf890a0-e24e-402d-b392-4d8bf413735a';
    $display->content['new-7cf890a0-e24e-402d-b392-4d8bf413735a'] = $pane;
    $display->panels['content_center'][0] = 'new-7cf890a0-e24e-402d-b392-4d8bf413735a';
    $pane = new stdClass();
    $pane->pid = 'new-69433cc0-61e3-4bbf-90a0-9e7724cc51f7';
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
    $pane->uuid = '69433cc0-61e3-4bbf-90a0-9e7724cc51f7';
    $display->content['new-69433cc0-61e3-4bbf-90a0-9e7724cc51f7'] = $pane;
    $display->panels['content_left'][0] = 'new-69433cc0-61e3-4bbf-90a0-9e7724cc51f7';
    $pane = new stdClass();
    $pane->pid = 'new-af9f7fb7-c6ad-493c-8f2c-0293b1239042';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Изменения на сайте',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'af9f7fb7-c6ad-493c-8f2c-0293b1239042';
    $display->content['new-af9f7fb7-c6ad-493c-8f2c-0293b1239042'] = $pane;
    $display->panels['content_left'][1] = 'new-af9f7fb7-c6ad-493c-8f2c-0293b1239042';
    $pane = new stdClass();
    $pane->pid = 'new-4ed9ce88-38f3-496c-9d9c-0c17b941ce39';
    $pane->panel = 'content_left';
    $pane->type = 'debut_common_contact_us';
    $pane->subtype = 'debut_common_contact_us';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Связаться с нами',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4ed9ce88-38f3-496c-9d9c-0c17b941ce39';
    $display->content['new-4ed9ce88-38f3-496c-9d9c-0c17b941ce39'] = $pane;
    $display->panels['content_left'][2] = 'new-4ed9ce88-38f3-496c-9d9c-0c17b941ce39';
    $pane = new stdClass();
    $pane->pid = 'new-0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Книги',
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
    $pane->uuid = '0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $display->content['new-0cce4376-2b36-48b0-b75f-9e54f1ca374f'] = $pane;
    $display->panels['top'][0] = 'new-0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $pane = new stdClass();
    $pane->pid = 'new-1c8a67be-a6e9-45a5-80bf-1ea2e7e17a54';
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
    $pane->uuid = '1c8a67be-a6e9-45a5-80bf-1ea2e7e17a54';
    $display->content['new-1c8a67be-a6e9-45a5-80bf-1ea2e7e17a54'] = $pane;
    $display->panels['top'][1] = 'new-1c8a67be-a6e9-45a5-80bf-1ea2e7e17a54';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_9'] = $handler;

  return $export;
}
