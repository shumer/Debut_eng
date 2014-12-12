/**
 * @file
 * Implements logic for images lazy_load.
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {

// Init main object.
site_common.lazy_load = site_common.lazy_load || {
  _is_mobile: false,
  _inited: false,
  _lazy_count: 0
};

/**
 * Default load, should be overriden in your theme!
 */
Drupal.behaviors.site_common_lazy_load = {
  attach: function ($context, settings) {
    // Only run init if its not already inited.
    if (!site_common.lazy_load.ready()) {
      qtools.addOnLoadListener(function () {
        // Double check init state.
        if (!site_common.lazy_load.ready()) {
          $(window).resize(function () {
            site_common.lazy_load.update();
          });
          site_common.lazy_load.ready(true);
        }
      });
    }
    else {
      // Update lazyload images inside the content.
      site_common.lazy_load.update($context, true);
    }
  }
}

/**
 * Set/Get ready stae for lazy load.
 */
site_common.lazy_load.ready = function (is_ready) {
  if (is_ready) {
    site_common.lazy_load._inited = is_ready;

    // Issue update.
    site_common.lazy_load.update();
  }
  return site_common.lazy_load._inited;
}

/**
 * Check for mobile media (0 - desktop, 1 - mobile).
 */
site_common.lazy_load.isMobile = function (refresh) {
  if (refresh || (site_common.lazy_load._is_mobile === false)) {
    if (Drupal.settings && Drupal.settings.site_common && Drupal.settings.site_common.lazy_load) {
      var width = window.innerWidth || document.documentElement.clientWidth;
      return (width > Drupal.settings.site_common.lazy_load.threshold) ? 0 : 1;
    }
  }
  else {
    return site_common.lazy_load._is_mobile;
  }
};

/**
 * Issue flip check.
 */
site_common.lazy_load.update = function ($context, force) {
  // Only support resize events AFTER document ready.
  // This will allow IE to settle.
  if (site_common.lazy_load.ready()) {
    var is_mobile = site_common.lazy_load.isMobile(true);
    if ((is_mobile !== site_common.lazy_load._is_mobile) || force) {
      site_common.lazy_load._is_mobile = is_mobile;
      site_common.lazy_load.onMediaFlip(is_mobile, $context);
    }
  }
}

/**
 * When media changes, load apropriate images.
 */
site_common.lazy_load.onMediaFlip = function (is_mobile, $context) {

  // Set search context.
  if (!$context) {
    $context = $(document);
  }

  qtools.log('flip: ' + is_mobile);

  // If media is mobile - load mobile images if available.
  if (is_mobile == 1) {
    qtools.log('onMediaFlip: lazyLoad(' + is_mobile + ', false, true)');
    site_common.lazy_load.lazyLoad($context, is_mobile, false, true);
  }
  else {
    // If we are going desktop, load all images.
    qtools.log('onMediaFlip: lazyLoad(' + is_mobile + ', true, true)');
    site_common.lazy_load.lazyLoad($context, is_mobile, true, true);
  }

  // Allow other modules to interact.
  $(window).trigger('onMediaFlip', [is_mobile]);
}

/**
 * General purpose Image lazy load.
 */
site_common.lazy_load.lazyLoad = function ($context, is_mobile, show_invisible, skip_delay) {

  if (true) {
    $context = $($context);
  }

  site_common.lazy_load._lazy_count++;
  var lazy_id = site_common.lazy_load._lazy_count;
  var lazy_count = -1;

  var $images = $context.find('.img-lazy-load').not('.lazy-load-default');
  if ($images.length > 0) {
    lazy_count = 0;
    qtools.log('lazyLoad: ' + lazy_id + ':start :' + $images.length);
    if (typeof(document.readyState) != 'undefined') {
      qtools.log('lazyLoad: ' + lazy_id + ':doc :' + document.readyState + ' : ' + new Date().getTime());
    }
  }

  $images.each(function () {
    var $this = $(this);
    var targetArrt = 'src';

    // Check if element visible.
    if (show_invisible || site_common.lazy_load.isVisible($this)) {
      var src  = $this.attr(targetArrt);
      var srcM = $this.attr('data-src-mobile');
      var srcD = $this.attr('data-src-default');
      var use_default = false;

      // Mobile Devices.
      if (is_mobile) {
        // Attempt to load mobile version.
        if (srcM != null && srcM != src) {
          $this.attr(targetArrt, srcM);
          lazy_count++;
          qtools.log('lazyLoad: ' + lazy_id + ':mobile:' + targetArrt + ': ', srcM);

          // Mark item as usng mobile version.
          $this.addClass('lazy-load-mobile');
        }
        // Flag to use default image.
        else {
          use_default = true;
        }
      }
      else {
        // If we in default mode use desctop images.
        use_default = true;
      }

      // Default images.
      if (use_default) {
        if (srcD != null && srcD != src) {
          $this.attr(targetArrt, srcD);
          //$this.removeAttr('data-src-mobile');
          //$this.removeAttr('data-src-default');
          lazy_count++;
          qtools.log('lazyLoad: ' + lazy_id + ':default:' + targetArrt + ': ', srcD);
        }
        // After loading default version we no longer need this image to be processed.
        $this.addClass('lazy-load-default').removeClass('lazy-load-mobile');
      }
    }
  });

  if (lazy_count >= 0) {
    qtools.log('lazyLoad: ' + lazy_id + ':end :' + lazy_count);
  }
}

/**
 * Check if element is visible.
 */
site_common.lazy_load.isVisible = function ($element) {
  var visible = ($element.css('display') != 'none');
  if (visible && ($element.parents('.lazy-load-visible').size() == 0)) {
    $element.parents().each(function () {
      if ($(this).css('display') == 'none') {
        visible = false;
      }
    });
  }
  return visible;
}

})(jQuery);