<?php
/**
 * @file
 * landing_user.inc
 * Definition of custom panels layout.
 *
 */

/**
 * Implements hook_panels_layouts().
 */
function debut_debut_content_2col_toped_panels_layouts() {
  return array(
    'debut_content_2col_toped' => array(
      'title'       => t('Debut: 2 Column with top', array(), array('context' => 'COMMON: admin area')),
      'icon'        => 'debut_content_2col_toped.png',
      'category'    => t('Debut', array(), array('context' => 'COMMON: admin area')),
      'theme'       => 'debut_content_2col_toped',
      'admin theme' => 'debut_content_2col_toped_admin',
      'regions'     => array(
        'top' => t('Top'),
        'content_pre' => t('Content: pre', array(), array('context' => 'COMMON: admin area')),
        'content_left' => t('Content: left', array(), array('context' => 'COMMON: admin area')),
        'content_center' => t('Content: center', array(), array('context' => 'COMMON: admin area')),
         ),
    ),
  );
}
