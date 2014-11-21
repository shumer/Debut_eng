<?php
/**
 * @file
 * Admin forms.
 */

/**
 * Settings form builder.
 */
function site_common_admin_settings_form() {
  $form = array();

  // Root element to store settings.
  $form['site_common_settings'] = array(
    '#tree' => TRUE,
  );

  // Get list os image styles (extracting mobile styles).
  $list = image_styles();
  foreach ($list as $name => $style) {
    if (strpos($name, '__m') == strlen($name) - 3) {
      continue;
    }
    $mobile_style = $name . '__m';
    $label = empty($list[$mobile_style])
      ? $style['label']
      : $style['label'] . ' [M]';
    $options[$name] = $label;
  }

  // Lazy Load images settings.
  $form['site_common_settings']['lazy_load'] = array(
    '#title' => t('Images Lazy Load', array(), array('context' => 'COMMON: admin area')),
    '#type' => 'fieldset',
    '#description' => t('You may want to override %behavior behavior in your theme.', array(
      '%behavior' => 'Drupal.behaviors.site_common_lazy_load',
    ), array('context' => 'COMMON: admin area')),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['site_common_settings']['lazy_load']['enabled'] = array(
    '#title' => t('Enable images lazy load', array(), array('context' => 'COMMON: admin area')),
    '#type' => 'checkbox',
    '#description' => t('!IMPORTANT! You must clear theme registry after changing this value.', array(), array('context' => 'COMMON: admin area')),
    '#default_value' => _site_common_settings('lazy_load', 'enabled', FALSE),
  );
  $form['site_common_settings']['lazy_load']['threshold'] = array(
    '#title' => t('Mobile treshold', array(), array('context' => 'COMMON: admin area')),
    '#type' => 'textfield',
    '#description' => t('This is max width in which mobile images will be loaded (if available).', array(), array('context' => 'COMMON: admin area')),
    '#default_value' => _site_common_settings('lazy_load', 'threshold', SITE_COMMON_VAR_MOBILE_THRESHOLD),
    '#element_validate' => array('element_validate_integer'),
    '#required' => TRUE,
  );
  $form['site_common_settings']['lazy_load']['image_styles'] = array(
    '#title' => t('Image styles', array(), array('context' => 'COMMON: admin area')),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#description' => t('If style have mobile version it wil be displayed as [M].', array(), array('context' => 'COMMON: admin area')),
    '#options' => $options,
    '#default_value' => _site_common_settings('lazy_load', 'image_styles', array()),
  );
  $form['site_common_settings']['lazy_load']['placeholder_styles'] = array(
    '#title' => t('Placeholder styles', array(), array('context' => 'COMMON: admin area')),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#description' => t('Specify which styles should have blank placeholder instead of empty src (this prevents page from jumping on image load, but increase page size).', array(), array('context' => 'COMMON: admin area')),
    '#options' => $options,
    '#default_value' => _site_common_settings('lazy_load', 'placeholder_styles', array()),
  );

  return system_settings_form($form);
}
