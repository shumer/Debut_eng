/**
 * @file
 * Example of async loaded file.
 * in drupal add it with drupal_add_js(drupal_get_path('module', 'site_common') . '/js/site-common.async-example.js', array('async' => TRUE));
 * or site_common_add_async_js(drupal_get_path('module', 'site_common') . '/js/site-common.async-example.js');
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {
  // Init main object.
  site_common.async_example = site_common.async_example || {};
  site_common.async_example.behavior = function (context, settings) {
    console.log('site_common_async_example: inited');
  }

  /**
   * Implements attach behavior.
   */
  Drupal.behaviors.site_common_async_example = {
    attach: function (context, settings) {
      // If flexslider already loaded call attach.
      if ($.flexslider) {
        site_common.async_example.behavior(context, settings);
      }
      else if (site_common && site_common.async) {
        // Load lib using site_common loader.
        site_common.async.require_js('sites/all/themes/custom/mytheme/html/js/libs/jquery.flexslider.js', function () {
          site_common.async_example.behavior(context, settings);
        });
      }
      else {
        // Load lib using jquery loader (slice fallback).
        $.getScript('sites/all/themes/custom/mytheme/html/js/libs/jquery.flexslider.js', function () {
          site_common.async_example.behavior(context, settings);
        });
      }
    }
  }

  // Init self in case we are loaded async.
  if (jQuery.isReady) {
    // It is up to script to define scope and settings it should be applied to
    // in case of jquery mobile integration used you can use site_common.jquery_mobile.getPageContext()
    // to get only current page's context.
    // In this example we use global scope.
    console.log('site_common_async_example: jquery already inited');
    var $context = $(document);
    var settings = Drupal.settings;
    Drupal.behaviors.site_common_async_example.attach($context, settings);
  }

})(jQuery);
