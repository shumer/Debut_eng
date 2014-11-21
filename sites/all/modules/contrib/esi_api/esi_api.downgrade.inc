<?php
// $Id$

/**
 * @file
 * ESI downgrade specifics.
 */

/**
 * Alter page build accordingly when in downgrade mode.
 */
function _esi_api_downgrade_page_build_alter(&$build) {
  $variables = esi_api_variables();
  esi_api_variables_expunge_defaults($variables);
  drupal_add_js(drupal_get_path('module', 'esi_api') . '/esi_api.downgrade.js', array(
    'scope' => 'header',
    'group' => JS_LIBRARY,
    'every_page' => TRUE,
    'preprocess' => TRUE,
  ));
  drupal_add_js(array('esi' => array(
    'parallelize' => (bool) variable_get('esi_api_downgrade_parellelize', FALSE),
    'global' => $variables,
  )), 'setting');
}

/**
 * Render loading temporary HTML code when ESI is not enabled and module
 * runs in downgraded mode.
 */
function theme_esi_api_downgrade_loading() {
  return '<div style="margin: 0 auto; width: 15px; height: 20px; background: transparent url(' . base_path() . 'misc/throbber.gif) left 20px;"/></div>';
}
