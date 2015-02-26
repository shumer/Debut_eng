<?php
/**
 * @file
 * Theme functions for debut theme.
 */

/**
 * Preprocess debut_mobile_form, threat forms like enteties.
 */
function debut_preprocess_confirm_form(&$variables) {

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
  if (!in_array($variables['entity_type'], array('commerce_product', 'config_pages', 'field_collection_item'))) {
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
  $ids = entity_extract_ids($entity_type, $entity);
  $preprocess_exact = 'debut_preprocess_' . $entity_type . '__' . $ids[2] . '__' . $view_mode;
  $preprocess_all   = 'debut_preprocess_' . $entity_type . '__' . $ids[2];

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

  // Get contextual links from title_suffix array.
  $ts = isset($variables['title_suffix']) ? $variables['title_suffix'] : array();

  // Render contextual links if exists.
  $_html['contextual_links'] = isset($ts['contextual_links']) ? debut_render($ts, 'contextual_links') : '';

  // Run specific preprocess function.
  $preprocess = 'debut_preprocess_node__' . $node->type . '__' . $view_mode;
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
  elseif (debut_common_developer()) {
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
  elseif (debut_common_developer()) {
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

  // Add ajax support.
  qtools_api__js_add('base');
  qtools_api__js_add('ajax');

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

  // Image for FB.
  $variables['fb_image'] = theme('image', array('path' => $theme_path . '/html/images/flash.jpg'));
  
  // A dummy query-string is added to filenames, to gain control over
  // browser-caching. The string changes on every update or full cache
  // flush, forcing browsers to load a new copy of the files, as the
  // URL changed.
  $query_string = variable_get('css_js_query_string', '0');

  $variables['styles_custom'] = drupal_get_css($css);
  $variables['styles_custom'] .= '<link type="text/css" rel="stylesheet" id="stylesheet" href="/' . $theme_path . '/html/css/screen.css?' . $query_string . '" media="all" />' . PHP_EOL;
  $variables['styles_custom'] .= '<link type="text/css" rel="stylesheet" id="stylesheet" href="/' . $theme_path . '/html/css/responsive.css?' . $query_string . '" media="only screen and (max-width : 1200px)" />' . PHP_EOL;
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
  elseif (debut_common_developer()) {
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
    if (empty($query['field_publication_date_value']['value'])) {
      $query['field_publication_date_value']['value']['year'] = date('Y', time());
    }
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
  return '<a' . drupal_attributes($attributes) . '><span>' . check_plain($text) . '</span></a>';
}

/**
 * Theme pager.
 */
function debut_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = '';
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? t('') : t('<span class="ico"></span>')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? t('') : t('<span class="ico"></span>')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = '';

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => 'pager-first',
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => '<span>'. $i .'</span>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => 'pager-first',
        'data' => $li_last,
      );
    }
    return theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Theme field.
 */
function debut_field(&$variables) {
  // Prevent default field wrapping into odd divs.
  // this function MUST be present even if empty.
}

/**
 * Theme item list.
 */
function debut_item_list($variables) {
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
 * Returns HTML for a textfield form element.
 */
function debut_textfield($variables) {
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

  $output = '<div class="form-text-wrap"><div class="form-text-wrap-inner">';
  $output .= '<input' . drupal_attributes($element['#attributes']) . ' />';
  $output .= '</div></div>';

  return $output . $extra;
}

/**
 * Returns HTML for a textarea form element.
 */
function debut_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper', 'form-textarea-wrap'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<div class="form-textarea-wrap-inner">';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div></div>';

  return $output;
}

/**
 * Theme function: creates the custom themed recaptcha widget.
 */
function debut_recaptcha_custom_widget() {
  $recaptcha_only_if_incorrect_sol = t('Попробуйте еще раз');
  $recaptcha_only_if_image_enter = t('Введите текст с картинки:');
  $recaptcha_get_another_captcha = t('Обновить изображение');
  $help = t('Help');
  return <<<EOT
    <div id="recaptcha_image" class="recaptcha_image"></div>
    <div class="recaptcha_only_if_incorrect_sol" style="color:red">$recaptcha_only_if_incorrect_sol</div>
    <span class="recaptcha_only_if_image">$recaptcha_only_if_image_enter</span>
    <div class="form-text-wrap"><div class="form-text-wrap-inner"><input type="text" id="recaptcha_response_field" name="recaptcha_response_field" class="form-text" /></div></div>
    <div class="recaptcha_get_another_captcha"><a href="javascript:Recaptcha.reload()">$recaptcha_get_another_captcha</a></div>
EOT;
}

/**
 * Returns HTML for a file upload form element.
 */
function debut_file($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));

  return '<div class="item-upload"><input' . drupal_attributes($element['#attributes']) . ' /></div>';
}
