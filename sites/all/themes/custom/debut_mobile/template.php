<?php
/**
 * @file
 * Theme functions for debut theme.
 */

/**
 * Implements theme_form.
 */
function debut_mobile_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }

  return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
}

/**
 * Get element from array or object checking if it exists.
 */
function debut_mobile_get($index, $array, $default = array()) {
  $result = $default;
  if (is_array($array) && isset($array[$index])) {
    $result = $array[$index];
  }
  elseif (is_object($array) && property_exists($array, $index)) {
    $result = $array->{$index};
  }
  return $result;
}

/**
 * Preprocess entity.
 */
function debut_mobile_preprocess_entity(&$variables) {

  // Only handle supported types.
  if (!in_array($variables['entity_type'], array('commerce_product', 'config_pages'))) {
    return;
  }

  $preprocess_entity_loaded = &drupal_static('debut_mobile_preprocess_entity_loaded', FALSE);

  $entity_type = $variables['entity_type'];
  $entity = &$variables[$entity_type];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Ignore label settings and suffix/prefix from out of theme.
  foreach (element_children($content) as $key) {
    $content[$key]['#label_display'] = 'hidden';
    unset($content[$key]['#prefix']);
    unset($content[$key]['#suffix']);
  }
  unset($variables['elements']['#theme_wrappers']);

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut_mobile.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Just in case.
  $view_mode = !empty($variables['elements']['#view_mode'])
    ? $variables['elements']['#view_mode']
    : 'full';
  $entity->view_mode = $view_mode;

  // Set delta.
  $entity->_delta = !empty($entity->_delta)
    ? $entity->_delta
    : 0;

  // Run specific preprocess function.
  $ids = entity_extract_ids($entity_type, $entity);
  $preprocess_exact = 'debut_mobile_preprocess_' . $entity_type . '__' . $ids[2] . '__' . $view_mode;
  $preprocess_all   = 'debut_mobile_preprocess_' . $entity_type . '__' . $ids[2];

  if (function_exists($preprocess_exact)) {
    $preprocess_exact($variables);
  }
  elseif (function_exists($preprocess_all)) {
    $preprocess_all($variables);
  }
  elseif (debut_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess_exact)));
  }
}

/**
 * Preprocess node.
 */
function debut_mobile_preprocess_node(&$variables) {
  $preprocess_entity_loaded = &drupal_static('debut_mobile_preprocess_entity_loaded', FALSE);

  $node = &$variables['node'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Ignore label settings and suffix/prefix from out of theme.
  foreach (element_children($content) as $key) {
    $content[$key]['#label_display'] = 'hidden';
    unset($content[$key]['#prefix']);
    unset($content[$key]['#suffix']);
  }

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut_mobile.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Just in case.
  $view_mode = !empty($variables['view_mode'])
    ? $variables['view_mode']
    : 'full';
  $node->view_mode = $view_mode;

  // Set delta.
  $node->_delta = !empty($node->_delta)
    ? $node->_delta
    : 0;

  // Run specific preprocess function.
  $preprocess = 'debut_mobile_preprocess_node__' . $node->type . '__' . $view_mode;
  if (function_exists($preprocess)) {
    $preprocess($variables);
  }
  elseif (debut_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
  // Add specific templates.
  foreach ($variables['theme_hook_suggestions'] as $theme_suggestion) {
    $variables['theme_hook_suggestions'][] = $theme_suggestion . '__' . $view_mode;
  }
}

/**
 * Preprocess views.
 */
function debut_mobile_preprocess_views_view(&$variables) {
  $view  = &$variables['view'];
  $_data = &$variables['_data'];
  $_html = &$variables['_html'];

  // Load preprocess funtions file.
  $preprocess_entity_loaded = &drupal_static('debut_mobile_preprocess_entity_loaded', FALSE);
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut_mobile.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Trigger specific preprocess function based on view.
  $preprocess = 'debut_mobile_preprocess_views_view__' . $view->name . '__' . reset($view->display)->id;
  if (function_exists($preprocess)) {
    return $preprocess($variables);
  }
  elseif (debut_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
}

/**
 * Preprocess views unformatted.
 */
function debut_mobile_preprocess_views_view_unformatted(&$variables) {
  $view  = &$variables['view'];

  // Trigger specific preprocess function based on view.
  $preprocess = 'debut_mobile_preprocess_views_' . $view->name . '__' . reset($view->display)->id;
  if (function_exists($preprocess)) {
    return $preprocess($variables);
  }
  elseif (debut_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
}

/**
 * Preprocess debut_mobile_form, threat forms like enteties.
 */
function debut_mobile_preprocess_debut_mobile_form(&$variables) {

  $preprocess_entity_loaded = &drupal_static('debut_mobile_preprocess_entity_loaded', FALSE);

  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut_mobile.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Add specific templates.
  $variables['theme_hook_suggestions'][] = 'debut_mobile_form__' . $form['#form_id'];

  // Run specific preprocess function.
  $preprocess = 'debut_mobile_preprocess_form__' . $form['#form_id'];
  if (function_exists($preprocess)) {
    $preprocess($variables);
  }
}

/**
 * Set custom meta theme for forms.
 */
function debut_mobile_form_alter(&$form, $form_state, $form_key) {

  // We need to fill exposed views forms according to selected settings.
  if ($form_key == 'views_exposed_form') {
    foreach (element_children($form) as $key) {
      $form[$key]['#attributes']['autocomplete'] = 'off';
    }
  }

  // Add theme function.
  $ignore = variable_get('debut_mobile_form_alter_ignore', array());
  if (!in_array($form_key, $ignore)) {
    if (!is_array($form['#theme'])) {
      $form['#theme'] = array($form['#theme']);
    }
    $form['#theme'][] = 'debut_mobile_form';
  }
}

/**
 * Implements hook_theme().
 */
function debut_mobile_theme($existing, $type, $theme, $path) {

  $theme_path = drupal_get_path('theme', 'debut');

  // Meta theme for all site forms.
  $hooks['debut_mobile_form'] = array(
    'render element' => 'form',
    'path' => $theme_path . '/templates/form',
    'template' => 'debut-mobile-form',
  );

  $hooks += drupal_find_theme_templates($hooks, '.tpl.php', $path);

  return $hooks;
}

/**
 * Process HTML.
 */
function debut_mobile_process_html(&$variables) {
 global $is_https;

  admin_menu_suppress();

  // Add ajax.
  site_common_js_add('ajax');
  site_common_js_add('jquery_mobile', FALSE, array(
    'exclude' => _site_common_settings('jquery_mobile', 'exclude_url', SITE_COMMON_VAR_JQM_EXCLUDE),
  ));

  // Set redirect flag.
  $variables['redirect'] = !empty($_SERVER['REQUEST_REPLACED']);

  // Theme path for future use.
  $theme_path = drupal_get_path('theme', 'debut_mobile');

  // Add theme path to javascript settings.
  drupal_add_js(array('path_to_html' => '/' . $theme_path . '/html/'), 'setting');

  // Extra classes.
  $extra_classes = &drupal_static('debut_mobile_process_html_body_classes', array());
  $extra_html_classes = &drupal_static('debut_mobile_process_html_html_classes', array());

  // Load SVG resources.
  $variables['svg'] = file_get_contents($theme_path . '/html/inc/svg.php');

  // Add custom classes to body class array.
  if (!empty($extra_classes)) {
    $variables['classes_array'] = array_merge($variables['classes_array'], $extra_classes);
    $variables['classes'] = implode(' ', array_unique($variables['classes_array']));
  }

  // Add classes to html.
  $variables['html_classes'] = '';
  if (!empty($extra_html_classes)) {
    $variables['html_classes'] = implode(' ', array_unique($extra_html_classes));
  }

  // Title.
  $variables['head_title_array']['name'] = t('Debut');
  $variables['head_title'] = implode(' | ', $variables['head_title_array']);

  $theme_path = path_to_theme();

  // Replace default jQuery with our variant for normal pages.
  $js_list = drupal_add_js();
  if (!site_common_is_xmlhttp()) {
    if (!empty($js_list['misc/jquery.js'])) {
      $protocol = ($is_https) ? 'https://' : 'http://';

      // Add migrate plugin and refetch list.
      drupal_add_js($protocol . 'code.jquery.com/jquery-migrate-1.2.1.min.js', 'external');
      $js_list = drupal_add_js();

      // Use jquery CDN.
      $js_list['misc/jquery.js']['data'] = 'external';
      $js_list['misc/jquery.js']['data'] = $protocol . 'code.jquery.com/jquery-1.9.0.min.js';
    }
  }
  else {
    // Remove all scripts except settings for ajax pages.
    $settings = !empty($js_list['settings']) ? $js_list['settings'] : array();
    $js_list = array('settings' => $settings);
  }
  $variables['scripts'] = drupal_get_js('header', $js_list);

  // Exclude css from ajax pages to reduce size.
  if (site_common_is_xmlhttp()) {
    $variables['styles'] = '';
  }
}

/**
 * Debut render.
 */
function debut_mobile_render(&$content, $key, $default = '') {
  return array_key_exists($key, $content)
    ? drupal_render($content[$key])
    : $default;
}

/**
 * Preprocess taxonomy term.
 */
function debut_mobile_preprocess_taxonomy_term(&$variables) {

  $preprocess_entity_loaded = &drupal_static('debut_mobile_preprocess_entity_loaded', FALSE);

  $entity = &$variables['term'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut_mobile.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Just in case.
  $view_mode = !empty($variables['elements']['#view_mode'])
    ? $variables['elements']['#view_mode']
    : 'full';
  $entity->view_mode = $view_mode;

  // Set delta.
  $entity->_delta = !empty($entity->_delta)
    ? $entity->_delta
    : 0;

  // Run specific preprocess function.
  $preprocess_exact = 'debut_mobile_preprocess_taxonomy_term__' . $entity->vocabulary_machine_name . '__' . $view_mode;
  $preprocess_all   = 'debut_mobile_preprocess_taxonomy_term__' . $entity->vocabulary_machine_name;

  if (function_exists($preprocess_exact)) {
    $preprocess_exact($variables);
  }
  elseif (function_exists($preprocess_all)) {
    $preprocess_all($variables);
  }
  elseif (debut_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess_exact)));
  }
}


/**
 * Theme field.
 */
function debut_mobile_field(&$variables) {
  // Prevent default field wrapping into odd divs.
  // this function MUST be present even if empty.
}

/**
 * Theme item list.
 */
function debut_mobile_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }

  return $output;
}


/**
 * Overrides theme_form_element().
 */
function debut_mobile_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  // Removed default wrappers as those goes directly from slice :/
  $output = '<div class="form-item">' . "\n";

  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      if ($element['#type'] == 'checkbox') {
        $element['#prelabel'] = $element['#children'];
        $element['#children'] = '';
        $element['#required'] = FALSE;
        if (!empty($element['#_label'])) {
          $element['#title'] = $element['#_label'];
        }
      }
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      if ($element['#type'] == 'checkbox') {
        $element['#prelabel'] = $element['#children'];
        $element['#children'] = '';
        $element['#required'] = FALSE;
        if (!empty($element['#_label'])) {
          $element['#title'] = $element['#_label'];
        }
      }
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  // No decription for now.
  if (FALSE && !empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Implements theme_textfield().
 */
function debut_mobile_textfield(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'text';
  element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  // Compatible with JQM.
  if (empty($element['#attributes']['data-role'])) {
    $element['#attributes']['data-role'] = 'none';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}
