<?php
/**
 * @file
 * debut_feature_pages_prize_jury.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_prize_jury_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'prize_jury';
  $page->task = 'page';
  $page->admin_title = 'Жюри премии';
  $page->admin_description = '';
  $page->path = 'prize_jury';
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
  $handler->name = 'page_prize_jury_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'prize_jury';
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
  $display->uuid = 'b3aafc48-cc8b-406e-8838-a36bfa053bcd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Жюри премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $display->content['new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5'] = $pane;
    $display->panels['content_center'][0] = 'new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $pane = new stdClass();
    $pane->pid = 'new-e0939e98-dfa4-4381-88b5-7359ea46129b';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
      'page' => 'jury_list',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e0939e98-dfa4-4381-88b5-7359ea46129b';
    $display->content['new-e0939e98-dfa4-4381-88b5-7359ea46129b'] = $pane;
    $display->panels['content_center'][1] = 'new-e0939e98-dfa4-4381-88b5-7359ea46129b';
    $pane = new stdClass();
    $pane->pid = 'new-76553901-c19a-4529-87c4-bd7dacaf6387';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_jury_years_list';
    $pane->subtype = 'debut_common_jury_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'voc' => '5',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '76553901-c19a-4529-87c4-bd7dacaf6387';
    $display->content['new-76553901-c19a-4529-87c4-bd7dacaf6387'] = $pane;
    $display->panels['content_center'][2] = 'new-76553901-c19a-4529-87c4-bd7dacaf6387';
    $pane = new stdClass();
    $pane->pid = 'new-62623494-c6c4-42bc-b97e-f081303d832f';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_jury_list';
    $pane->subtype = 'debut_common_jury_list';
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
    $pane->uuid = '62623494-c6c4-42bc-b97e-f081303d832f';
    $display->content['new-62623494-c6c4-42bc-b97e-f081303d832f'] = $pane;
    $display->panels['content_center'][3] = 'new-62623494-c6c4-42bc-b97e-f081303d832f';
    $pane = new stdClass();
    $pane->pid = 'new-f18abd22-5a21-4581-b9df-86221bc61c11';
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
    $pane->uuid = 'f18abd22-5a21-4581-b9df-86221bc61c11';
    $display->content['new-f18abd22-5a21-4581-b9df-86221bc61c11'] = $pane;
    $display->panels['content_left'][0] = 'new-f18abd22-5a21-4581-b9df-86221bc61c11';
    $pane = new stdClass();
    $pane->pid = 'new-4829f5ba-623b-4b08-a1df-e96e4a69cabb';
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
    $pane->uuid = '4829f5ba-623b-4b08-a1df-e96e4a69cabb';
    $display->content['new-4829f5ba-623b-4b08-a1df-e96e4a69cabb'] = $pane;
    $display->panels['content_left'][1] = 'new-4829f5ba-623b-4b08-a1df-e96e4a69cabb';
    $pane = new stdClass();
    $pane->pid = 'new-4204ea79-8c7b-4582-af7c-eac7b27151ee';
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
    $pane->uuid = '4204ea79-8c7b-4582-af7c-eac7b27151ee';
    $display->content['new-4204ea79-8c7b-4582-af7c-eac7b27151ee'] = $pane;
    $display->panels['content_left'][2] = 'new-4204ea79-8c7b-4582-af7c-eac7b27151ee';
    $pane = new stdClass();
    $pane->pid = 'new-e0099688-ca32-4e77-9bc2-dc3cb388b823';
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
    $pane->uuid = 'e0099688-ca32-4e77-9bc2-dc3cb388b823';
    $display->content['new-e0099688-ca32-4e77-9bc2-dc3cb388b823'] = $pane;
    $display->panels['content_right'][0] = 'new-e0099688-ca32-4e77-9bc2-dc3cb388b823';
    $pane = new stdClass();
    $pane->pid = 'new-2570f16e-30eb-4a7a-a387-f2b46adb1148';
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
    $pane->uuid = '2570f16e-30eb-4a7a-a387-f2b46adb1148';
    $display->content['new-2570f16e-30eb-4a7a-a387-f2b46adb1148'] = $pane;
    $display->panels['content_right'][1] = 'new-2570f16e-30eb-4a7a-a387-f2b46adb1148';
    $pane = new stdClass();
    $pane->pid = 'new-3320a2d6-e6af-467b-b3a5-a434cc53ef8e';
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
    $pane->uuid = '3320a2d6-e6af-467b-b3a5-a434cc53ef8e';
    $display->content['new-3320a2d6-e6af-467b-b3a5-a434cc53ef8e'] = $pane;
    $display->panels['content_right'][2] = 'new-3320a2d6-e6af-467b-b3a5-a434cc53ef8e';
    $pane = new stdClass();
    $pane->pid = 'new-b034f0fd-b857-4e06-9a64-3704e65c5726';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Жюри премии|@arg0|1
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
    $pane->uuid = 'b034f0fd-b857-4e06-9a64-3704e65c5726';
    $display->content['new-b034f0fd-b857-4e06-9a64-3704e65c5726'] = $pane;
    $display->panels['top'][0] = 'new-b034f0fd-b857-4e06-9a64-3704e65c5726';
    $pane = new stdClass();
    $pane->pid = 'new-f7c125e5-03b7-4b9c-82a9-c4d0ba74d00c';
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
    $pane->uuid = 'f7c125e5-03b7-4b9c-82a9-c4d0ba74d00c';
    $display->content['new-f7c125e5-03b7-4b9c-82a9-c4d0ba74d00c'] = $pane;
    $display->panels['top'][1] = 'new-f7c125e5-03b7-4b9c-82a9-c4d0ba74d00c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_prize_jury_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'prize_jury';
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
  $display->uuid = 'b3aafc48-cc8b-406e-8838-a36bfa053bcd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b034f0fd-b857-4e06-9a64-3704e65c5726';
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
    $pane->uuid = 'b034f0fd-b857-4e06-9a64-3704e65c5726';
    $display->content['new-b034f0fd-b857-4e06-9a64-3704e65c5726'] = $pane;
    $display->panels['content'][0] = 'new-b034f0fd-b857-4e06-9a64-3704e65c5726';
    $pane = new stdClass();
    $pane->pid = 'new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Жюри премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $display->content['new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5'] = $pane;
    $display->panels['content'][1] = 'new-0c6bd498-0e0c-4fee-ab3f-d2f8dda1dfd5';
    $pane = new stdClass();
    $pane->pid = 'new-e0939e98-dfa4-4381-88b5-7359ea46129b';
    $pane->panel = 'content';
    $pane->type = 'debut_common_alphabet_header';
    $pane->subtype = 'debut_common_alphabet_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'alphabet' => '2',
      'page' => 'jury_list',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e0939e98-dfa4-4381-88b5-7359ea46129b';
    $display->content['new-e0939e98-dfa4-4381-88b5-7359ea46129b'] = $pane;
    $display->panels['content'][2] = 'new-e0939e98-dfa4-4381-88b5-7359ea46129b';
    $pane = new stdClass();
    $pane->pid = 'new-76553901-c19a-4529-87c4-bd7dacaf6387';
    $pane->panel = 'content';
    $pane->type = 'debut_common_jury_years_list';
    $pane->subtype = 'debut_common_jury_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'voc' => '5',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '76553901-c19a-4529-87c4-bd7dacaf6387';
    $display->content['new-76553901-c19a-4529-87c4-bd7dacaf6387'] = $pane;
    $display->panels['content'][3] = 'new-76553901-c19a-4529-87c4-bd7dacaf6387';
    $pane = new stdClass();
    $pane->pid = 'new-62623494-c6c4-42bc-b97e-f081303d832f';
    $pane->panel = 'content';
    $pane->type = 'debut_common_jury_list';
    $pane->subtype = 'debut_common_jury_list';
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
    $pane->uuid = '62623494-c6c4-42bc-b97e-f081303d832f';
    $display->content['new-62623494-c6c4-42bc-b97e-f081303d832f'] = $pane;
    $display->panels['content'][4] = 'new-62623494-c6c4-42bc-b97e-f081303d832f';
    $pane = new stdClass();
    $pane->pid = 'new-e0099688-ca32-4e77-9bc2-dc3cb388b823';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e0099688-ca32-4e77-9bc2-dc3cb388b823';
    $display->content['new-e0099688-ca32-4e77-9bc2-dc3cb388b823'] = $pane;
    $display->panels['content'][5] = 'new-e0099688-ca32-4e77-9bc2-dc3cb388b823';
    $pane = new stdClass();
    $pane->pid = 'new-2570f16e-30eb-4a7a-a387-f2b46adb1148';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '2570f16e-30eb-4a7a-a387-f2b46adb1148';
    $display->content['new-2570f16e-30eb-4a7a-a387-f2b46adb1148'] = $pane;
    $display->panels['content'][6] = 'new-2570f16e-30eb-4a7a-a387-f2b46adb1148';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['prize_jury'] = $page;

  return $pages;

}
