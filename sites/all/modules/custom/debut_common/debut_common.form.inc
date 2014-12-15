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

  $form['submit'] = array(
    '#type' => 'submit',
    '#attributes' => array('class' => array('button')),
    '#value' => 'Send'
  );

  $form['#validate'][] = 'debut_common_contact_us_form_validate';

  return $form;
}

/**
 * Validate contact us form.
 */
function debut_common_contact_us_form_validate($form, &$form_state) {
  global $user;
  $values = variable_get('debut_common_conf', array());
  $ips = explode(',', $values['common']['site_banned_ip']);
  if (!is_array($ips)) {
    $ips = array($ips);
  }
  if (in_array($user->hostname, $ips)) {
    form_set_error('contact_form_email', t('You IP adress was banned.'));
    watchdog('Debut Forms', t('Submit contact form from banned IP address: @address', array('@address' => $user->hostname)), NULL, WATCHDOG_INFO);
  }
  $email = $form_state['values']['contact_form_email'];
  if (!valid_email_address($email)) {
    form_set_error('contact_form_email', t('Please, enter the valid email'));
  }
}

/**
 * Contact form submit.
 */
function debut_common_contact_us_form_submit($form, &$form_state) {
  global $language;

  // Send mail with notify about contact us form.
  $site_conf_values = variable_get('debut_common_conf', array());
  $mail_conf = $site_conf_values['mail'];

  $values = $form_state['values'];
  $token_bundle = 'debut_common_contact_us';
  $params = array($token_bundle => $values);

  $mail = drupal_mail('debut_common', $mail_conf['message_contact_us'], $mail_conf['contact_us_email'], $language, $params, $values['contact_form_email']);
  drupal_set_message(t('You message has been sent. We contact to you shortly. Thank you.'));
}
