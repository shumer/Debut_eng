<?php
/**
 * @file
 * Containt hooks and field API logic.
 */

/**
 * Helper function to get image style for formatter.
 */
function _site_common_field_formatter_image_field_default_preset($instance, $view_mode) {
  if ($view_mode == 'default') {
    $view_mode = 'full';
  }

  $style = implode('__', array_filter(array($instance['entity_type'], $instance['field_name'], $view_mode)));
  return $style;
}

/**
 * Helper function to generate default alt
 */
function _site_common_field_formatter_image_field_default_alt() {
  return variable_get('site_name', '');
}

/**
 * Implements hook_field_formatter_info().
 */
function site_common_field_formatter_info() {
  $formatters = array(
    // Image field.
    'site_common_image_field_default' => array(
      'label' => t('Site Common Image', array(), array('context' => 'COMMON: admin area')),
      'field types' => array('image'),
      'settings' => array(
        'image_style' => '',
        'image_link' => '',
        'preset' => '',
        'nosize' => TRUE,
        'deltas' => '',
      ),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function site_common_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  // Settings form for Site common Image formatter.
  if ($display['type'] == 'site_common_image_field_default') {
    $element['deltas'] = array(
      '#title' => t('Deltas', array(), array('context' => 'COMMON: admin area')),
      '#description' => t('Deltas to render. Leave blank to render all.', array(), array('context' => 'COMMON: admin area')),
      '#type' => 'textfield',
      '#size' => 20,
      '#default_value' => $settings['deltas'],
      '#element_validate' => array('element_validate_integer'),
    );

    // Check if we should link image to content.
    $link_types = array(
      'content' => t('Content', array(), array('context' => 'COMMON: admin area')),
      'file' => t('File', array(), array('context' => 'COMMON: admin area')),
    );
    $element['image_link'] = array(
      '#title' => t('Link image to', array(), array('context' => 'COMMON: admin area')),
      '#type' => 'select',
      '#default_value' => $settings['image_link'],
      '#empty_option' => t('Nothing', array(), array('context' => 'COMMON: admin area')),
      '#options' => $link_types,
    );

    // Preset value cannot be changed.
    $element['preset'] = array(
      '#type' => 'value',
      '#value' => _site_common_field_formatter_image_field_default_preset($instance, $view_mode),
    );

    // Controll size properties strip.
    $element['nosize'] = array(
      '#title' => t('Remove size', array(), array('context' => 'COMMON: admin area')),
      '#description' => t('Remove size properties from resulting image (experimantal).', array(), array('context' => 'COMMON: admin area')),
      '#type' => 'checkbox',
      '#size' => 20,
      '#default_value' => $settings['nosize'],
    );

  }
  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function site_common_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = array();

  // Settings form for Site common Image formatter.
  if ($display['type'] == 'site_common_image_field_default') {

    // Get preset.
    $preset = $settings['preset'];

    // Check if this style created.
    $styles = image_styles();
    if (empty($styles[$preset])) {
      $missing = t('(missing)', array(), array('context' => 'COMMON: admin area'));
    }
    else {
      $missing = '';
    }

    if (empty($preset)) {
      $summary[] = t('Please open and save settings form.', array(), array('context' => 'COMMON: admin area'));
    }
    else {
      $summary[] = t('Image style: [!preset] !missing', array('!preset' => $preset, '!missing' => $missing), array('context' => 'COMMON: admin area'));
      $summary[] = !empty($settings['deltas'])
        ? t('Deltas: @keys', array('@keys' => $settings['deltas']), array('context' => 'COMMON: admin area'))
        : t('All deltas will be rendered.', array(), array('context' => 'COMMON: admin area'));
      if (!empty($settings['nosize'])) {
        $summary[] = t('Size properties will be stripped from resilting image.', array(), array('context' => 'COMMON: admin area'));
      }
    }
  }
  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function site_common_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  // Site common image formatter.
  if ($display['type'] == 'site_common_image_field_default') {

    // Calculate deltas.
    $length = 0;
    $deltas = isset($settings['deltas']) ? $settings['deltas'] : NULL;

    // Calculate deltas.
    if (is_numeric($deltas)) {
      $deltas = array($deltas);
    }
    elseif (empty($deltas)) {
      $deltas = array_keys($items);
    }

    // Render required deltas.
    foreach ($deltas as $key) {

      // Fix for empty items.
      if (empty($items[$key]['uri'])) {
        $items[$key]['uri'] = 'public://image_not_found.png';
      }

      // Pass nosize further, this will be processed by site_common_image_style().
      if (!empty($settings['nosize'])) {
        $items[$key]['attributes']['nosize'] = TRUE;
      }

      // Set default ALT.
      if (empty($items[$key]['alt'])) {
        // Generate default alt if empty.
        $items[$key]['alt'] = _site_common_field_formatter_image_field_default_alt();
      }

      // Build Path.
      $path = '';
      if ($settings['image_link'] == 'content') {
        $path = entity_uri($entity_type, $entity);
      }
      elseif ($settings['image_link'] == 'file') {
        $path = array(
          'path' => file_create_url($items[$key]['uri']),
          'options' => array(),
        );
      }

      // Build element content.
      $element[$key] = array(
        '#theme' => 'image_formatter',
        '#item' => $items[$key],
        '#image_style' => $settings['preset'],
        '#path' => $path,
      );
    }
  }

  return $element;
}
