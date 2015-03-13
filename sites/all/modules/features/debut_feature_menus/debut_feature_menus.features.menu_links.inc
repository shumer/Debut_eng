<?php
/**
 * @file
 * debut_feature_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function debut_feature_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_debut-authors:prize_persons
  $menu_links['main-menu_debut-authors:prize_persons'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'prize_persons',
    'router_path' => 'prize_persons',
    'link_title' => 'Debut Authors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_debut-authors:prize_persons',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_events:news_list
  $menu_links['main-menu_events:news_list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'news_list',
    'router_path' => 'news_list',
    'link_title' => 'Events',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_events:news_list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_press-on-debut:press_list
  $menu_links['main-menu_press-on-debut:press_list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'press_list',
    'router_path' => 'press_list',
    'link_title' => 'Press on Debut',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_press-on-debut:press_list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_publications:books_list
  $menu_links['main-menu_publications:books_list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'books_list',
    'router_path' => 'books_list',
    'link_title' => 'Publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_publications:books_list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_videos:video_list
  $menu_links['main-menu_videos:video_list'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video_list',
    'router_path' => 'video_list',
    'link_title' => 'Videos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_videos:video_list',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Debut Authors');
  t('Events');
  t('Press on Debut');
  t('Publications');
  t('Videos');


  return $menu_links;
}
