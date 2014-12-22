// require jquery, jquery.once

"use strict";

// namespace

var diorbc = diorbc || {};

diorbc.mainMenuFold = function(context, settings) {

  $('#main-menu', context).once('diorbc-mainMenuFold', function () {

    $(this).on('click', '.foldable > a', function(event) {
      event.preventDefault();
      $(this).parent().toggleClass('active');
    });

  });
}

Drupal.behaviors.mainMenuFold = {

  attach: diorbc.mainMenuFold
}
