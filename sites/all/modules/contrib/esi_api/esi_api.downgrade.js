// $Id$

/**
 * @file
 * ESI module graceful downgrade AJAX script.
 */

(function ($) {
  Drupal.behaviors.EsiDowngrade = {
    /**
     * Found AJAX placeholders.
     */
    elements: [],

    /**
     * Replace element buffer using the given one.
     */
    attachData: function ( element, html ) {
      // This algorithm seems to be the only one really working for replacing
      // the element keeping track of a pointer on the new one.
      element.after(html);
      Drupal.attachBehaviors(element.next());
      element.remove();
    },

    /**
     * Proceed to element fetch in order. Request first unshifted element
     * and proceed to next only once it's finished.
     */
    requestSerial: function () {
      // Fetch next element in the list.
      var current = Drupal.behaviors.EsiDowngrade.elements.shift();

      if (current) {
        $.ajax({
          'url': current.url,
          //'type': (current.variables ? 'POST' : 'GET'),
          // GET will maximize cache hit chances, and browsers cache also btw.
          'type': 'GET',
          'data': current.variables,
          'async': true,
          'cache': true,
          'success': function ( data, textStatus, jqXHR ) {
            Drupal.behaviors.EsiDowngrade.attachData(current.element, data);
            Drupal.behaviors.EsiDowngrade.requestSerial();
          },
          'error': function( jqXHR, textStatus, errorThrown ) {
            current.element.remove();
            Drupal.behaviors.EsiDowngrade.requestSerial();
          }
        });
      }
    },

    /**
     * Proceed to element fetch parallelized.
     */
    requestParallel: function () {
      for (var key in Drupal.behaviors.EsiDowngrade.elements) {
        var current = Drupal.behaviors.EsiDowngrade.elements.shift();
        if (current) {
          $.ajax({
            'url': current.url,
            'type': (current.variables ? 'POST' : 'GET'),
            'data': current.variables,
            'async': true,
            'cache': true,
            'success': function ( data, textStatus, jqXHR ) {
              Drupal.behaviors.EsiDowngrade.attachData(current.element, data);
            },
            'error': function( jqXHR, textStatus, errorThrown ) {
              current.element.remove();
            }
          });
        }
      }
    },

    attach: function( context ) {
      // Build the element array.
      $('.esi-downgrade:not(.esi-processed)', context)
        .addClass('esi-processed')
        .each(function () {
          var $this = $(this),
              container = $this,
              rel = $this.attr('rel'),
              id = $this.attr('id'),
              variables = Drupal.settings.esi[id] ? Drupal.settings.esi[id] : {};
  
          // Element may be malformed.
          if (rel) {
            variables = $.extend({}, variables, Drupal.settings.esi.global);
            element = {
              url: rel,
              element: container
            };
            if (!$.isEmptyObject(variables)) {
              element.variables = variables;
            }
            Drupal.behaviors.EsiDowngrade.elements.push(element);
          } else {
            // In case of error, remove the erroneous element.
            parent.remove();
          }
        });

      // Trigger AJAX load only if we have elements.
      if (Drupal.behaviors.EsiDowngrade.elements.length) {
        if (Drupal.settings.esi.parallelize) {
          Drupal.behaviors.EsiDowngrade.requestParallel();
        }
        else {
          Drupal.behaviors.EsiDowngrade.requestSerial();
        }
      }
    }
  };
})(jQuery);
