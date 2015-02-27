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
  $handler->weight = 2;
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
  $handler->weight = -2;
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
        1 => array(
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
    $pane->pid = 'new-b8b861c5-a8a3-46e4-a5e4-85dc493a8b19';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b8b861c5-a8a3-46e4-a5e4-85dc493a8b19';
    $display->content['new-b8b861c5-a8a3-46e4-a5e4-85dc493a8b19'] = $pane;
    $display->panels['content_right'][0] = 'new-b8b861c5-a8a3-46e4-a5e4-85dc493a8b19';
    $pane = new stdClass();
    $pane->pid = 'new-1dece7a3-5809-4c48-addb-fcf8047634b1';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1dece7a3-5809-4c48-addb-fcf8047634b1';
    $display->content['new-1dece7a3-5809-4c48-addb-fcf8047634b1'] = $pane;
    $display->panels['content_right'][1] = 'new-1dece7a3-5809-4c48-addb-fcf8047634b1';
    $pane = new stdClass();
    $pane->pid = 'new-61dab048-e130-4802-a560-442f67bdfdee';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '61dab048-e130-4802-a560-442f67bdfdee';
    $display->content['new-61dab048-e130-4802-a560-442f67bdfdee'] = $pane;
    $display->panels['content_right'][2] = 'new-61dab048-e130-4802-a560-442f67bdfdee';
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
  $handler->weight = -22;
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
        1 => array(
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
    $pane->pid = 'new-53532047-9b1f-46f0-a3b4-a2837fcf79aa';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '53532047-9b1f-46f0-a3b4-a2837fcf79aa';
    $display->content['new-53532047-9b1f-46f0-a3b4-a2837fcf79aa'] = $pane;
    $display->panels['content_right'][0] = 'new-53532047-9b1f-46f0-a3b4-a2837fcf79aa';
    $pane = new stdClass();
    $pane->pid = 'new-bfe5bee5-afe1-434f-a0d9-3048cb991e40';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bfe5bee5-afe1-434f-a0d9-3048cb991e40';
    $display->content['new-bfe5bee5-afe1-434f-a0d9-3048cb991e40'] = $pane;
    $display->panels['content_right'][1] = 'new-bfe5bee5-afe1-434f-a0d9-3048cb991e40';
    $pane = new stdClass();
    $pane->pid = 'new-eeba015c-d48c-4f9c-9393-ae2cb9b503f5';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'eeba015c-d48c-4f9c-9393-ae2cb9b503f5';
    $display->content['new-eeba015c-d48c-4f9c-9393-ae2cb9b503f5'] = $pane;
    $display->panels['content_right'][2] = 'new-eeba015c-d48c-4f9c-9393-ae2cb9b503f5';
    $pane = new stdClass();
    $pane->pid = 'new-c2db2674-8cbf-4df8-9388-f291f757d808';
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
  $handler->name = 'node_view_panel_context_11';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Nobel speech',
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
              'nobel_speech' => 'nobel_speech',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
  $display->uuid = 'f2d4db7d-2039-4e1a-be4c-9f09c1a17826';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9bc4df40-9687-4ce3-aca2-8d1df011ae42';
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
    $pane->uuid = '9bc4df40-9687-4ce3-aca2-8d1df011ae42';
    $display->content['new-9bc4df40-9687-4ce3-aca2-8d1df011ae42'] = $pane;
    $display->panels['content_center'][0] = 'new-9bc4df40-9687-4ce3-aca2-8d1df011ae42';
    $pane = new stdClass();
    $pane->pid = 'new-1d55fbe4-d008-4fb7-94b1-49b31cfe13d8';
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
    $pane->uuid = '1d55fbe4-d008-4fb7-94b1-49b31cfe13d8';
    $display->content['new-1d55fbe4-d008-4fb7-94b1-49b31cfe13d8'] = $pane;
    $display->panels['content_left'][0] = 'new-1d55fbe4-d008-4fb7-94b1-49b31cfe13d8';
    $pane = new stdClass();
    $pane->pid = 'new-84795d2b-59b7-4da4-98e0-cd50a8c44075';
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
    $pane->uuid = '84795d2b-59b7-4da4-98e0-cd50a8c44075';
    $display->content['new-84795d2b-59b7-4da4-98e0-cd50a8c44075'] = $pane;
    $display->panels['content_left'][1] = 'new-84795d2b-59b7-4da4-98e0-cd50a8c44075';
    $pane = new stdClass();
    $pane->pid = 'new-da1b5f48-8d00-45e4-89b1-445ba728fcf3';
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
    $pane->uuid = 'da1b5f48-8d00-45e4-89b1-445ba728fcf3';
    $display->content['new-da1b5f48-8d00-45e4-89b1-445ba728fcf3'] = $pane;
    $display->panels['content_left'][2] = 'new-da1b5f48-8d00-45e4-89b1-445ba728fcf3';
    $pane = new stdClass();
    $pane->pid = 'new-0d6c609c-3ba5-486c-9a28-413134e6b262';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0d6c609c-3ba5-486c-9a28-413134e6b262';
    $display->content['new-0d6c609c-3ba5-486c-9a28-413134e6b262'] = $pane;
    $display->panels['content_right'][0] = 'new-0d6c609c-3ba5-486c-9a28-413134e6b262';
    $pane = new stdClass();
    $pane->pid = 'new-880eba02-66ca-483c-9568-4fd79afa79a6';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '880eba02-66ca-483c-9568-4fd79afa79a6';
    $display->content['new-880eba02-66ca-483c-9568-4fd79afa79a6'] = $pane;
    $display->panels['content_right'][1] = 'new-880eba02-66ca-483c-9568-4fd79afa79a6';
    $pane = new stdClass();
    $pane->pid = 'new-6567b540-7f55-4fbf-a9e9-0ea2dda8bd4b';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6567b540-7f55-4fbf-a9e9-0ea2dda8bd4b';
    $display->content['new-6567b540-7f55-4fbf-a9e9-0ea2dda8bd4b'] = $pane;
    $display->panels['content_right'][2] = 'new-6567b540-7f55-4fbf-a9e9-0ea2dda8bd4b';
    $pane = new stdClass();
    $pane->pid = 'new-8838a2d4-f7c7-4d87-9073-017e5eab5147';
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
    $pane->uuid = '8838a2d4-f7c7-4d87-9073-017e5eab5147';
    $display->content['new-8838a2d4-f7c7-4d87-9073-017e5eab5147'] = $pane;
    $display->panels['top'][0] = 'new-8838a2d4-f7c7-4d87-9073-017e5eab5147';
    $pane = new stdClass();
    $pane->pid = 'new-7c3f0d27-05e7-477d-be85-7a9fbad0f3c8';
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
    $pane->uuid = '7c3f0d27-05e7-477d-be85-7a9fbad0f3c8';
    $display->content['new-7c3f0d27-05e7-477d-be85-7a9fbad0f3c8'] = $pane;
    $display->panels['top'][1] = 'new-7c3f0d27-05e7-477d-be85-7a9fbad0f3c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8838a2d4-f7c7-4d87-9073-017e5eab5147';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_11'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_12';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Prize person',
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
              'debut_prize_person' => 'debut_prize_person',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
      'content_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5acc253f-d508-4f43-a89f-cd4a7fa305b5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
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
    $pane->uuid = '4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
    $display->content['new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0'] = $pane;
    $display->panels['content_center'][0] = 'new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
    $pane = new stdClass();
    $pane->pid = 'new-1f77fdf4-fe84-4e8e-abba-c01089b5c3ab';
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
    $pane->uuid = '1f77fdf4-fe84-4e8e-abba-c01089b5c3ab';
    $display->content['new-1f77fdf4-fe84-4e8e-abba-c01089b5c3ab'] = $pane;
    $display->panels['content_left'][0] = 'new-1f77fdf4-fe84-4e8e-abba-c01089b5c3ab';
    $pane = new stdClass();
    $pane->pid = 'new-9561c475-d9bc-4efd-bb9c-f4bb5e7c2d22';
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
    $pane->uuid = '9561c475-d9bc-4efd-bb9c-f4bb5e7c2d22';
    $display->content['new-9561c475-d9bc-4efd-bb9c-f4bb5e7c2d22'] = $pane;
    $display->panels['content_left'][1] = 'new-9561c475-d9bc-4efd-bb9c-f4bb5e7c2d22';
    $pane = new stdClass();
    $pane->pid = 'new-34cdb9b8-62eb-45b4-9839-4e3da0cb1866';
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
    $pane->uuid = '34cdb9b8-62eb-45b4-9839-4e3da0cb1866';
    $display->content['new-34cdb9b8-62eb-45b4-9839-4e3da0cb1866'] = $pane;
    $display->panels['content_left'][2] = 'new-34cdb9b8-62eb-45b4-9839-4e3da0cb1866';
    $pane = new stdClass();
    $pane->pid = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
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
    $pane->uuid = '55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
    $display->content['new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9'] = $pane;
    $display->panels['top'][0] = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
    $pane = new stdClass();
    $pane->pid = 'new-2b524924-825c-4d73-85af-6a3f3327dc08';
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
    $pane->uuid = '2b524924-825c-4d73-85af-6a3f3327dc08';
    $display->content['new-2b524924-825c-4d73-85af-6a3f3327dc08'] = $pane;
    $display->panels['top'][1] = 'new-2b524924-825c-4d73-85af-6a3f3327dc08';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_12'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_13';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Jury person',
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
              'debut_jury' => 'debut_jury',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
  $display->uuid = '4df3b290-8048-4023-87f4-0e8df26751a5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-666e697c-166d-49b9-85e7-c94634556a45';
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
    $pane->uuid = '666e697c-166d-49b9-85e7-c94634556a45';
    $display->content['new-666e697c-166d-49b9-85e7-c94634556a45'] = $pane;
    $display->panels['content_center'][0] = 'new-666e697c-166d-49b9-85e7-c94634556a45';
    $pane = new stdClass();
    $pane->pid = 'new-12625741-20a3-49da-a60d-001adb429c99';
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
    $pane->uuid = '12625741-20a3-49da-a60d-001adb429c99';
    $display->content['new-12625741-20a3-49da-a60d-001adb429c99'] = $pane;
    $display->panels['content_left'][0] = 'new-12625741-20a3-49da-a60d-001adb429c99';
    $pane = new stdClass();
    $pane->pid = 'new-bb0369eb-0ecf-4d5f-80c4-4b84065aff60';
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
    $pane->uuid = 'bb0369eb-0ecf-4d5f-80c4-4b84065aff60';
    $display->content['new-bb0369eb-0ecf-4d5f-80c4-4b84065aff60'] = $pane;
    $display->panels['content_left'][1] = 'new-bb0369eb-0ecf-4d5f-80c4-4b84065aff60';
    $pane = new stdClass();
    $pane->pid = 'new-50f744d8-dbaf-42f4-b735-fe3486fa9ae8';
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
    $pane->uuid = '50f744d8-dbaf-42f4-b735-fe3486fa9ae8';
    $display->content['new-50f744d8-dbaf-42f4-b735-fe3486fa9ae8'] = $pane;
    $display->panels['content_left'][2] = 'new-50f744d8-dbaf-42f4-b735-fe3486fa9ae8';
    $pane = new stdClass();
    $pane->pid = 'new-435193e3-c203-4d14-9fc3-4bcb34a898d2';
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
    $pane->uuid = '435193e3-c203-4d14-9fc3-4bcb34a898d2';
    $display->content['new-435193e3-c203-4d14-9fc3-4bcb34a898d2'] = $pane;
    $display->panels['top'][0] = 'new-435193e3-c203-4d14-9fc3-4bcb34a898d2';
    $pane = new stdClass();
    $pane->pid = 'new-6e795251-640d-47a2-9da5-62493a333f3b';
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
    $pane->uuid = '6e795251-640d-47a2-9da5-62493a333f3b';
    $display->content['new-6e795251-640d-47a2-9da5-62493a333f3b'] = $pane;
    $display->panels['top'][1] = 'new-6e795251-640d-47a2-9da5-62493a333f3b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_13'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_14';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => '(Popup) Books',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/popup',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
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
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->uuid = '4dbc3e7c-0ee7-4984-9e77-6fb7df94970b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
    $pane->panel = 'content';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'popup',
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
    $pane->uuid = 'd973bf1d-b9a0-4981-affa-107e33fa45a6';
    $display->content['new-d973bf1d-b9a0-4981-affa-107e33fa45a6'] = $pane;
    $display->panels['content'][0] = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_14'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_15';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => '(Popup) iBooks',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/popup',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
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
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->uuid = '4dbc3e7c-0ee7-4984-9e77-6fb7df94970b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
    $pane->panel = 'content';
    $pane->type = 'cache_node_content';
    $pane->subtype = 'cache_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'build_mode' => 'popup',
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
    $pane->uuid = 'd973bf1d-b9a0-4981-affa-107e33fa45a6';
    $display->content['new-d973bf1d-b9a0-4981-affa-107e33fa45a6'] = $pane;
    $display->panels['content'][0] = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d973bf1d-b9a0-4981-affa-107e33fa45a6';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_15'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_16';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -10;
  $handler->conf = array(
    'title' => 'Master class section',
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
              'master_class' => 'master_class',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
  $display->uuid = '88878439-5a68-4620-a20d-509f0a85d26d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fa0a7c3f-48c8-4d25-8433-3eb393344678';
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
    $pane->uuid = 'fa0a7c3f-48c8-4d25-8433-3eb393344678';
    $display->content['new-fa0a7c3f-48c8-4d25-8433-3eb393344678'] = $pane;
    $display->panels['content_center'][0] = 'new-fa0a7c3f-48c8-4d25-8433-3eb393344678';
    $pane = new stdClass();
    $pane->pid = 'new-28b27b54-0817-4fac-b5dd-cd5d4f97fa39';
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
    $pane->uuid = '28b27b54-0817-4fac-b5dd-cd5d4f97fa39';
    $display->content['new-28b27b54-0817-4fac-b5dd-cd5d4f97fa39'] = $pane;
    $display->panels['content_left'][0] = 'new-28b27b54-0817-4fac-b5dd-cd5d4f97fa39';
    $pane = new stdClass();
    $pane->pid = 'new-d2c39647-00cf-4541-91ff-a02cb7b0c776';
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
    $pane->uuid = 'd2c39647-00cf-4541-91ff-a02cb7b0c776';
    $display->content['new-d2c39647-00cf-4541-91ff-a02cb7b0c776'] = $pane;
    $display->panels['content_left'][1] = 'new-d2c39647-00cf-4541-91ff-a02cb7b0c776';
    $pane = new stdClass();
    $pane->pid = 'new-2fdeb0ba-95bd-49bd-a31e-8f26c641342f';
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
    $pane->uuid = '2fdeb0ba-95bd-49bd-a31e-8f26c641342f';
    $display->content['new-2fdeb0ba-95bd-49bd-a31e-8f26c641342f'] = $pane;
    $display->panels['content_left'][2] = 'new-2fdeb0ba-95bd-49bd-a31e-8f26c641342f';
    $pane = new stdClass();
    $pane->pid = 'new-fe78b965-db81-4218-b5a9-a558702125f8';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fe78b965-db81-4218-b5a9-a558702125f8';
    $display->content['new-fe78b965-db81-4218-b5a9-a558702125f8'] = $pane;
    $display->panels['content_right'][0] = 'new-fe78b965-db81-4218-b5a9-a558702125f8';
    $pane = new stdClass();
    $pane->pid = 'new-a9973cf6-083c-4147-adeb-3a524e57834c';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a9973cf6-083c-4147-adeb-3a524e57834c';
    $display->content['new-a9973cf6-083c-4147-adeb-3a524e57834c'] = $pane;
    $display->panels['content_right'][1] = 'new-a9973cf6-083c-4147-adeb-3a524e57834c';
    $pane = new stdClass();
    $pane->pid = 'new-6bcb2411-6bda-4bdb-89ad-ea2fec51b842';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6bcb2411-6bda-4bdb-89ad-ea2fec51b842';
    $display->content['new-6bcb2411-6bda-4bdb-89ad-ea2fec51b842'] = $pane;
    $display->panels['content_right'][2] = 'new-6bcb2411-6bda-4bdb-89ad-ea2fec51b842';
    $pane = new stdClass();
    $pane->pid = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
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
    $pane->uuid = '39c2360a-de17-4ba0-911b-810c0efa7638';
    $display->content['new-39c2360a-de17-4ba0-911b-810c0efa7638'] = $pane;
    $display->panels['top'][0] = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
    $pane = new stdClass();
    $pane->pid = 'new-ff8ff9c4-5e95-45d5-bd5b-4dc4ed061aaa';
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
    $pane->uuid = 'ff8ff9c4-5e95-45d5-bd5b-4dc4ed061aaa';
    $display->content['new-ff8ff9c4-5e95-45d5-bd5b-4dc4ed061aaa'] = $pane;
    $display->panels['top'][1] = 'new-ff8ff9c4-5e95-45d5-bd5b-4dc4ed061aaa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_16'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_17';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Document (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane->panel = 'content';
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
    $display->panels['content'][0] = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content'][1] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-aa4d3ad3-87f4-49fb-aa88-7eb6afe0afa2';
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
    $pane->uuid = 'aa4d3ad3-87f4-49fb-aa88-7eb6afe0afa2';
    $display->content['new-aa4d3ad3-87f4-49fb-aa88-7eb6afe0afa2'] = $pane;
    $display->panels['content'][2] = 'new-aa4d3ad3-87f4-49fb-aa88-7eb6afe0afa2';
    $pane = new stdClass();
    $pane->pid = 'new-74104674-0141-45b2-8de4-5085a42dc3cf';
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
    $pane->uuid = '74104674-0141-45b2-8de4-5085a42dc3cf';
    $display->content['new-74104674-0141-45b2-8de4-5085a42dc3cf'] = $pane;
    $display->panels['content'][3] = 'new-74104674-0141-45b2-8de4-5085a42dc3cf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_17'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_18';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'News (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane->panel = 'content';
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
    $display->panels['content'][0] = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content'][1] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-06314309-c5b3-42e3-bc06-89533b026978';
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
    $pane->uuid = '06314309-c5b3-42e3-bc06-89533b026978';
    $display->content['new-06314309-c5b3-42e3-bc06-89533b026978'] = $pane;
    $display->panels['content'][2] = 'new-06314309-c5b3-42e3-bc06-89533b026978';
    $pane = new stdClass();
    $pane->pid = 'new-b0f45b32-c937-4430-b18c-e85e6dbf2196';
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
    $pane->uuid = 'b0f45b32-c937-4430-b18c-e85e6dbf2196';
    $display->content['new-b0f45b32-c937-4430-b18c-e85e6dbf2196'] = $pane;
    $display->panels['content'][3] = 'new-b0f45b32-c937-4430-b18c-e85e6dbf2196';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_18'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_19';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
  $handler->conf = array(
    'title' => 'Press about Debut (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane->panel = 'content';
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
    $display->panels['content'][0] = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content'][1] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-0aad50b0-234f-40cb-8422-1caa114e4b1b';
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
    $pane->uuid = '0aad50b0-234f-40cb-8422-1caa114e4b1b';
    $display->content['new-0aad50b0-234f-40cb-8422-1caa114e4b1b'] = $pane;
    $display->panels['content'][2] = 'new-0aad50b0-234f-40cb-8422-1caa114e4b1b';
    $pane = new stdClass();
    $pane->pid = 'new-8448e692-dfa0-4ae6-8463-9a6ed1ee745f';
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
    $pane->uuid = '8448e692-dfa0-4ae6-8463-9a6ed1ee745f';
    $display->content['new-8448e692-dfa0-4ae6-8463-9a6ed1ee745f'] = $pane;
    $display->panels['content'][3] = 'new-8448e692-dfa0-4ae6-8463-9a6ed1ee745f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_19'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
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
        1 => array(
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
    $pane->pid = 'new-d759f0ba-9c8a-4d76-8b00-1d9c37756971';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd759f0ba-9c8a-4d76-8b00-1d9c37756971';
    $display->content['new-d759f0ba-9c8a-4d76-8b00-1d9c37756971'] = $pane;
    $display->panels['content_right'][0] = 'new-d759f0ba-9c8a-4d76-8b00-1d9c37756971';
    $pane = new stdClass();
    $pane->pid = 'new-48427f4e-0581-44bb-89e1-1c29bfd65eab';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '48427f4e-0581-44bb-89e1-1c29bfd65eab';
    $display->content['new-48427f4e-0581-44bb-89e1-1c29bfd65eab'] = $pane;
    $display->panels['content_right'][1] = 'new-48427f4e-0581-44bb-89e1-1c29bfd65eab';
    $pane = new stdClass();
    $pane->pid = 'new-ad5c1d8e-aee0-4eec-ab41-d27a4f79f1a5';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ad5c1d8e-aee0-4eec-ab41-d27a4f79f1a5';
    $display->content['new-ad5c1d8e-aee0-4eec-ab41-d27a4f79f1a5'] = $pane;
    $display->panels['content_right'][2] = 'new-ad5c1d8e-aee0-4eec-ab41-d27a4f79f1a5';
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
  $handler->name = 'node_view_panel_context_20';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -8;
  $handler->conf = array(
    'title' => 'Interview',
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
              'interview' => 'interview',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
  $display->uuid = 'b7e2cf35-af85-43a3-938a-b3fcb7c2faa5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
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
    $pane->uuid = 'bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
    $display->content['new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30'] = $pane;
    $display->panels['content_center'][0] = 'new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
    $pane = new stdClass();
    $pane->pid = 'new-2459e204-432d-4bcb-b95f-1b7bce35a97a';
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
    $pane->uuid = '2459e204-432d-4bcb-b95f-1b7bce35a97a';
    $display->content['new-2459e204-432d-4bcb-b95f-1b7bce35a97a'] = $pane;
    $display->panels['content_left'][0] = 'new-2459e204-432d-4bcb-b95f-1b7bce35a97a';
    $pane = new stdClass();
    $pane->pid = 'new-0894114a-f10f-478a-86e2-3ccee9cfbf4f';
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
    $pane->uuid = '0894114a-f10f-478a-86e2-3ccee9cfbf4f';
    $display->content['new-0894114a-f10f-478a-86e2-3ccee9cfbf4f'] = $pane;
    $display->panels['content_left'][1] = 'new-0894114a-f10f-478a-86e2-3ccee9cfbf4f';
    $pane = new stdClass();
    $pane->pid = 'new-b2b962e4-2b2f-4ece-b885-c838ef3a0c67';
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
    $pane->uuid = 'b2b962e4-2b2f-4ece-b885-c838ef3a0c67';
    $display->content['new-b2b962e4-2b2f-4ece-b885-c838ef3a0c67'] = $pane;
    $display->panels['content_left'][2] = 'new-b2b962e4-2b2f-4ece-b885-c838ef3a0c67';
    $pane = new stdClass();
    $pane->pid = 'new-ba07487a-3d25-4eec-bbe5-a654f75b4d93';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ba07487a-3d25-4eec-bbe5-a654f75b4d93';
    $display->content['new-ba07487a-3d25-4eec-bbe5-a654f75b4d93'] = $pane;
    $display->panels['content_right'][0] = 'new-ba07487a-3d25-4eec-bbe5-a654f75b4d93';
    $pane = new stdClass();
    $pane->pid = 'new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
    $display->content['new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618'] = $pane;
    $display->panels['content_right'][1] = 'new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
    $pane = new stdClass();
    $pane->pid = 'new-9277d8d2-00ac-4331-aa3d-633c79c7ad22';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9277d8d2-00ac-4331-aa3d-633c79c7ad22';
    $display->content['new-9277d8d2-00ac-4331-aa3d-633c79c7ad22'] = $pane;
    $display->panels['content_right'][2] = 'new-9277d8d2-00ac-4331-aa3d-633c79c7ad22';
    $pane = new stdClass();
    $pane->pid = 'new-548a46e5-31b9-48ac-a670-98d3cefaddef';
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
    $pane->uuid = '548a46e5-31b9-48ac-a670-98d3cefaddef';
    $display->content['new-548a46e5-31b9-48ac-a670-98d3cefaddef'] = $pane;
    $display->panels['top'][0] = 'new-548a46e5-31b9-48ac-a670-98d3cefaddef';
    $pane = new stdClass();
    $pane->pid = 'new-0a066481-7569-46e8-ad09-c4ffb2bec9d8';
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
    $pane->uuid = '0a066481-7569-46e8-ad09-c4ffb2bec9d8';
    $display->content['new-0a066481-7569-46e8-ad09-c4ffb2bec9d8'] = $pane;
    $display->panels['top'][1] = 'new-0a066481-7569-46e8-ad09-c4ffb2bec9d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_20'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_21';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Jury person (mobile)',
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
              'debut_jury' => 'debut_jury',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b633cf41-8443-470a-99ea-71643c39258e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane->panel = 'content';
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
    $display->panels['content'][0] = 'new-2702e824-3285-4230-9a54-acfef533dd5a';
    $pane = new stdClass();
    $pane->pid = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $display->content['new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328'] = $pane;
    $display->panels['content'][1] = 'new-5fdcdaa3-b40f-4bca-aba0-b1e640bb4328';
    $pane = new stdClass();
    $pane->pid = 'new-9aea299a-b729-4aee-9f80-b70d648a14bc';
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
    $pane->uuid = '9aea299a-b729-4aee-9f80-b70d648a14bc';
    $display->content['new-9aea299a-b729-4aee-9f80-b70d648a14bc'] = $pane;
    $display->panels['content'][2] = 'new-9aea299a-b729-4aee-9f80-b70d648a14bc';
    $pane = new stdClass();
    $pane->pid = 'new-de98d339-c74a-4c22-b13e-ababb8186088';
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
    $pane->uuid = 'de98d339-c74a-4c22-b13e-ababb8186088';
    $display->content['new-de98d339-c74a-4c22-b13e-ababb8186088'] = $pane;
    $display->panels['content'][3] = 'new-de98d339-c74a-4c22-b13e-ababb8186088';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_21'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_22';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Nobel speech (mobile)',
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
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'nobel_speech' => 'nobel_speech',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
  $display->uuid = 'c7b134cd-8583-40ef-8e57-939148b3b303';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eca14877-ff3b-472b-b17f-a49ae01fbbaa';
    $pane->panel = 'content';
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
    $pane->uuid = 'eca14877-ff3b-472b-b17f-a49ae01fbbaa';
    $display->content['new-eca14877-ff3b-472b-b17f-a49ae01fbbaa'] = $pane;
    $display->panels['content'][0] = 'new-eca14877-ff3b-472b-b17f-a49ae01fbbaa';
    $pane = new stdClass();
    $pane->pid = 'new-db6eaabd-8f37-409a-9838-cc57cd58efc0';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'db6eaabd-8f37-409a-9838-cc57cd58efc0';
    $display->content['new-db6eaabd-8f37-409a-9838-cc57cd58efc0'] = $pane;
    $display->panels['content'][1] = 'new-db6eaabd-8f37-409a-9838-cc57cd58efc0';
    $pane = new stdClass();
    $pane->pid = 'new-d78e9efb-2816-4ae9-8991-d401bd4943f4';
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
    $pane->uuid = 'd78e9efb-2816-4ae9-8991-d401bd4943f4';
    $display->content['new-d78e9efb-2816-4ae9-8991-d401bd4943f4'] = $pane;
    $display->panels['content'][2] = 'new-d78e9efb-2816-4ae9-8991-d401bd4943f4';
    $pane = new stdClass();
    $pane->pid = 'new-84395c3e-9383-4bdb-91ed-23672e7efdbd';
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
    $pane->uuid = '84395c3e-9383-4bdb-91ed-23672e7efdbd';
    $display->content['new-84395c3e-9383-4bdb-91ed-23672e7efdbd'] = $pane;
    $display->panels['content'][3] = 'new-84395c3e-9383-4bdb-91ed-23672e7efdbd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-eca14877-ff3b-472b-b17f-a49ae01fbbaa';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_22'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_23';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -13;
  $handler->conf = array(
    'title' => 'Travel description (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ccf7fb06-6822-42f1-b377-2a785b05cbda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-998e75d8-8f84-4d0b-b224-bb38d5f84f80';
    $pane->panel = 'content';
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
    $pane->uuid = '998e75d8-8f84-4d0b-b224-bb38d5f84f80';
    $display->content['new-998e75d8-8f84-4d0b-b224-bb38d5f84f80'] = $pane;
    $display->panels['content'][0] = 'new-998e75d8-8f84-4d0b-b224-bb38d5f84f80';
    $pane = new stdClass();
    $pane->pid = 'new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $display->content['new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b'] = $pane;
    $display->panels['content'][1] = 'new-383b8fd9-d7c1-4cbe-96c6-744d404ce59b';
    $pane = new stdClass();
    $pane->pid = 'new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
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
    $pane->uuid = '8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
    $display->content['new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597'] = $pane;
    $display->panels['content'][2] = 'new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
    $pane = new stdClass();
    $pane->pid = 'new-22b3791d-72e3-4f08-8046-513379f4b85a';
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
    $pane->uuid = '22b3791d-72e3-4f08-8046-513379f4b85a';
    $display->content['new-22b3791d-72e3-4f08-8046-513379f4b85a'] = $pane;
    $display->panels['content'][3] = 'new-22b3791d-72e3-4f08-8046-513379f4b85a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_23'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_24';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -11;
  $handler->conf = array(
    'title' => 'Travels (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1168eb33-da88-489c-8ef6-9fce18d681ee';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8b6e6326-af5d-4483-972e-59697a9c2938';
    $pane->panel = 'content';
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
    $pane->uuid = '8b6e6326-af5d-4483-972e-59697a9c2938';
    $display->content['new-8b6e6326-af5d-4483-972e-59697a9c2938'] = $pane;
    $display->panels['content'][0] = 'new-8b6e6326-af5d-4483-972e-59697a9c2938';
    $pane = new stdClass();
    $pane->pid = 'new-f4525fa9-333c-4233-bb99-b95a5a75f784';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f4525fa9-333c-4233-bb99-b95a5a75f784';
    $display->content['new-f4525fa9-333c-4233-bb99-b95a5a75f784'] = $pane;
    $display->panels['content'][1] = 'new-f4525fa9-333c-4233-bb99-b95a5a75f784';
    $pane = new stdClass();
    $pane->pid = 'new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
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
    $pane->uuid = '1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
    $display->content['new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01'] = $pane;
    $display->panels['content'][2] = 'new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
    $pane = new stdClass();
    $pane->pid = 'new-2f4ad278-6e28-4f06-a08c-2e8029ca8316';
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
    $pane->uuid = '2f4ad278-6e28-4f06-a08c-2e8029ca8316';
    $display->content['new-2f4ad278-6e28-4f06-a08c-2e8029ca8316'] = $pane;
    $display->panels['content'][3] = 'new-2f4ad278-6e28-4f06-a08c-2e8029ca8316';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_24'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_25';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -7;
  $handler->conf = array(
    'title' => 'Interview (mobile)',
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
              'interview' => 'interview',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b7e2cf35-af85-43a3-938a-b3fcb7c2faa5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-548a46e5-31b9-48ac-a670-98d3cefaddef';
    $pane->panel = 'content';
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
    $pane->uuid = '548a46e5-31b9-48ac-a670-98d3cefaddef';
    $display->content['new-548a46e5-31b9-48ac-a670-98d3cefaddef'] = $pane;
    $display->panels['content'][0] = 'new-548a46e5-31b9-48ac-a670-98d3cefaddef';
    $pane = new stdClass();
    $pane->pid = 'new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
    $display->content['new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30'] = $pane;
    $display->panels['content'][1] = 'new-bacdff70-21ca-4ee8-936f-6d8b8fa7ed30';
    $pane = new stdClass();
    $pane->pid = 'new-ba07487a-3d25-4eec-bbe5-a654f75b4d93';
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
    $pane->uuid = 'ba07487a-3d25-4eec-bbe5-a654f75b4d93';
    $display->content['new-ba07487a-3d25-4eec-bbe5-a654f75b4d93'] = $pane;
    $display->panels['content'][2] = 'new-ba07487a-3d25-4eec-bbe5-a654f75b4d93';
    $pane = new stdClass();
    $pane->pid = 'new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
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
    $pane->uuid = '09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
    $display->content['new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618'] = $pane;
    $display->panels['content'][3] = 'new-09f1c03e-4d8a-4434-b487-dfb0cf3a9618';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_25'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_26';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -5;
  $handler->conf = array(
    'title' => 'Master class text (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '157a7850-e4b8-4f87-8045-48e572ba309f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
    $pane->panel = 'content';
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
    $pane->uuid = 'a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
    $display->content['new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d'] = $pane;
    $display->panels['content'][0] = 'new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
    $pane = new stdClass();
    $pane->pid = 'new-47b52023-0a90-46be-b65c-db95abc75c62';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '47b52023-0a90-46be-b65c-db95abc75c62';
    $display->content['new-47b52023-0a90-46be-b65c-db95abc75c62'] = $pane;
    $display->panels['content'][1] = 'new-47b52023-0a90-46be-b65c-db95abc75c62';
    $pane = new stdClass();
    $pane->pid = 'new-7eba6df9-896b-4a08-af5f-1922cf5ca801';
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
    $pane->uuid = '7eba6df9-896b-4a08-af5f-1922cf5ca801';
    $display->content['new-7eba6df9-896b-4a08-af5f-1922cf5ca801'] = $pane;
    $display->panels['content'][2] = 'new-7eba6df9-896b-4a08-af5f-1922cf5ca801';
    $pane = new stdClass();
    $pane->pid = 'new-2c8eae53-87f8-4284-afd6-b7842fa1713f';
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
    $pane->uuid = '2c8eae53-87f8-4284-afd6-b7842fa1713f';
    $display->content['new-2c8eae53-87f8-4284-afd6-b7842fa1713f'] = $pane;
    $display->panels['content'][3] = 'new-2c8eae53-87f8-4284-afd6-b7842fa1713f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_26'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_27';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -9;
  $handler->conf = array(
    'title' => 'Master class section (mobile)',
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
              'master_class' => 'master_class',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '88878439-5a68-4620-a20d-509f0a85d26d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
    $pane->panel = 'content';
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
    $pane->uuid = '39c2360a-de17-4ba0-911b-810c0efa7638';
    $display->content['new-39c2360a-de17-4ba0-911b-810c0efa7638'] = $pane;
    $display->panels['content'][0] = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
    $pane = new stdClass();
    $pane->pid = 'new-fa0a7c3f-48c8-4d25-8433-3eb393344678';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fa0a7c3f-48c8-4d25-8433-3eb393344678';
    $display->content['new-fa0a7c3f-48c8-4d25-8433-3eb393344678'] = $pane;
    $display->panels['content'][1] = 'new-fa0a7c3f-48c8-4d25-8433-3eb393344678';
    $pane = new stdClass();
    $pane->pid = 'new-fe78b965-db81-4218-b5a9-a558702125f8';
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
    $pane->uuid = 'fe78b965-db81-4218-b5a9-a558702125f8';
    $display->content['new-fe78b965-db81-4218-b5a9-a558702125f8'] = $pane;
    $display->panels['content'][2] = 'new-fe78b965-db81-4218-b5a9-a558702125f8';
    $pane = new stdClass();
    $pane->pid = 'new-a9973cf6-083c-4147-adeb-3a524e57834c';
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
    $pane->uuid = 'a9973cf6-083c-4147-adeb-3a524e57834c';
    $display->content['new-a9973cf6-083c-4147-adeb-3a524e57834c'] = $pane;
    $display->panels['content'][3] = 'new-a9973cf6-083c-4147-adeb-3a524e57834c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-39c2360a-de17-4ba0-911b-810c0efa7638';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_27'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_28';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Prize person (mobile)',
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
              'debut_prize_person' => 'debut_prize_person',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5acc253f-d508-4f43-a89f-cd4a7fa305b5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
    $pane->panel = 'content';
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
    $pane->uuid = '55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
    $display->content['new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9'] = $pane;
    $display->panels['content'][0] = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
    $pane = new stdClass();
    $pane->pid = 'new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
    $display->content['new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0'] = $pane;
    $display->panels['content'][1] = 'new-4ef0ec45-1ec9-42da-b092-603df1f0ffa0';
    $pane = new stdClass();
    $pane->pid = 'new-e6f2bdcb-8e54-4963-a6a1-608d378c6603';
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
    $pane->uuid = 'e6f2bdcb-8e54-4963-a6a1-608d378c6603';
    $display->content['new-e6f2bdcb-8e54-4963-a6a1-608d378c6603'] = $pane;
    $display->panels['content'][2] = 'new-e6f2bdcb-8e54-4963-a6a1-608d378c6603';
    $pane = new stdClass();
    $pane->pid = 'new-198daf72-20f0-4cb5-9235-b8bbcd481683';
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
    $pane->uuid = '198daf72-20f0-4cb5-9235-b8bbcd481683';
    $display->content['new-198daf72-20f0-4cb5-9235-b8bbcd481683'] = $pane;
    $display->panels['content'][3] = 'new-198daf72-20f0-4cb5-9235-b8bbcd481683';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-55b4e0b8-cfeb-49d5-8b46-affc8e1012b9';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_28'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_29';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -17;
  $handler->conf = array(
    'title' => 'Photos (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '460332ad-d8c9-4559-abbc-7980f990c7ed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0c5f6c3e-3e02-4257-933e-5e7abcd16712';
    $pane->panel = 'content';
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
    $pane->uuid = '0c5f6c3e-3e02-4257-933e-5e7abcd16712';
    $display->content['new-0c5f6c3e-3e02-4257-933e-5e7abcd16712'] = $pane;
    $display->panels['content'][0] = 'new-0c5f6c3e-3e02-4257-933e-5e7abcd16712';
    $pane = new stdClass();
    $pane->pid = 'new-ab60c5bc-585c-4ca8-b386-da2677d1a658';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ab60c5bc-585c-4ca8-b386-da2677d1a658';
    $display->content['new-ab60c5bc-585c-4ca8-b386-da2677d1a658'] = $pane;
    $display->panels['content'][1] = 'new-ab60c5bc-585c-4ca8-b386-da2677d1a658';
    $pane = new stdClass();
    $pane->pid = 'new-8f2acce6-7d34-4754-9e22-34d909319340';
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
    $pane->uuid = '8f2acce6-7d34-4754-9e22-34d909319340';
    $display->content['new-8f2acce6-7d34-4754-9e22-34d909319340'] = $pane;
    $display->panels['content'][2] = 'new-8f2acce6-7d34-4754-9e22-34d909319340';
    $pane = new stdClass();
    $pane->pid = 'new-2446bde1-bbb7-4fdc-8925-0ee6130c2d91';
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
    $pane->uuid = '2446bde1-bbb7-4fdc-8925-0ee6130c2d91';
    $display->content['new-2446bde1-bbb7-4fdc-8925-0ee6130c2d91'] = $pane;
    $display->panels['content'][3] = 'new-2446bde1-bbb7-4fdc-8925-0ee6130c2d91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_29'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -4;
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
        1 => array(
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
    $pane->pid = 'new-4de20bdc-75ed-4eb9-bf59-1f3bb908b5a7';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4de20bdc-75ed-4eb9-bf59-1f3bb908b5a7';
    $display->content['new-4de20bdc-75ed-4eb9-bf59-1f3bb908b5a7'] = $pane;
    $display->panels['content_right'][0] = 'new-4de20bdc-75ed-4eb9-bf59-1f3bb908b5a7';
    $pane = new stdClass();
    $pane->pid = 'new-68a7e152-9b5b-40b7-9036-9f2de69c80c6';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '68a7e152-9b5b-40b7-9036-9f2de69c80c6';
    $display->content['new-68a7e152-9b5b-40b7-9036-9f2de69c80c6'] = $pane;
    $display->panels['content_right'][1] = 'new-68a7e152-9b5b-40b7-9036-9f2de69c80c6';
    $pane = new stdClass();
    $pane->pid = 'new-6caa6731-6616-4c68-b6cd-fc3b023d64f5';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6caa6731-6616-4c68-b6cd-fc3b023d64f5';
    $display->content['new-6caa6731-6616-4c68-b6cd-fc3b023d64f5'] = $pane;
    $display->panels['content_right'][2] = 'new-6caa6731-6616-4c68-b6cd-fc3b023d64f5';
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
  $handler->name = 'node_view_panel_context_30';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -15;
  $handler->conf = array(
    'title' => 'Video (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '29dc1eb7-2de3-4296-9245-12b3d0aea5d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
    $pane->panel = 'content';
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
    $display->panels['content'][0] = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
    $pane = new stdClass();
    $pane->pid = 'new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
    $display->content['new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93'] = $pane;
    $display->panels['content'][1] = 'new-665aab50-606e-4dc2-b65c-bb8e8fdfcb93';
    $pane = new stdClass();
    $pane->pid = 'new-7977ee46-e479-45ee-8375-76e501ec01bf';
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
    $pane->uuid = '7977ee46-e479-45ee-8375-76e501ec01bf';
    $display->content['new-7977ee46-e479-45ee-8375-76e501ec01bf'] = $pane;
    $display->panels['content'][2] = 'new-7977ee46-e479-45ee-8375-76e501ec01bf';
    $pane = new stdClass();
    $pane->pid = 'new-44241359-a5e8-43d3-a397-0a5a052f019b';
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
    $pane->uuid = '44241359-a5e8-43d3-a397-0a5a052f019b';
    $display->content['new-44241359-a5e8-43d3-a397-0a5a052f019b'] = $pane;
    $display->panels['content'][3] = 'new-44241359-a5e8-43d3-a397-0a5a052f019b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2f26c4fe-12ba-4de9-8117-2444d31b53b2';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_30'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_31';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -19;
  $handler->conf = array(
    'title' => 'Books (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '48184bdb-c91d-4ff7-848c-faeb25b244c1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $pane->panel = 'content';
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
    $pane->uuid = '0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $display->content['new-0cce4376-2b36-48b0-b75f-9e54f1ca374f'] = $pane;
    $display->panels['content'][0] = 'new-0cce4376-2b36-48b0-b75f-9e54f1ca374f';
    $pane = new stdClass();
    $pane->pid = 'new-7cf890a0-e24e-402d-b392-4d8bf413735a';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7cf890a0-e24e-402d-b392-4d8bf413735a';
    $display->content['new-7cf890a0-e24e-402d-b392-4d8bf413735a'] = $pane;
    $display->panels['content'][1] = 'new-7cf890a0-e24e-402d-b392-4d8bf413735a';
    $pane = new stdClass();
    $pane->pid = 'new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
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
    $pane->uuid = '0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
    $display->content['new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c'] = $pane;
    $display->panels['content'][2] = 'new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
    $pane = new stdClass();
    $pane->pid = 'new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
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
    $pane->uuid = 'c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
    $display->content['new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61'] = $pane;
    $display->panels['content'][3] = 'new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_31'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_32';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -21;
  $handler->conf = array(
    'title' => 'iBooks (mobile)',
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
        1 => array(
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
      'content_right' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'df5178e7-2115-42b5-993d-1ea84f45e499';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c2db2674-8cbf-4df8-9388-f291f757d808';
    $pane->panel = 'content';
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
    $pane->uuid = 'c2db2674-8cbf-4df8-9388-f291f757d808';
    $display->content['new-c2db2674-8cbf-4df8-9388-f291f757d808'] = $pane;
    $display->panels['content'][0] = 'new-c2db2674-8cbf-4df8-9388-f291f757d808';
    $pane = new stdClass();
    $pane->pid = 'new-6698768e-414a-4057-859e-073a53c6b5d2';
    $pane->panel = 'content';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6698768e-414a-4057-859e-073a53c6b5d2';
    $display->content['new-6698768e-414a-4057-859e-073a53c6b5d2'] = $pane;
    $display->panels['content'][1] = 'new-6698768e-414a-4057-859e-073a53c6b5d2';
    $pane = new stdClass();
    $pane->pid = 'new-53532047-9b1f-46f0-a3b4-a2837fcf79aa';
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
    $pane->uuid = '53532047-9b1f-46f0-a3b4-a2837fcf79aa';
    $display->content['new-53532047-9b1f-46f0-a3b4-a2837fcf79aa'] = $pane;
    $display->panels['content'][2] = 'new-53532047-9b1f-46f0-a3b4-a2837fcf79aa';
    $pane = new stdClass();
    $pane->pid = 'new-bfe5bee5-afe1-434f-a0d9-3048cb991e40';
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
    $pane->uuid = 'bfe5bee5-afe1-434f-a0d9-3048cb991e40';
    $display->content['new-bfe5bee5-afe1-434f-a0d9-3048cb991e40'] = $pane;
    $display->panels['content'][3] = 'new-bfe5bee5-afe1-434f-a0d9-3048cb991e40';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_32'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -6;
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
        1 => array(
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
    $pane->pid = 'new-7eba6df9-896b-4a08-af5f-1922cf5ca801';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7eba6df9-896b-4a08-af5f-1922cf5ca801';
    $display->content['new-7eba6df9-896b-4a08-af5f-1922cf5ca801'] = $pane;
    $display->panels['content_right'][0] = 'new-7eba6df9-896b-4a08-af5f-1922cf5ca801';
    $pane = new stdClass();
    $pane->pid = 'new-2c8eae53-87f8-4284-afd6-b7842fa1713f';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2c8eae53-87f8-4284-afd6-b7842fa1713f';
    $display->content['new-2c8eae53-87f8-4284-afd6-b7842fa1713f'] = $pane;
    $display->panels['content_right'][1] = 'new-2c8eae53-87f8-4284-afd6-b7842fa1713f';
    $pane = new stdClass();
    $pane->pid = 'new-9da818c7-be29-4944-b5e3-39c805b5b39a';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9da818c7-be29-4944-b5e3-39c805b5b39a';
    $display->content['new-9da818c7-be29-4944-b5e3-39c805b5b39a'] = $pane;
    $display->panels['content_right'][2] = 'new-9da818c7-be29-4944-b5e3-39c805b5b39a';
    $pane = new stdClass();
    $pane->pid = 'new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
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
    $pane->uuid = 'a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
    $display->content['new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d'] = $pane;
    $display->panels['top'][0] = 'new-a11a287e-888a-4a0a-ba6f-9a129f7f1f6d';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4c7cbd9c-602c-4a22-bd69-473bccece2ed';
    $display->content['new-4c7cbd9c-602c-4a22-bd69-473bccece2ed'] = $pane;
    $display->panels['top'][1] = 'new-4c7cbd9c-602c-4a22-bd69-473bccece2ed';
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
  $handler->weight = -14;
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
        1 => array(
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
    $pane->pid = 'new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
    $display->content['new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597'] = $pane;
    $display->panels['content_right'][0] = 'new-8f2971a1-8c2c-49a5-ae37-60d2e3ab6597';
    $pane = new stdClass();
    $pane->pid = 'new-22b3791d-72e3-4f08-8046-513379f4b85a';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '22b3791d-72e3-4f08-8046-513379f4b85a';
    $display->content['new-22b3791d-72e3-4f08-8046-513379f4b85a'] = $pane;
    $display->panels['content_right'][1] = 'new-22b3791d-72e3-4f08-8046-513379f4b85a';
    $pane = new stdClass();
    $pane->pid = 'new-713d449d-9d22-402f-b564-0f878c610dee';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '713d449d-9d22-402f-b564-0f878c610dee';
    $display->content['new-713d449d-9d22-402f-b564-0f878c610dee'] = $pane;
    $display->panels['content_right'][2] = 'new-713d449d-9d22-402f-b564-0f878c610dee';
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
  $handler->weight = -12;
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
        1 => array(
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
    $pane->pid = 'new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
    $display->content['new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01'] = $pane;
    $display->panels['content_right'][0] = 'new-1f8d29d6-5363-4b91-a80e-5e1c156ebf01';
    $pane = new stdClass();
    $pane->pid = 'new-2f4ad278-6e28-4f06-a08c-2e8029ca8316';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2f4ad278-6e28-4f06-a08c-2e8029ca8316';
    $display->content['new-2f4ad278-6e28-4f06-a08c-2e8029ca8316'] = $pane;
    $display->panels['content_right'][1] = 'new-2f4ad278-6e28-4f06-a08c-2e8029ca8316';
    $pane = new stdClass();
    $pane->pid = 'new-bb1cfd0b-115d-44bd-917e-44c175243acc';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bb1cfd0b-115d-44bd-917e-44c175243acc';
    $display->content['new-bb1cfd0b-115d-44bd-917e-44c175243acc'] = $pane;
    $display->panels['content_right'][2] = 'new-bb1cfd0b-115d-44bd-917e-44c175243acc';
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
  $handler->weight = -16;
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
        1 => array(
          'name' => 'theme',
          'settings' => array(
            'theme' => 'debut',
          ),
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
    $pane->pid = 'new-7977ee46-e479-45ee-8375-76e501ec01bf';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7977ee46-e479-45ee-8375-76e501ec01bf';
    $display->content['new-7977ee46-e479-45ee-8375-76e501ec01bf'] = $pane;
    $display->panels['content_right'][0] = 'new-7977ee46-e479-45ee-8375-76e501ec01bf';
    $pane = new stdClass();
    $pane->pid = 'new-44241359-a5e8-43d3-a397-0a5a052f019b';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '44241359-a5e8-43d3-a397-0a5a052f019b';
    $display->content['new-44241359-a5e8-43d3-a397-0a5a052f019b'] = $pane;
    $display->panels['content_right'][1] = 'new-44241359-a5e8-43d3-a397-0a5a052f019b';
    $pane = new stdClass();
    $pane->pid = 'new-a8b185e4-2711-4245-a617-f1492c618eb3';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a8b185e4-2711-4245-a617-f1492c618eb3';
    $display->content['new-a8b185e4-2711-4245-a617-f1492c618eb3'] = $pane;
    $display->panels['content_right'][2] = 'new-a8b185e4-2711-4245-a617-f1492c618eb3';
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
  $handler->weight = -18;
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
        1 => array(
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
  $handler->weight = -20;
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
        1 => array(
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
    $pane->pid = 'new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_prize_jury';
    $pane->subtype = 'debut_common_prize_jury';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
    $display->content['new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c'] = $pane;
    $display->panels['content_right'][0] = 'new-0b25bdfd-ca21-4afc-9f83-279a8cd0960c';
    $pane = new stdClass();
    $pane->pid = 'new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
    $pane->panel = 'content_right';
    $pane->type = 'debut_blocks_prize_person';
    $pane->subtype = 'debut_blocks_prize_person';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
    $display->content['new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61'] = $pane;
    $display->panels['content_right'][1] = 'new-c918817b-e0ea-481f-bee0-ec4d4cc4fa61';
    $pane = new stdClass();
    $pane->pid = 'new-570312da-c00b-4df6-8d0f-30cdfec554fd';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '570312da-c00b-4df6-8d0f-30cdfec554fd';
    $display->content['new-570312da-c00b-4df6-8d0f-30cdfec554fd'] = $pane;
    $display->panels['content_right'][2] = 'new-570312da-c00b-4df6-8d0f-30cdfec554fd';
    $pane = new stdClass();
    $pane->pid = 'new-0cce4376-2b36-48b0-b75f-9e54f1ca374f';
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
