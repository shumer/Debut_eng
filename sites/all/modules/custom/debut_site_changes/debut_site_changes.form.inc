<?php
/**
 *
 * @file
 *   Form builders.
 */

/**
 * Config form builder.
 */
function debut_site_changes_form_config() {
  $values = variable_get('debut_site_changes_conf', array());
  $form = array();

  $form['debut_site_changes_conf'] = array(
    '#tree' => TRUE,
  );

  // Get all CT.
  $content_types = node_type_get_types();
  $options = array();
  foreach ($content_types as $type) {
    $options[$type->type] = $type->name;
  }
  asort($options);

  $form['debut_site_changes_conf']['types'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#description' => t('Node types statistics grab for:'),
  );

  $form['debut_site_changes_conf']['types']['node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node to grab statistics'),
    '#default_value' => !empty($values['types']['node_types'])
        ? $values['types']['node_types'] : array(),
    '#options' => $options,
  );

  return system_settings_form($form);
}
