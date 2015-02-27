<?php
/**
 * @file
 * debut_feature_pages_jury_alphabet_list.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_jury_alphabet_list_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'jury_list';
  $page->task = 'page';
  $page->admin_title = 'Жюри премии (алфавит)';
  $page->admin_description = 'Вывод списка жюри по первой букве фамилии.';
  $page->path = 'jury_list/%letter';
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
  $handler->name = 'page_jury_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'jury_list';
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
  $display->uuid = '13390323-3aa1-4602-be34-7724993ca9b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4768a5ba-3b48-4e31-bb28-f60df46c3f45';
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
    $pane->uuid = '4768a5ba-3b48-4e31-bb28-f60df46c3f45';
    $display->content['new-4768a5ba-3b48-4e31-bb28-f60df46c3f45'] = $pane;
    $display->panels['content_center'][0] = 'new-4768a5ba-3b48-4e31-bb28-f60df46c3f45';
    $pane = new stdClass();
    $pane->pid = 'new-4fd1ee70-3fa0-4308-a417-1f3239bf2397';
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
    $pane->uuid = '4fd1ee70-3fa0-4308-a417-1f3239bf2397';
    $display->content['new-4fd1ee70-3fa0-4308-a417-1f3239bf2397'] = $pane;
    $display->panels['content_center'][1] = 'new-4fd1ee70-3fa0-4308-a417-1f3239bf2397';
    $pane = new stdClass();
    $pane->pid = 'new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $pane->panel = 'content_center';
    $pane->type = 'debut_common_jury_alphabet_list';
    $pane->subtype = 'debut_common_jury_alphabet_list';
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
    $pane->uuid = '1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $display->content['new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f'] = $pane;
    $display->panels['content_center'][2] = 'new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $pane = new stdClass();
    $pane->pid = 'new-4d373374-c425-4619-9644-712d2f8180a3';
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
    $pane->uuid = '4d373374-c425-4619-9644-712d2f8180a3';
    $display->content['new-4d373374-c425-4619-9644-712d2f8180a3'] = $pane;
    $display->panels['content_left'][0] = 'new-4d373374-c425-4619-9644-712d2f8180a3';
    $pane = new stdClass();
    $pane->pid = 'new-7dd0e02d-4897-46e8-9dbb-4964e84b15a6';
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
    $pane->uuid = '7dd0e02d-4897-46e8-9dbb-4964e84b15a6';
    $display->content['new-7dd0e02d-4897-46e8-9dbb-4964e84b15a6'] = $pane;
    $display->panels['content_left'][1] = 'new-7dd0e02d-4897-46e8-9dbb-4964e84b15a6';
    $pane = new stdClass();
    $pane->pid = 'new-a3216c8b-47da-4af5-a550-86eb3aace59c';
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
    $pane->uuid = 'a3216c8b-47da-4af5-a550-86eb3aace59c';
    $display->content['new-a3216c8b-47da-4af5-a550-86eb3aace59c'] = $pane;
    $display->panels['content_left'][2] = 'new-a3216c8b-47da-4af5-a550-86eb3aace59c';
    $pane = new stdClass();
    $pane->pid = 'new-292241b1-d65b-4107-a09b-1d5d397bcf71';
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
    $pane->uuid = '292241b1-d65b-4107-a09b-1d5d397bcf71';
    $display->content['new-292241b1-d65b-4107-a09b-1d5d397bcf71'] = $pane;
    $display->panels['content_right'][0] = 'new-292241b1-d65b-4107-a09b-1d5d397bcf71';
    $pane = new stdClass();
    $pane->pid = 'new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
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
    $pane->uuid = 'e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
    $display->content['new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476'] = $pane;
    $display->panels['content_right'][1] = 'new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
    $pane = new stdClass();
    $pane->pid = 'new-5bceed7e-93dc-42da-85a1-45059d13602d';
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
    $pane->uuid = '5bceed7e-93dc-42da-85a1-45059d13602d';
    $display->content['new-5bceed7e-93dc-42da-85a1-45059d13602d'] = $pane;
    $display->panels['content_right'][2] = 'new-5bceed7e-93dc-42da-85a1-45059d13602d';
    $pane = new stdClass();
    $pane->pid = 'new-2b97e152-bb89-4126-a203-e4e932cdceba';
    $pane->panel = 'top';
    $pane->type = 'debut_common_breadcrumb';
    $pane->subtype = 'debut_common_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'extend' => 0,
      'custombc' => 'Жюри премии|prize_jury|1
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
    $pane->uuid = '2b97e152-bb89-4126-a203-e4e932cdceba';
    $display->content['new-2b97e152-bb89-4126-a203-e4e932cdceba'] = $pane;
    $display->panels['top'][0] = 'new-2b97e152-bb89-4126-a203-e4e932cdceba';
    $pane = new stdClass();
    $pane->pid = 'new-41dcd181-5ccc-44df-8a08-6e2eb8f75560';
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
    $pane->uuid = '41dcd181-5ccc-44df-8a08-6e2eb8f75560';
    $display->content['new-41dcd181-5ccc-44df-8a08-6e2eb8f75560'] = $pane;
    $display->panels['top'][1] = 'new-41dcd181-5ccc-44df-8a08-6e2eb8f75560';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d373374-c425-4619-9644-712d2f8180a3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_jury_list_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'jury_list';
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
  $display->uuid = '13390323-3aa1-4602-be34-7724993ca9b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2b97e152-bb89-4126-a203-e4e932cdceba';
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
    $pane->uuid = '2b97e152-bb89-4126-a203-e4e932cdceba';
    $display->content['new-2b97e152-bb89-4126-a203-e4e932cdceba'] = $pane;
    $display->panels['content'][0] = 'new-2b97e152-bb89-4126-a203-e4e932cdceba';
    $pane = new stdClass();
    $pane->pid = 'new-4768a5ba-3b48-4e31-bb28-f60df46c3f45';
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
    $pane->uuid = '4768a5ba-3b48-4e31-bb28-f60df46c3f45';
    $display->content['new-4768a5ba-3b48-4e31-bb28-f60df46c3f45'] = $pane;
    $display->panels['content'][1] = 'new-4768a5ba-3b48-4e31-bb28-f60df46c3f45';
    $pane = new stdClass();
    $pane->pid = 'new-4fd1ee70-3fa0-4308-a417-1f3239bf2397';
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
    $pane->uuid = '4fd1ee70-3fa0-4308-a417-1f3239bf2397';
    $display->content['new-4fd1ee70-3fa0-4308-a417-1f3239bf2397'] = $pane;
    $display->panels['content'][2] = 'new-4fd1ee70-3fa0-4308-a417-1f3239bf2397';
    $pane = new stdClass();
    $pane->pid = 'new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $pane->panel = 'content';
    $pane->type = 'debut_common_jury_alphabet_list';
    $pane->subtype = 'debut_common_jury_alphabet_list';
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
    $pane->uuid = '1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $display->content['new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f'] = $pane;
    $display->panels['content'][3] = 'new-1c8bd0f8-16ca-4823-ae73-f3f1f403378f';
    $pane = new stdClass();
    $pane->pid = 'new-292241b1-d65b-4107-a09b-1d5d397bcf71';
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
    $pane->uuid = '292241b1-d65b-4107-a09b-1d5d397bcf71';
    $display->content['new-292241b1-d65b-4107-a09b-1d5d397bcf71'] = $pane;
    $display->panels['content'][4] = 'new-292241b1-d65b-4107-a09b-1d5d397bcf71';
    $pane = new stdClass();
    $pane->pid = 'new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
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
    $pane->uuid = 'e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
    $display->content['new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476'] = $pane;
    $display->panels['content'][5] = 'new-e32b9cc0-b9ab-4cc0-9572-5d9c0f0a1476';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['jury_list'] = $page;

  return $pages;

}
