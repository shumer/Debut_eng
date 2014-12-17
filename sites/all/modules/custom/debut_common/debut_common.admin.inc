<?php
/**
 * @file
 * Admin forms.
 */

/**
 * Form builder.
 */
function debut_common_form_conf() {
  $values = variable_get('debut_common_conf', array());
  $form['#_values'] = $values;

  $form['debut_common_conf'] = array(
    '#title' => t('General'),
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Mail settings.
  $form['debut_common_conf']['mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mail settings'),
    '#description' => t('Mail settings.'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
  );

  $form['debut_common_conf']['mail']['manuscript_email'] = array(
    '#title' => t('Email address which manuscript will be sent'),
    '#type' => 'textfield',
    '#default_value' => !empty($values['mail']['manuscript_email'])
      ? $values['mail']['manuscript_email'] : ''
  );

  $form['debut_common_conf']['mail']['contact_us_email'] = array(
    '#title' => t('Email address which contact us will be sent'),
    '#type' => 'textfield',
    '#default_value' => !empty($values['mail']['contact_us_email'])
      ? $values['mail']['contact_us_email'] : ''
  );

  $query = db_select('mail_edit_registry', 'mer')->extend('PagerDefault')->limit(50)
    ->fields('mer', array('id', 'module', 'mailkey', 'description'))
    ->orderBy('mer.module')
    ->orderBy('mer.mailkey');
  $template_options = array();
  foreach ($query->execute() as $template) {
    $template_options[$template->mailkey] = $template->description;
  }

  $form['debut_common_conf']['mail']['message_contact_us'] = array(
    '#type' => 'select',
    '#title' => t('Message contact us'),
    '#description' => t('Mail template for "message send contact us" e-mail. Sent when user submit Contact us form.'),
    '#options' => $template_options,
    '#default_value' => isset($form['#_values']['mail']['message_contact_us'])
      ? $form['#_values']['mail']['message_contact_us'] : NULL,
  );

  $form['debut_common_conf']['mail']['message_manuscript'] = array(
    '#type' => 'select',
    '#title' => t('Message manuscript'),
    '#description' => t('Mail template for "message send manuscript" e-mail. Sent when user upload new manuscript.'),
    '#options' => $template_options,
    '#default_value' => isset($form['#_values']['mail']['message_manuscript'])
      ? $form['#_values']['mail']['message_manuscript'] : NULL,
  );

  $form['debut_common_conf']['common']['site_language_links'] = array(
    '#title' => t('Enter links in format "EN|http://www.debutprize.com"'),
    '#type' => 'textarea',
    '#default_value' => !empty($values['common']['site_language_links'])
      ? $values['common']['site_language_links'] : ''
  );

  $form['debut_common_conf']['common']['site_banned_ip'] = array(
    '#title' => t('Enter banned ip Example: 192.168.0.1, 192.168.0.2'),
    '#type' => 'textarea',
    '#default_value' => !empty($values['common']['site_banned_ip'])
      ? $values['common']['site_banned_ip'] : ''
  );

  return system_settings_form($form);
}
