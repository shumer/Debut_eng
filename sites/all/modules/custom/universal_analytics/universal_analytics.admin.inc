<?php

/**
 * @file
 * Universal Analytics admin settings.
 */

/**
 * Administer settings form callback.
 */
function universal_analytics_admin_settings_form($form, &$form_state) {
  global $cookie_domain;
  $form['universal_analytics_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Web property ID'),
    '#size' => 20,
    '#default_value' => variable_get('universal_analytics_id', ''),
    '#required' => TRUE,
  );
  $form['universal_analytics_excluded'] = array(
    '#title' => t('Excluded paths'),
    '#type' => 'textarea',
    '#wysiwyg' => FALSE,
    '#cols' => 10,
    '#rows' => 10, 
    '#default_value' => variable_get('universal_analytics_excluded', ''),
  );
  $form['universal_analytics_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Cookie domain'),
    '#size' => 20,
    '#default_value' => variable_get('universal_analytics_domain', $cookie_domain),
  );
  $form['universal_analytics_dimensions'] = array(
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#title' => t('Custom dimensions'),
    '#tree' => TRUE,
    '#type' => 'fieldset',
  );
  $form['universal_analytics_track_downloads'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('universal_analytics_track_downloads', TRUE),
    '#title' => t('Track downloads'),
  );
  $form['universal_analytics_track_external'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('universal_analytics_track_external', TRUE),
    '#title' => t('Track external link clicks'),
  );
  $form['universal_analytics_track_mailto'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('universal_analytics_track_mailto', TRUE),
    '#title' => t('Track mailto links'),
  );
  $dimensions = variable_get('universal_analytics_dimensions', array());
  for ($a = 1; $a <= 20; $a++) {
    if ($a == 1 || (isset($dimensions[$a]) && $dimensions[$a]) || (isset($dimensions[$a - 1]) && $dimensions[$a - 1])) {
      $form['universal_analytics_dimensions'][$a] = array(
        '#type' => 'textfield',
        '#title' => t('Dimension #@a', array('@a' => $a)),
        '#size' => 20,
        '#default_value' => isset($dimensions[$a]) ?  $dimensions[$a] : '',
        '#element_validate' => array('token_element_validate'),
      );
    }
  }
  $form['universal_analytics_dimensions']['universal_analytics_token'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'page'),
    '#dialog' => TRUE,
  );
  $form['universal_analytics_pre_js'] = array(
    '#title' => t('Custom JS code (Before tracking)'),
    '#type' => 'textarea',
    '#wysiwyg' => FALSE,
    '#cols' => 10,
    '#rows' => 10, 
    '#default_value' => variable_get('universal_analytics_pre_js', ''),
  );
  $form['universal_analytics_post_js'] = array(
    '#title' => t('Custom JS code (After tracking)'),
    '#type' => 'textarea',
    '#wysiwyg' => FALSE,
    '#cols' => 10,
    '#rows' => 10, 
    '#default_value' => variable_get('universal_analytics_post_js', ''),
  );
 
  return system_settings_form($form);
}
