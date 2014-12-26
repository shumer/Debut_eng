<?php
/**
 * @file
 * Page callbacks for the module.
 */

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
  $content[] = '<script type="text/javascript">
  jQuery("#qtools_varnish_userblocks .qtools_varnish_userblock-item").each(function () {
    var $this = jQuery(this);
    jQuery($this.attr("data-target")).replaceWith($this.html());
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

  // Return actual content and set desired TTL.
  // Grace for user block is 0 by design.
  return array(
    'content' => qtools_varnish_wrap($content, FALSE),
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
  $path = (!empty($variables['path']) && is_string($variables['path']))
    ? $variables['path']
    : NULL;

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

  // Read menu item for specified path.
  if (!empty($path)) {
    $menu_item = menu_get_item($path);

    // Exit if user dont have access to this path.
    if (empty($menu_item['access']) ) {
      return QTOOLS_VARNISH_ERR_MENU_DENIED;
    }

    // Build tail args.
    $tail_args = explode('/', $path);
    array_splice($tail_args, 0, count(explode('/', $menu_item['path'])));

  }
  else {
    // Unset REQUEST URI if path empty.
    if (empty($path)) {
      $request_uri = $_SERVER['REQUEST_URI'];
      $_SERVER['REQUEST_URI'] = '';
    }

    // Empty tail args.
    $tail_args = array();
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

  // Set drupal path.
  $_path = $_GET['q'];
  $_GET['q'] = $path;
  $_REQUEST['q'] = $path;

  // Looks like we are ready to actually render our pane.
  $content = _qtools_varnish_get_themed_pane($pane, $display, $context, $tail_args);

  // Restore path.
  $_GET['q'] = $_path;
  $_REQUEST['q'] = $_path;
  if (!empty($request_uri)) {
    $_SERVER['REQUEST_URI'] = $request_uri;
  }

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
    'content' => qtools_varnish_wrap($content, FALSE),
    'ttl' => !empty($cache_settins['ttl']) ? $cache_settins['ttl'] : -1,
  );
}

/**
 * Dispatcher for ESI.
 */
function qtools_varnish_page_esi($esi_type, $esi_id, $signature = '') {

  $content = '';

  // Reference to debug content.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  // Get arguments.
  $esi_args = !empty($_GET['a']) ? $_GET['a'] : array();

  // Validate signature.
  $new_sig = qtools_varnish_get_signature($esi_type, $esi_id, $esi_args);
  if ($new_sig != $signature) {
    // Signature error.
    $error = QTOOLS_VARNISH_ERR_SIGNATURE_FAIL;
  }
  else {
    // Mark request as contained ESI.
    qtools_option('qtools_varnish:esi_rendered', TRUE);

    // Dispatch esi.
    $handler = qtools_varnish_esi_handler($esi_type);
    if (!empty($handler) && !empty($handler['callback'])) {

      // Get result.
      if (function_exists($handler['callback'])) {
        $result = $handler['callback']($esi_id, $esi_args, $signature);
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
        $content = $result['content'];

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

  // TODO: log error.
  if (!empty($error)) {
    // Log error.
    $content = '<!-- ' . $error . ' -->';
  }

  // Add debug content.
  // NOT CACHE MESSAGES!.
  $debug_content[] = theme('status_messages');

  // Print content end exit.
  print implode("\r\n<br>", $debug_content) . $content;
  die;
}
