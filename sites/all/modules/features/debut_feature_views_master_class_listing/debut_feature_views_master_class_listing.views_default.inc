<?php
/**
 * @file
 * debut_feature_views_master_class_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function debut_feature_views_master_class_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'debut_view_get_master_class_by_params';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Debut: View get Master class by params';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Контекстный фильтр: Содержимое: Master class text (field_master_class_text) */
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['id'] = 'field_master_class_text_target_id';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['table'] = 'field_data_field_master_class_text';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['field'] = 'field_master_class_text_target_id';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_master_class_text_target_id']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'master_class' => 'master_class',
  );
  /* Критерий фильтра: Содержимое: Master class text (field_master_class_text) */
  $handler->display->display_options['filters']['field_master_class_text_target_id']['id'] = 'field_master_class_text_target_id';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['table'] = 'field_data_field_master_class_text';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['field'] = 'field_master_class_text_target_id';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_master_class_text_target_id']['expose']['operator_id'] = 'field_master_class_text_target_id_op';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['expose']['label'] = 'Master class text (field_master_class_text)';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['expose']['operator'] = 'field_master_class_text_target_id_op';
  $handler->display->display_options['filters']['field_master_class_text_target_id']['expose']['identifier'] = 'field_master_class_text_target_id';

  /* Display: interview */
  $handler = $view->new_display('panel_pane', 'interview', 'interview');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Interview (field_master_class_interview) */
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['id'] = 'field_master_class_interview_target_id';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['table'] = 'field_data_field_master_class_interview';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['field'] = 'field_master_class_interview_target_id';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_master_class_interview_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['debut_view_get_master_class_by_params'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Nid'),
    t('Все'),
    t('Master class text (field_master_class_text)'),
    t('interview'),
    t('Представления-Фрагменты'),
  );
  $export['debut_view_get_master_class_by_params'] = $view;

  $view = new view();
  $view->name = 'debut_view_list_master_class';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Debut: View list Master class';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'master_class' => 'master_class',
  );
  $translatables['debut_view_list_master_class'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Nid'),
  );
  $export['debut_view_list_master_class'] = $view;

  return $export;
}
