/**
 * @file
 * Example of asynk loaded file.
 * in drupal add it with drupal_add_js(drupal_get_path('module', 'site_common') . '/js/site-common.asynk-example.js', array('asynk' => TRUE));
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {
  // Init main object.
  site_common.asynk_example = site_common.asynk_example || {};

  /**
   * Implements attach behavior.
   */
  Drupal.behaviors.site_common_asynk_example = {
    attach: function (context, settings) {
      console.log('site_common_asynk_example: inited');
    }
  }

  // Init self in case we are loaded asynk.
  if (jQuery.isReady) {
    // It is up to script to define scope and settings it should be applied to
    // in case of jquery mobile integration used you can use site_common.jquery_mobile.getPageContext()
    // to get only current page's context.
    // In this example we use global scope.
    console.log('site_common_asynk_example: jquery already inited');
    var $context = $(document);
    var settings = Drupal.settings;
    Drupal.behaviors.site_common_asynk_example.attach($context, settings);
  }

})(jQuery);
