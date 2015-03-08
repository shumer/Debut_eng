<?php
/**
 * @file
 * Forms.
 */

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
  $form['#after_build'][] = 'debut_common_contact_us_form_after_build';

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

  $mail = drupal_mail('debut_common', $mail_conf['message_contact_us'], $mail_conf['contact_us_email'], $language, $params, 'noreply@pokolenie-debut.ru');

  $is_mobile = debut_common_is_mobile();

  // Redirect depending on popup state.
  if (debut_common_in_popup()) {
    $form_state['redirect'] = 'contact_us/submitted';
  }
  elseif ($is_mobile) {
    $form_state['redirect'] = 'contact_us/submitted';
  }
  else {
    $form_state['redirect'] = '<front>';
  }
}

/**
 * Send manuscript form.
 */
function debut_common_send_manuscript_form($form, $form_state) {

  $form['#attributes'] = array(
    'data-ajax' => 'false',
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#attributes' => array('class' => array('send-manuscript-name')),
    '#default_value' => '',
    '#required' => TRUE,
    '#size' => 30
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#attributes' => array('class' => array('send-manuscript-email')),
    '#default_value' => '',
    '#required' => TRUE,
    '#size' => 30
  );

  $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => t('Comment'),
    '#attributes' => array('class' => array('send-manuscript-comment')),
    '#default_value' => '',
    '#rows' => '10',
    '#cols' => '5',
    '#required' => TRUE,
    '#resizable' => FALSE
  );

  $form['file_upload'] = array(
    '#type' => 'file',
    '#title' => t('Select the file'),
    '#description' => t('Select the file with extension .doc or .rtf')
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#attributes' => array('class' => array('button')),
    '#value' => 'Send'
  );

  $form['#after_build'][] = 'debut_common_send_manuscript_form_after_build';

  return $form;
}

/**
 * Validate send manuscript form.
 */
function debut_common_send_manuscript_form_validate($form, &$form_state) {

  // Try to upload file.
  $validators = array(
    'file_validate_extensions' => array('doc rtf'),
  );
  $file = file_save_upload('file_upload', $validators);

  // If the file passed validation.
  if ($file) {
    // Prepared dir.
    $base_dir = 'public://sended_manuscripts/';
    file_prepare_directory($base_dir, FILE_CREATE_DIRECTORY);
    $date = date('m-Y', time());
    $directory = $base_dir . $date;
    file_prepare_directory($directory, FILE_CREATE_DIRECTORY);

    // Move the file into the Drupal file system.
    if ($file = file_move($file, $directory)) {

      // Save the file for use in the submit handler.
      $form_state['storage']['file'] = $file;
    }
    else {
      form_set_error('file_upload', t('File could not be uploaded'));
    }
  }
  else {
    form_set_error('file_upload', t('File did not pass validation. Check file extension.'));
  }
}

/**
 * Send manuscript form submit.
 */
function debut_common_send_manuscript_form_submit($form, &$form_state) {
  global $language;

  // Mark file as permanent or Drupal will delete it on next cron run.
  $file = $form_state['storage']['file'];
  unset($form_state['storage']['file']);
  $file->status = FILE_STATUS_PERMANENT;
  file_save($file);

  // Send mail with notify about contact us form.
  $site_conf_values = variable_get('debut_common_conf', array());
  $mail_conf = $site_conf_values['mail'];

  $values = $form_state['values'];
  $token_bundle = 'debut_common_send_manuscript';
  $values['manuscript_url'] = l(t('Скачать файл'), file_create_url($file->uri));
  $params = array($token_bundle => $values);

  $mail = drupal_mail('debut_common', $mail_conf['message_manuscript'], $mail_conf['manuscript_email'], $language, $params, 'noreply@pokolenie-debut.ru');
  drupal_set_message(t('Ваше сообщение было успешно отправлено'));
}

/**
 * After build contact us form.
 */
function debut_common_contact_us_form_after_build($form, &$form_state) {
  $is_mobile = debut_common_is_mobile();
  if ($is_mobile) {
    unset($form['captcha']);
  }
  return $form;
}

/**
 * After build contact us form.
 */
function debut_common_send_manuscript_form_after_build($form, &$form_state) {
  $is_mobile = debut_common_is_mobile();
  if ($is_mobile) {
    unset($form['captcha']);
  }
  return $form;
}
