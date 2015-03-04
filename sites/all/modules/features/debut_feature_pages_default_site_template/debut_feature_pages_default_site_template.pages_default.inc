<?php
/**
 * @file
 * debut_feature_pages_default_site_template.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function debut_feature_pages_default_site_template_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'DEFAULT',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'debut_default_site_template';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e0bf8ba5-cbc1-4e38-99fb-e87b66dad72f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6b12aad0-5876-477d-9385-905a24e6f578';
    $pane->panel = 'content';
    $pane->type = 'debut_common_facebook_plugin';
    $pane->subtype = 'debut_common_facebook_plugin';
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
    $pane->uuid = '6b12aad0-5876-477d-9385-905a24e6f578';
    $display->content['new-6b12aad0-5876-477d-9385-905a24e6f578'] = $pane;
    $display->panels['content'][0] = 'new-6b12aad0-5876-477d-9385-905a24e6f578';
    $pane = new stdClass();
    $pane->pid = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $display->content['new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2'] = $pane;
    $display->panels['content'][1] = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $pane = new stdClass();
    $pane->pid = 'new-eed7df26-2d4f-4fbc-8861-24d73680a374';
    $pane->panel = 'footer';
    $pane->type = 'debut_common_footer';
    $pane->subtype = 'debut_common_footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'footer_menu' => '0',
      'first_text_block' => '',
      'second_text_block' => 'Наш адрес: 111141, г. Москва, Зеленый проспект, д. 5/12, стр. 2 Электронная почта: info@pokolenie-debut.ru Данный сайт является официальным сайтом премии "Дебют" . Все права защищены ®',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eed7df26-2d4f-4fbc-8861-24d73680a374';
    $display->content['new-eed7df26-2d4f-4fbc-8861-24d73680a374'] = $pane;
    $display->panels['footer'][0] = 'new-eed7df26-2d4f-4fbc-8861-24d73680a374';
    $pane = new stdClass();
    $pane->pid = 'new-c3db0213-858d-46ba-a894-106a51b4dced';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
              1 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'PingDom',
      'title' => 'PingDom',
      'body' => '<script>
var _prum = [[\'id\', \'54eef555abe53d4637d54684\'],
             [\'mark\', \'firstbyte\', (new Date()).getTime()]];
(function() {
    var s = document.getElementsByTagName(\'script\')[0]
      , p = document.createElement(\'script\');
    p.async = \'async\';
    p.src = \'//rum-static.pingdom.net/prum.min.js\';
    s.parentNode.insertBefore(p, s);
})();
</script>',
      'format' => 'admin_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c3db0213-858d-46ba-a894-106a51b4dced';
    $display->content['new-c3db0213-858d-46ba-a894-106a51b4dced'] = $pane;
    $display->panels['header'][0] = 'new-c3db0213-858d-46ba-a894-106a51b4dced';
    $pane = new stdClass();
    $pane->pid = 'new-40e28a71-10e7-46d8-95ac-adb34666ec34';
    $pane->panel = 'header';
    $pane->type = 'debut_common_header';
    $pane->subtype = 'debut_common_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'language_links' => 1,
      'search_form' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '40e28a71-10e7-46d8-95ac-adb34666ec34';
    $display->content['new-40e28a71-10e7-46d8-95ac-adb34666ec34'] = $pane;
    $display->panels['header'][1] = 'new-40e28a71-10e7-46d8-95ac-adb34666ec34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_2';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e0bf8ba5-cbc1-4e38-99fb-e87b66dad72f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $display->content['new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2'] = $pane;
    $display->panels['middle'][0] = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_3';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'MOBILE',
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
  $display->layout = 'site_common_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
      'middle' => NULL,
      'left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e0bf8ba5-cbc1-4e38-99fb-e87b66dad72f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $display->content['new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2'] = $pane;
    $display->panels['content'][0] = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
    $pane = new stdClass();
    $pane->pid = 'new-eed7df26-2d4f-4fbc-8861-24d73680a374';
    $pane->panel = 'footer';
    $pane->type = 'debut_common_footer';
    $pane->subtype = 'debut_common_footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'footer_menu' => '0',
      'first_text_block' => '',
      'second_text_block' => 'Наш адрес: 111141, г. Москва, Зеленый проспект, д. 5/12, стр. 2 Электронная почта: info@pokolenie-debut.ru Данный сайт является официальным сайтом премии "Дебют" . Все права защищены ®',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eed7df26-2d4f-4fbc-8861-24d73680a374';
    $display->content['new-eed7df26-2d4f-4fbc-8861-24d73680a374'] = $pane;
    $display->panels['footer'][0] = 'new-eed7df26-2d4f-4fbc-8861-24d73680a374';
    $pane = new stdClass();
    $pane->pid = 'new-377daca5-3f4d-45d1-b7f4-30cd150736fd';
    $pane->panel = 'footer';
    $pane->type = 'debut_common_site_calendar';
    $pane->subtype = 'debut_common_site_calendar';
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
    $pane->uuid = '377daca5-3f4d-45d1-b7f4-30cd150736fd';
    $display->content['new-377daca5-3f4d-45d1-b7f4-30cd150736fd'] = $pane;
    $display->panels['footer'][1] = 'new-377daca5-3f4d-45d1-b7f4-30cd150736fd';
    $pane = new stdClass();
    $pane->pid = 'new-da9d60f7-4c8d-4ca5-9d1c-fecbfd80d466';
    $pane->panel = 'header';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
              1 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'PingDom',
      'title' => 'PingDom',
      'body' => '<script>
var _prum = [[\'id\', \'54eef555abe53d4637d54684\'],
             [\'mark\', \'firstbyte\', (new Date()).getTime()]];
(function() {
    var s = document.getElementsByTagName(\'script\')[0]
      , p = document.createElement(\'script\');
    p.async = \'async\';
    p.src = \'//rum-static.pingdom.net/prum.min.js\';
    s.parentNode.insertBefore(p, s);
})();
</script>',
      'format' => 'admin_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da9d60f7-4c8d-4ca5-9d1c-fecbfd80d466';
    $display->content['new-da9d60f7-4c8d-4ca5-9d1c-fecbfd80d466'] = $pane;
    $display->panels['header'][0] = 'new-da9d60f7-4c8d-4ca5-9d1c-fecbfd80d466';
    $pane = new stdClass();
    $pane->pid = 'new-62e7feef-407d-4bfe-8086-0a3fd3b31ae7';
    $pane->panel = 'header';
    $pane->type = 'debut_common_mobile_header';
    $pane->subtype = 'debut_common_mobile_header';
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
    $pane->uuid = '62e7feef-407d-4bfe-8086-0a3fd3b31ae7';
    $display->content['new-62e7feef-407d-4bfe-8086-0a3fd3b31ae7'] = $pane;
    $display->panels['header'][1] = 'new-62e7feef-407d-4bfe-8086-0a3fd3b31ae7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_3'] = $handler;

  return $export;
}
