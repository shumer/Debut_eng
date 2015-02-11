<?php
/**
 * @file
 * Basic api for qtools.
 */

global $qtools_request_cookie;
$qtools_request_cookie = $_COOKIE;

/**
 * Parse single tag selector.
 */
function qtools_api__selector_parse($selector) {
  $tag = '';
  $id = '';
  $class = array();

  // Check for id attrib.
  if (strpos($selector, '#')) {
    list($tag, $selector) = explode('#', $selector);
    $class = explode('.', $selector);
    $id = array_shift($class);
  }
  elseif (strpos($selector, '.')) {
    $class = explode('.', $selector);
    $tag = array_shift($class);
  }
  return array($tag, $id, $class);
}

/**
 * See if current user is developer.
 */
function qtools_api__developer($set = NULL) {
  global $qtools_api__developer;
  if ($set !== NULL) {
    if (!empty($set)) {
      $_SESSION['qtools_api__developer'] = TRUE;
    }
    else {
      unset($_SESSION['qtools_api__developer']);
    }
  }
  return !empty($_SESSION['qtools_api__developer']) || !empty($qtools_api__developer);
}

/**
 * Include qtools js.
 */
function qtools_api__js_add($name = '', $force = FALSE) {

  // Get path and added scripts list.
  $options = NULL;
  $added_list = &drupal_static(__FUNCTION__ . '_list', array());
  $js_path = drupal_get_path('module', 'qtools') . '/js/qtools.' . $name . '.js';

  // Add required script.
  if (!empty($name) && empty($added_list[$js_path])) {

    // Add requirements.
    if ($name == 'ajax') {
      drupal_add_library('system', 'drupal.ajax');
    }
    elseif ($name == 'autocomplete') {
      drupal_add_library('system', 'drupal.autocomplete');
    }
    elseif ($name == 'base') {

      // Add settings.
      $settings = variable_get('qtools_api__js_add_base_settings', array(
        'base' => array(
          'log' => TRUE,
        ),
      ));
      $js = 'var qtools_settings = ' . drupal_json_encode($settings) . ';';
      drupal_add_js($js, 'inline');

      // If file is added it is present on every page.
      $options['every_page'] = TRUE;
    }

    // Add js.
    drupal_add_js($js_path, $options);
    $added_list[] = $js_path;
  }
}

/**
 * Build ajax call command.
 * @param $type
 *   (string) Command type: call/view/form
 * @param $key
 *   (string) Depends on command url/view_name/form_id
 */
function qtools_api__ajax_command($type, $key, $data = array(), $name = '', $method = 'post', $spam = 5000) {
  return array(
    'command' => 'qtools_command_ajax',
    'type' => $type,
    'key' => $key,
    'data' => $data,
    'name' => $name,
    'method' => $method,
    'spam' => $spam,
  );
}

/**
 * Ajax command to print data to console.
 */
function qtools_api__ajax_command_log($title, $data) {
  return array(
    'command' => 'qtools_command_log',
    'title' => $title,
    'data' => $data,
  );
}

/**
 * Entity extractor.
 *
 * @param $param
 *   (string) entity_type.
 * @param $value
 *   (int) entity id.
 */
function _qtools_api__field_get_item_entity($param, $value) {
  $result = entity_load($param, array($value));
  return !empty($result[$value]) ? $result[$value] : NULL;
}

/**
 * Get specific field delta.
 */
function qtools_api__field_get_item($entity_type, $entity, $field_name, $deltas = NULL, $key = NULL, $langcode = NULL) {

  // Check that node contain this firld.
  if (empty($entity) || !is_object($entity) || !property_exists($entity, $field_name)) {
    if (is_numeric($deltas)) {
      return NULL;
    }
    else {
      return array();
    }
  }

  // Get items.
  $items = field_get_items($entity_type, $entity, $field_name, $langcode);

  // Return empty value based on requested deltas.
  if (empty($items)) {
    if (is_numeric($deltas)) {
      return NULL;
    }
    else {
      return array();
    }
  }

  // Get list of deltas we need to return.
  if (is_numeric($deltas)) {
    $_return_delta = $deltas;
    $deltas = array($deltas);
  }
  else {
    $deltas = !empty($deltas)
      ? $deltas
      : array_keys($items);
  }
  $return = array();

  // Check if we have complex extractor.
  if (!empty($key) && strpos($key, ':')) {
    list($key, $function, $param) = explode(':', $key);
    if (empty($function)) {
      $function = '_qtools_api__field_get_item_entity';
    }
  }

  // Get all items.
  foreach ($deltas as $delta) {
    if (!empty($items[$delta])) {
      if ($key === NULL) {
        $return[$delta] = $items[$delta];
      }
      else {
        $return[$delta] = !empty($items[$delta][$key])
          ? $items[$delta][$key]
          : NULL;

        // If we have valid extractor - use it.
        if (!empty($function)) {
          if (function_exists($function)) {
            $return[$delta] = $function($param, $return[$delta]);
          }
          else {
            $return[$delta] = NULL;
          }
        }
      }
    }
    else {
      $return[$delta] = NULL;
    }
  }

  // If we need to return one item then extract it from the results.
  if (isset($_return_delta)) {
    $return = !empty($return[$_return_delta])
      ? $return[$_return_delta]
      : NULL;
  }
  return $return;
}

/**
 * Default path condition to check node type.
 */
function _qtools_api__path_match_chunk_condition_user_role($argument, $value, $inverse) {
  // Load user.
  $account = user_load($argument);

  // Check if type match.
  if (!empty($account)) {
    $result = qtools_api__user_has_role($value, $account);
    if ($inverse) {
      $result = !$result;
    }
  }
  else {
    $result = FALSE;
  }
  return $result;
}

/**
 * Default path condition to check node type.
 */
function _qtools_api__path_match_chunk_condition_node_type($argument, $value, $inverse) {
  // Load node.
  $node = node_load($argument);

  // Check if type match.
  if (!empty($node)) {
    if ($inverse) {
      $result = $node->type != $value;
    }
    else {
      $result = $node->type == $value;
    }
  }
  else {
    $result = FALSE;
  }
  return $result;
}

/**
 * Return list of available condition and callbacks.
 */
function _qtools_api__path_match_chunk_condition_conditions() {
  $conditions = &drupal_static(__FUNCTION__, array());

  // Build condition callbacks.
  if (empty($conditions)) {
    $conditions = array(
      ':node_type' => '_qtools_api__path_match_chunk_condition_node_type',
      ':user_role' => '_qtools_api__path_match_chunk_condition_user_role',
    );

    // Allow other modules to add condition.
    drupal_alter('qtools_api__path_match_chunk_condition', $conditions);
  }

  return $conditions;
}

/**
 * Check path chunk condition.
 */
function _qtools_api__path_match_chunk_condition($argument, $condition, $value, $inverse) {

  // This will be returned if condition callback not found.
  $result = FALSE;

  // Get conditions list.
  $conditions = _qtools_api__path_match_chunk_condition_conditions();

  // If condition present - evaluate it.
  if (!empty($conditions[$condition]) && function_exists($conditions[$condition])) {
    $result = $conditions[$condition]($argument, $value, $inverse);
  }
  return $result;
}

/**
 * Helper function for match check.
 */
function _qtools_api__path_match_chunk($pchunk, $schunk, $pos) {

  $match = FALSE;

  // Direct match.
  if ($pchunk == $schunk) {
    $match = TRUE;
  }
  // Wildcard match.
  elseif ($pchunk == '*') {
    $match = TRUE;
  }
  elseif (strpos($pchunk, ':') === 0) {
    if (strpos($pchunk, '!=') > 0) {
      list($condition, $value) = explode('!=', $pchunk);
      $inverse = TRUE;
    }
    else {
      list($condition, $value) = explode('==', $pchunk);
      $inverse = FALSE;
    }
    // Run condition check.
    $match = _qtools_api__path_match_chunk_condition($schunk, $condition, $value, $inverse);
  }

  return $match;
}

/**
 * Check if given string (path) match pattern.
 */
function qtools_api__path_match($string, $pattern = array()) {

  // Prepare data.
  $found = '';
  $_string_chunks = explode('/', trim($string));

  // Iterate through patterns.
  foreach ($pattern as $pattern_line) {
    $pattern_chunks = explode('/', trim($pattern_line));
    $string_chunks  = $_string_chunks;

    // We start as match = TRUE.
    $match = TRUE;

    // Check each chunk of a pattern.
    $pos = 0;
    while (!empty($pattern_chunks) && $match) {
      $pchunk = array_shift($pattern_chunks);
      $schunk = array_shift($string_chunks);

      if ($pchunk == '**') {

        // We cant rely on pos after greedy wildcard.
        $pos = -1;

        // We need to swap match here.
        $match = FALSE;

        // Get next chunk from pattern.
        $pchunk = array_shift($pattern_chunks);

        // Cut off one by one chunks from string.
        while (!empty($string_chunks) && !$match) {
          $schunk = array_shift($string_chunks);
          $match = _qtools_api__path_match_chunk($pchunk, $schunk, $pos);
        }
      }
      else {
        // Regulat comparasing.
        $match = _qtools_api__path_match_chunk($pchunk, $schunk, $pos);
      }

      if ($pos != -1) {
        $pos++;
      }
    }

    // If we got match - exit returning string that match.
    if ($match) {
      $found = $pattern_line;
      break;
    }
  }
  return $found;
}

/**
 * Get role ID.
 */
function qtools_api__user_role($name) {
  $roles = user_roles();
  return array_search($name, $roles);
}

/**
 * Check if user has specified role.
 */
function qtools_api__user_has_role($role, $account = NULL) {
  global $user;

  $has_role = FALSE;

  // Choose account to test against.
  if (empty($account)) {
    $account = $user;
  }

  $roles = $account->roles;
  if (in_array($role, $roles) || !empty($roles[$role])) {
    $has_role = TRUE;
  }
  return $has_role;
}

/**
 * Get image dimensions if they will be passed to given image style.
 *
 * @param $source
 *   (string) filepath to the image.
 * @style $style
 *   (string) Style name to be applied to the image to calcualte dimenstions.
 */
function qtools_api__image_dimensions($source, $style = FALSE) {
  // If the source file doesn't exist, return FALSE.
  if (!$image = image_load($source)) {
    return FALSE;
  }

  // Get image dimensions.
  $dimensions = array(
    'width' => $image->info['width'],
    'height' => $image->info['height'],
  );

  // Apply style if given.
  if (!empty($style)) {
    image_style_transform_dimensions($style, $dimensions);
  }

  return $dimensions;
}

/**
 * Generate transparent img image with given size and return base64 representation.
 *
 * Creadits to http://stackoverflow.com/questions/17271742/create-a-transparent-png-file-using-php
 */
function qtools_api__image_placeholder($width, $height) {

  // Get file and directory path.
  $directory = variable_get('qtools_api__image_placeholder_path', 'public://qtools_api__image_placeholder');
  $file = $directory . '/' . $width . '_' . $height . '.src';

  // Check foe existing image and return if already created.
  if (file_exists($file)) {
    // For safety reasons we did not store encoded results.
    $contents = file_get_contents();
  }
  else {
    // Build image.
    $image = imagecreatetruecolor($width, $height);
    imagesavealpha($image, true);
    $color = imagecolorallocatealpha($image, 0, 0, 0, 127);
    imagefill($image, 0, 0, $color);

    // Save image from buffer.
    ob_start();
      imagepng($image);
      $contents = ob_get_contents();
    ob_end_clean();

    // Prepare saving folder.
    $prepared = FALSE;
    if (!file_exists($directory)) {
      $res = drupal_mkdir($directory);
      if (empty($res)) {
        watchdog('qtools_api:image', '@function can not create directory @dir', array(
          '@function' => __FUNCTION__,
          '@dir' => $directory,
        ), WATCHDOG_ERROR);
      }
      else {
        $prepared = TRUE;
      }
    }
    else {
      $prepared = TRUE;
    }
  }

  // Save result.
  if ($prepared) {
    // Build data URI.
    $dataUri = "data:image/png;base64," . base64_encode($contents);
    file_put_contents($file, $dataUri);
  }

  return $dataUri;
}

/**
 * Unique id that can be shown to users.
 */
function qtools_api__unique_id() {
  $id = uniqid(time(), TRUE);
  return substr(md5($id), 5, 10);
}

/**
 * Executes view without invoking all entities to load.
 *
 * @see function views::execute();
 */
function _qtools_api__views_execute_view($view, $display_id) {

  if (empty($view->built)) {
    if (!$view->build($display_id)) {
      return FALSE;
    }
  }

  if (!empty($view->executed)) {
    return TRUE;
  }

  // Don't allow to use deactivated displays, but display them on the live preview.
  if (!$view->display[$view->current_display]->handler->get_option('enabled') && empty($view->live_preview)) {
    $view->build_info['fail'] = TRUE;
    return FALSE;
  }

  // Let modules modify the view just prior to executing it.
  foreach (module_implements('views_pre_execute') as $module) {
    $function = $module . '_views_pre_execute';
    $function($view);
  }

  // Add each field to the query.
  $need_rebuild = FALSE;
  foreach ($view->field as $field_info) {
    if (!empty($field_info->table) && !empty($field_info->real_field)) {
      $view->query->add_field($field_info->table, $field_info->real_field, $field_info->field);
      $need_rebuild = TRUE;
    }
  }

  // Rebulid query if needed.
  if ($need_rebuild) {
    $view->query->build($view);
  }

  // Execute.
  $view->query->execute($view);

  // Enforce the array key rule as documented in
  // views_plugin_query::execute().
  $view->result = array_values($view->result);

  // This is where magic is done, just comment this out.
  //$view->_post_execute();

  // Let modules modify the view just after executing it.
  foreach (module_implements('views_post_execute') as $module) {
    $function = $module . '_views_post_execute';
    $function($view);
  }

  $view->executed = TRUE;
}

/**
 * Analog of views_get_view_result but cleaner.
 *
 * // TODO: document.
 */
function qtools_api__views_get_result($name, $display_id = 'default', $args = array(), $exposed = array(), $items_per_page = FALSE, $mode = FALSE, &$raw_results = FALSE) {

  $result = ($mode != QTOOLS_VIEWS_MODE_PREVIEW) ? array() : '';

  // Load init and execute.
  $view = views_get_view($name);
  if (is_object($view)) {

    // Set args and exposed filters.
    $view->set_arguments($args);

    // Set items per page.
    if ($items_per_page !== FALSE) {
      $view->set_items_per_page($items_per_page);
    }

    // Block exposed finters to be fetched from GET.
    if (empty($exposed)) {
      $exposed = array('__key__' => '__value__');
    }
    $view->set_exposed_input($exposed);

    // Init display.
    if (is_string($display_id)) {
      $view->set_display($display_id);
    }
    else {
      $view->init_display();
    }

    $view->pre_execute();

    // Execute.
    if ($mode == QTOOLS_VIEWS_MODE_PREVIEW) {
      $result = $view->display_handler->execute();
    }
    elseif ($mode == QTOOLS_VIEWS_MODE_FIELDS) {
      $view->execute();
      $result = $view->result;
    }
    else {
      // QTOOLS_VIEWS_MODE_VALUES execute will load all entities which is huge performance hit.
      _qtools_api__views_execute_view($view, $display_id);
      $result = $view->result;
    }

    // Save raw result if array was passed.
    if (is_array($raw_results)) {
      $raw_results = $view->result;
    }

    // Clean up.
    $view->destroy();
  }

  return $result;
}

/**
 * Check if this page is allowed to redirect, be default resource files should not be redirected.
 */
function qtools_api__redirect_forbidden($path = '') {
  global $qtools_request_cookie;

  if (!empty($_SESSION['qtools_api__redirect_forbidden'])) {
    return TRUE;
  }
  elseif (variable_get('qtools_api__redirect_forbidden', FALSE)) {
    return TRUE;
  }
  elseif (variable_get('qtools_api__redirect_forbidden_nocookie', TRUE) && empty($qtools_request_cookie)) {
    // This one is important as search engines dont have cookie support
    // and we dont want them to enter infinite loop.
    // Also images may have their cookies be stripped at Varnish level.
    return TRUE;
  }

  // By default ecxlude resource path.
  $path_to_exclude = array(
    variable_get('file_private_path'),
    variable_get('file_public_path'),
    variable_get('file_temporary_path'),
  );

  // Get current path as default.
  $path = !empty($path)
    ? $path
    : $_GET['q'];

  // Allow other modules to interfier.
  drupal_alter('qtools_api__redirect_forbidden', $path_to_exclude, $path);

  // Check against excluded path.
  $forbidden = FALSE;
  foreach ($path_to_exclude as $exclude) {
    if (strpos($path, $exclude) === 0) {
      $forbidden = TRUE;
    }
  }

  return $forbidden;
}

/**
 * Check if we in normal environment.
 */
function qtools_api__ready() {
  return (basename($_SERVER['PHP_SELF']) == 'index.php' && php_sapi_name() != 'cli');
}

/**
 * Generate hash for given structure with inner seed.
 */
function qtools_api__hash($params, $noise = NULL, $length = NULL) {
  global $drupal_hash_salt;

  // Use sitewide noise if not provided.
  if ($noise === NULL) {
    $noise = $drupal_hash_salt;
  }

  // Order arrays before serializing to keep hash same for similar arrays.
  if (is_array($params)) {
    $params = serialize(qtools_api__array_order($params));
  }

  // Hash and return result.
  $hash = hash('sha256', $params . $noise);
  if (!empty($length)) {
    $hlength = drupal_strlen($hash);
    if ($hlength > $length) {
      $hash = substr($hash, floor(($hlength - $length) / 2), $length);
    }
  }
  return $hash;
}

/**
 * Modified version of file_transfer() that allow to transfer prepared
 *
 * @see file_transfer()
 */
function qtools_api__transfer($uri, $headers, $data = NULL) {
  if (ob_get_level()) {
    ob_end_clean();
  }

  foreach ($headers as $name => $value) {
    drupal_add_http_header($name, $value);
  }
  drupal_send_headers();

  // File transfer.
  if (!empty($uri)) {
    // Attempt to increase time to transfer file.
    drupal_set_time_limit(240);

    $scheme = variable_get('file_default_scheme', 'public');
    // Transfer file in 16 KB chunks to save memory usage.
    if ($scheme && file_stream_wrapper_valid_scheme($scheme) && $fd = fopen($uri, 'rb')) {
      while (!feof($fd)) {
        print fread($fd, 1024*16);
      }
      fclose($fd);
    }
    else {
      drupal_not_found();
    }
  }
  else {
    // Data transfer.
    print $data;
  }
  drupal_exit();
}

/**
 * Find form element inside a form.
 * // TODO: docs.
 */
function qtools_api__form_find(&$form, $path) {
  if (!is_array($path)) {
    $name = $path;
  }
  elseif (count($path) == 1) {
    $name = $path[0];
  }
  else {
    $name = array_shift($path) . '[';
    $name .= implode('][', $path) . ']';
  }

  $element = NULL;
  foreach (element_children($form) as $key) {
    if (!empty($form[$key]['#name']) && ($form[$key]['#name'] == $name)) {
      $element = &$form[$key];
      break;
    }
    if (count(element_children($form[$key])) > 0) {
      if ($element = qtools_api__form_find($form[$key], $name)) {
        break;
      }
    }
  }
  return $element;
}

/**
 * Geocode using google maps.
 * // TODO: document.
 */
function qtools_api__geo_code($address, $req_lng = array(), $res_lng = '', $expire = CACHE_PERMANENT) {

  $headers = array();
  $args = func_get_args();
  $ckey = 'qtools_api_geo_code-' . serialize($args);
  $cache = cache_get($ckey);
  if (!empty($cache->data) && (($cache->expire > time()) || $expire <= 0) ) {
    watchdog('qt:geo:cache', '!res', array('!res' => var_export($cache->data, TRUE)));
    $result = $cache->data;
    foreach ($result as &$row) {
      $row['from_cache'] = TRUE;
    }
    return $result;
  }

  $geo_code_url = "http://maps.googleapis.com/maps/api/geocode/json";
  $query = array(
    'sensor' => 'false',
    'address' => $address,
  );
  if (!empty($res_lng)) {
    $query['language'] = $res_lng;
  }
  $url = url($geo_code_url, array('external' => TRUE, 'query' => $query));

  // User request language if specified.
  if (is_array($req_lng)) {
    $lng = explode(',', $_SERVER['HTTP_ACCEPT_LANGUAGE']);
    $first = explode(';', $lng[0]);
    $lng[0] = $first[0] .';q=0.95';
    $lng = array_merge_recursive($req_lng, $lng);

    // We need to supply language to make search more accurate.
    $headers = array(
      'Accept-Language' => implode(', ', $lng),
    );
  }

  $res = drupal_http_request($url, $headers);
  if (!empty($res->data)) {
    $geo_res = json_decode($res->data);
  }

  watchdog('qt:geo', '!res', array('!res' => var_export($res, TRUE)));

  // If we ok - parse results.
  $result = array();
  $i = 0;
  $accuracy = 0;
  $most_accurate = 0;
  if (!empty($geo_res) && $geo_res->status == 'OK') {
    foreach($geo_res->results as $row) {
      $row->address_components_r = qtools_api__array_remap($row->address_components, array('types', 0));
      if ($accuracy < count($row->address_components_r)) {
        $accuracy = count($row->address_components_r);
        $most_accurate = $i;
      };
      $types = array_merge($row->types, array_keys($row->address_components_r));
      $result[$i] = array(
        'status' => 200,
        'types' => $types,
        'latitude' => $row->geometry->location->lat,
        'longitude' => $row->geometry->location->lng,
        'api3' => $row,
        'http_res' => $res,
      );
      $i++;
    }
    $tmp = $result[0];
    $result[0] = $result[$most_accurate];
    $result[$most_accurate] = $tmp;
    cache_set($ckey, $result, 'cache', $expire);
  }
  return $result;
}

/**
 * Set or get option.
 *
 * @param $key
 * (string) Option Name.
 * @param $value
 * (any) Option value, if !== NULL will be assigned to key.
 * if !NULL, and not empty default - it will use default as value.
 * @param $default
 * (any) Default value.
 */
function qtools_option($key, $value = NULL, $default = NULL) {
  $options = &drupal_static(__FUNCTION__, array());
  if (($value !== NULL) && ($default === NULL)) {
    if (!isset($options[$key])) {
      drupal_alter('qtools_option', $value, $default);
    }
    $options[$key] = $value;
  }
  elseif ($value !== NULL) {
    if (!isset($options[$key])) {
      drupal_alter('qtools_option', $default, $default);
    }
    $options[$key] = $default;
  }
  return isset($options[$key]) ? $options[$key] : $default;
}

/**
 * Double sort array callback.
 */
function _qtools_api__array_sort($a, $b) {
  $primary_a = qtools_api__array_get($a, array('_sort', 0), NULL);
  $primary_b = qtools_api__array_get($b, array('_sort', 0), NULL);
  $result = 0;
  $level = 0;
  if ($primary_a > $primary_b) {
    $result = 1;
  }
  elseif ($primary_a < $primary_b) {
    $result = -1;
  }
  else {
    $level = 1;
    $secondary_a = qtools_api__array_get($a, array('_sort', 1), NULL);
    $secondary_b = qtools_api__array_get($b, array('_sort', 1), NULL);
    if ($secondary_a > $secondary_b) {
      $result = 1;
    }
    elseif ($secondary_a < $secondary_b) {
      $result = -1;
    }
  }
  return $result;
}

/**
 * Sort mulileveled array by wieghts array.
 *
 * @param $tree
 *   (array) Multileveld array of items.
 * @param $weights
 *   (array) Multileveld array of weights for each level of depth.
 * @param $defaults
 *   (array) plain array of default values for each level of depth.
 * @param $sort_flags
 *   (int) sert_flags see sort().
 *
 * @return
 *   (array) ordered up to count($weights) deep.
 */
function qtools_api__array_sort_tree($tree, $weights, $defaults, $sort_flags = SORT_REGULAR) {

  // Get data for current level.
  $weight = array_shift($weights);
  $default = !empty($defaults) ? array_shift($defaults) : '';

  // Map keys to weights.
  $keys = array_keys($tree);
  $tree_keys = array();
  foreach ($keys as $key) {
    $tree_keys[$key] = !empty($weight[$key]) ? $weight[$key] : $default;
  }

  // Sort map.
  asort($tree_keys, $sort_flags);

  // Rebuild tree using sorted keys.
  $tree_data = array();
  foreach ($tree_keys as $key => $weight) {
    // Sort inner levels.
    if (is_array($tree[$key]) && !empty($weights)) {
      $tree_data[$key] = qtools_api__array_sort_tree($tree[$key], $weights, $defaults, $sort_flags);
    }
    else {
      $tree_data[$key] = $tree[$key];
    }
  }
  return $tree_data;
}

/**
 * Sort array by specified key.
 *
 * @param $array
 *   (array) Array to sort.
 * @param $key_path
 *   (str/array) Path to prime key.
 * @param $default
 *   (var) Default value for items that doesnot have key.
 *
 * @return
 *   (array) Sorted array.
 */
function qtools_api__array_sort($array, $key_path, $default = NULL) {

  $sort = array();

  foreach ($array as $key => $value) {
    $sort[$key] = qtools_api__array_get($value, $key_path, $default);
  }

  asort($sort);

  foreach ($sort as $key => &$value) {
    $value = $array[$key];
  }

  return $sort;
}

/**
 * Order array recurcively, does not specify any order,
 * but just to make sure that same content will have same order.
 *
 * @param $array
 *   (array) Array to order.
 *
 * @return
 *   (array) Ordered array.
 */
function qtools_api__array_order($array) {
  foreach ($array as &$value) {
    if (is_array($value)) {
      $value = qtools_api__array_order($value);
    }
  }
  sort($array);
  return $array;
}

/**
 * Check if array is associative.
 *
 * @see http://stackoverflow.com/questions/173400/php-arrays-a-good-way-to-check-if-an-array-is-associative-or-numeric/4254008#4254008
 */
function qtools_api__array_is_assoc($array) {
  return (bool)count(array_filter(array_keys($array), 'is_string'));
}

/**
 * Recursive array diff.
 *
 * @see http://www.php.net/manual/en/function.array-diff.php#91756
 */
function qtools_api__array_diff($aArray1, $aArray2) {
  $aReturn = array();

  // Both variables must be arrays.
  if (!is_array($aArray1) || !is_array($aArray2)) {
    return $aReturn;
  }

  foreach ($aArray1 as $mKey => $mValue) {
    if (array_key_exists($mKey, $aArray2)) {
      if (is_array($mValue)) {
        $aRecursiveDiff = qtools_api__array_diff($mValue, $aArray2[$mKey]);
        if (count($aRecursiveDiff)) {
          $aReturn[$mKey] = $aRecursiveDiff;
        }
      }
      else {
        if ($mValue != $aArray2[$mKey]) {
          $aReturn[$mKey] = $mValue;
        }
      }
    }
    else {
      $aReturn[$mKey] = $mValue;
    }
  }
  return $aReturn;
}

/**
 * Apply array diff.
 */
function qtools_api__array_extend($array, $diff) {

  // Both variables must be arrays.
  if (!is_array($array) || !is_array($diff)) {
    return $array;
  }

  // Fast merge if both plain.
  if (!qtools_api__array_is_assoc($array) && qtools_api__array_is_assoc($diff)) {
    return array_merge($array, $diff);
  }

  // Merge assoc arrays.
  foreach ($diff as $key => $value) {
    if (array_key_exists($key, $array)) {
      if (is_array($value)) {
        if (!is_array($array[$key])) {
          $array[$key] = array();
        }
        $array[$key] = qtools_api__array_extend($array[$key], $value);
      }
      else {
        if ($value != $array[$key]) {
          $array[$key] = $value;
        }
      }
    }
    else {
      $array[$key] = $value;
    }
  }
  return $array;
}

/**
 * Filter array, will LEAVE matched items.
 *
 * @param $array
 *   (array) Array to filter.
 * @param $key_path
 *   (str/array) Path to prime key.
 * @param $key_value
 *   (var) Value of prime key to filter.
 * @param $op
 *   (str) Operation to check against
 * @param $invert
 *   (bool) Invert filter results.
 *
 * @return
 *   (array) Filtered array.
 */
function qtools_api__array_filter($array, $key_path, $key_value, $op = '==', $invert = FALSE) {

  foreach ($array as $key => $value) {
    $match = TRUE;
    $value = qtools_api__array_get($value, $key_path);

    switch ($op) {
      case '==':
        $match = ($value == $key_value);
      break;

      case 'empty':
        $match = empty($value);
      break;
    }

    if ($invert) {
      $match = !$match;
    }

    if (!$match) {
      unset($array[$key]);
    }
  }
  return $array;
}

/**
 * Split array into pieces.
 *
 * DEPRECATED WILL BE REMOVED.
 */
function qtools_api__array_split($array, $size = 2) {
  return array_chunk($array, $size);
}

/**
 * Extract specified key from array.
 *
 * @param $array
 *   (array/object) array of items, we will extract value from each of them.
 * @param $key_path
 *   (str/array) path to value we search for (array of keys we need to check).
 * @param $default
 *   (any) default value if we cant find given key_path in array.
 *
 * @return
 *   (array) array of values for each item with given key_path.
 */
function qtools_api__array_extract($array, $key_path, $default = NULL) {
  $res = array();

  // Return if given argument is not an array.
  if (!is_array($array)) {
    return $res;
  }

  // Extract given key.
  foreach ($array as $key => $value) {
    $res[$key] = qtools_api__array_get($value, $key_path, $default);
  }
  return $res;
}

/**
 * Get item from array(object) for specified path.
 *
 * @param $array
 *   (array/object) item from which we will extract value.
 * @param $key_path
 *   (str/array) path to value we search for (array of keys we need to check).
 * @param $default
 *   (any) default value if we cant find given key_path in array.
 *
 * @return
 *   (any) value of array with given key_path.
 */
function qtools_api__array_get($array, $key_path, $default = NULL) {

  $array = (array) $array;

  $key_path = is_array($key_path) ? $key_path : array($key_path);
  $key = array_shift($key_path);

  $value = !empty($array[$key]) ? $array[$key] : $default;

  if (!empty($key_path) && (is_array($value) || is_object($value))) {
    $value = qtools_api__array_get($value, $key_path, $default);
  }
  return $value;
}

function qtools_api__array_set(&$array, $key_path, $value) {

  $array = (array) $array;

  $key_path = is_array($key_path) ? $key_path : array($key_path);
  $key = array_shift($key_path);

  // If path empty - set given value.
  if (empty($key_path)) {
    $array[$key] = $value;
  }
  else {
    if (empty($array[$key])) {
      $array[$key] = array();
    }
    qtools_api__array_set($array[$key], $key_path, $value);
  }
}

/**
 * Set array keys corresponding to one of item property/key.
 *
 * If element is missing key property/key it will be removed from resulted array.
 *
 * @param $array
 *   (array) array we want to remap.
 * @param $key_path
 *   (str/array) keypath to new key value.
 *
 * @return
 *   (array) array keyyed with new keys.
 */
function qtools_api__array_remap($array, $key_path) {
  $res = array();

  // Return if given argument is not an array.
  if (!is_array($array)) {
    return $res;
  }

  // Remap array.
  foreach ($array as $key => $value) {
    $new_key = qtools_api__array_get($value, $key_path);
    $res[$new_key] = $value;
  }
  return $res;
}

/**
 * Plain array up to specified level.
 *
 * @param $arrays
 *   (array) multilevel array that we want to reduce in levels.
 * @param $level
 *   (int) how mane levels we want to plain (start from top).
 * @param $preserve_keys
 *   (bool) specify if we want to keep array leys of plained items,
 *   this may remove elements if they have same keys!
 *
 * @return
 *   (array) array plained.
 */
function qtools_api__array_plain($arrays, $level = 1, $preserve_keys = FALSE) {
  $result = array();

  foreach ($arrays as $array) {
    if (is_array($array)) {
      foreach ($array as $key => $item) {
        if ($preserve_keys) {
          $result[$key] = $item;
        }
        else {
          $result[] = $item;
        }
      }
    }
  }

  // Plain results.
  if ($level > 1) {
    $result = qtools_api__array_plain($result, $level - 1, $preserve_keys);
  }

  return $result;
}


/**
 * Convert array to object recurcive.
 */
function qtools_api__array_to_object($array, $depth = 0) {

  // If object supplied - fast return.
  if (!is_array($array)) {
    return $array;
  }

  // Flag if the we all keys suitable for conversation.
  $allowed = TRUE;

  foreach ($array as $key => $value) {

    $allowed = $allowed && !is_numeric($key);

    if (is_array($value)) {
      $array[$key] = qtools_api__array_to_object($value, $depth + 1);
    }
  }

  // If we allowed to convert this to object - convert.
  if ($allowed) {
    return (object) $array;
  }
  else {
    return $array;
  }
}

/**
 * Convert array to object recur.
 *
 * // TODO: recursion handle.
 */
function qtools_api__array_from_object($object, $depth = 0) {

  $result = array();

  foreach ((array)$object as $key => $value) {
    if (is_object($value) || is_array($value)) {
      $result[$key] = qtools_api__array_from_object($value, $depth + 1);
    }
    else {
      $result[$key] = $value;
    }
  }

  return $result;
}


/**
 * Prepare clean id.
 *
 * There is more fancy ways to do this, but I like to have a list of
 * accented chars on my hand :) .
 */
function qtools_api__id_clear($id) {

  $id = trim(drupal_strtolower($id));

  $replace = array(
    'à' => 'a',
    'â' => 'a',
    'á' => 'a',

    'é' => 'e',
    'è' => 'e',

    'í' => 'i',

    'ó' => 'o',
    'ô' => 'o',

    'ú' => 'u',
    'û' => 'u',

    'ç' => 'c',
    'ẃ' => 'w',
    'ý' => 'y',
  );

  $id = strtr($id, $replace);
  return $id;
}

/**
 * Bind type.
 */
function qtools_api__bind_type($value, $type, $recursive = FALSE) {
  if ($recursive && is_array($value)) {
    foreach ($value as &$_value) {
      $_value = qtools_api__bind_type($_value, $type, $recursive);
    }
  }
  else {
    switch ($type) {
      case 's':
        $value = (string) $value;
      break;
      case 'i':
        $value = (int) $value;
      break;
      case 'f':
        $value = (float) $value;
      break;
      case 'a':
        $value = (array) $value;
      break;
    }
  }

  return $value;
}

/**
 * Format time as 1 dimensional value.
 */
function qtools_api__time_past($value, &$dim = '') {

  // Lesser than a minute.
  if ($value < 60) {
    $dim = format_plural($value, 'second', 'seconds');
    return $value;
  }

  // Lesser than a hour.
  if ($value < 60 * 60) {
    $dim = format_plural(round($value / 60 ), 'minute', 'minutes');
    return round($value / 60);
  }

  // Lesser than a day.
  if ($value < 60 * 60 * 24) {
    $dim = format_plural(round($value / 60 / 60), 'hour', 'hours');
    return round($value / 60 / 60);
  }

  // Lesser than a month.
  if ($value < 60 * 60 * 24 * 30) {
    $dim = format_plural(round($value / 60 / 60 / 24), 'day', 'days');
    return round($value / 60 / 60 / 24);
  }

  // Lesser than a year.
  if ($value < 60 * 60 * 24 * 365) {
    $dim = format_plural(round($value / 60 / 60 / 24 / 30), 'month', 'monthes');
    return round($value / 60 / 60 / 24 / 30);
  }

  // More that a year.
  $dim = format_plural(round($value / 60 / 60 / 24 / 365), 'year', 'years');
  return round($value / 60 / 60 / 24 / 365);

}

/**
 * Decode unicode enteties.
 *
 * @see http://www.php.net/manual/en/function.preg-replace.php#76467
 */
function qtools_api__unicode_decode($str) {
  preg_replace_callback('#\\\u([0-9a-f]{4})#', "qtools_api__unicode_value", $str);
}

/**
 * Decode unicode enteties.
 *
 * @see http://www.php.net/manual/en/function.preg-replace.php#76467
 */
function qtools_api__unicode_value($matches) {

  $code = $matches[1];

  $value=hexdec($code);
  if ($value < 0x0080) {
    return chr($value);
  }
  elseif ($value < 0x0800) {
    return chr((($value&0x07c0)>>6)|0xc0) . chr(($value&0x3f)|0x80);
  }
  else {
    return chr((($value&0xf000)>>12)|0xe0) . chr((($value&0x0fc0)>>6)|0x80) . chr(($value&0x3f)|0x80);
  }
}

/**
 * Create ctools context wrapper (simplifyed version).
 *
 * @param $ctools_context_id
 *   (string) context ID (like "argument_entity_id:node_1").
 * @param $arg
 *   (mixed) context argument usually a string/int like node id.
 */
function qtools_api__ctools_context_create($ctools_context_id, $arg, $id =1, $settings = FALSE) {
  global $user;
  $context = NULL;

  ctools_include('context');
  ctools_include('plugins');

  $parts = explode('_', $ctools_context_id);
  $context_type = array_shift($parts);
  $id = array_pop($parts);
  $name = implode('_', $parts);

  // If this is argument.
  if ($context_type == 'argument') {
    $plugin = ctools_get_plugins('ctools', 'arguments', $name);
    $argument = array(
      'keyword' => $plugin['keyword'],
      'identifier' => $plugin['title'],
      'id' => $id,
      'name' => $name,
      'settings' => $settings,
    );
    $context = ctools_context_get_context_from_argument($argument, $arg);
  }
  elseif ($context_type == 'context') {
    $context = ctools_context_create($name, $arg, $settings);
  }
  else {
    // Some edge cases.
    switch ($context_type) {
      case 'account':
        $context = ctools_context_create('user', $arg, $settings);
        break;
      case 'logged-in-user':
        $context = ctools_context_create('user', $user->uid, $settings);
        break;
      case 'node':
        $context = ctools_context_create('node', $arg, $settings);
        break;
    }
  }

  return $context;
}

/**
 * Get handler(s) by name.
 *
 * @param $handler_id
 * (string) Handler ID/name.
 *
 * @return
 * (panels_display) Display object.
 */
function qtools_api__ctools_page_handler_get($handler_id = '') {

  $handlers = &drupal_static(__FUNCTION__, array());

  // Update handlers list.
  if (empty($handlers)) {
    ctools_include('export');

    // Get handlers from pages.
    $_tmp = ctools_export_load_object('page_manager_pages');
    $handlers = qtools_api__array_plain(array_filter(qtools_api__array_extract($_tmp, 'default_handlers')), 1, TRUE);

    // Get standalone handlers.
    $handlers = ctools_export_load_object('page_manager_handlers') + $handlers;
  }

  $handler = !empty($handler_id)
    ? $handlers[$handler_id]
    : $handlers;

  return $handler;
}

/**
 * Get panels display based on cache key.
 *
 * @param $handler_id
 * (string) Handler id
 * @param $task_id
 * (string) Task id
 * @param $plugin_id
 * (string) Plugin id
 *
 * @return
 * (object) Display object.
 */
function qtools_api__ctools_panels_display_get($handler_id, $task_id = NULL, $plugin_id = 'panel_context') {

  $display = NULL;

  // Load handler.
  if ($handler = qtools_api__ctools_page_handler_get($handler_id, $task_id)) {
    ctools_include('plugins');
    ctools_include('context');
    ctools_include('context-task-handler');
    ctools_include('plugins', 'panels');
    ctools_get_plugins('page_manager', 'task_handlers', $plugin_id);
    $display = panels_panel_context_get_display($handler);
  }

  return $display;
}

/**
 * Cache get, if cache locked - will wait for given amount of time.
 *
 * @param $cid
 *   (string) cache id.
 * @param $bin
 *   (string) cache bin.
 * @param $wait
 *   (int) wait time in seconds that we can wait for someone else to finish cache generation.
 * @param $stale
 *   (int) if cache is currently rebuilding we might be satisfied with older one if its not that old.
 *
 * @return
 *   (object) cache object.
 */
function qtools_api__cache_get($cid, $bin = 'cache', $wait = 3, $stale = 60) {

  $lid = 'qtools_api__cache_lock:' . $cid;

  // Check if we not rebuilding this $cid.
  if ($wait > 0 && !lock_may_be_available($lid)) {
    // Wait until lock is released.
    if (lock_wait($lid, $wait) == FALSE) {
      // If lock expire than someone finish cache build, so we no longer want see stale cache.
      $stale = 0;
    }
  }
  else {
    // Rely only on expire if wait = 0.
    $stale = 0;
  }

  // Load cache from a bin.
  $cache = cache_get($cid, $bin);

  // Reset cache if it is expire, or temporary.
  if (!empty($cache) && !empty($cache->expire) && ($cache->expire < (time() - $stale))) {
    $cache = NULL;
  }

  // Return cache if exists.
  return $cache;
}

/**
 * Cache start.
 *
 * Start cache chain and attempt to get lock on it.
 *
 * @param $cid
 *   (string) Cache id to start, will open tags chain with same name.
 * @param $lock
 *   (int) lock time in sec for this cache generation, lock may be freed earlier
 *   upon qtools_api__cache_set().
 *
 * @return
 *   (bool) TRUE if lock acquired.
 */

function qtools_api__cache_start($cid, $lock = 30) {

  // Prepare fresh tags array.
  $tags = &drupal_static('qtools_api__cache_tag', array());
  $tags[$cid] = array();

  // Attempt to aquire lock.
  $lid = 'qtools_api__cache_lock:' . $cid;
  return lock_acquire($lid, $lock);
}

/**
 * Normalize tag values.
 *
 * @param $tag
 *   (string/array) list (or one) tag, like node:123
 * @param $escape
 *   (bool) if TRUE will escape special chars.
 *
 * @return
 *   (array) array of prepared tags.
 */
function qtools_api__cache_tags_prepare($tag, $escape = FALSE) {
  $regex_special = array(
    '.' => '\\\.',
    '^' => '\\\^',
    '$' => '\\\$',
    '*' => '\\\*',
    '+' => '\\\+',
    '?' => '\\\?',
    '(' => '\\\(',
    ')' => '\\\)',
    '[' => '\\\[',
    '{' => '\\\{',
    '|' => '\\\|',
    '/' => '/',
  );
  if (!is_array($tag)) {
    $tag = array($tag);
  }
  // We use ; for concating, so replace it with dash.
  foreach ($tag as &$_tag) {
    $_tag = strtr($_tag, array(';' => '_'));
    // If asked to escape - escape for regex.
    if ($escape) {
      $_tag = strtr($_tag, $regex_special);
    }
  }
  return array_unique($tag);
}

/**
 * Return list of shorten tags.
 *
 * @return
 *   (array) list of tag types shortcuts.
 */
function qtools_api__cache_tag_short() {
  $short = &drupal_static(__FUNCTION__, array());
  if (!empty($short)) {
    return $short;
  }

  // Build new short array.
  $short = array(
    'entity:node' => 'n',
    'entity:user' => 'u',
    'entity:taxonomy_term' => 't',
    'entity:comment' => 'c',
    'node' => 'n',
    'node_comments' => 'nc',
    'user' => 'u',
    'taxonomy_term' => 't',
    'comment' => 'c',
    'page' => 'p',
  );
  drupal_alter('qtools_api__cache_tag_short', $short);
  return $short;
}

/**
 * Make simple tag.
 *
 * @param $type
 *   (string) tag type, like node or taxonomy_term.
 * @param $value
 *   (string/int) tag value like node nid.
 *
 * @return
 *   (string) cobmined tag like node|123 or node=123.
 */
function qtools_api__cache_tag($type, $value) {

  $short = qtools_api__cache_tag_short();

  if (!empty($short[$type])) {
    $type = $short[$type];
  }

  // Normalize tag.
  // Type should not contain separator.
  $type = str_replace(QTOOLS_TAG_EQUAL_SIGN, '_', $type);
  $tag = current(qtools_api__cache_tags_prepare($type . QTOOLS_TAG_EQUAL_SIGN . $value));
  return $tag;
}

/**
 * Make user custom tag.
 *
 * @param $type
 *   (string) type tag like userblocks.
 * @param $cachemode
 *   (int) cachemode, determinate tag value.
 * @param $account
 *   (user object) user account, determinate tag value.
 *
 * @return
 *   (string) cache tag with value based on cachemode.
 */
function qtools_api__cache_tag_cust($type, $cachemode = DRUPAL_CACHE_PER_USER, $account = NULL) {
  global $user;
  $account = !empty($account) ? $account : $user;
  if ($cachemode == DRUPAL_CACHE_PER_USER) {
    $tag = qtools_api__cache_tag($type, $account->uid);
  }
  elseif ($cachemode == DRUPAL_CACHE_PER_ROLE) {
    $roles = array_filter(array_keys($account->roles));
    sort($roles);
    $roles = implode('_', $roles);
    $tag = qtools_api__cache_tag($type, $roles);
  }
  else {
    $tag = qtools_api__cache_tag($type, $_GET['q']);
  }
  return $tag;
}

/**
 * Cache tag.
 *
 * If seed are not specified mark all opened cache pipes.
 * Note that any ';' will be replaced with dash.
 *
 * @param $tag
 *   (string/array) tag to be applied to cache chains.
 * @param $cids
 *   (array) list of chain ids to apply $tag to, empty = all open chains.
 *
 * @return
 *   (array) list of affected chains with their tags.
 */
function qtools_api__cache_tag_apply($tag, $cids = array()) {
  $tags = &drupal_static('qtools_api__cache_tag', array());
  $bans = &drupal_static('qtools_api__cache_ban', array());
  $keys = !empty($cids)
    ? $cids
    : array_keys($tags);

  // Normalize tag.
  $tag = qtools_api__cache_tags_prepare($tag);

  // Check for bans.
  if (!empty($bans['__global__'])) {
    $tag = array_diff($tag, $bans['__global__']);
  }

  $return = array();
  foreach ($keys as $key) {
    if (isset($tags[$key])) {
      // Check for bans.
      if (!empty($bans[$key])) {
        $_tag = array_diff($tag, $bans[$key]);
        $tags[$key] = array_unique(array_merge($tags[$key], array_values($_tag)));
      }
      else {
        $tags[$key] = array_unique(array_merge($tags[$key], array_values($tag)));
      }
      $return[$key] = $tags[$key];
    }
  }
  return $return;
}

/**
 * Cache tag remove.
 *
 * If seed are not specified unmark all opened cache pipes.
 * Note that any ';' will be replaced with dash.
 *
 * @param $tag
 *   (string/array) tag to be substracted from cache chains.
 * @param $cids
 *   (array) list of chain ids to substract $tag from, empty = all open chains.
 *
 * @return
 *   (array) list of affected chains with their tags.
 */
function qtools_api__cache_tag_remove($tag, $cids = array()) {
  $tags = &drupal_static('qtools_api__cache_tag', array());
  $keys = !empty($cids)
    ? $cids
    : array_keys($tags);

  // Normalize tag.
  $tag = qtools_api__cache_tags_prepare($tag);

  $return = array();
  foreach ($keys as $key) {
    if (isset($tags[$key])) {
      // Substract given tags from chain.
      $tags[$key] = array_diff($tags[$key], array_values($tag));
      $return[$key] = $tags[$key];
    }
  }
  return $return;
}

/**
 * Cache tag ban.
 *
 * If seed are not specified creates global ban.
 * Note that any ';' will be replaced with dash.
 *
 * @param $tag
 *   (string/array) tag to be banned from cache chains.
 * @param $cids
 *   (array) list of chain ids to ban $tag from, empty = all open chains.
 */
function qtools_api__cache_tag_ban($tag, $cids = array()) {
  $tags = &drupal_static('qtools_api__cache_tag', array());
  $bans = &drupal_static('qtools_api__cache_ban', array());
  $keys = !empty($cids)
    ? $cids
    : array_keys($tags);
  $ban_keys = !empty($cids)
    ? $cids
    : array('__global__');

  // Normalize tag.
  $tag = qtools_api__cache_tags_prepare($tag);

  // Substract given tags from chain.
  // @see qtools_api__cache_tag_remove().
  foreach ($keys as $key) {
    if (isset($tags[$key])) {
      $tags[$key] = array_diff($tags[$key], array_values($tag));
    }
  }

  // Save bans.
  foreach ($ban_keys as $key) {
    if (isset($bans[$key])) {
      $bans[$key] = array_unique(array_merge($bans[$key], array_values($tag)));
    }
    else {
      $bans[$key] = array_values($tag);
    }
  }
  return $bans;
}

/**
 * Get cache tags from ctools context.
 *
 * @param
 *   (array) list of ctools context object to fetch tags from.
 *
 * @return
 *   (array) list of tags that represent given context.
 */
function qtools_api__cache_tags_from($context) {
  $return = array();
  foreach ($context as $element) {
    if (!empty($element->argument)) {
      $type = is_array($element->type)
        ? reset($element->type)
        : $element->type;
      $return[] = qtools_api__cache_tag($type, $element->argument);
    }
  }
  return $return;
}

/**
 * Get cache tags for given chain id.
 *
 * @param $cid
 *   (string) cache id.
 * @param $clear
 *   (bool) specify if we want to clear tags for this cache chain.
 *
 * @return
 *   (array) list of tags applied to this cache chain.
 */
function qtools_api__cache_tags_for($cid, $clear = FALSE) {
  $tags = &drupal_static('qtools_api__cache_tag', array());
  $track_tags = !empty($tags[$cid]) ? $tags[$cid] : array();

  if ($clear && isset($tags[$cid])) {
    unset($tags[$cid]);
  }

  return $track_tags;
}

/**
 * Cache set, release lock, return applied tags.
 *
 * @param $cid
 *   (string) cache id.
 * @param $data
 *   (string) data to cache.
 * @param $bin
 *   (string) bin to place cache to.
 * @param $expire
 *   (int) cache TTL, see cache expire.
 *
 * @return
 *   (array) list of tags applied to this cache.
 */
function qtools_api__cache_set($cid, $data, $bin = 'cache', $expire = CACHE_PERMANENT) {

  $track_tags = qtools_api__cache_tags_for($cid);

  // Add tags to cache object if required.
  if (is_array($data) && isset($data['tags']) && is_array($data['tags'])) {
    $data['tags'] = array_unique(array_merge($data['tags'], $track_tags));
  }

  // Set cache.
  cache_set($cid, $data, $bin, $expire);

  // Release lock.
  $lid = 'qtools_api__cache_lock:' . $cid;
  lock_release($lid);

  // Return tags.
  return $track_tags;
}
