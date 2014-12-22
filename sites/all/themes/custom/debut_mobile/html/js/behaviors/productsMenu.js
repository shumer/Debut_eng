// require jquery, jquery.once

"use strict";

// namespace

var diorbc = diorbc || {};

diorbc.productsMenu = function(context, settings) {

  $('.block-products-menu', context).once('diorbc-productsMenu', function () {

    var $this = $(this);
    var $link = $(this).find("ul li a");

    $link.click(function(){
      $(this).parent("li").toggleClass("extended");
    });

  });
}

Drupal.behaviors.productsMenu = {

  attach: diorbc.productsMenu
}

