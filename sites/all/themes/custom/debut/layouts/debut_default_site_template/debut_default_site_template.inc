<?php

/**
 * Implements hook_panels_layouts().
 */
function debut_debut_default_site_template_panels_layouts() {
  return array(
    'debut_default_site_template' => array(
      'title'       => t('Debut: Default site layout', array(), array('context' => 'COMMON: admin area')),
      'icon'        => 'debut_default_site_template.png',
      'category'    => t('Debut', array(), array('context' => 'COMMON: admin area')),
      'theme'       => 'debut_default_site_template',
      'admin theme' => 'debut_default_site_template_admin',
      'regions'     => array(
        'header'  => t('HEADER', array(), array('context' => 'COMMON: admin area')),
        'content' => t('CONTENT', array(), array('context' => 'COMMON: admin area')),
        'footer'  => t('FOOTER', array(), array('context' => 'COMMON: admin area')),
      ),
    ),
  );
}
