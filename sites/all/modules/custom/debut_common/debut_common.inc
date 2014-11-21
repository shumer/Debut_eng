<?php
/**
 * @file
 * Module logic and API.
 */

/**
 * Generate search url.
 */
function debut_common_search_url($keys, $absolute = TRUE) {
  return url(DEBUT_COMMON_PATH_SEARCH . '/' . urlencode($keys), array('absolute' => $absolute));
}
