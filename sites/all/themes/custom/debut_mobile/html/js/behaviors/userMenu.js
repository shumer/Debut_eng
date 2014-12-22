// require jquery, jquery.once

"use strict";

// namespace

var diorbc = diorbc || {};

diorbc.userMenu = function(context, settings) {

  $('#header', context).once('diorbc-userMenu', function () {

    var $this = $(this);
    var $trigger = $this.find('#user-menu-trigger');
    var $collapsible = $this.find($trigger.attr('href'));

    if($trigger.length && $collapsible.length){

      $collapsible.collapsible({collapsed: true, contentTheme: false});

      $trigger.on('click', function (event) {

        event.stopPropagation();
        event.preventDefault();

        if($collapsible.collapsible('option', 'collapsed')){

          $trigger.addClass('active');
          $collapsible.collapsible('expand');

          $(context).on('click.usermenu', function (event) {

            var $target = $(event.target);

            if(!$target.closest($collapsible).length && !$target.closest($trigger).length){

              event.stopPropagation();
              event.preventDefault();
              $trigger.removeClass('active');
              $collapsible.collapsible('collapse');
              $(context).off('.usermenu');
            }
          });
        }
        else{

          $trigger.removeClass('active');
          $collapsible.collapsible('collapse');
        }
      });
    }
  });
}

Drupal.behaviors.userMenu = {

  attach: diorbc.userMenu
}

