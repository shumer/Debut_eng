/**
 * @file
 * Common js handling.
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {
  // Init main object.
  site_common.ajax = site_common.ajax || {};

  /**
   * Default ajax attach, can be overriden in your theme!
   */
  Drupal.behaviors.site_common_ajax = {
    attach: function (context, settings) {
      site_common.ajax.attach_ajax_call($(context), settings);
      site_common.ajax.attach_ajax_form($(context), settings);
      site_common.ajax.attach_ajax_group($(context), settings);
    }
  }

  /**
   * Attach ajax behavior to common elements like links.
   */
  site_common.ajax.attach_ajax_call = function ($context, settings) {
    // Get proper context.
    var $elements = $context.find('.site-common-ajax-call');
    if ($elements.length == 0 && $context.hasClass('site-common-ajax-call')) {
      $elements = $context;
    }
    $elements.once('site-common-ajax-call', function () {
      $(this).click(function (event) {
        var $this = $(this);
        // If ajax is disabled we skip this.
        if (!$this.hasClass('site-common-ajax-disabled')) {
          var url = $this.attr('data-site-common-ajax-url');
          var name = $this.attr('data-site-common-ajax-name');
          var method = $this.attr('data-site-common-ajax-method');
          var sendid = $this.attr('data-site-common-ajax-sendid');

          // Gather page IDs if required.
          var data = {};
          if (sendid) {
            var ids = [];
            $('[id]').each(function () {
              ids.push(this.id);
            });
            data['ajax_html_ids[]'] = ids.join(',');
          }

          // Make ajax request.
          qtools_ajax.ajax_call(name, url, data, method);
          if (event) {
            event.preventDefault();
          }
          return false;
        }
      });
    });
  }

  /**
   * Attach ajax behavior to forms.
   */
  site_common.ajax.attach_ajax_form = function ($context, settings) {
    // Get proper context.
    var $elements = $context.find('.site-common-ajax-form');
    if ($elements.length == 0 && $context.hasClass('site-common-ajax-form')) {
      $elements = $context;
    }
    $elements.once('site-common-ajax-form', function () {
      var $this = $(this);
      // If ajax is disabled we skip this.
      if (!$this.hasClass('site-common-ajax-disabled')) {

        // Find ajax submit links.
        $this.find('.site-common-ajax-submit').once('site-common-ajax-submit', function () {
          $(this).click(function () {
            var target = $(this).attr('data-site-common-ajax-submit-target');
            $this.find(target).submit();
            return false;
          });
        });

        // Attach to submit event on submit buttons to see what was pressed.
        $this.find("input:submit").submit(function () {
          $this.sender = this;
        }).click(function () {
          $this.sender = this;
        });

        // Attach submit handlers.
        $this.submit(function (event) {

          // Save all CKEditor info to the apropriate textareas.
          if (typeof(CKEDITOR) != 'undefined' && CKEDITOR.instances) {
            $this.find('textarea.ckeditor-processed').each(function () {
              var textarea_id = $(this).attr('id');
              if (typeof(CKEDITOR.instances[textarea_id]) != 'undefined') {
                $(this).val(CKEDITOR.instances[textarea_id].getData());
              }
            });
          }

          // Add sender op if exists.
          var extraData = [];
          if ($this.sender) {
            extraData.push({name: $this.sender.name, value: $this.sender.value});
          }

          // Create ajax request.
          qtools_ajax.ajax_form($this.attr('id'), null, extraData);
          event.preventDefault();
          return false;
        });
      }
    });
  }

  /**
   * Attach ajax behavior to groups.
   */
  site_common.ajax.attach_ajax_group = function ($context, settings) {
    // Here we trigger onLoad group loading.
    if ($context.find('.site-common-ajax-group-load').length > 0 || $context.hasClass('site-common-ajax-group-load')) {
      qtools.addOnLoadListener(function () {
        site_common.ajax.load_group($context, 'load');
      }, 100);
    }
  }

  /**
   * Trigger ajax calls on a group of element.
   */
  site_common.ajax.load_group = function ($context, group) {
    $group_class = 'site-common-ajax-group-' + group;

    // Get proper context.
    var $elements = $context.find('.' + $group_class);
    if ($elements.length == 0 && $context.hasClass($group_class)) {
      $elements = $context;
    }

    // Invoke ajax on all elements.
    $elements.each(function (index) {
      var $this = $(this);

      // If ajax is disabled we skip this.
      if (!$this.hasClass('site-common-ajax-disabled')) {
        var url = $this.attr('data-site-common-ajax-url');
        var name = $this.attr('data-site-common-ajax-name');
        var method = $this.attr('data-site-common-ajax-method');
        if (!name || name == '') {
          name = url;
        }
        qtools_ajax.ajax_call(name, url, {}, method);
      }
    });
  }


})(jQuery);
