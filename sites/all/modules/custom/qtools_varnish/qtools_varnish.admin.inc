<?php
/**
 * @file
 * Admin page handling
 */

/**
 * Purge form submit handler.
 */
function qtools_varnish_admin_purge_form_submit($form, $form_state) {

  // Purge specified request or tag in varnish.
  $values = $form_state['values'];
  if ($values['purge_type'] == QTOOLS_VARNISH_PURGE_TAG) {
    $result = qtools_varnish_purge_tags(array($values['purge_value']));
  }
  else {
    $result = qtools_varnish_purge_request($values['purge_value']);
  }

  // Display information about results.
  if (empty($result)) {
    drupal_set_message(t('Server refuce to execute command.'), 'error');
  }
  else {
    foreach ($result as $server => $commands) {
      foreach ($commands as $command => $status) {
        drupal_set_message(t('Server %server executed command %command successfuly.', array(
          '%server' => $server,
          '%command' => $command,
        )));
      }
    }
  }
}

/**
 * Purge form.
 */
function qtools_varnish_admin_purge_form() {
  $form = array();

  // Display module status.
  $backend_status = qtools_varnish__varnish_get_status();
  $_messages = $_SESSION['messages'];
  $_SESSION['messages'] = array();
  if (empty($backend_status)) {
    drupal_set_message(t('Varnish backend is not set.'), 'warning');
  }
  else {
    foreach ($backend_status as $backend => $status) {
      if (empty($status)) {
        drupal_set_message(t('Varnish at !backend not responding.', array('!backend' => $backend)), 'error');
      }
      else {
        drupal_set_message(t('Varnish at !backend connected.', array('!backend' => $backend)));
      }
    }
    if (_qtools_varnish_settings('purge', 'all_hosts', TRUE)) {
      drupal_set_message(t('Note that purge will affect all hosts, you can change this on settings page.'), 'warning');
    }
  }

  $status_html = theme('status_messages');
  $_SESSION['messages'] = $_messages;

  $form['qtools_varnish_status'] = array(
    '#weight' => -1,
    '#type' => 'markup',
    '#markup' => $status_html,
  );

  // Purge type.
  $options = array(
    QTOOLS_VARNISH_PURGE_REQUEST => t('Purge request'),
    QTOOLS_VARNISH_PURGE_TAG => t('Purge tag'),
  );
  $form['purge_type'] = array(
    '#title' => t('Purge condition'),
    '#type' => 'radios',
    '#options' => $options,
    '#required' => TRUE,
  );

  // Purge value.
  $form['purge_value'] = array(
    '#title' => t('Purge value to check against'),
    '#type' => 'textfield',
    '#description' => t('If "Purge request" choosen, value "/" will purge everything, be careful on production servers.'),
    '#required' => TRUE,
  );

  $form['purge'] = array(
    '#type' => 'submit',
    '#value' => 'Purge',
  );

  return $form;
}

/**
 * Settings form builder.
 */
function qtools_varnish_admin_settings_form() {
  $form = array();
  $form['qtools_varnish_settings'] = array(
    '#tree' => TRUE,
  );

  // Display module status.
  $backend_status = qtools_varnish__varnish_get_status();
  $_messages = $_SESSION['messages'];
  $_SESSION['messages'] = array();
  if (empty($backend_status)) {
    drupal_set_message(t('Varnish backend is not set.'), 'warning');
  }
  else {
    foreach ($backend_status as $backend => $status) {
      if (empty($status)) {
        drupal_set_message(t('Varnish at !backend not responding.', array('!backend' => $backend)), 'error');
      }
      else {
        drupal_set_message(t('Varnish at !backend connected.', array('!backend' => $backend)));
      }
    }
  }

  $status_html = theme('status_messages');
  $_SESSION['messages'] = $_messages;

  $form['qtools_varnish_status'] = array(
    '#weight' => -1,
    '#type' => 'markup',
    '#markup' => $status_html,
  );

  // User blocks settings.
  $form['qtools_varnish_settings']['general'] = array(
    '#title' => t('General settings'),
    '#type' => 'fieldset',
  );
  $form['qtools_varnish_settings']['general']['logging'] = array(
    '#title' => t('Logging'),
    '#type' => 'checkbox',
    '#description' => t('Check if you want to log vital actions to watchdog.'),
    '#default_value' => _qtools_varnish_settings('general', 'logging', FALSE),
  );
  $form['qtools_varnish_settings']['general']['debug'] = array(
    '#title' => t('Debug ESI'),
    '#type' => 'checkbox',
    '#description' => t('Check if you want to add debug info to ESI tags.'),
    '#default_value' => _qtools_varnish_settings('general', 'debug', FALSE),
  );
  $form['qtools_varnish_settings']['general']['noise'] = array(
    '#title' => t('Hashing Noise'),
    '#type' => 'textfield',
    '#description' => t('This works as private key, you can change it at any time.'),
    '#default_value' => _qtools_varnish_settings('general', 'noise', ''),
  );

  $form['qtools_varnish_settings']['connection'] = array(
    '#title' => t('Varnish Connection settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // This is replica from Varnish module.
  $form['qtools_varnish_settings']['connection']['control_terminal'] = array(
    '#type' => 'textfield',
    '#title' => t('Control Terminal'),
    '#default_value' => _qtools_varnish_settings('connection', 'control_terminal', '127.0.0.1:6082'),
    '#required' => TRUE,
    '#description' => t('Set this to the server IP or hostname that varnish runs on (e.g. 127.0.0.1:6082). This must be configured for Drupal to talk to Varnish. Separate multiple servers with spaces.'),
  );

  // This is replica from Varnish module.
  $form['qtools_varnish_settings']['connection']['control_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Control Key'),
    '#default_value' => _qtools_varnish_settings('connection', 'control_key', ''),
    '#description' => t('Optional: if you have established a secret key for control terminal access, please put it here.'),
  );

  // This is replica from Varnish module.
  $form['qtools_varnish_settings']['connection']['socket_timeout'] = array(
   '#type' => 'textfield',
   '#title' => t('Connection timeout (milliseconds)'),
   '#default_value' => _qtools_varnish_settings('connection', 'socket_timeout', 100),
   '#description' => t('If Varnish is running on a different server, you may need to increase this value.'),
   '#required' => TRUE,
  );

  $form['qtools_varnish_settings']['available'] = array(
    '#title' => t('Availability settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['available']['exclude'] = array(
    '#title' => t('Excluded URLs'),
    '#type' => 'textarea',
    '#description' => t('Specify excluded request urls @format.', array('@format' => '<SERVER_NAME>|<partial REQUEST_URI *>')),
    '#default_value' => _qtools_varnish_settings('available', 'exclude'),
  );
  $form['qtools_varnish_settings']['available']['https'] = array(
    '#title' => t('Enable for HTTPS pages'),
    '#type' => 'checkbox',
    '#description' => t('Check if you want enable Varnish support for HTTPS pages.'),
    '#default_value' => _qtools_varnish_settings('available', 'https'),
  );
  $form['qtools_varnish_settings']['available']['admin_theme'] = array(
    '#title' => t('Enable for admin theme'),
    '#type' => 'checkbox',
    '#description' => t('Check if you want enable Varnish support for admin theme.'),
    '#default_value' => _qtools_varnish_settings('available', 'admin_theme'),
  );

  $form['qtools_varnish_settings']['custom'] = array(
    '#title' => t('Custom Rules'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['custom']['rules'] = array(
    '#title' => t('Enabled Drupal Path'),
    '#type' => 'textarea',
    '#description' => t('Specify custom drupal path rules @format.', array('@format' => '<PATH>|<TTL>|<PAGE TAG>')),
    '#default_value' => _qtools_varnish_settings('custom', 'rules'),
  );

  // User blocks settings.
  $form['qtools_varnish_settings']['userblocks'] = array(
    '#title' => t('User Blocks'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['userblocks']['clear_on_post'] = array(
    '#title' => t('Clear on every POST'),
    '#type' => 'checkbox',
    '#description' => t('It is common that each form submit made by user will affect it personnal data.'),
    '#default_value' => _qtools_varnish_settings('userblocks', 'clear_on_post', FALSE),
  );

  $options = drupal_map_assoc(array(3, 5, 10, 15, 30, 60, 120, 180, 240, 300, 600, 900, 1200, 1800, 3600, 7200, 14400, 28800, 43200, 86400, 172800, 259200, 345600, 604800), 'format_interval');
  $options[-1] = t('Pass through');
  ksort($options);
  $form['qtools_varnish_settings']['userblocks']['ttl'] = array(
    '#title' => t('Lifetime'),
    '#description' => t('For how long user blocks should be keept alive.'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => _qtools_varnish_settings('userblocks', 'ttl', -1),
  );

  $form['qtools_varnish_settings']['userblocks']['cachetags'] = array(
    '#title' => t('Custom tags'),
    '#type' => 'textarea',
    '#description' => t('Custom cache tags, comma (,) separated, those should be backed by your code.'),
    '#default_value' => _qtools_varnish_settings('userblocks', 'cachetags', 'user'),
  );

  // Redirect caching settings.
  $form['qtools_varnish_settings']['redirects'] = array(
    '#title' => t('Redirects'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['redirects']['rules'] = array(
    '#title' => t('Redirect caching rules'),
    '#type' => 'textarea',
    '#description' => t('Redirect cache rules in form @format.', array('@format' => '<drupal path>|<ttl>')),
    '#default_value' => _qtools_varnish_settings('redirects', 'rules'),
  );

  // Cache controll header settings.
  $form['qtools_varnish_settings']['cache_control'] = array(
    '#title' => t('Cache control'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['cache_control']['anonymous'] = array(
    '#title' => t('Cache control header rules (anonymous)'),
    '#type' => 'textarea',
    '#description' => t('Cache control header rules in form @format.', array('@format' => '<drupal path>|<cache-control-value>')),
    '#default_value' => _qtools_varnish_settings('cache_control', 'anonymous', '*|cdn-no-store'),
  );
  $form['qtools_varnish_settings']['cache_control']['logged_in'] = array(
    '#title' => t('Cache control header rules (logged in)'),
    '#type' => 'textarea',
    '#description' => t('Cache control header rules in form @format.', array('@format' => '<drupal path>|<cache-control-value>')),
    '#default_value' => _qtools_varnish_settings('cache_control', 'logged_in', '*|must-revalidate, no-cache, cdn-no-store'),
  );

  // Purge settings.
  $form['qtools_varnish_settings']['purge'] = array(
    '#title' => t('Purge Settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['qtools_varnish_settings']['purge']['automatic'] = array(
    '#title' => t('Automatic purge'),
    '#type' => 'checkbox',
    '#description' => t('Purge pages automatically on entity update or delete.'),
    '#default_value' => _qtools_varnish_settings('purge', 'automatic', TRUE),
  );
  $form['qtools_varnish_settings']['purge']['all_hosts'] = array(
    '#title' => t('Purge on all hosts'),
    '#type' => 'checkbox',
    '#description' => t('Purge actions will affect all hosts'),
    '#default_value' => _qtools_varnish_settings('purge', 'all_hosts', TRUE),
  );
  return system_settings_form($form);
}