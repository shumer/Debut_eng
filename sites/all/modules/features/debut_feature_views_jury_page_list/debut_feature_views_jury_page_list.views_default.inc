<?php
/**
 * @file
 * debut_feature_views_jury_page_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function debut_feature_views_jury_page_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'debut_view_jury_prize_list';
  $view->description = 'Debut Jury list in different view mode.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Debut: View Jury prize list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Глобальный: Случайно */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Контекстный фильтр: Содержимое: Jury years (field_jury_years) */
  $handler->display->display_options['arguments']['field_jury_years_target_id']['id'] = 'field_jury_years_target_id';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['table'] = 'field_data_field_jury_years';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['field'] = 'field_jury_years_target_id';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_jury_years_target_id']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'debut_jury' => 'debut_jury',
  );

  /* Display: Listing */
  $handler = $view->new_display('panel_pane', 'Listing', 'listing_view_mode');
  $handler->display->display_options['display_description'] = 'Listing view mode';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Surname (field_person_surname) */
  $handler->display->display_options['sorts']['field_person_surname_value']['id'] = 'field_person_surname_value';
  $handler->display->display_options['sorts']['field_person_surname_value']['table'] = 'field_data_field_person_surname';
  $handler->display->display_options['sorts']['field_person_surname_value']['field'] = 'field_person_surname_value';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['debut_view_jury_prize_list'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Все'),
    t('Listing'),
    t('Listing view mode'),
    t('Представления-Фрагменты'),
  );
  $export['debut_view_jury_prize_list'] = $view;

  return $export;
}
