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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '40e28a71-10e7-46d8-95ac-adb34666ec34';
    $display->content['new-40e28a71-10e7-46d8-95ac-adb34666ec34'] = $pane;
    $display->panels['header'][0] = 'new-40e28a71-10e7-46d8-95ac-adb34666ec34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-22d6dce7-6c4a-4b9c-a065-85bafd8dfce2';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}
