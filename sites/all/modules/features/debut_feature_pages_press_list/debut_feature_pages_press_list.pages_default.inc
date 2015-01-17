<?php
/**
 * @file
 * debut_feature_pages_press_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_press_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'press_list';
  $page->task = 'page';
  $page->admin_title = 'Пресса о премии';
  $page->admin_description = '';
  $page->path = 'press_list';
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
  $handler->name = 'page_press_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'press_list';
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
  $display->uuid = 'ac7b031d-20f0-4dd5-b1b2-f51cc69c3d3e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cc97951d-2288-4b50-944e-44bedbed50ca';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Пресса о премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cc97951d-2288-4b50-944e-44bedbed50ca';
    $display->content['new-cc97951d-2288-4b50-944e-44bedbed50ca'] = $pane;
    $display->panels['content_center'][0] = 'new-cc97951d-2288-4b50-944e-44bedbed50ca';
    $pane = new stdClass();
    $pane->pid = 'new-452c78d8-549d-46fd-81d2-bac9882734fa';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_press_about_debut',
      'pre_text' => '',
      'post_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '452c78d8-549d-46fd-81d2-bac9882734fa';
    $display->content['new-452c78d8-549d-46fd-81d2-bac9882734fa'] = $pane;
    $display->panels['content_center'][1] = 'new-452c78d8-549d-46fd-81d2-bac9882734fa';
    $pane = new stdClass();
    $pane->pid = 'new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_press_listing';
    $pane->subtype = 'debut_common_press_listing';
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
    $pane->uuid = 'cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $display->content['new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0'] = $pane;
    $display->panels['content_center'][2] = 'new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $pane = new stdClass();
    $pane->pid = 'new-24283e60-7423-41ce-b61d-285df88ab5ce';
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
    $pane->uuid = '24283e60-7423-41ce-b61d-285df88ab5ce';
    $display->content['new-24283e60-7423-41ce-b61d-285df88ab5ce'] = $pane;
    $display->panels['content_left'][0] = 'new-24283e60-7423-41ce-b61d-285df88ab5ce';
    $pane = new stdClass();
    $pane->pid = 'new-25d42bfe-8dde-4155-ac3a-1c1c63947eb3';
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
    $pane->uuid = '25d42bfe-8dde-4155-ac3a-1c1c63947eb3';
    $display->content['new-25d42bfe-8dde-4155-ac3a-1c1c63947eb3'] = $pane;
    $display->panels['content_left'][1] = 'new-25d42bfe-8dde-4155-ac3a-1c1c63947eb3';
    $pane = new stdClass();
    $pane->pid = 'new-b3dcd4a6-0362-4565-b6b7-a119b636bc9d';
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
    $pane->uuid = 'b3dcd4a6-0362-4565-b6b7-a119b636bc9d';
    $display->content['new-b3dcd4a6-0362-4565-b6b7-a119b636bc9d'] = $pane;
    $display->panels['content_left'][2] = 'new-b3dcd4a6-0362-4565-b6b7-a119b636bc9d';
    $pane = new stdClass();
    $pane->pid = 'new-37eca829-1809-4168-a452-63c294b1a73d';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '37eca829-1809-4168-a452-63c294b1a73d';
    $display->content['new-37eca829-1809-4168-a452-63c294b1a73d'] = $pane;
    $display->panels['top'][0] = 'new-37eca829-1809-4168-a452-63c294b1a73d';
    $pane = new stdClass();
    $pane->pid = 'new-a2aec159-a555-4600-9615-6cb1e23322c9';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Пресса о премии',
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
    $pane->uuid = 'a2aec159-a555-4600-9615-6cb1e23322c9';
    $display->content['new-a2aec159-a555-4600-9615-6cb1e23322c9'] = $pane;
    $display->panels['top'][1] = 'new-a2aec159-a555-4600-9615-6cb1e23322c9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_press_list_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'press_list';
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
  $display->uuid = 'ac7b031d-20f0-4dd5-b1b2-f51cc69c3d3e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a2aec159-a555-4600-9615-6cb1e23322c9';
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
    $pane->uuid = 'a2aec159-a555-4600-9615-6cb1e23322c9';
    $display->content['new-a2aec159-a555-4600-9615-6cb1e23322c9'] = $pane;
    $display->panels['content'][0] = 'new-a2aec159-a555-4600-9615-6cb1e23322c9';
    $pane = new stdClass();
    $pane->pid = 'new-cc97951d-2288-4b50-944e-44bedbed50ca';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_header';
    $pane->subtype = 'debut_common_years_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => 'Пресса о премии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cc97951d-2288-4b50-944e-44bedbed50ca';
    $display->content['new-cc97951d-2288-4b50-944e-44bedbed50ca'] = $pane;
    $display->panels['content'][1] = 'new-cc97951d-2288-4b50-944e-44bedbed50ca';
    $pane = new stdClass();
    $pane->pid = 'new-452c78d8-549d-46fd-81d2-bac9882734fa';
    $pane->panel = 'content';
    $pane->type = 'debut_common_years_list';
    $pane->subtype = 'debut_common_years_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'debut_view_list_press_about_debut',
      'pre_text' => '',
      'post_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '452c78d8-549d-46fd-81d2-bac9882734fa';
    $display->content['new-452c78d8-549d-46fd-81d2-bac9882734fa'] = $pane;
    $display->panels['content'][2] = 'new-452c78d8-549d-46fd-81d2-bac9882734fa';
    $pane = new stdClass();
    $pane->pid = 'new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $pane->panel = 'content';
    $pane->type = 'debut_common_press_listing';
    $pane->subtype = 'debut_common_press_listing';
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
    $pane->uuid = 'cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $display->content['new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0'] = $pane;
    $display->panels['content'][3] = 'new-cbf2d8d5-084c-436e-bab0-8c98bd5767b0';
    $pane = new stdClass();
    $pane->pid = 'new-a4860171-8469-42a6-8f0d-02ec4b6efad6';
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
    $pane->uuid = 'a4860171-8469-42a6-8f0d-02ec4b6efad6';
    $display->content['new-a4860171-8469-42a6-8f0d-02ec4b6efad6'] = $pane;
    $display->panels['content'][4] = 'new-a4860171-8469-42a6-8f0d-02ec4b6efad6';
    $pane = new stdClass();
    $pane->pid = 'new-2c430161-78e5-4067-8c86-65cf476c324f';
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
    $pane->uuid = '2c430161-78e5-4067-8c86-65cf476c324f';
    $display->content['new-2c430161-78e5-4067-8c86-65cf476c324f'] = $pane;
    $display->panels['content'][5] = 'new-2c430161-78e5-4067-8c86-65cf476c324f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['press_list'] = $page;

  return $pages;

}
