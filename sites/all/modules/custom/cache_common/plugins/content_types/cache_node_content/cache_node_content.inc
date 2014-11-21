<?php
/**
 * @file
 * Node content CCT.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Cache Common: Node content'),
  'icon' => NULL,
  'description' => t('The content of the referenced node.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Cache'),
  'defaults' => array(
    'build_mode' => 'teaser',
  ),
);

/**
 * Render the node content.
 */
function cache_common_cache_node_content_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!empty($context) && empty($context->data)) {
    return;
  }

  $node = isset($context->data) ? clone($context->data) : NULL;
  $block = new stdClass();
  $block->module = 'node';
  $block->delta  = $node->nid;

  if (empty($node)) {
    $block->delta   = 'placeholder';
    $block->title = t('Node title.');
    $block->content = t('Node content goes here.');
  }
  else {
    $block->title = $node->title;
    $block->content = cache_common_entity_render('node', $node, $conf['build_mode']);
  }

  return $block;
}

/**
 * Returns an edit form for the custom type.
 */
function cache_common_cache_node_content_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $entity = entity_get_info('node');
  $build_mode_options = array();
  foreach ($entity['view modes'] as $mode => $option) {
    $build_mode_options[$mode] = $option['label'];
  }

  $form['build_mode'] = array(
    '#title' => t('Build mode'),
    '#type' => 'select',
    '#description' => t('Select a build mode for this node.'),
    '#options' => $build_mode_options,
    '#default_value' => $conf['build_mode'],
  );

  return $form;
}

/**
 * Submit function.
 */
function cache_common_cache_node_content_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Admin title callback.
 */
function cache_common_cache_node_content_content_type_admin_title($subtype, $conf, $context) {
  return t('Cache Common: "@s" content', array('@s' => $context->identifier));
}

