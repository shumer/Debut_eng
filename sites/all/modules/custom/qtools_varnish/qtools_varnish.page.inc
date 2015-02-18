<?php
/**
 * @file
 * Page callbacks for the module.
 */

/**
 * Render custom ESI block.
 */
function qtools_varnish_page_esi_block_render($identifier, $variables) {

  // Reference to debug array.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  // Get module and block_id.
  $tmp = explode('-', $identifier);
  $module = array_shift($tmp);
  $block_id = implode('-', $tmp);

  $function = $module . '_qtools_varnish_esi_block';
  if (function_exists($function)) {
    $result = $function($block_id, $variables);
  }
  else {
    $result = QTOOLS_VARNISH_ERR_DATA;
  }

  return $result;
}

/**
 * Render User blocks.
 */
function qtools_varnish_page_esi_userblocks_render($identifier, $variables) {
  global $user;

  // Reference to debug array.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  $content = array();

  // Gather user specific content, note that this is placed inline to update
  // targets before drupal behaviors.
  $js_data = array();
  $user_data = module_invoke_all('qtools_varnish_userblocks');

  // Parse returned data.
  foreach ($user_data as $target => $data) {
    if (is_array($data)) {
      $js_data[$target] = $data;
    }
    elseif (is_string($data)) {
      $content[] = '<div class="qtools_varnish_userblock-item" data-target="' . $target . '">' . $data . '</div>';
    }
  }

  // Wrap content and add inline JS to make shure JS is present if this block is present.
  $debug = _qtools_varnish_settings('general', 'debug', FALSE);

  $content[] = '<script type="text/javascript">
  var _qtools_varnish_debug = ' . $debug . ';
  if (_qtools_varnish_debug) {
    qtools.log("QTV:user_blocks", jQuery("#qtools_varnish_userblocks .qtools_varnish_userblock-item"));
  }
  jQuery("#qtools_varnish_userblocks .qtools_varnish_userblock-item").each(function () {
    var $this = jQuery(this);
    var $target = jQuery($this.attr("data-target"));
    if ($target.length > 0) {
      $target.replaceWith($this.html());
    }
  });' . 'jQuery.extend(true, Drupal.settings, ' . drupal_json_encode(drupal_array_merge_deep_array($js_data)) . ');'
  . '</script>';

  $content = implode(PHP_EOL, $content);
  $content = '<div id="qtools_varnish_userblocks" style="display:none;" time="' . time() . '">' . $content . '</div>';

  // Return actual content and set desired TTL.
  $cache_tags = array();
  $tags = explode(',', _qtools_varnish_settings('userblocks', 'cachetags', 'user'));
  $tags[] = QTOOLS_VARNISH_TAG_USER_BLOCKS;
  foreach ($tags as $tag) {
    if (trim($tag) != '') {
      $cache_tags[] = qtools_api__cache_tag_cust($tag, DRUPAL_CACHE_PER_USER);
    }
  }

  // Apply tags.
  qtools_api__cache_tag_apply($cache_tags);

  // Return actual content and set desired TTL.
  // Grace for user block is 0 by design.
  return array(
    'content' => $content,
    'ttl' => _qtools_varnish_settings('userblocks', 'ttl', -1),
    'grace' => 0,
  );
}

/**
 * Render one given pane, respecting context, visibility and styling.
 */
function qtools_varnish_page_esi_pane_render($identifier, $variables, $signature) {
  global $user;

  // Reference to debug array.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  // Parse identifier, exit if missing some params.
  $identifier = explode(':', $identifier);
  if (count($identifier) != 7) {
    return QTOOLS_VARNISH_ERR_PARAMS_MISSING;
  }

  // Extract variables from request.
  $tail_args = (!empty($variables['tail_args']) && is_array($variables['tail_args']))
    ? $variables['tail_args']
    : array();

  $context = (!empty($variables['context']) && is_array($variables['context']))
    ? $variables['context']
    : array();

  $cachemode = !empty($variables['cachemode'])
    ? $variables['cachemode']
    : DRUPAL_CACHE_PER_PAGE;
  ksort($context);

  // Load display, exit if none.
  $display = qtools_api__ctools_panels_display_get($identifier[2], $identifier[1], $identifier[0]);
  if (empty($display)) {
    return QTOOLS_VARNISH_ERR_DISPLAY_NONE;
  }

  // Extract our pane, exit if none.
  $pane = $display->content[$identifier[3]];
  if (empty($pane)) {
    return QTOOLS_VARNISH_ERR_PANE_NONE;
  }

  // Populate context.
  foreach ($context as $cid => &$cdata) {
    $cdata = qtools_api__ctools_context_create($cid, $cdata);
  }
  $display->context = $context;

  // If this pane is not visible to the user, skip out and do the next one.
  if (empty($pane->shown) || !panels_pane_access($pane, $display)) {
    return QTOOLS_VARNISH_ERR_EMPTY;
  }

  // Looks like we are ready to actually render our pane.
  $content = _qtools_varnish_get_themed_pane($pane, $display, $context, $tail_args);

  // Tag all caches with all context.
  $context_tags = qtools_api__cache_tags_from($context);
  foreach ($context_tags as $context_tag) {
    qtools_api__cache_tag_apply($context_tag);
  }
  // Tag all caches with custom tags.
  $cache_settins = $pane->cache['settings'];
  $cust_tags = !empty($cache_settins['cachetags'])
    ? explode(',', $cache_settins['cachetags'])
    : array();
  foreach ($cust_tags as $cust_tag) {
    $cust_tag = qtools_api__cache_tag_cust($cust_tag, $cachemode);
    qtools_api__cache_tag_apply($cust_tag);
  }

  // Return actual content and set desired TTL.
  return array(
    'content' => $content,
    'ttl' => !empty($cache_settins['ttl']) ? $cache_settins['ttl'] : -1,
  );
}

/**
 * Prepare environment.
 */
function _qtools_varnish_page_environment($esi_args = NULL) {

  // If esi args not suplied then we need to restore environment.
  if ($esi_args === NULL) {

    // Restore REQUEST_URI.
    $_SERVER['REQUEST_URI'] = qtools_option('qtools_varnish_esi:request_uri', NULL, $_SERVER['REQUEST_URI']);

    // Restore drupal path.
    $_GET['q'] = qtools_option('qtools_varnish_esi:get_q', NULL, $_GET['q']);
    $_REQUEST['q'] = qtools_option('qtools_varnish_esi:request_q', NULL, $_REQUEST['q']);
    return;
  }

  // Save current values.
  qtools_option('qtools_varnish_esi:request_uri', $_SERVER['REQUEST_URI']);
  qtools_option('qtools_varnish_esi:get_q', $_GET['q']);
  qtools_option('qtools_varnish_esi:request_q', $_REQUEST['q']);

  // Prepare environment (default homepage).
  $path = (!empty($esi_args['path']) && is_string($esi_args['path']))
    ? $esi_args['path']
    : NULL;

  // Read menu item for specified path.
  if ($path != NULL) {
    $menu_item = menu_get_item($path);

    // Exit if user don't have access to this path.
    if (empty($menu_item['access']) ) {
      return QTOOLS_VARNISH_ERR_MENU_DENIED;
    }

    // Build tail args.
    $tail_args = explode('/', $path);
    array_splice($tail_args, 0, count(explode('/', $menu_item['path'])));
  }
  else {
    // Unset REQUEST URI if path empty.
    // TODO: WHY? something connected to drupal default cache.
    //$_SERVER['REQUEST_URI'] = '';

    // Empty tail args.
    $tail_args = array();
  }

  // Set server REQUEST_URI to path, this is needed for forms.
  // @see request_uri().
  $_SERVER['REQUEST_URI'] = ($path != variable_get('site_frontpage', 'node'))
    ? '/' . $path
    : '/';

  // Set drupal path.
  $_GET['q'] = $path;
  $_REQUEST['q'] = $path;

  // Return tail args or error code.
  return $tail_args;
}

/**
 * Dispatcher for ESI.
 */
function qtools_varnish_page_esi($esi_type, $esi_id, $signature = '') {

  // Log incoming ESI request.
  $debug = _qtools_varnish_settings('general', 'debug', FALSE);
  if ($debug) {
    if (_qtools_varnish_settings('general', 'logging', FALSE)) {
      watchdog('qtools_varnish:ESI', '(@esi_type, @esi_id, @signature)', array(
        '@esi_type' => $esi_type,
        '@esi_id' => $esi_id,
        '@signature' => $signature,
      ));
    }
  }

  $content = '';

  // Reference to debug content.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  // Get arguments.
  $esi_args = !empty($_GET['a']) ? $_GET['a'] : array();
  $cachemode = !empty($_GET['cachemode']) ? $_GET['cachemode'] : DRUPAL_CACHE_PER_USER;

  // Validate signature.
  $new_sig = qtools_varnish_get_signature($esi_type, $esi_id, $cachemode, $esi_args);
  if ($new_sig != $signature) {
    // Signature error.
    $error = QTOOLS_VARNISH_ERR_SIGNATURE_FAIL;
  }
  else {
    // Mark request as contained ESI.
    qtools_option('qtools_varnish:esi_rendered', TRUE);

    // Set environment.
    $tail_args = _qtools_varnish_page_environment($esi_args);

    // If tail_args are not array - this is an error.
    if (!is_array($tail_args)) {
      $result = $tail_args;
    }
    else {
      // Dispatch esi.
      $handler = qtools_varnish_esi_handler($esi_type);
      if (!empty($handler) && !empty($handler['callback'])) {

        // Include callback file.
        if (!empty($handler['include'])) {
          module_load_include($handler['include'][0], $handler['include'][1], $handler['include'][2]);
        }

        // Get result.
        if (function_exists($handler['callback'])) {
          // Add cachemode to the arguments.
          $variables = $esi_args;
          $variables['cachemode'] = $cachemode;
          $variables['tail_args'] = $tail_args;
          $result = $handler['callback']($esi_id, $variables, $signature);
        }
        else {
          $result = QTOOLS_VARNISH_ERR_CALLBACK;
        }

        // Valid result should be an array.
        if (!is_array($result)) {
          $error = $result;
        }
        else {
          // Extract content to return.
          $content = qtools_varnish_wrap($result['content'], FALSE);

          // Set page ttl.
          $cache_tags = qtools_api__cache_tags_for(QTOOLS_VARNISH_CACHE_ID_PAGE);
          qtools_varnish_set_page_ttl($result['ttl'], $cache_tags);
        }
      }
      else {
        // Handler error.
        $error = QTOOLS_VARNISH_ERR_HANDLER;
      }
    }
  }

  // TODO: log error.
  if (!empty($error)) {
    // Log error.
    $content = '<!-- ' . $error . ' -->';
  }

  // Add messages to debug content.
  $debug_content[] = theme('status_messages');
  array_filter($debug_content);

  // Add debug content.
  if (!empty($debug) && !empty($debug_content)) {
    $content = implode("\r\n<br>", $debug_content) . $content;
  }

  // Print content end exit.
  print $content;
  die;
}
