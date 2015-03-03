<?php
/**
 * @file
 * Header CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('Debut Common: Header', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Header', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_header',
  'single' => TRUE,
  'render callback' => 'debut_common_header_content_type_render',
  'edit form' => 'debut_common_header_content_type_edit_form',
  'admin title' => 'debut_common_header_content_type_admin_title',
  'hook theme' => 'debut_common_header_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
);

/**
 * Admin title callback.
 */
function debut_common_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Header');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_header_content_type_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];

  $form['conf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration', array(), array('context' => 'Debut: admin area')),
    '#tree' => TRUE,
  );

  $form['conf']['language_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show links'),
    '#description' => t('Show panel with links to other language site version'),
    '#default_value' => !empty($conf['language_links']) ? $conf['language_links'] : FALSE,
  );

  $form['conf']['search_form'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show search form'),
    '#default_value' => !empty($conf['search_form']) ? $conf['search_form'] : FALSE,
  );

  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_header_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Output function for the userbar content type.
 */
function debut_common_header_content_type_render($subtype, $_conf, $panel_args, $context) {
  $language_links = array();

  // Debut logo.
  $logo_slogan = '';
  $logo_path = drupal_get_path('theme', 'debut') .'/html/images/bgs/logo.gif';
  $image_options = array(
    'path' => $logo_path,
    'alt' => t('Pokolenie-Debut'),
    'title' => t('Pokolenie-Debut'),
  );
  $_html['logo_image'] = theme('image', $image_options);
  if (!drupal_is_front_page()) {
    $_html['logo_image'] = l($_html['logo_image'] . '<span class="slogan">'. $logo_slogan .'</span>',
      '', array('absolute' => TRUE, 'html' => TRUE)
    );
  }

  // Main Debut logo.
  $pokolenie_logo_path = drupal_get_path('theme', 'debut') .'/html/images/content/header_pokolenie_logo.gif';
  $image_options = array(
    'path' => $pokolenie_logo_path,
    'alt' => t('Pokolenie-Debut'),
    'title' => t('Pokolenie-Debut'),
  );
  $_html['pokolenie_logo_image'] = theme('image', $image_options);
  if (!drupal_is_front_page()) {
    $_html['pokolenie_logo_image']  = l($_html['pokolenie_logo_image'] , '', array('absolute' => TRUE, 'html' => TRUE)
    );
  }

  // Founder logo path.
  $founder_logo_path = drupal_get_path('theme', 'debut') .'/html/images/content/header_founder_logo.jpg';
  $image_options = array(
    'path' => $founder_logo_path,
    'alt' => t('Pokolenie-Debut'),
    'title' => t('Pokolenie-Debut'),
  );
  $_html['founder_logo_image'] = theme('image', $image_options);
  if (!drupal_is_front_page()) {
    $_html['founder_logo_image'] = l($_html['founder_logo_image'], '', array('absolute' => TRUE, 'html' => TRUE)
    );
  }

  // Prepare language links for header.
  if (!empty($_conf['language_links'])) {
    $language_links[] = l('RU', '', array('attributes' => array('class' => 'active')));
    $values = variable_get('debut_common_conf', array());
    $languages = $values['common']['site_language_links'];
    if (!empty($languages)) {
      $chunks = explode(PHP_EOL, $languages);
      foreach ($chunks as $chunk) {
        $chunk = explode('|', $chunk);
        $chunk[1] = !empty($chunk[1]) ? $chunk[1] : '';
        $chunk[2] = !empty($chunk[2]) ? $chunk[2] : 0;
        $title = $chunk[0];
        $path = $chunk[1];
        $language_links[] = l($title, $path, array('external' => TRUE));
      }
    }
  }
  $_html['language_links'] = implode('', $language_links);

  // Search data.
  $_html['input_value'] = '';
  $q = current_path();
  $page_path = explode('/', $q);
  
  if (!empty($page_path[0]) && !empty($page_path[1])) {
    if ($page_path[0] == DEBUT_COMMON_PATH_SEARCH) {
      $_html['input_value'] = check_plain($page_path[1]);
    }
  }
  
  // Prepare data for search form.
  $url_path = 'search';
  $page_url = url($url_path);
  drupal_add_js(array('debut_common' => array(
    'search_page_url' => $page_url,
  )), 'setting');

  $data['_html'] = $_html;

  $block = new stdClass();
  $block->content = theme('debut_common_header', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_header_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_header'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-header',
    'variables' => array('params' => array()),
  );
}
