<?php
/**
 * @file
 * Page callbacks for the module.
 */

/**
 * Implements hook_esi_api_TYPE_render().
 *
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
    'grace' => !empty($cache_settins['grace']) ? $cache_settins['grace'] : 0,
  );
}

/**
 * Dispatcher for ESI.
 */
function qtools_varnish_page_esi($esi_type, $esi_id, $signature = '') {

  // Content initialisation.
  $content = '';

  // Reference to debug content.
  $debug_content = drupal_static('qtools_varnish_page_esi_debug_content', array());

  // Get arguments.
  $esi_args = !empty($_GET['a']) ? $_GET['a'] : array();

  // Validate signature.
  $new_sig = qtools_varnish_get_signature($esi_type, $esi_id, $esi_args);
  if ($new_sig != $signature) {
    $error = QTOOLS_VARNISH_ERR_SIGNATURE_FAIL;
  }
  else {
    // TODO: actual dispatcher.
    if ($esi_type == QTOOLS_VARNISH_ESI_TYPE_PANE) {

      // Mark request as contained ESI.
      qtools_option('qtools_varnish:esi_rendered', TRUE);

      // Get result.
      $result = qtools_varnish_page_esi_pane_render($esi_id, $esi_args, $signature);

      // Valid result should be an array.
      if (!is_array($result)) {
        $error = $result;
      }
      else {
        // Extract content to return.
        $content = $result['content'];

        // Set page ttl.
        $cache_tags = qtools_api__cache_tags_for(QTOOLS_VARNISH_CACHE_ID_PAGE);
        qtools_varnish_set_page_ttl($result['ttl'], $cache_tags, $result['grace']);
      }
    }
  }

  // TODO: log error.
  if (!empty($error)) {
    // Log error.
  }

  // Add debug content.
  $debug_content[] = theme('status_messages');

  // Print content end exit.
  print implode("\r\n<br>", $debug_content) . $content;
  die;
}
