<?php
/**
 * @file
 * debut_feature_pages_persons_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_persons_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'persons_list';
  $page->task = 'page';
  $page->admin_title = 'Лица премии (алфавит)';
  $page->admin_description = '';
  $page->path = 'persons_list/%letter';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'letter' => array(
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
  $handler->name = 'page_persons_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'persons_list';
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
  $display->uuid = '4734bfe4-dc9f-4870-ad4a-63cfdeeeb1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Лица премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5de18652-48df-43d8-92d3-d4475ce74273';
    $display->content['new-5de18652-48df-43d8-92d3-d4475ce74273'] = $pane;
    $display->panels['content_center'][0] = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane = new stdClass();
    $pane->pid = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
      'page' => 'persons_list',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $display->content['new-c7dd38d9-d0c7-4833-ab66-2c26669115fe'] = $pane;
    $display->panels['content_center'][1] = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane = new stdClass();
    $pane->pid = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_persons_list';
    $pane->subtype = 'debut_common_persons_list';
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
    $pane->uuid = '2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $display->content['new-2bbd93a8-288b-48ca-8dff-146d0f610f09'] = $pane;
    $display->panels['content_center'][2] = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane = new stdClass();
    $pane->pid = 'new-ebc73712-f85d-4713-88ed-2f03625974f8';
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
    $pane->uuid = 'ebc73712-f85d-4713-88ed-2f03625974f8';
    $display->content['new-ebc73712-f85d-4713-88ed-2f03625974f8'] = $pane;
    $display->panels['content_left'][0] = 'new-ebc73712-f85d-4713-88ed-2f03625974f8';
    $pane = new stdClass();
    $pane->pid = 'new-e6d64dbf-9fef-46a1-b2e1-771de4f91751';
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
    $pane->uuid = 'e6d64dbf-9fef-46a1-b2e1-771de4f91751';
    $display->content['new-e6d64dbf-9fef-46a1-b2e1-771de4f91751'] = $pane;
    $display->panels['content_left'][1] = 'new-e6d64dbf-9fef-46a1-b2e1-771de4f91751';
    $pane = new stdClass();
    $pane->pid = 'new-b1c085a5-3708-4c02-938c-68d028cd10c1';
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
    $pane->uuid = 'b1c085a5-3708-4c02-938c-68d028cd10c1';
    $display->content['new-b1c085a5-3708-4c02-938c-68d028cd10c1'] = $pane;
    $display->panels['content_left'][2] = 'new-b1c085a5-3708-4c02-938c-68d028cd10c1';
    $pane = new stdClass();
    $pane->pid = 'new-06c47802-12e1-45e3-8aea-0746834b9e49';
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
    $pane->uuid = '06c47802-12e1-45e3-8aea-0746834b9e49';
    $display->content['new-06c47802-12e1-45e3-8aea-0746834b9e49'] = $pane;
    $display->panels['content_right'][0] = 'new-06c47802-12e1-45e3-8aea-0746834b9e49';
    $pane = new stdClass();
    $pane->pid = 'new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
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
    $pane->uuid = '151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
    $display->content['new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b'] = $pane;
    $display->panels['content_right'][1] = 'new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
    $pane = new stdClass();
    $pane->pid = 'new-39160305-6aab-4f7c-8bf0-89dcbe32bd0d';
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
    $pane->uuid = '39160305-6aab-4f7c-8bf0-89dcbe32bd0d';
    $display->content['new-39160305-6aab-4f7c-8bf0-89dcbe32bd0d'] = $pane;
    $display->panels['content_right'][2] = 'new-39160305-6aab-4f7c-8bf0-89dcbe32bd0d';
    $pane = new stdClass();
    $pane->pid = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Лица премии|prize_persons|1
@arg1',
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
    $pane->uuid = 'a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $display->content['new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6'] = $pane;
    $display->panels['top'][0] = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $pane = new stdClass();
    $pane->pid = 'new-0556a126-e5ce-4a68-b557-9508ab5c151b';
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
    $pane->uuid = '0556a126-e5ce-4a68-b557-9508ab5c151b';
    $display->content['new-0556a126-e5ce-4a68-b557-9508ab5c151b'] = $pane;
    $display->panels['top'][1] = 'new-0556a126-e5ce-4a68-b557-9508ab5c151b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_persons_list_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'persons_list';
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
  $display->uuid = '4734bfe4-dc9f-4870-ad4a-63cfdeeeb1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
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
    $pane->uuid = 'a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $display->content['new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6'] = $pane;
    $display->panels['content'][0] = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
    $pane = new stdClass();
    $pane->pid = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Лица премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5de18652-48df-43d8-92d3-d4475ce74273';
    $display->content['new-5de18652-48df-43d8-92d3-d4475ce74273'] = $pane;
    $display->panels['content'][1] = 'new-5de18652-48df-43d8-92d3-d4475ce74273';
    $pane = new stdClass();
    $pane->pid = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane->panel = 'content';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
      'page' => 'persons_list',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $display->content['new-c7dd38d9-d0c7-4833-ab66-2c26669115fe'] = $pane;
    $display->panels['content'][2] = 'new-c7dd38d9-d0c7-4833-ab66-2c26669115fe';
    $pane = new stdClass();
    $pane->pid = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane->panel = 'content';
    $pane->type = 'debut_common_persons_list';
    $pane->subtype = 'debut_common_persons_list';
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
    $pane->uuid = '2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $display->content['new-2bbd93a8-288b-48ca-8dff-146d0f610f09'] = $pane;
    $display->panels['content'][3] = 'new-2bbd93a8-288b-48ca-8dff-146d0f610f09';
    $pane = new stdClass();
    $pane->pid = 'new-06c47802-12e1-45e3-8aea-0746834b9e49';
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
    $pane->uuid = '06c47802-12e1-45e3-8aea-0746834b9e49';
    $display->content['new-06c47802-12e1-45e3-8aea-0746834b9e49'] = $pane;
    $display->panels['content'][4] = 'new-06c47802-12e1-45e3-8aea-0746834b9e49';
    $pane = new stdClass();
    $pane->pid = 'new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
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
    $pane->uuid = '151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
    $display->content['new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b'] = $pane;
    $display->panels['content'][5] = 'new-151c07fe-5d4b-48c3-ad1b-bc5ab0f27a4b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a8dce88f-e5f8-4835-a08a-46ed2fbfbea6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['persons_list'] = $page;

  return $pages;

}
