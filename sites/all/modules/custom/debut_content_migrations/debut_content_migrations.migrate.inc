<?php
/**
 * @file
 * Migrate hooks.
 */

/**
 * Implements hook_migrate_api()
 */
function debut_content_migrations_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'debut' => array(
        'title' => t('Debut Migrations'),
      ),
    ),
    'migrations' => array(
      'DebutNews' => array(
        'class_name' => 'DebutNewsMigration',
        'group_name' => 'debut',
      ),
      'DebutPress' => array(
        'class_name' => 'DebutPressMigration',
        'group_name' => 'debut',
      ),
      'DebutVideo' => array(
        'class_name' => 'DebutVideoMigration',
        'group_name' => 'debut',
      ),
      'DebutAlphabet' => array(
        'class_name' => 'DebutAlphabetMigration',
        'group_name' => 'debut',
      ),
      'DebutPrizes' => array(
        'class_name' => 'DebutPrizesMigration',
        'group_name' => 'debut',
      ),
      'DebutPrizePersons' => array(
        'class_name' => 'DebutPrizePersonsMigration',
        'group_name' => 'debut',
      ),
    ),
  );
  return $api;
}
