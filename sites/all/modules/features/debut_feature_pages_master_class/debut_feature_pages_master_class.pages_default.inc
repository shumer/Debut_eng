<?php
/**
 * @file
 * debut_feature_pages_master_class.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_master_class_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'master_class';
  $page->task = 'page';
  $page->admin_title = 'Мастер классы';
  $page->admin_description = '';
  $page->path = 'master_class';
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
  $handler->name = 'page_master_class_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'master_class';
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
  $display->uuid = 'af99141a-1722-4d79-93c5-1c5ce83afe89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-119fbddc-972d-4202-bf20-7545d5255d6c';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Мастер-классы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '119fbddc-972d-4202-bf20-7545d5255d6c';
    $display->content['new-119fbddc-972d-4202-bf20-7545d5255d6c'] = $pane;
    $display->panels['content_center'][0] = 'new-119fbddc-972d-4202-bf20-7545d5255d6c';
    $pane = new stdClass();
    $pane->pid = 'new-49d048fd-0296-4e80-9375-286308a46c94';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_master_class_list';
    $pane->subtype = 'debut_common_master_class_list';
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
    $pane->uuid = '49d048fd-0296-4e80-9375-286308a46c94';
    $display->content['new-49d048fd-0296-4e80-9375-286308a46c94'] = $pane;
    $display->panels['content_center'][1] = 'new-49d048fd-0296-4e80-9375-286308a46c94';
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
    $pane->pid = 'new-694eeb30-ea46-4c49-80af-218824828209';
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
    $pane->uuid = '694eeb30-ea46-4c49-80af-218824828209';
    $display->content['new-694eeb30-ea46-4c49-80af-218824828209'] = $pane;
    $display->panels['content_right'][0] = 'new-694eeb30-ea46-4c49-80af-218824828209';
    $pane = new stdClass();
    $pane->pid = 'new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
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
    $pane->uuid = '23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
    $display->content['new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb'] = $pane;
    $display->panels['content_right'][1] = 'new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
    $pane = new stdClass();
    $pane->pid = 'new-12c41e78-522c-442f-93e0-50791d69c155';
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
    $pane->uuid = '12c41e78-522c-442f-93e0-50791d69c155';
    $display->content['new-12c41e78-522c-442f-93e0-50791d69c155'] = $pane;
    $display->panels['content_right'][2] = 'new-12c41e78-522c-442f-93e0-50791d69c155';
    $pane = new stdClass();
    $pane->pid = 'new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Мастер-классы',
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
    $pane->uuid = 'd89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
    $display->content['new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5'] = $pane;
    $display->panels['top'][0] = 'new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
    $pane = new stdClass();
    $pane->pid = 'new-0bdf978b-ed82-4926-b733-ef4ce697d4b4';
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
    $pane->uuid = '0bdf978b-ed82-4926-b733-ef4ce697d4b4';
    $display->content['new-0bdf978b-ed82-4926-b733-ef4ce697d4b4'] = $pane;
    $display->panels['top'][1] = 'new-0bdf978b-ed82-4926-b733-ef4ce697d4b4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_master_class_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'master_class';
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
  $display->uuid = 'af99141a-1722-4d79-93c5-1c5ce83afe89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
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
    $pane->uuid = 'd89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
    $display->content['new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5'] = $pane;
    $display->panels['content'][0] = 'new-d89d0b9b-e9ef-41c2-87d2-97882c0e47a5';
    $pane = new stdClass();
    $pane->pid = 'new-119fbddc-972d-4202-bf20-7545d5255d6c';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Мастер-классы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '119fbddc-972d-4202-bf20-7545d5255d6c';
    $display->content['new-119fbddc-972d-4202-bf20-7545d5255d6c'] = $pane;
    $display->panels['content'][1] = 'new-119fbddc-972d-4202-bf20-7545d5255d6c';
    $pane = new stdClass();
    $pane->pid = 'new-49d048fd-0296-4e80-9375-286308a46c94';
    $pane->panel = 'content';
    $pane->type = 'debut_common_master_class_list';
    $pane->subtype = 'debut_common_master_class_list';
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
    $pane->uuid = '49d048fd-0296-4e80-9375-286308a46c94';
    $display->content['new-49d048fd-0296-4e80-9375-286308a46c94'] = $pane;
    $display->panels['content'][2] = 'new-49d048fd-0296-4e80-9375-286308a46c94';
    $pane = new stdClass();
    $pane->pid = 'new-694eeb30-ea46-4c49-80af-218824828209';
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
    $pane->uuid = '694eeb30-ea46-4c49-80af-218824828209';
    $display->content['new-694eeb30-ea46-4c49-80af-218824828209'] = $pane;
    $display->panels['content'][3] = 'new-694eeb30-ea46-4c49-80af-218824828209';
    $pane = new stdClass();
    $pane->pid = 'new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
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
    $pane->uuid = '23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
    $display->content['new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb'] = $pane;
    $display->panels['content'][4] = 'new-23d63ed1-b324-4dba-b4f9-9b1cefeb08fb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['master_class'] = $page;

  return $pages;

}
