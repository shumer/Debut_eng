<?php
/**
 * @file
 * debut_feature_views_persons_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function debut_feature_views_persons_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'debut_view_persons_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Debut: View Persons list';
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'compact';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликован или админ */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'debut_prize_person' => 'debut_prize_person',
  );
  /* Критерий фильтра: Содержимое: Surname (field_person_surname) */
  $handler->display->display_options['filters']['field_person_surname_value']['id'] = 'field_person_surname_value';
  $handler->display->display_options['filters']['field_person_surname_value']['table'] = 'field_data_field_person_surname';
  $handler->display->display_options['filters']['field_person_surname_value']['field'] = 'field_person_surname_value';
  $handler->display->display_options['filters']['field_person_surname_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_person_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['operator_id'] = 'field_person_surname_value_op';
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['label'] = 'Surname (field_person_surname)';
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['operator'] = 'field_person_surname_value_op';
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['identifier'] = 'field_person_surname_value';
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_person_surname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $translatables['debut_view_persons_list'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Surname (field_person_surname)'),
  );
  $export['debut_view_persons_list'] = $view;

  return $export;
}
