<?php
/**
 * @file
 * debut_feature_pages_photo_listing.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_photo_listing_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'photo_listing';
  $page->task = 'page';
  $page->admin_title = 'Фоторепортажи';
  $page->admin_description = '';
  $page->path = 'photo_listing';
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
  $handler->name = 'page_photo_listing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'photo_listing';
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
  $display->layout = 'debut_content_2col_toped';
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
  $display->uuid = '20b01d75-d479-4d1f-b8a0-7599a06d2a00';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_photo_listing';
    $pane->subtype = 'debut_common_photo_listing';
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
    $pane->uuid = '65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $display->content['new-65038aef-c4ad-46e7-92de-d43f4880e0a9'] = $pane;
    $display->panels['content_center'][0] = 'new-65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $pane = new stdClass();
    $pane->pid = 'new-b0c7534c-b1da-4925-8d8d-3a1416f15888';
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
    $pane->uuid = 'b0c7534c-b1da-4925-8d8d-3a1416f15888';
    $display->content['new-b0c7534c-b1da-4925-8d8d-3a1416f15888'] = $pane;
    $display->panels['content_left'][0] = 'new-b0c7534c-b1da-4925-8d8d-3a1416f15888';
    $pane = new stdClass();
    $pane->pid = 'new-665b861e-baa3-4afd-8a53-df023674ea5e';
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
    $pane->uuid = '665b861e-baa3-4afd-8a53-df023674ea5e';
    $display->content['new-665b861e-baa3-4afd-8a53-df023674ea5e'] = $pane;
    $display->panels['content_left'][1] = 'new-665b861e-baa3-4afd-8a53-df023674ea5e';
    $pane = new stdClass();
    $pane->pid = 'new-a3df1d7a-df53-4823-9897-5285e3836469';
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
    $pane->uuid = 'a3df1d7a-df53-4823-9897-5285e3836469';
    $display->content['new-a3df1d7a-df53-4823-9897-5285e3836469'] = $pane;
    $display->panels['content_left'][2] = 'new-a3df1d7a-df53-4823-9897-5285e3836469';
    $pane = new stdClass();
    $pane->pid = 'new-491c47c9-9631-4bad-8380-a37acd7cd98e';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Фоторепортажи',
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
    $pane->uuid = '491c47c9-9631-4bad-8380-a37acd7cd98e';
    $display->content['new-491c47c9-9631-4bad-8380-a37acd7cd98e'] = $pane;
    $display->panels['top'][0] = 'new-491c47c9-9631-4bad-8380-a37acd7cd98e';
    $pane = new stdClass();
    $pane->pid = 'new-a99437f7-2ff4-4c07-b967-6fce7adec3b7';
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
    $pane->uuid = 'a99437f7-2ff4-4c07-b967-6fce7adec3b7';
    $display->content['new-a99437f7-2ff4-4c07-b967-6fce7adec3b7'] = $pane;
    $display->panels['top'][1] = 'new-a99437f7-2ff4-4c07-b967-6fce7adec3b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_photo_listing_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'photo_listing';
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
  $display->uuid = '20b01d75-d479-4d1f-b8a0-7599a06d2a00';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-491c47c9-9631-4bad-8380-a37acd7cd98e';
    $pane->panel = 'content';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Фоторепортажи',
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
    $pane->uuid = '491c47c9-9631-4bad-8380-a37acd7cd98e';
    $display->content['new-491c47c9-9631-4bad-8380-a37acd7cd98e'] = $pane;
    $display->panels['content'][0] = 'new-491c47c9-9631-4bad-8380-a37acd7cd98e';
    $pane = new stdClass();
    $pane->pid = 'new-65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $pane->panel = 'content';
    $pane->type = 'debut_common_photo_listing';
    $pane->subtype = 'debut_common_photo_listing';
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
    $pane->uuid = '65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $display->content['new-65038aef-c4ad-46e7-92de-d43f4880e0a9'] = $pane;
    $display->panels['content'][1] = 'new-65038aef-c4ad-46e7-92de-d43f4880e0a9';
    $pane = new stdClass();
    $pane->pid = 'new-41cfde4b-7df7-4c7d-bba4-f6eb923d0995';
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
    $pane->uuid = '41cfde4b-7df7-4c7d-bba4-f6eb923d0995';
    $display->content['new-41cfde4b-7df7-4c7d-bba4-f6eb923d0995'] = $pane;
    $display->panels['content'][2] = 'new-41cfde4b-7df7-4c7d-bba4-f6eb923d0995';
    $pane = new stdClass();
    $pane->pid = 'new-28131526-3e0b-492f-b236-77f544576057';
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
    $pane->uuid = '28131526-3e0b-492f-b236-77f544576057';
    $display->content['new-28131526-3e0b-492f-b236-77f544576057'] = $pane;
    $display->panels['content'][3] = 'new-28131526-3e0b-492f-b236-77f544576057';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['photo_listing'] = $page;

  return $pages;

}
