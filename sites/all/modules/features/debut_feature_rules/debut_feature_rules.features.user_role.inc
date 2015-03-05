<?php
/**
 * @file
 * debut_feature_rules.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function debut_feature_rules_user_default_roles() {
  $roles = array();

  // Exported role: contributor.
  $roles['contributor'] = array(
    'name' => 'contributor',
    'weight' => 3,
  );

  return $roles;
}
