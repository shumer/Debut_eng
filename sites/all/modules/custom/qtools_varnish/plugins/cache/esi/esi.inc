<?php

/**
 * @file
 * Provides a simple time-based caching option for panel panes.
 */

// Plugin definition.
$plugin = array(
  'title' => t("QTools ESI cache"),
  'description' => t('Provide ESI tag placeholder instead of content to be cached by ESI handler.'),
  'cache get' => 'qtools_varnish_esi_cache_get_cache',
  'cache set' => 'qtools_varnish_esi_cache_set_cache',
  'cache clear' => 'qtools_varnish_esi_cache_clear_cache',
  'settings form' => 'qtools_varnish_esi_cache_settings_form',
  'settings form submit' => 'qtools_varnish_esi_cache_settings_form_submit',
  'defaults' => array(
    'ttl' => 15,
    'cachemode' => DRUPAL_CACHE_PER_PAGE,
    'options' => array(
      'context' => TRUE,
    ),
  ),
);

/**
 * Get cached content.
 * Placeholder as caching will be done by ESI handler.
 */
function qtools_varnish_esi_cache_get_cache($conf, $display, $args, $contexts, $pane = NULL) {
  return FALSE;
}

/**
 * Set cached content.
 * Replace actual output with ESI tag.
 */
function qtools_varnish_esi_cache_set_cache($conf, $content, $display, $args, $contexts, &$pane = NULL) {
  global $user;

  // If no ESI support by backend - exit.
  // TODO: fallback to DB cache.
  if (!qtools_varnish_enabled()) {
    return;
  }

  // Extract context.
  $context = array_filter(qtools_api__array_extract((array) $contexts, 'argument'));
  ksort($context);

  // Select cache mode.
  $cachemode = $conf['cachemode'];
  $path = $_GET['q'];
  if (!empty($conf['nocontext']) || ($cachemode < 0)) {
    $context = array();
  }
  if ($cachemode < 0) {
    $cachemode = -$cachemode;
    $path = '';
  }

  // Extract display info, this approach will support both old and newer panels.
  $display_info = array_values(array_filter(explode(':', $display->cache_key)));
  // Plugin ID.
  $esi_id_array[0] = $display_info[0];

  // Task ID.
  $esi_id_array[1] = $display_info[1];

  // Handler ID.
  $esi_id_array[2] = $display_info[2];

  // Pane info.
  $esi_id_array[3] = $pane->pid;
  $esi_id_array[4] = $pane->panel;
  $esi_id_array[5] = $pane->type;
  $esi_id_array[6] = $pane->subtype;
  $esi_id = implode(':', $esi_id_array);

  // Base ESI args.
  $esi_args = array_filter(array(
    'context' => $context,
    'nocontext' => $conf['nocontext'],
    'path' => $path,
  ));

  // Set style to default, preventing overwriting of our ESI tag.
  $pane->style['style'] = 'default';
  $pane->style['settings'] = NULL;

  // Generate ESI tag.
  $esi_tag = qtools_varnish_esi_tag(QTOOLS_VARNISH_ESI_TYPE_PANE, $esi_id, $cachemode, $esi_args);
  $printed_content = qtools_varnish_wrap($esi_tag);

  $content->content->content = $printed_content;
}

/**
 * Clear cached content.
 * Placeholder as cache stored on ESI handler side.
 */
function qtools_varnish_esi_cache_clear_cache($display) {
}

/**
 * Settings form.
 */
function qtools_varnish_esi_cache_settings_form($conf, $display, $pid) {

  $form['info'] = array(
    '#type' => 'markup',
    '#markup' => t('<div>Note that this cache may (in rare cases) not be suitable for some panes, so always test your result.</div>'),
  );

  $options = drupal_map_assoc(array(3, 5, 10, 15, 30, 60, 120, 180, 240, 300, 600, 900, 1200, 1800, 3600, 7200, 14400, 28800, 43200, 86400, 172800, 259200, 345600, 604800), 'format_interval');
  $options[-1] = t('Pass through');
  ksort($options);
  $form['ttl'] = array(
    '#title' => t('Lifetime'),
    '#description' => t('We send this TTL to ESI handler, this is not drupal related cache time.'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['ttl'],
  );

  $options2 = array(
    -DRUPAL_CACHE_PER_PAGE => t('Shared'),
    -DRUPAL_CACHE_PER_ROLE => t('Per User Roles'),
    -DRUPAL_CACHE_PER_USER => t('Per User ID'),
    DRUPAL_CACHE_PER_PAGE => t('Context + Per page'),
    DRUPAL_CACHE_PER_ROLE => t('Context + Per page + Per User Roles'),
    DRUPAL_CACHE_PER_USER => t('Context + Per page + Per User ID'),
  );

  $form['cachemode'] = array(
    '#title' => t('Cache granularity (Cache bin)'),
    '#description' => t('Choosing those will increase cache relevance, but reduce performance.'),
    '#type' => 'select',
    '#options' => $options2,
    '#default_value' => $conf['cachemode'],
  );

  $form['nocontext'] = array(
    '#title' => t('Ignore context'),
    '#description' => t('Ithis will remove Context granularity from above(Recommended for "Panels everywhere" Site template).'),
    '#type' => 'checkbox',
    '#default_value' => $conf['nocontext'],
  );

  $form['cachetags'] = array(
    '#title' => t('Custom tags'),
    '#description' => t('Custom cache tags types comma (,) separated, no values or pipes (|) should be supplied, those should be backed by your code.'),
    '#type' => 'textarea',
    '#default_value' => $conf['cachetags'],
  );

  return $form;
}
