<?php
/**
 * @file
 * Logic and API.
 */

/**
 * Apply tags to open cache chains from loaded entitys.
 *
 * This should be called inside ::load() entity controller's method.
 */
function _cache_common_cache_tags_apply($entity_type, $entities) {
  // Build default tag set.
  foreach ($entities as $entity) {
    $ids = entity_extract_ids($entity_type, $entity);
    $tags[] = qtools_api__cache_tag($entity_type, $ids[0]);

    // For comments we also track groupped node tag.
    if ($entity_type == 'comment') {
      $tag_node_comments = qtools_api__cache_tag('node_comments', $entity->nid);
      if (!in_array($tag_node_comments, $tags)) {
        $tags[] = $tag_node_comments;
      }
    }
  }

  // Allow other modules to alter applied tags.
  drupal_alter('cache_common_cache_tags_apply', $tags, $entity_type, $entities);

  // Apply tags if have any.
  if (!empty($tags)) {
    qtools_api__cache_tag_apply($tags);
  }
}

/**
 * Clear cache based on tag.
 */
function cache_common_cache_clear($tags) {
  global $user;

  if (is_array($tags)) {
    $tags = array_filter($tags);
  }

  // Do nothing if tags table not created.
  if (!db_table_exists(CACHE_COMMON_TABLE_CACHE_TAGS)) {
    return;
  }

  // Clear all table if tags = *; and return.
  if ($tags == '*') {
    watchdog('cache_common_cache:clear', 'truncate');
    return db_truncate(CACHE_COMMON_TABLE_CACHE_TAGS)->execute();
  }
  if (empty($tags)) {
    watchdog('cache_common_cache:clear', '!uid empty', array('!uid' => $user->uid));
    return;
  }

  // Make sure tags is array past this point.
  if (!is_array($tags)) {
    $tags = array($tags);
  }

  // Build or condition.
  $or = db_or();
  foreach ($tags as $tag) {
    $or->condition('tags', '%' . $tag . ';%', 'LIKE');
  }
  $result = db_select(CACHE_COMMON_TABLE_CACHE_TAGS)
    ->fields(CACHE_COMMON_TABLE_CACHE_TAGS, array('cid', 'expire'))
    ->condition($or)
    ->condition('bin', CACHE_COMMON_CACHE_BIN)
    ->execute()->fetchAllAssoc('cid');

  // Extract cache IDs.
  $cids = array_keys($result);

  if (variable_get('cache_common_cache_clear_log', TRUE)) {
    watchdog('cache_common_cache:clear', '!uid [!tags] [!cids]', array(
      '!uid' => $user->uid,
      '!tags' => implode(', ', $tags),
      '!cids' => implode(', ', $cids)
    ));
  }

  // Exit if nothing to do.
  if (empty($result)) {
    return;
  }

  // Clear cache for those IDs.
  cache_clear_all($cids, CACHE_COMMON_CACHE_BIN);

  // Clear own references.
  return db_delete(CACHE_COMMON_TABLE_CACHE_TAGS)
    ->condition('cid', $cids, 'IN')
    ->condition('bin', CACHE_COMMON_CACHE_BIN)
    ->execute();
}

/**
 * Mark cache with custom tags.
 */
function cache_common_cache_tag($cache_id, $cache_tags, $expire = CACHE_PERMANENT) {
  global $user;

  // Do nothing if tags table not created.
  if (!db_table_exists(CACHE_COMMON_TABLE_CACHE_TAGS)) {
    return;
  }

  $fields = array(
    'cid' => $cache_id,
    'bin' => CACHE_COMMON_CACHE_BIN,
    'expire' => $expire,
    'tags' => '-' . implode(';', $cache_tags) . ';-',
  );

  db_merge(CACHE_COMMON_TABLE_CACHE_TAGS)
    ->key(array('cid' => $cache_id))
    ->fields($fields)
    ->execute();

  if (variable_get('cache_common_cache_tag_log', TRUE)) {
    watchdog('cache_common_cache:tag', '!uid !cid [!tags]', array(
      '!uid' => $user->uid,
      '!tags' => implode(', ', $cache_tags),
      '!cid' => $cache_id
    ));
  }
}

/**
 * Retusr single field content.
 */
function cache_common_field_content($entity_type, $entity, $field_name, $view_mode = 'full', $fallback = TRUE) {

  $content = array();
  $ids = entity_extract_ids($entity_type, $entity);
  // Sanity check.
  if (empty($entity)) {
    return $content;
  }
  $bundle = $ids[2];
  if (empty($bundle)) {
    return $content;
  }

  // Render field.
  $field = field_info_field($field_name);
  $instance = field_info_instance($entity_type, $field_name, $bundle);
  if (!empty($field) && !empty($instance)) {
    $display = field_get_display($instance, $view_mode, $entity);
    if ($display['type'] != 'hidden') {
      $content = field_view_field($entity_type, $entity, $field_name, $display);
    }
    elseif ($fallback) {
      $content = field_view_field($entity_type, $entity, $field_name);
    }

    // Remove label and bind view_mode.
    if (!empty($content)) {
      $content['#label_display'] = 'hidden';
      $content['#view_mode'] = $view_mode;
    }
  }
  return $content;
}

/**
 * Tag cache functions.
 */
function cache_common_cache_track($chain_id = NULL) {
  $tracked_chain = &drupal_static('_cache_common_tracked_chain', array());
  if (empty($chain_id)) {
    $chain_id = uniqid();
    $tracked_chain[$chain_id] = array();
    $result = $chain_id;
  }
  else {
    $result = $tracked_chain[$chain_id];
    unset($tracked_chain[$chain_id]);
  }
  return $result;
}

/**
 * Render given entity.
 */
function cache_common_entity_render($entity_type, $entity, $view_mode = 'full', $langcode = NULL) {
  global $language, $user, $theme;

  // Do not cache by default.
  $cache_ttl = -1;
  $cache_action = 0;

  // Extract ids.
  $ids = entity_extract_ids($entity_type, $entity);
  $entity_bundle = $ids[2];
  $entity_id = $ids[0];

  $cache_id = implode(':', array(
    $entity_type,
    $entity_bundle,
    $entity_id,
    $view_mode,
    implode('_', array_keys($user->roles)),
    ($langcode ? $langcode : $language->language),
    $theme,
  ));

  // Start performance timer.
  timer_start($cache_id);

  // Check if we should cache this entity render and we not in admin theme.
  $admin_theme = variable_get('admin_theme', 0); //
  if ((cache_common_setting('re_cache', 'enabled', FALSE) == TRUE) && ($theme != $admin_theme)) {
    $rules = explode(PHP_EOL, cache_common_setting('re_cache', 'rules', ''));
    foreach ($rules as $rule) {
      $match = TRUE;

      // Check for empty string or comment line.
      $line = trim($rule);
      if (empty($line) || (mb_substr($line, 0, 1,"UTF-8") == '#')) {
        continue;
      }

      $rule = explode('|', trim($rule));
      if (($rule[0] != '*') && ($rule[0] != $entity_type)) {
        $match = FALSE;
      }
      if (($rule[1] != '*') && ($rule[1] != $entity_bundle)) {
        $match = FALSE;
      }
      if (($rule[2] != '*') && ($rule[2] != $view_mode)) {
        $match = FALSE;
      }
      if ($match) {
        $cache_ttl = $rule[3];
        break;
      }
    }
  }

  // Fast exit if cache TTL <= 0.
  if ($cache_ttl <= 0) {
    $content = cache_common_entity_content($entity_type, $entity, $view_mode, $langcode);
    $html = drupal_render($content);
  }
  else {

    // Track cache ids.
    $cache = qtools_api__cache_get($cache_id, CACHE_COMMON_CACHE_BIN);
    if (!empty($cache)) {
      $html = $cache->data['html'];

      // Merge Recursive JS && CSS.
      $css = &drupal_static('drupal_add_css', array());
      $javascript = &drupal_static('drupal_add_js', array());
      if (!empty($cache->data['css_diff'])) {
        $css = qtools_api__array_extend($css, $cache->data['css_diff']);
      }
      if (!empty($cache->data['js_diff'])) {
        $javascript = qtools_api__array_extend($javascript, $cache->data['js_diff']);
      }

      // We should also apply tags from inner cache to outer.
      if (!empty($cache->data['tags'])) {
        qtools_api__cache_tag_apply($cache->data['tags']);
      }
      $cache_action = 1;
    }
    else {
      $locked = qtools_api__cache_start($cache_id);
      $css_start = drupal_add_css();
      $js_start = drupal_add_js();
      $content = cache_common_entity_content($entity_type, $entity, $view_mode, $langcode);
      $html = drupal_render($content);

      if ($locked) {

        // Self mark.
        qtools_api__cache_tag_apply(qtools_api__cache_tag($entity_type, $ids[0]));

        // Gather added JS & CSS.
        $css_end = drupal_add_css();
        $js_end = drupal_add_js();

        $css_diff = qtools_api__array_diff($css_end, $css_start);
        $js_diff  = qtools_api__array_diff($js_end, $js_start);

        // We need to pass through our render cache statistic.
        if (!empty($js_diff['settings']['data'])) {
          $js_diff['settings']['data'] = qtools_api__array_filter($js_diff['settings']['data'], 'cache_common', NULL, 'empty');
        }
        // Combine cache object with metadata.
        $cache = array(
          'html' => $html,
          'js_diff' => $js_diff,
          'css_diff' => $css_diff,
          'tags' => array(),
        );
        $expire = time() + $cache_ttl;
        $tags = qtools_api__cache_set($cache_id, $cache, CACHE_COMMON_CACHE_BIN, $expire);
        cache_common_cache_tag($cache_id, $tags, $expire);
        $cache_action = '2:' . $cache_ttl;
      }
      else {
        $cache_action = 3;
      }
    }
  }

  // Add cache actiona and statistic to JS for debug.
  $elapsed = timer_stop($cache_id);
  $info = $cache_action . ' - ' . $elapsed['time'] . ' - ' . time();
  drupal_add_js(array('cache_common' => array('render_cache' => array($cache_id => $info))), 'setting');
  return $html;
}

/**
 * Proxy enrity view functions so we can cache or wrap all output.
 *
 * This will preload entity if required.
 */
function cache_common_entity_content($entity_type, &$entity, $view_mode = 'full', $langcode = NULL) {
  $content_static = &drupal_static(__FUNCTION__, array());

  // Preload entity if required.
  if (is_numeric($entity)) {
    $entity_id = $entity;
    if ($entity = entity_load($entity_type, array($entity_id))) {
      $entity = reset($entity);
    }
  }

  // At this point we should have entity object.
  if (is_object($entity)) {
    $ids = entity_extract_ids($entity_type, $entity);
    $entity_id = $ids[0];
  }
  else {
    return array();
  }


  // Check if we have this content already built.
  if (!empty($content_static[$entity_type][$entity_id][$view_mode])) {
    return $content_static[$entity_type][$entity_id][$view_mode];
  }

  // Build content for selected entity.
  switch ($entity_type) {
    case 'node':
      $content = node_view($entity, $view_mode, $langcode);

      break;
    default:
      $content = entity_view($entity_type, array($entity), $view_mode, $langcode);
      $content = $content[$entity_type][$entity_id];
      break;
  }

  // Save static cache.
  $content_static[$entity_type][$entity_id][$view_mode] = $content;

  return $content;
}

/**
 * Safe nodeload proxy function.
 */
function cache_common_load_node($nid, $safe = TRUE, $as_anonym = FALSE) {
  global $language, $user;
  if (!is_numeric($nid)) {
    return;
  }
  $tracked_chain = &drupal_static('_cache_common_tracked_chain', array());
  $chain_id = uniqid('n:' . $nid);
  $tracked_chain[$chain_id] = array();

  $account = (CACHE_COMMON_VAR_FORCE_ACCESS_ANONYM || $as_anonym)
    ? drupal_anonymous_user()
    : $user;

  $return = NULL;

  if (!empty($nid) && is_numeric($nid)) {
    $return = node_load($nid);
    if ($safe && !node_access('view', $return, $account)) {
      $return = NULL;
    }
  }

  if (is_object($return)) {
    if (!empty($return->_cache_chain)) {
      $return->_cache_chain = array_merge_recursive($return->_cache_chain, $tracked_chain[$chain_id]);
    }
    else {
      $return->_cache_chain = $tracked_chain[$chain_id];
    }
  }

  unset($tracked_chain[$chain_id]);
  return $return;
}

/**
 * Get specific cache_common setting.
 */
function cache_common_setting($block, $key = NULL, $default_value = NULL) {
  $conf = variable_get('cache_common_settings', array());
  $result = !empty($conf[$block])
    ? $conf[$block]
    : array();
  if (!empty($key)) {
    $result = isset($result[$key])
      ? $result[$key]
      : $default_value;
  }
  return $result;
}

/**
 * Field render proxy.
 */
function cache_common_refence_field_render($parent_entity, $entity_type = 'node', $item = array(), $mode = 'full', $key = NULL, $last_delta = FALSE) {

  $entity_id = $item['target_id'];

  // Get entity.
  $entity = cache_common_load_entity_single($entity_type, $entity_id);

  // Exit if no entity loaded.
  if (empty($entity)) {
    return '';
  }

  // Set some additional properties.
  $entity->_parent_entity = $parent_entity;
  $entity->_delta = $key;
  $entity->_delta_last = $last_delta;
  $entity->_last_delta = ($key == $last_delta)
    ? TRUE
    : FALSE;
  $content = cache_common_entity_render($entity_type, $entity, $mode);

  return $content;
}

/**
 * Load entity single proxy.
 */
function cache_common_load_entity_single($entity_type, $entity_id) {

  $entity = NULL;

  // Use our proxy function to load some common entity types.
  switch ($entity_type) {
    case 'node':
      if ($node = cache_common_load_node($entity_id)) {
        $entity = $node;
      }
      break;
    case 'commerce_product':
      if ($sku = cache_common_load_sku($entity_id)) {
        $entity = $sku;
      }
      break;
    case 'asset':
      if ($asset = cache_common_load_asset($entity_id)) {
        $entity = $asset;
      }
      break;
    default:
      if ($entity = entity_load($entity_type, array($entity_id))) {
        $entity = $entity[$entity_id];
      }
      break;
  }

  return $entity;
}

/**
 * Safe entity load proxy, require status=1 at very least.
 */
function cache_common_load_sku($sku_id, $safe = TRUE) {
  global $language, $user;

  // Set account to check against.
  $account = $user;

  // Load default SKU.
  $sku = commerce_product_load($sku_id);

  // Check for SKU publish && Schedule.
  if ($safe && !empty($sku)) {
    if (empty($sku->status)) {
      $sku = NULL;
    }
  }

  // Check for access to translation, via access to unpublished node.
  if ($safe && !empty($sku) && !user_access('view unpublished domain content', $account)) {
    $handler = entity_translation_get_handler('commerce_product', $sku, TRUE);
    $entity_translations = $handler->getTranslations();
    if (empty($entity_translations->data) || empty($entity_translations->data[$language->language]['status'])) {
      $sku = NULL;
    }
  }

  return $sku;
}

/**
 * Safe asset load proxy.
 */
function cache_common_load_asset($aid, $safe = TRUE) {
  global $language, $user;

  // Exit if aid not numeric.
  if (!is_numeric($aid)) {
    return;
  }

  $return = NULL;

  // Load asset.
  $return = asset_load($aid);

  return $return;
}
