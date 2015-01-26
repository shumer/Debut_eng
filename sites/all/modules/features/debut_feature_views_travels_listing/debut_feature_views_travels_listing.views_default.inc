<?php
/**
 * @file
 * debut_feature_views_travels_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function debut_feature_views_travels_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'debut_view_list_travels';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Debut: View list travels';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  /* Поле: Содержимое: Publication date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Критерий сортировки: Содержимое: Publication date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_publication_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_publication_date_value']['expose']['label'] = 'Publication date (field_publication_date)';
  /* Контекстный фильтр: Содержимое: Publication date (field_publication_date) */
  $handler->display->display_options['arguments']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['arguments']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['arguments']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['arguments']['field_publication_date_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_publication_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_publication_date_value']['year_range'] = '-100:+100';
  $handler->display->display_options['arguments']['field_publication_date_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_publication_date_value']['use_fromto'] = 'no';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'travel' => 'travel',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;

  /* Display: year_list */
  $handler = $view->new_display('panel_pane', 'year_list', 'year_list');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Publication date (field_publication_date) */
  $handler->display->display_options['arguments']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['arguments']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['arguments']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['arguments']['field_publication_date_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_publication_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_publication_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_publication_date_value']['year_range'] = '-100:+100';
  $handler->display->display_options['arguments']['field_publication_date_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_publication_date_value']['use_fromto'] = 'no';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'travel' => 'travel',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['debut_view_list_travels'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Publication date'),
    t('Publication date (field_publication_date)'),
    t('Все'),
    t('year_list'),
    t('Представления-Фрагменты'),
  );
  $export['debut_view_list_travels'] = $view;

  return $export;
}
