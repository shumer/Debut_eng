<?php
/**
 * @file
 * debut_feature_pages_send_manuscript.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_send_manuscript_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'send_manuscript';
  $page->task = 'page';
  $page->admin_title = 'Send manuscript';
  $page->admin_description = '';
  $page->path = 'send_manuscript';
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
  $handler->name = 'page_send_manuscript_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'send_manuscript';
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
  $display->uuid = '2bd4efa0-57c9-4507-9650-7dbd81c51a87';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'ОТПРАВИТЬ РУКОПИСЬ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $display->content['new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59'] = $pane;
    $display->panels['content_center'][0] = 'new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $pane = new stdClass();
    $pane->pid = 'new-25616515-ed1b-486d-bf61-63eae7018e25';
    $pane->panel = 'content_center';
    $pane->type = 'content';
    $pane->subtype = 'content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'bundle' => 'manuscript_page',
      'view_mode' => 'full',
      'override_title' => 1,
      'override_title_text' => 'ОТПРАВИТЬ РУКОПИСЬ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '25616515-ed1b-486d-bf61-63eae7018e25';
    $display->content['new-25616515-ed1b-486d-bf61-63eae7018e25'] = $pane;
    $display->panels['content_center'][1] = 'new-25616515-ed1b-486d-bf61-63eae7018e25';
    $pane = new stdClass();
    $pane->pid = 'new-40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_send_manuscript';
    $pane->subtype = 'debut_common_send_manuscript';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $display->content['new-40075f3d-506b-4ad7-ae86-c5b057ea8bad'] = $pane;
    $display->panels['content_center'][2] = 'new-40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $pane = new stdClass();
    $pane->pid = 'new-43e45705-a380-47dc-ab2d-b8379ef70f0e';
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
    $pane->uuid = '43e45705-a380-47dc-ab2d-b8379ef70f0e';
    $display->content['new-43e45705-a380-47dc-ab2d-b8379ef70f0e'] = $pane;
    $display->panels['content_left'][0] = 'new-43e45705-a380-47dc-ab2d-b8379ef70f0e';
    $pane = new stdClass();
    $pane->pid = 'new-ea5d8f3a-2fe9-419b-a645-5c566d77f291';
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
    $pane->uuid = 'ea5d8f3a-2fe9-419b-a645-5c566d77f291';
    $display->content['new-ea5d8f3a-2fe9-419b-a645-5c566d77f291'] = $pane;
    $display->panels['content_left'][1] = 'new-ea5d8f3a-2fe9-419b-a645-5c566d77f291';
    $pane = new stdClass();
    $pane->pid = 'new-f0b0b877-1e14-4de2-bd0a-7b1913154557';
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
    $pane->uuid = 'f0b0b877-1e14-4de2-bd0a-7b1913154557';
    $display->content['new-f0b0b877-1e14-4de2-bd0a-7b1913154557'] = $pane;
    $display->panels['content_right'][0] = 'new-f0b0b877-1e14-4de2-bd0a-7b1913154557';
    $pane = new stdClass();
    $pane->pid = 'new-6f610ece-4e8a-4f5f-ae55-51098647dc91';
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
    $pane->uuid = '6f610ece-4e8a-4f5f-ae55-51098647dc91';
    $display->content['new-6f610ece-4e8a-4f5f-ae55-51098647dc91'] = $pane;
    $display->panels['content_right'][1] = 'new-6f610ece-4e8a-4f5f-ae55-51098647dc91';
    $pane = new stdClass();
    $pane->pid = 'new-51591403-3b5e-4d77-8c1c-c967de15e0ad';
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
    $pane->uuid = '51591403-3b5e-4d77-8c1c-c967de15e0ad';
    $display->content['new-51591403-3b5e-4d77-8c1c-c967de15e0ad'] = $pane;
    $display->panels['content_right'][2] = 'new-51591403-3b5e-4d77-8c1c-c967de15e0ad';
    $pane = new stdClass();
    $pane->pid = 'new-084e22cc-ba5c-4944-a2e8-6c2530501429';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Отправить рукопись',
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
    $pane->uuid = '084e22cc-ba5c-4944-a2e8-6c2530501429';
    $display->content['new-084e22cc-ba5c-4944-a2e8-6c2530501429'] = $pane;
    $display->panels['top'][0] = 'new-084e22cc-ba5c-4944-a2e8-6c2530501429';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_send_manuscript_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'send_manuscript';
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
  $display->uuid = '2bd4efa0-57c9-4507-9650-7dbd81c51a87';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ee1baac4-ca0e-4c6f-9fad-3ee02fac8bce';
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
    $pane->uuid = 'ee1baac4-ca0e-4c6f-9fad-3ee02fac8bce';
    $display->content['new-ee1baac4-ca0e-4c6f-9fad-3ee02fac8bce'] = $pane;
    $display->panels['content'][0] = 'new-ee1baac4-ca0e-4c6f-9fad-3ee02fac8bce';
    $pane = new stdClass();
    $pane->pid = 'new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'ОТПРАВИТЬ РУКОПИСЬ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $display->content['new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59'] = $pane;
    $display->panels['content'][1] = 'new-00bad0ef-252e-4a17-8559-cb6cb6a4aa59';
    $pane = new stdClass();
    $pane->pid = 'new-25616515-ed1b-486d-bf61-63eae7018e25';
    $pane->panel = 'content';
    $pane->type = 'content';
    $pane->subtype = 'content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'bundle' => 'manuscript_page',
      'view_mode' => 'full',
      'override_title' => 1,
      'override_title_text' => 'ОТПРАВИТЬ РУКОПИСЬ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '25616515-ed1b-486d-bf61-63eae7018e25';
    $display->content['new-25616515-ed1b-486d-bf61-63eae7018e25'] = $pane;
    $display->panels['content'][2] = 'new-25616515-ed1b-486d-bf61-63eae7018e25';
    $pane = new stdClass();
    $pane->pid = 'new-40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $pane->panel = 'content';
    $pane->type = 'debut_common_send_manuscript';
    $pane->subtype = 'debut_common_send_manuscript';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $display->content['new-40075f3d-506b-4ad7-ae86-c5b057ea8bad'] = $pane;
    $display->panels['content'][3] = 'new-40075f3d-506b-4ad7-ae86-c5b057ea8bad';
    $pane = new stdClass();
    $pane->pid = 'new-f0b0b877-1e14-4de2-bd0a-7b1913154557';
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
    $pane->uuid = 'f0b0b877-1e14-4de2-bd0a-7b1913154557';
    $display->content['new-f0b0b877-1e14-4de2-bd0a-7b1913154557'] = $pane;
    $display->panels['content'][4] = 'new-f0b0b877-1e14-4de2-bd0a-7b1913154557';
    $pane = new stdClass();
    $pane->pid = 'new-6f610ece-4e8a-4f5f-ae55-51098647dc91';
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
    $pane->uuid = '6f610ece-4e8a-4f5f-ae55-51098647dc91';
    $display->content['new-6f610ece-4e8a-4f5f-ae55-51098647dc91'] = $pane;
    $display->panels['content'][5] = 'new-6f610ece-4e8a-4f5f-ae55-51098647dc91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['send_manuscript'] = $page;

  return $pages;

}
