<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_common_page_panels_layouts() {
  return array(
    'site_common_page' => array(
      'title'       => t('Site Common: page', array(), array('context' => 'COMMON: admin area')),
      'icon'        => 'site_common_page.png',
      'category'    => t('Site Common', array(), array('context' => 'COMMON: admin area')),
      'theme'       => 'site_common_page',
      'admin theme' => 'site_common_page_admin',
      'regions'     => array(
        'header'  => t('HEADER', array(), array('context' => 'COMMON: admin area')),
        'left'  =>   t('LEFT', array(), array('context' => 'COMMON: admin area')),
        'content' => t('CONTENT', array(), array('context' => 'COMMON: admin area')),
        'footer'  => t('FOOTER', array(), array('context' => 'COMMON: admin area')),
      ),
    ),
  );
}
