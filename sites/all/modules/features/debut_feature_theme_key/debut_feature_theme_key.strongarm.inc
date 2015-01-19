<?php
/**
 * @file
 * debut_feature_theme_key.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function debut_feature_theme_key_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_paths';
  $strongarm->value = array(
    0 => array(
      'path' => 'node/#/revisions/#/view',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
        3 => 'node:vid',
      ),
      'weight' => 10,
      'fit' => 21,
    ),
    1 => array(
      'path' => 'comment/reply/#/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'node:nid',
        3 => 'comment:cid',
      ),
      'weight' => 3,
      'fit' => 12,
    ),
    2 => array(
      'path' => 'taxonomy/term/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'taxonomy:tid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    3 => array(
      'path' => 'comment/reply/#',
      'callbacks' => array(),
      'wildcards' => array(
        2 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 6,
    ),
    4 => array(
      'path' => 'comment/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'comment:cid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    5 => array(
      'path' => 'comment/#/delete',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'comment:cid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    6 => array(
      'path' => 'user/#/edit',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 2,
      'fit' => 5,
    ),
    7 => array(
      'path' => 'user/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'profile:uid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
    8 => array(
      'path' => 'node/#',
      'callbacks' => array(),
      'wildcards' => array(
        1 => 'node:nid',
      ),
      'weight' => 1,
      'fit' => 2,
    ),
  );
  $export['themekey_paths'] = $strongarm;

  return $export;
}
