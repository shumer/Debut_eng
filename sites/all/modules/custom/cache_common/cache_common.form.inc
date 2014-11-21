<?php
/**
 * @file
 * Forms.
 */

/**
 * Config form.
 */
function cache_common_form_site_settings() {
  $form = array();

  $form['cache_common_settings'] = array(
    '#tree' => TRUE,
  );

  // Caching part.
  $form['cache_common_settings']['re_cache'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rendered entity cache'),
    '#description' => t('Rendered entity cache settings.'),
  );
  $form['cache_common_settings']['re_cache']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => cache_common_setting('re_cache', 'enabled', FALSE),
    '#description' => t('If not enabled, values below will be ignored.'),
  );
  $form['cache_common_settings']['re_cache']['rules'] = array(
    '#type' => 'textarea',
    '#title' => t('Settings'),
    '#default_value' => cache_common_setting('re_cache', 'rules', ''),
    '#description' => t('Please specify cache rules form %form, first match will be used, you can use *', array(
      '%form' => '<entity_type>|<bundle>|<view_mode>|<ttl>',
    )),
  );

  return system_settings_form($form);
}

