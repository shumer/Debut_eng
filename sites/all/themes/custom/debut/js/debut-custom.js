/**
 * @file
 * Custom JS.
 */

// jQuery sign.
var $ = $ || jQuery;

// Namespace.
var debut_custom = debut_custom || {
  _inited: false,
  _windows: {},
};

/**
 * Log function.
 */
debut_custom.log = function(text, data) {
  if (typeof console == "object" && $.isFunction(console.log))  {
    if (data) {
      console.log(text, data);
    }
    else {
      console.log(text);
    }
  }
}

/**
 * Attach Ajax.
 */
debut_custom.attach_ajax = function ($context, settings) {

  // Ajax links click.
  $context.find('.debut-ajax-link').once('debut-ajax-link', function () {
    $(this).click(function () {
      var $this = $(this);
      // If ajax is disabled we skip this.
      if (!$this.hasClass('debut-ajax-disabled')) {
        var url = $(this).attr('data-ajax-url');
        var name = $(this).attr('data-ajax-name');
        if (!name || name == '') {
          name = url;
        }
        site_ajax.ajax_call(name, url, {});
      }
    });
  });
}

/**
 * Attach behavior.
 */
Drupal.behaviors.debut_custom = {
  'attach' : function (context, settings) {
    debut_custom.attach($(context), settings);
  }
};

/**
 * Attach behavior handler.
 */
debut_custom.attach = function ($context, settings) {

  // Attach Ajax.
  debut_custom.attach_ajax($context, settings);

  // Init.
  if (!debut_custom._inited) {
    debut_custom.init();
  }

  // Move message to proper place.
  var $messages = $('.messages-container').html();
  $('.messages-target').html($messages);
}

/**
 * Init function.
 */
debut_custom.init = function () {

  // Mark init as complete.
  debut_custom._inited = true;

  $(".gallery_elements").fancybox({
    nextEffect  : 'none',
    prevEffect  : 'node'
  });
}
