<?php
/**
 * @file
 * Module login and api.
 */

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
