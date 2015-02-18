<?php
/**
 *
 * @file
 * Breadcrumb CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Breadcrumb', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Breadcrumb', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_breadcrumb',
  'single' => TRUE,
  'render callback' => 'debut_common_breadcrumb_content_type_render',
  'edit form' => 'debut_common_breadcrumb_content_type_edit_form',
  'admin title' => 'debut_common_breadcrumb_content_type_admin_title',
  'hook theme' => 'debut_common_breadcrumb_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => array(new ctools_context_optional(t('Node'), 'node')),
);

/**
 * Render callback.
 */
function debut_common_breadcrumb_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_html = array();
  $_data = array();
  $context_node = $context[0];
  $is_mobile = debut_common_is_mobile();

  // Check for custom BC.
  if (drupal_strlen(trim($conf['custombc'])) > 0) {
    for ($i = 0; $i < 10; $i++) {
      $replace['@arg' . $i] = arg($i);
    }
    if ($is_mobile) {
      $breadcrumb[] = l('</span><span class="ico ico-home-c"> </span>', '',
        array('attributes' =>
          array(
            'data-rel' => 'back',
            'class' => array('back'),
          ),
          'html' => true,
        )
      );
    }
    else {
      $breadcrumb[] = l(t('Home'), '');
    }
    $chunks = explode(PHP_EOL, $conf['custombc']);
    foreach ($chunks as $chunk) {
      $chunk = explode('|', $chunk);
      $chunk[1] = !empty($chunk[1]) ? $chunk[1] : '';
      $chunk[2] = !empty($chunk[2]) ? $chunk[2] : 0;
      $title = t($chunk[0], $replace);
      $path = strtr($chunk[1], $replace);
      $condition = arg($chunk[2]);
      if (trim($title) != '') {
        $breadcrumb[] = (trim($path) != '' && !empty($condition))
          ? l($title, $path)
          : $title;
      }
    }
  }

  // Special breadcrumb for node context.
  elseif (!empty($context_node->data)) {
    $breadcrumb[] = l(t('Home'), '');
    $node = $context_node->data;

    if ($is_mobile) {
      $breadcrumb = debut_common_create_node_mobile_breadcrumbs($node);
    }
    else {
      $breadcrumb = array_merge($breadcrumb, debut_common_create_node_breadcrumbs($node));
    }
  }

  // Special breadcrumb for pages.
  else {
    $breadcrumb[] = l(t('Home'), '');
    if ($is_mobile) {
      $breadcrumb = debut_common_create_page_mobile_breadcrumbs();
    }
    else {
      $breadcrumb = array_merge($breadcrumb, debut_common_create_page_breadcrumbs());
    }
  }

  $_data['breadcrumbs'] = $breadcrumb;

  $data['_data'] = $_data;
  $data['_html'] = $_html;

  $block->content = theme('debut_common_breadcrumb', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_breadcrumb_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $form['conf']['extend'] = array(
    '#type' => 'checkbox',
    '#title' => t('Extend BC to full width'),
    '#description' => t('Extend BC to full width.'),
    '#default_value' => !empty($conf['extend']) ? $conf['extend'] : FALSE,
  );

  // Custom bc for static pages.
  $form['conf']['custombc'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom BC'),
    '#description' => t('Specify custom BC in for of a list [title]|[path]|[arg() required], each chunk from new line. Use @arg0/1/n for path parts.'),
    '#default_value' => !empty($conf['custombc']) ? $conf['custombc'] : '',
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_breadcrumb_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_breadcrumb_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Breadcrumb', array(), array('context' => 'Debut: admin area'));
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_breadcrumb_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_breadcrumb'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-breadcrumb',
    'variables' => array('params' => array()),
  );
}
