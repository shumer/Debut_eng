/**
 * @file
 * Implements logic to support async script loading.
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {
  // Init main object.
  site_common.async = site_common.async || {
    _added: {},
    _callbacks: {},
    _inited: false
  };

  /**
   * Custom command that load async js.
   */
  Drupal.ajax.prototype.commands.site_common_async_js = function (ajax, command, status) {
    // Load async js.
    if (command.js_src) {
      site_common.async.add_js(command.js_src);
    }
  }

  /**
   * Default async load, can be overriden in your theme!
   */
  Drupal.behaviors.site_common_async = {
    attach: function ($context, settings) {
      // Create JS elements.
      if (settings.site_common && settings.site_common.async && settings.site_common.async.js) {
        for (var i in settings.site_common.async.js) {
          site_common.async.add_js(settings.site_common.async.js[i]);
        }
      }
    }
  }

  /**
   * Create dom object to load script.
   */
  site_common.async.add_js = function (src) {
    if (!site_common.async._added[src]) {

      // Log action and prevent duplicate.
      qtools.log('SCASL:', src);
      site_common.async._added[src] = true;

      // Create script.
      var s = document.getElementsByTagName('script')[0];
      var p = document.createElement('script');
      p.async = 'async';
      p.src = src;
      qtools.addOnLoadListener(function () {
        s.parentNode.insertBefore(p, s);
      });
    }
  }

  /**
   * Create dom object to load script.
   */
  site_common.async.require_js = function (src, callback) {
    if (!site_common.async._added[src]) {

      // Log action and prevent duplicate.
      qtools.log('SCASL-R:', src);
      site_common.async._added[src] = true;

      // Save callback
      site_common.async._callbacks[src] = [callback];

      // Create script.
      $.ajax({
        url: src,
        dataType: "script",
        cache: true,
        success: function () {
          site_common.async.require_js.success(src)
        },
      });
    }
    else if (site_common.async._callbacks[src]) {
      // If there is callbacks waiting to be executed add to list.
      site_common.async._callbacks[src].push(callback);
    }
    else {
      callback();
    }
  }

  /**
   * Run success callbacks.
   */
  site_common.async.require_js.success = function(src) {
    if (site_common.async._callbacks[src]) {
      // Free callbacks gathering as soon as we got success.
      var callbacks = site_common.async._callbacks[src];
      site_common.async._callbacks[src] = false;

      // Loaf action.
      qtools.log('SCASL-R:[' + callbacks.length + ']', src);

      // Run all callbacks.
      for (var i in callbacks) {
        callbacks[i]();
      }
    }
  }
})(jQuery);
