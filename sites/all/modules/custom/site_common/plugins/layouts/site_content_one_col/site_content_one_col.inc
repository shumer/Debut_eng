<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_content_one_col_panels_layouts() {
  return array(
    'site_content_one_col' => array(
      'title'       => t('Site Content: one col', array(), array('context' => 'COMMON: admin area')),
      'icon'        => 'site_content_one_col.png',
      'category'    => t('Site Common', array(), array('context' => 'COMMON: admin area')),
      'theme'       => 'site_content_one_col',
      'admin theme' => 'site_content_one_col_admin',
      'regions'     => array(
        'content' => t('CONTENT', array(), array('context' => 'COMMON: admin area')),
      ),
    ),
  );
}
