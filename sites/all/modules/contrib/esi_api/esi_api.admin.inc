<?php
// $Id$

/**
 * @file
 * ESI API administration pages.
 */

/**
 * Common ESI configuration.
 */
function esi_api_admin_settings($form, &$form_state) {
  
  $form['esi_api_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t("Enable full ESI support"),
    '#description'=> t("If this is left unchecked, ESI tags will be replaced by AJAX loading facilities."),
    '#default_value' => variable_get('esi_api_enabled', FALSE),
  );

  $form['esi_api_downgrade_parellelize'] = array(
    '#type' => 'checkbox',
    '#title' => t("Parallelize AJAX in downgrade mode"),
    '#description'=> t("If you check this option, when in downgrade mode the JavaScript will parallelize all AJAX request. This can be really heavy for your server but will build pages more quickly for final user."),
    '#default_value' => variable_get('esi_api_downgrade_parellelize', FALSE),
    '#disabled' => TRUE,
  );

  $form['esi_api_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t("Exclude from path"),
    '#default_value' => variable_get('esi_api_exclude', "admin\nadmin/*"),
    '#description' => t("Disabling ESI facilities on specific pages can sometime avoid some bugs. Excluding all administration pages seems to be a good idea globally. Type on path match per line."),
  );

  return system_settings_form($form);
}
