<?php
/**
 * @file
 * debut_feature_pages_contact.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function debut_feature_pages_contact_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact';
  $page->task = 'page';
  $page->admin_title = 'Contact';
  $page->admin_description = '';
  $page->path = 'nofollow/contact';
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
  $handler->name = 'page_contact_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'POPUP',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/popup',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->uuid = '162de410-f127-4056-9da0-c5018936bb72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
    $pane->panel = 'content';
    $pane->type = 'debut_common_contact_us_page';
    $pane->subtype = 'debut_common_contact_us_page';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
    $display->content['new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c'] = $pane;
    $display->panels['content'][0] = 'new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'contact';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Page',
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
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->uuid = '162de410-f127-4056-9da0-c5018936bb72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-169322bf-0829-46a3-869e-667daa04f7d5';
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
    $pane->uuid = '169322bf-0829-46a3-869e-667daa04f7d5';
    $display->content['new-169322bf-0829-46a3-869e-667daa04f7d5'] = $pane;
    $display->panels['content'][0] = 'new-169322bf-0829-46a3-869e-667daa04f7d5';
    $pane = new stdClass();
    $pane->pid = 'new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
    $pane->panel = 'content';
    $pane->type = 'debut_common_contact_us_page';
    $pane->subtype = 'debut_common_contact_us_page';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
    $display->content['new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c'] = $pane;
    $display->panels['content'][1] = 'new-6bfddf1b-b78b-4cf2-84c8-e620625e3b6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contact_us_submitted';
  $page->task = 'page';
  $page->admin_title = 'Contat Us submitted';
  $page->admin_description = 'comment_added';
  $page->path = 'contact_us/submitted';
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
  $handler->name = 'page_contact_us_submitted_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contact_us_submitted';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Desktop',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'popup-body',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_pre' => NULL,
      'content' => NULL,
      'content_after' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a2d46e7d-8dde-41e8-ab76-effe493d5153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b0be1c2c-43f5-4736-b114-84b80dc623bf';
    $pane->panel = 'middle';
    $pane->type = 'debut_common_contact_submitted';
    $pane->subtype = 'debut_common_contact_submitted';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'confirm_text' => 'You message has been sent. We contact to you shortly. Thank you.',
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
    $pane->uuid = 'b0be1c2c-43f5-4736-b114-84b80dc623bf';
    $display->content['new-b0be1c2c-43f5-4736-b114-84b80dc623bf'] = $pane;
    $display->panels['middle'][0] = 'new-b0be1c2c-43f5-4736-b114-84b80dc623bf';
    $pane = new stdClass();
    $pane->pid = 'new-07b2bb73-c346-41ec-80af-2deec9a27778';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Success HTML + Reload parent page',
      'title' => '',
      'body' => '<script language="JavaScript">
setTimeout( function () {
  if (self != top) {
    top.$.fancybox.close();
  }
}, 4000);
</script>',
      'format' => 'admin_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '07b2bb73-c346-41ec-80af-2deec9a27778';
    $display->content['new-07b2bb73-c346-41ec-80af-2deec9a27778'] = $pane;
    $display->panels['middle'][1] = 'new-07b2bb73-c346-41ec-80af-2deec9a27778';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contact_us_submitted_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'contact_us_submitted';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Mobile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'popup-body',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => '',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_pre' => NULL,
      'content' => NULL,
      'content_after' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a2d46e7d-8dde-41e8-ab76-effe493d5153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85c686b1-f418-43a0-9b84-295368ccfafb';
    $pane->panel = 'middle';
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
    $pane->uuid = '85c686b1-f418-43a0-9b84-295368ccfafb';
    $display->content['new-85c686b1-f418-43a0-9b84-295368ccfafb'] = $pane;
    $display->panels['middle'][0] = 'new-85c686b1-f418-43a0-9b84-295368ccfafb';
    $pane = new stdClass();
    $pane->pid = 'new-b0be1c2c-43f5-4736-b114-84b80dc623bf';
    $pane->panel = 'middle';
    $pane->type = 'debut_common_contact_submitted';
    $pane->subtype = 'debut_common_contact_submitted';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'confirm_text' => 'You message has been sent. We contact to you shortly. Thank you.',
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
    $pane->uuid = 'b0be1c2c-43f5-4736-b114-84b80dc623bf';
    $display->content['new-b0be1c2c-43f5-4736-b114-84b80dc623bf'] = $pane;
    $display->panels['middle'][1] = 'new-b0be1c2c-43f5-4736-b114-84b80dc623bf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contact_us_submitted'] = $page;

  return $pages;

}
