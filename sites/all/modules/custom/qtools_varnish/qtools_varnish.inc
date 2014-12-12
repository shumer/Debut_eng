<?php
/**
 * @file
 * Module login and api.
 */

/**
 * Check if this server can handle Varnish.
 */
function qtools_varnish_enabled() {
  global $theme, $is_https;
  $varnish_enabled = &drupal_static('qtools_varnish_enabled', NULL);
  if ($varnish_enabled !== NULL) {
    return $varnish_enabled;
  }

  // Disabled by default.
  $varnish_enabled = FALSE;

  // Enable Varnish if header present.
  if (!empty($_SERVER[QTOOLS_VARNISH_HEADER_ENABLED])) {

    // Check for https.
    if (_qtools_varnish_settings('available', 'https') || !$is_https) {

      // Do nothing if in admin theme.
      $admin_theme = variable_get('admin_theme', 0);
      if (_qtools_varnish_settings('available', 'admin_theme') || ($admin_theme != $theme)) {

        // From now Varnish enabled by default.
        $varnish_enabled = TRUE;

        // Disable if current user may bypass varnish.
        if (user_access(QTOOLS_VARNISH_PERM_BYPASS_VARNISH)) {
          $varnish_enabled = FALSE;
        }

        // Disable if varnish disabled for specific domain name.
        if ($varnish_enabled) {
          $config = explode(PHP_EOL, _qtools_varnish_settings('available', 'exclide', ''));
          foreach ($config as $line) {
            $rule = explode('|', trim($line));
            if (($rule[0] == '*') || ($_SERVER['SERVER_NAME'] == $rule[0])) {
              if (($rule[1] == '*') || strpos($_SERVER['REQUEST_URI'], $rule[1]) === 0) {
                $varnish_enabled = FALSE;
                break;
              }
            }
          }
        }
      }
    }
  }
  return $varnish_enabled;
}

/**
 * Get tags array from given text.
 */
function qtools_varnish_parse_tags($text) {
  $tags = explode(',', $text);
  foreach ($tags as &$tag) {
    $tag = explode(QTOOLS_TAG_EQUAL_SIGN, trim($tag));
    if (empty($tag[1])) {
      $tag[1] = '';
    }
    $tag = qtools_api__cache_tag($tag[0], $tag[1]);
  }
  return $tags;
}

/**
 * Get deflate KEY.
 */
function qtools_varnish_get_def_key($reset = FALSE) {
  $key = variable_get(__FUNCTION__, -1);
  if ($key == -1 || $reset) {
    $key = time();
    variable_set(__FUNCTION__, $key);
  }
  return $key;
}

/**
 * Generate ESI tag.
 */
function qtools_varnish_esi_tag($esi_type, $esi_id, $esi_args = array(), $maxwait = 5000) {

  // Generate ESI path.
  $path = 'qtools_varnish/esi/' . $esi_type . '/' . $esi_id;

  // Add signature.
  $signature = qtools_varnish_get_signature($esi_type, $esi_id, $esi_args);
  if (!empty($esi_args)) {
    $esi_args = array('a' => $esi_args);
  }
  $url = url($path . '/' . $signature, array('query' => $esi_args));

  // Build tag.
  $tag = "<!--esi\n" . '<esi:include src="' . $url  . '" maxwait="' . $maxwait . '"/>' . "\n-->";
  return $tag;
}
