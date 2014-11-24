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
  $handler->weight = 0;
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
    $pane->pid = 'new-daeacc5b-e258-4e77-9454-a54121a77fdd';
    $pane->panel = 'top';
    $pane->type = 'debut-common-breadcrumb';
    $pane->subtype = 'debut-common-breadcrumb';
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
    $pane->uuid = 'daeacc5b-e258-4e77-9454-a54121a77fdd';
    $display->content['new-daeacc5b-e258-4e77-9454-a54121a77fdd'] = $pane;
    $display->panels['top'][0] = 'new-daeacc5b-e258-4e77-9454-a54121a77fdd';
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
  $handler->weight = 1;
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
    $pane->pid = 'new-daeacc5b-e258-4e77-9454-a54121a77fdd';
    $pane->panel = 'top';
    $pane->type = 'debut-common-breadcrumb';
    $pane->subtype = 'debut-common-breadcrumb';
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
    $pane->uuid = 'daeacc5b-e258-4e77-9454-a54121a77fdd';
    $display->content['new-daeacc5b-e258-4e77-9454-a54121a77fdd'] = $pane;
    $display->panels['top'][0] = 'new-daeacc5b-e258-4e77-9454-a54121a77fdd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
