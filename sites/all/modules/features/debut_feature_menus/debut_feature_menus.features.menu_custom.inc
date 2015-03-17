<?php
/**
 * @file
 * debut_feature_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function debut_feature_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-main-menu-mobile.
  $menus['menu-main-menu-mobile'] = array(
    'menu_name' => 'menu-main-menu-mobile',
    'title' => 'Main menu mobile',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Main menu mobile');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
