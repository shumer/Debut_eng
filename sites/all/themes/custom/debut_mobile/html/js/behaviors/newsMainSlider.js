// require jquery, jquery.once, jquery.flexslider

"use strict";

// namespace

var diorbc = diorbc || {};

(function($){

  diorbc.newsMainSlider = function(context, settings) {

    $('.news-main-slider', context).once('diorbc-newsMainSlider', function () {

      var $this = $(this);

      $this.flexslider({
        namespace: 'news-main-',
        selector: '.news-main-slides > .news-main-slide',
        animation: 'slide',
        directionNav: true,
        controlNav: true,
        animationLoop: false,
        prevText: ' ',
        nextText: ' ',
        slideshow: false,
        controlsContainer: '.news-main-control-wrap'
      });
    });
  }

  Drupal.behaviors.newsMainSlider = {

    attach: diorbc.newsMainSlider
  }

})(jQuery);