<?php
/**
 * @file
 * Forms.
 */

/**
 * Search form builder.
 */
function debut_common_header_search_form($form, $form_state) {
  $form['keys'] = array(
    '#type' => 'textfield',
    '#title' => '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Ok',
  );

  return $form;
}

/**
 * Search form submit.
 */
function debut_common_header_search_form_submit($form, &$form_state) {
  unset($_REQUEST['destination']);
  $form_state['redirect'] = debut_common_search_url($form_state['values']['keys']);
}
