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

/**
 * Contact us form
 */
function debut_common_contact_us_form($form, $form_state) {
  $form['contact_form_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#attributes' => array('class' => array('contact-us-name')),
    '#default_value' => '',
    '#required' => TRUE,
    '#size' => 15
  );
  $form['contact_form_email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#attributes' => array('class' => array('contact-us-email')),
    '#default_value' => '',
    '#required' => TRUE,
    '#size' => 15
  );
  $form['contact_form_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#attributes' => array('class' => array('contact-us-message')),
    '#default_value' => '',
    '#rows' => '5',
    '#cols' => '15',
    '#required' => TRUE,
    '#resizable' => FALSE,
  );
  $form['contact_captcha_element'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'image_captcha/Image',
    '#description' => t('<span class="reload-captcha">Обновить изображение</span>')
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#attributes' => array('class' => array('button')),
    '#value' => 'Send'
  );
  //$form['#after_build'][] = 'debut_blocks_block_contact_us_form_after_build';
  //$form['#validate'][] = 'debut_blocks_block_contact_us_form_validate';
  //$form['#submit'][] = 'debut_blocks_block_contact_us_form_submit';
  //$form['#theme'][] = 'debut_blocks_block_contact_us_form';
  return $form;
}

/**
 * Contact form submit.
 */
function debut_common_contact_us_form_submit($form, &$form_state) {
  drupal_set_message('11');
}
