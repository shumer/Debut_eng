<?php
// $Id$

/**
 * @file
 * ESI module API documentation.
 */

/**
 * Declare elements that can be rendered using an ESI gate.
 * 
 * Modules declare abitrary names elements the ESI API will render later
 * in AJAX or ESI request context.
 * 
 * Elements are not hook_element() defined elements. Nevertheless, then can
 * be, and if they are it would probably easier to handle.
 * Probably the best way for modules to be able to use ESI rendering would
 * be to replace process functions from hook_element_info_alter(), and use
 * their own instead.
 * 
 * Original elements to render should be replaced by a esi_api_build_tag()
 * call at page build time (and NOT at ESI callback time, this is important). 
 * 
 * @return array
 *   Keys are element TYPE and values are translated human name name for
 *   those.
 */
function hook_esi_api() {
  // Sample from 'esi_block' module.
  return array(
    'block' => t("Block"),
  );
}

/**
 * Called asynchronously when either the AJAX downgrade or the ESI gate ask
 * for the generated URL.
 * 
 * Modules that successfully replaced original rendered elements by their
 * own calling the esi_api_build_tag() function will then see this hook run at
 * ESI callback time.
 * 
 * This function has one and one only goal which is to render the Drupal
 * original element that has been switched.
 * 
 * Most of the Drupal core state has been restored as if it was the original
 * page build, therefore you can use the full API there.
 * 
 * Some business contextes from third party modules could not be initialized
 * that's why the $variable array here will contain the extra variables given
 * at the esi_api_build_tag() call.
 * 
 * This hook won't be run on more than one module. If more than one module
 * define the same element TYPE, the first will win and be run.
 * 
 * @param string $identifier
 *   An identifier defined by the hook_esi_api() of the same module.
 * @param array $variables
 *   Global Drupal context variables, set by ESI module, as well as custom
 *   variables that were added at esi_api_build_tag() call.
 * 
 * @return string|array
 *   drupal_render() friendly structure.
 */
function hook_esi_api_TYPE_render($identifier, $variables) {
  // Sample from the 'esi_block' module.
  global $theme_key;

  list($module, $delta, $cid) = explode(':', $identifier);

  // Fetch our only block and render our region, using block module internals.
  $block = esi_api_block_load_block($theme_key, $module, $delta);

  $key = $module . '_' . $delta;
  $region_blocks = _block_render_blocks(array($key => $block));

  return !empty($region_blocks) ? _block_get_renderable_array($region_blocks) : '';
}
