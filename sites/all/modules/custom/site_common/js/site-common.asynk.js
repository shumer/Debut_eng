/**
 * @file
 * Implements logic to support asynk script loading.
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {
  // Init main object.
  site_common.asynk = site_common.asynk || {
    _added: {},
    _inited: false
  };

  /**
   * Default asynk load, can be overriden in your theme!
   */
  Drupal.behaviors.site_common_asynk = {
    attach: function ($context, settings) {
      // Create JS elements.
      if (settings.site_common && settings.site_common.asynk && settings.site_common.asynk.js) {
        for (i in settings.site_common.asynk.js) {
          site_common.asynk.add_js(settings.site_common.asynk.js[i]);
        }
      }
    }
  }

  /**
   * Create dom object to load script.
   */
  site_common.asynk.add_js = function (name) {
    if (!site_common.asynk._added[name]) {
      // Create script.
      var s = document.getElementsByTagName('script')[0];
      var p = document.createElement('script');
      p.async = 'async';
      p.src = name;
      s.parentNode.insertBefore(p, s);

      // Log action and prevent dublicate.
      qtools.log('SCASL:', name);
      site_common.asynk._added[name] = true;
    }
  }
})(jQuery);
