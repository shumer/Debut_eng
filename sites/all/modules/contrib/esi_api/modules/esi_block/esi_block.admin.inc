<?php
// $Id$

/**
 * @file
 * ESI Block administration pages.
 */

/**
 * Common ESI configuration.
 */
function esi_block_admin_settings($form, &$form_state) {

  $form['esi_block_caching_policy'] = array(
    '#type' => 'radios',
    '#title' => t("Caching policy"),
    '#options' => array(
      NULL => t("All goes ESI"),
      DRUPAL_CACHE_GLOBAL => t("All except globally cached blocks"),
      DRUPAL_CACHE_PER_PAGE => t("All except per page and globally cached blocks"),
    ),
    '#default_value' => variable_get('esi_block_caching_policy', DRUPAL_CACHE_PER_PAGE),
    '#description' => t("If you select first or second option here, blocks that can be safely cached in the page cache itself won't use ESI for caching. This can be usefull in order to achieve aggressive caching efficiently."),
  );

  /*
  $form['esi_block_exclude'] = array(
    '#type' => 'checkboxes',
    '#title' => t("Exclude blocks from:"),
    '#description' => t("If "),
  );
   */

  return system_settings_form($form);
}
