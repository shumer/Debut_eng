<?php
/**
 *
 * @file
 * Menu CCT.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Debut Common: Menu', array(), array('context' => 'Debut: admin area')),
  'description' => t('Debut Common: Menu', array(), array('context' => 'Debut: admin area')),
  'content_types' => 'debut_common_menu',
  'single' => TRUE,
  'render callback' => 'debut_common_menu_content_type_render',
  'edit form' => 'debut_common_menu_content_type_edit_form',
  'admin title' => 'debut_common_menu_content_type_admin_title',
  'hook theme' => 'debut_common_menu_content_type_theme',
  'category' => t('Debut', array(), array('context' => 'Debut: admin area')),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => array(new ctools_context_optional(t('Node'), 'node')),
);

/**
 * Output function for the browser content type.
 */
function debut_common_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  $menu = $conf['browser_menu'];
  $type = NULL;
  if (!empty($context[0]->data)) {
    $type = $context[0]->data->type;
  }
  $browser_menu = menu_tree_all_data($menu);
  $page = explode('/', $_GET['q']);
  $page = $page[0];
  if (!empty($browser_menu)) {
    foreach ($browser_menu as $browser_menu_id => $item) {
      $class = '';
      $path = $item['link']['href'];
      $children = array();
      if (!empty($item['below'])) {
        foreach ($item['below'] as $subitem) {
          $subclass = '';
          switch ($type) {
            case DEBUT_COMMON_TYPE_MASTER_CLASS_SECTION:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST) {
                $subclass = 'active';
             }
            case DEBUT_COMMON_TYPE_MASTER_CLASS_TEXT:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST) {
                $subclass = 'active';
             }
            break;
            case DEBUT_COMMON_TYPE_INTERVIEW:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_MASTER_CLASS_SECTION_LIST) {
                $subclass = 'active';
             }
            break;
            case DEBUT_COMMON_TYPE_TRAVELS:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_TRAVEL_DESCRIPTION_LIST) {
               $subclass = 'active';
             }
            break;
            case DEBUT_COMMON_TYPE_TRAVEL_DESCRIPTION:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_TRAVEL_DESCRIPTION_LIST) {
               $subclass = 'active';
             }
            break;
            case DEBUT_COMMON_TYPE_NOBEL_SPEECH:
             if ($subitem['link']['href'] == DEBUT_COMMON_PAGE_NOBEL_SPEECH) {
               $subclass = 'active';
             }
            break;
            default:
              $subclass = '';
          }
          $children[] = array(
            'data' => l(t($subitem['link']['title']), $subitem['link']['href']),
            'class' => array( ($page == $subitem['link']['href']) ? 'active' : $subclass ),
          );
        }
      }
      $children = theme('item_list', array(
        'items' => $children,
        'title' => NULL,
        'type' => 'ul',
        'attributes' => array('class' => array('sub_menu'))
      ));
      switch ($type) {
        case DEBUT_COMMON_TYPE_DOCUMENTS:
          if ($path == DEBUT_COMMON_PAGE_DOCUMENTS_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_PERSONS:
          if ($path == DEBUT_COMMON_PAGE_PRIZE_PERSONS) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_JURY:
          if ($path == DEBUT_COMMON_PAGE_PRIZE_JURY) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_PRESS:
          if ($path == DEBUT_COMMON_PAGE_PRESS_ABOUT_DEBUT) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_NEWS:
          if ($path == DEBUT_COMMON_PAGE_NEWS_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_BOOKS:
          if ($path == DEBUT_COMMON_PAGE_BOOKS_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_IBOOKS:
          if ($path == DEBUT_COMMON_PAGE_IBOOKS_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_PHOTOS:
          if ($path == DEBUT_COMMON_PAGE_PHOTO_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_TRAVELS:
          if ($path == DEBUT_COMMON_PAGE_TRAVELS_LIST) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_NOBEL_SPEECH:
          if ($path == DEBUT_COMMON_PAGE_NOBEL_SPEECH) {
            $class = 'active';
          }
          break;
        case DEBUT_COMMON_TYPE_VIDEO:
          if ($path == DEBUT_COMMON_PAGE_VIDEO) {
            $class = 'active';
          }
          break;
        default:
          $class = '';
      }

      switch ($page) {
        case DEBUT_COMMON_PAGE_PERSONS_LIST:
          $page = DEBUT_COMMON_PAGE_PRIZE_PERSONS;
        break;
        case DEBUT_COMMON_PAGE_JURY_ALPHABET_LIST:
          $page = DEBUT_COMMON_PAGE_PRIZE_JURY;
        break;
      }
      if (!empty($item['below'])) {
        $menu_links[] = array(
          'data' => l(t($item['link']['title']), '', array('fragment' => '#', 'external' => TRUE)) . $children,
          'class' => array( ($page == $path ) ? 'active' : $class ),
        );
      }
      else {
        $menu_links[] = array(
          'data' => l(t($item['link']['title']), $path),
          'class' => array( ($page == $path ) ? 'active' : $class ),
        );
      }
    }
  }
  else {

    // If empty menu selected.
    return;
  }

  $_html = array();
  $_html['menu_links'] = theme('item_list', array(
    'items' => $menu_links,
    'title' => NULL,
    'type' => 'ul',
    'attributes' => array('class' => array('menu'))
  ));
  $data = array(
    '_html' => $_html,
  );
  $block = new stdClass();
  $block->title = NULL;
  $block->content = theme('debut_common_menu', $data);

  return $block;
}

/**
 * Admin title callback.
 */
function debut_common_menu_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Menu');
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_menu_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['conf'] = array(
    '#tree' => TRUE,
  );

  $menus = menu_get_menus();

  $form['conf']['browser_menu'] = array(
    '#type' => 'select',
    '#title' => t('Select menu for browser'),
    '#options' => $menus,
    '#required' => TRUE,
    '#default_value' => (!empty($conf['browser_menu'])) ? $conf['browser_menu'] : 'primary-links',
  );
  return $form;
}

/**
 * Presubmit handler.
 *
 * This is required to get access to the context.
 */
function debut_common_menu_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_menu_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_menu'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-menu',
    'variables' => array('params' => array()),
  );
}
