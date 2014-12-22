// require jquery, jquery.once, jquery.flexslider

"use strict";

// namespace

var diorbc = diorbc || {};

(function($){

  diorbc.notesSlider = function(context, settings) {

    $('.notes-slider', context).once('diorbc-notesSlider', function () {

      var $this = $(this);
      var $controls;

      $this.flexslider({
        namespace: 'notes-',
        selector: '.notes-slides > .notes-slide',
        animation: 'slide',
        directionNav: true,
        controlNav: true,
        animationLoop: false,
        prevText: ' ',
        nextText: ' ',
        slideshow: false,
        start: function(slider){
          $controls = slider.controlNavScaffold;
        },
        before: function(){
          $controls.addClass('hidden');
        },
        after: function(){
          $controls.removeClass('hidden');
        }
      });
    });
  }

  Drupal.behaviors.notesSlider = {

    attach: diorbc.notesSlider
  }

})(jQuery);