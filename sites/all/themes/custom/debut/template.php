<?php
/**
 * @file
 * Theme functions for debut theme.
 */

/**
 * Implements theme_form.
 */
function debut_form($variables) {
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
function debut_get($index, $array, $default = array()) {
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
function debut_preprocess_entity(&$variables) {

  // Only handle supported types.
  if (!in_array($variables['entity_type'], array('commerce_product', 'config_pages'))) {
    return;
  }

  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);

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
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
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
  $preprocess_exact = 'debut_preprocess_' . $entity_type . '__' . $entity->type . '__' . $view_mode;
  $preprocess_all   = 'debut_preprocess_' . $entity_type . '__' . $entity->type;

  if (function_exists($preprocess_exact)) {
    $preprocess_exact($variables);
  }
  elseif (function_exists($preprocess_all)) {
    $preprocess_all($variables);
  }
  elseif (site_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess_exact)));
  }
}

/**
 * Preprocess node.
 */
function debut_preprocess_node(&$variables) {
  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);

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
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
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
  $preprocess = 'debut_preprocess_node__' . $node->type . '__' . $view_mode;
  if (function_exists($preprocess)) {
    $preprocess($variables);
  }
  elseif (site_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
  // Add specific templates.
  foreach ($variables['theme_hook_suggestions'] as $theme_suggestion) {
    $variables['theme_hook_suggestions'][] = $theme_suggestion . '__' . $view_mode;
  }
}

/**
 * Preprocess field.
 */
function debut_preprocess_field(&$variables) {
  $element = $variables['element'];

  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);
  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  if ($element['#field_type'] == 'field_collection') {
    $view_mode = $element['#view_mode'];

    // Run specific preprocess function.
    $preprocess = 'debut_preprocess_field_collection_' . $element['#field_name'] . '__' . $view_mode;
    if (function_exists($preprocess)) {
      $preprocess($variables);
    }
    elseif (site_common_developer()) {
      dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
    }

    // Add specific templates.
    foreach ($variables['theme_hook_suggestions'] as $theme_suggestion) {
      $variables['theme_hook_suggestions'][] = $theme_suggestion . '__' . $view_mode;
    }
  }
}

/**
 * Preprocess views.
 */
function debut_preprocess_views_view(&$variables) {
  $view  = &$variables['view'];
  $_data = &$variables['_data'];
  $_html = &$variables['_html'];

  // Load preprocess funtions file.
  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Trigger specific preprocess function based on view.
  $preprocess = 'debut_preprocess_views_view__' . $view->name . '__' . reset($view->display)->id;
  if (function_exists($preprocess)) {
    return $preprocess($variables);
  }
  elseif (site_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
}

/**
 * Preprocess views unformatted.
 */
function debut_preprocess_views_view_unformatted(&$variables) {
  $view  = &$variables['view'];

  // Trigger specific preprocess function based on view.
  $preprocess = 'debut_preprocess_views_' . $view->name . '__' . reset($view->display)->id;
  if (function_exists($preprocess)) {
    return $preprocess($variables);
  }
  elseif (site_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess)));
  }
}

/**
 * Preprocess debut_form, threat forms like enteties.
 */
function debut_preprocess_debut_form(&$variables) {

  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);

  $form = &$variables['form'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
    if (is_file($file)) {
      require_once $file;
    }
  }

  // Add specific templates.
  $variables['theme_hook_suggestions'][] = 'debut_form__' . $form['#form_id'];

  // Run specific preprocess function.
  $preprocess = 'debut_preprocess_form__' . $form['#form_id'];
  if (function_exists($preprocess)) {
    $preprocess($variables);
  }
}


/**
 * Theme field.
 */
function givenchy_field(&$variables) {
  // Prevent default field wrapping into odd divs.
  // this function MUST be present even if empty.
}

/**
 * Set custom meta theme for forms.
 */
function debut_form_alter(&$form, $form_state, $form_key) {

  // We need to fill exposed views forms according to selected settings.
  if ($form_key == 'views_exposed_form') {
    foreach (element_children($form) as $key) {
      $form[$key]['#attributes']['autocomplete'] = 'off';
    }
  }

  // Add theme function.
  $ignore = variable_get('debut_form_alter_ignore', array());
  if (!in_array($form_key, $ignore)) {
    if (!is_array($form['#theme'])) {
      $form['#theme'] = array($form['#theme']);
    }
    $form['#theme'][] = 'debut_form';
  }
}

/**
 * Implements hook_theme().
 */
function debut_theme($existing, $type, $theme, $path) {

  $theme_path = drupal_get_path('theme', 'debut');

  // Meta theme for all site forms.
  $hooks['debut_form'] = array(
    'render element' => 'form',
    'path' => $theme_path . '/templates/form',
    'template' => 'debut-form',
  );

  $hooks += drupal_find_theme_templates($hooks, '.tpl.php', $path);

  return $hooks;
}

/**
 * Process HTML.
 */
function debut_process_html(&$variables) {

  // Theme path for future use.
  $theme_path = drupal_get_path('theme', 'debut');
  // Add theme path to javascript settings.
  drupal_add_js(array('path_to_html' => '/' . $theme_path . '/html/'), 'setting');

  // Extra classes.
  $extra_classes = &drupal_static('debut_process_html_body_classes', array());
  $extra_html_classes = &drupal_static('debut_process_html_html_classes', array());

  // Add class for popup pages.
  if (arg(0) == 'popup' ) {
    $extra_classes[] = 'popup';
  }

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

  // Replace default jQuery with our variant.
  $js_list = drupal_add_js();
  if (!empty($js_list['misc/jquery.js'])) {
    foreach($js_list as $key => $value ){
      preg_match('/misc\/ui/i', $key, $matches);
      if (!empty($matches)){
        unset($js_list[$key]);
      }
    }
    $js_list['misc/jquery.js']['data'] = $theme_path . '/html/js/jquery.js';
    $variables['scripts'] = drupal_get_js('header', $js_list);
  }

  // Unset unrequired css.
  $css = drupal_add_css();
  if (!empty($css)) {
    foreach($css as $key => $value ){
      preg_match('/misc\/ui/i', $key, $matches);
      if (!empty($matches)){
        unset($css[$key]);
      }
      preg_match('/modules\/system/i', $key, $matches);
      if (!empty($matches)){
        unset($css[$key]);
      }
    }
  }

  // A dummy query-string is added to filenames, to gain control over
  // browser-caching. The string changes on every update or full cache
  // flush, forcing browsers to load a new copy of the files, as the
  // URL changed.
  $query_string = variable_get('css_js_query_string', '0');

  $variables['styles_custom'] = drupal_get_css($css);
  $variables['styles_custom'] .= '<link type="text/css" rel="stylesheet" id="stylesheet" href="/' . $theme_path . '/html/css/screen.css?' . $query_string . '" media="all" />' . PHP_EOL;
  $variables['styles_custom'] .= '<link type="text/css" rel="stylesheet" href="/' . $theme_path . '/css/debut-custom.css?' . $query_string . '" media="all" />' . PHP_EOL;

  $variables['messages'] = theme('status_messages');
}

/**
 * Debut render.
 */
function debut_render($content, $key, $default = '') {
  return array_key_exists($key, $content)
    ? drupal_render($content[$key])
    : $default;
}

/**
 * Preprocess taxonomy term.
 */
function debut_preprocess_taxonomy_term(&$variables) {

  $preprocess_entity_loaded = &drupal_static('debut_preprocess_entity_loaded', FALSE);

  $entity = &$variables['term'];
  $content = &$variables['content'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = path_to_theme();

  // Load preprocess funtions file.
  if (!$preprocess_entity_loaded) {
    $preprocess_entity_loaded = TRUE;
    $file = path_to_theme() . '/debut.preprocess_entity.inc';
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
  $preprocess_exact = 'debut_preprocess_taxonomy_term__' . $entity->vocabulary_machine_name . '__' . $view_mode;
  $preprocess_all   = 'debut_preprocess_taxonomy_term__' . $entity->vocabulary_machine_name;

  if (function_exists($preprocess_exact)) {
    $preprocess_exact($variables);
  }
  elseif (function_exists($preprocess_all)) {
    $preprocess_all($variables);
  }
  elseif (site_common_developer()) {
    dpm(t('preprocess: !preprocess expected but not found', array('!preprocess' => $preprocess_exact)));
  }
}

/**
 * Preprocess debut_common_breadcrumb.
 */
function debut_preprocess_debut_common_breadcrumb(&$variables) {
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Theme breadcrumbs links.
  foreach ($_data['breadcrumbs'] as &$item) {
    if (is_array($item)) {
      $item = l($item['title'], $item['path']);
    }
  }

  $_html['breadcrumbs'] = implode('<span class="divider">/</span>', $_data['breadcrumbs']);
}

/**
 * Theme pager link.
 */
function debut_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '><span>' . check_plain($text) . '</sppan></a>';
}
