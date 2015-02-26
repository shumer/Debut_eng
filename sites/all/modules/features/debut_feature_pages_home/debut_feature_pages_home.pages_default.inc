<?php
/**
 * @file
 * debut_feature_pages_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Главная';
  $page->admin_description = '';
  $page->path = 'home';
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
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
  $display->uuid = '5361d65f-0bba-411a-9fd6-c96a229bf1d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2c397fcf-3263-4dab-b245-856b639a02d1';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_home_page_news';
    $pane->subtype = 'debut_common_home_page_news';
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
    $pane->uuid = '2c397fcf-3263-4dab-b245-856b639a02d1';
    $display->content['new-2c397fcf-3263-4dab-b245-856b639a02d1'] = $pane;
    $display->panels['content_center'][0] = 'new-2c397fcf-3263-4dab-b245-856b639a02d1';
    $pane = new stdClass();
    $pane->pid = 'new-eb1263bd-1f27-4b55-9d8b-64c03ced072f';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_home_page_books';
    $pane->subtype = 'debut_common_home_page_books';
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
    $pane->uuid = 'eb1263bd-1f27-4b55-9d8b-64c03ced072f';
    $display->content['new-eb1263bd-1f27-4b55-9d8b-64c03ced072f'] = $pane;
    $display->panels['content_center'][1] = 'new-eb1263bd-1f27-4b55-9d8b-64c03ced072f';
    $pane = new stdClass();
    $pane->pid = 'new-e8411dc4-d2f0-40fc-9491-ab1c53febf76';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_home_page_video';
    $pane->subtype = 'debut_common_home_page_video';
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
    $pane->uuid = 'e8411dc4-d2f0-40fc-9491-ab1c53febf76';
    $display->content['new-e8411dc4-d2f0-40fc-9491-ab1c53febf76'] = $pane;
    $display->panels['content_center'][2] = 'new-e8411dc4-d2f0-40fc-9491-ab1c53febf76';
    $pane = new stdClass();
    $pane->pid = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
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
    $pane->uuid = 'f1606c7d-a933-483e-8950-ac6baec77f29';
    $display->content['new-f1606c7d-a933-483e-8950-ac6baec77f29'] = $pane;
    $display->panels['content_left'][0] = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
    $pane = new stdClass();
    $pane->pid = 'new-127be3fc-6a62-4191-87e3-0c503b4c8c84';
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
    $pane->uuid = '127be3fc-6a62-4191-87e3-0c503b4c8c84';
    $display->content['new-127be3fc-6a62-4191-87e3-0c503b4c8c84'] = $pane;
    $display->panels['content_left'][1] = 'new-127be3fc-6a62-4191-87e3-0c503b4c8c84';
    $pane = new stdClass();
    $pane->pid = 'new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
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
    $pane->uuid = '070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
    $display->content['new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65'] = $pane;
    $display->panels['content_left'][2] = 'new-070b9d0e-d3c7-4878-ac76-b5e27a06ee65';
    $pane = new stdClass();
    $pane->pid = 'new-7ed86190-d384-42cc-a3d4-e52911605ccc';
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
    $pane->uuid = '7ed86190-d384-42cc-a3d4-e52911605ccc';
    $display->content['new-7ed86190-d384-42cc-a3d4-e52911605ccc'] = $pane;
    $display->panels['content_right'][0] = 'new-7ed86190-d384-42cc-a3d4-e52911605ccc';
    $pane = new stdClass();
    $pane->pid = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
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
    $pane->uuid = '71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $display->content['new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32'] = $pane;
    $display->panels['content_right'][1] = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $pane = new stdClass();
    $pane->pid = 'new-a3207211-1982-404c-86f1-fa939638f858';
    $pane->panel = 'content_right';
    $pane->type = 'debut_common_newsletter_block';
    $pane->subtype = 'debut_common_newsletter_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'newsletters' => '980',
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
    $pane->uuid = 'a3207211-1982-404c-86f1-fa939638f858';
    $display->content['new-a3207211-1982-404c-86f1-fa939638f858'] = $pane;
    $display->panels['content_right'][2] = 'new-a3207211-1982-404c-86f1-fa939638f858';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f1606c7d-a933-483e-8950-ac6baec77f29';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'home';
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
  $display->uuid = '5361d65f-0bba-411a-9fd6-c96a229bf1d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bbadc74b-f65c-4698-985f-1d35c7177f90';
    $pane->panel = 'content';
    $pane->type = 'debut_common_home_page_news';
    $pane->subtype = 'debut_common_home_page_news';
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
    $pane->uuid = 'bbadc74b-f65c-4698-985f-1d35c7177f90';
    $display->content['new-bbadc74b-f65c-4698-985f-1d35c7177f90'] = $pane;
    $display->panels['content'][0] = 'new-bbadc74b-f65c-4698-985f-1d35c7177f90';
    $pane = new stdClass();
    $pane->pid = 'new-68e6cd68-c776-41c8-b4e7-71946dca7f8e';
    $pane->panel = 'content';
    $pane->type = 'debut_common_home_page_books';
    $pane->subtype = 'debut_common_home_page_books';
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
    $pane->uuid = '68e6cd68-c776-41c8-b4e7-71946dca7f8e';
    $display->content['new-68e6cd68-c776-41c8-b4e7-71946dca7f8e'] = $pane;
    $display->panels['content'][1] = 'new-68e6cd68-c776-41c8-b4e7-71946dca7f8e';
    $pane = new stdClass();
    $pane->pid = 'new-bd353912-7a51-413f-942e-d4fc6c3e817a';
    $pane->panel = 'content';
    $pane->type = 'debut_common_home_page_video';
    $pane->subtype = 'debut_common_home_page_video';
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
    $pane->uuid = 'bd353912-7a51-413f-942e-d4fc6c3e817a';
    $display->content['new-bd353912-7a51-413f-942e-d4fc6c3e817a'] = $pane;
    $display->panels['content'][2] = 'new-bd353912-7a51-413f-942e-d4fc6c3e817a';
    $pane = new stdClass();
    $pane->pid = 'new-7ed86190-d384-42cc-a3d4-e52911605ccc';
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
    $pane->uuid = '7ed86190-d384-42cc-a3d4-e52911605ccc';
    $display->content['new-7ed86190-d384-42cc-a3d4-e52911605ccc'] = $pane;
    $display->panels['content'][3] = 'new-7ed86190-d384-42cc-a3d4-e52911605ccc';
    $pane = new stdClass();
    $pane->pid = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
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
    $pane->uuid = '71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
    $display->content['new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32'] = $pane;
    $display->panels['content'][4] = 'new-71db6479-0a82-40ab-aa4f-ff3ad7a72c32';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
