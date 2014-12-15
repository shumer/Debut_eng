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
        qtools_ajax.ajax_call(name, url, {});
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

  // Attach proxy.
  debut_custom.attach_proxy($context, settings);

  // Init.
  if (!debut_custom._inited) {
    debut_custom.init($context, settings);
  }

  // Move message to proper place.
  var $messages = $('.messages-container').html();
  $('.messages-target').html($messages);
}

/**
 * Init function.
 */
debut_custom.init = function ($context, settings) {

  // Mark init as complete.
  debut_custom._inited = true;
  
  $(".gallery_elements").fancybox({
    nextEffect  : 'none',
    prevEffect  : 'node'
  });

  debut_custom.init_calendar($context, settings);
}

/**
 * Init calendar block.
 */
debut_custom.init_calendar = function ($context, settings) {
  var calendar_monthes = Drupal.settings.debut_common_site_calendar.calendar_monthes;
  var calendar_monthes_short = Drupal.settings.debut_common_site_calendar.calendar_monthes_short;
  var calendar_days = Drupal.settings.debut_common_site_calendar.calendar_days;
  var calendar_days_min = Drupal.settings.debut_common_site_calendar.calendar_days_min;
  var calendar_days_short = Drupal.settings.debut_common_site_calendar.calendar_days_short;

  $context.find('.calendar-run').once('debut-calendar', function () {
    var $this = $(this);
    $this.datepicker({
      dateFormat: 'mm/dd/yy',
      minDate: Drupal.settings.debut_common_site_calendar.min_date,
      maxDate: new Date(Drupal.settings.debut_common_site_calendar.max_date),
      monthNames: calendar_monthes,
      monthNamesShort: calendar_monthes_short,
      dayNamesMin: calendar_days_min,
      dayNamesShort: calendar_days,
      dayNames: calendar_days,
      beforeShowDay: debut_custom.calendar_event_days,
      firstDay: 1,
      onSelect: function(dateText, inst) {
        $(this).datepicker('setDate' , dateText);
        var target = $('.debut_common_site_calendar_text').attr('id');
        var name = $this.attr('data-ajax-name');
        var url = $this.attr('data-ajax-url');
        var data = {'date': dateText};
        qtools_ajax.ajax_call(name, url, data, 'get');
        Drupal.settings.debut_common_site_calendar.selected_date = dateText;
      }
    });
    var date = Drupal.settings.debut_common_site_calendar.selected_date;
    $this.datepicker('setDate' , date);
  });
}

/**
 * Highlite day when one or more events present.
 */
debut_custom.calendar_event_days = function(date) {
  var eveDays = Drupal.settings.debut_common_site_calendar.days;
  for (i = 0; i < eveDays.length; i++) {
    if (date.getMonth() == eveDays[i][0] - 1 && date.getDate() == eveDays[i][1] && date.getFullYear() == eveDays[i][2]) {
      return [true, 'ui-state-custom'];
    }
  }
  return [true, ''];
}


// Attach proxy.
debut_custom.attach_proxy = function ($context, settings) {

  // Proxy clicks.
  $context.find('.debut-proxy-click').once('debut-proxy-click', function (delta) {
    $(this).click(function () {
      var target = $(this).attr('data-proxy-target');
      $(target).click();
    });
  });

  // Proxy mousedown.
  $context.find('.debut-proxy-mousedown').once('debut-proxy-mousedown', function (delta) {
    $(this).mousedown(function () {
      var target = $(this).attr('data-proxy-target');
      $(target).mousedown();
    });
  });

  // Proxy form submit.
  $context.find('.debut-proxy-submit').once('debut-proxy-submit', function (delta) {
    $(this).mousedown(function () {
      var target = $(this).attr('data-proxy-target');
      var op = $(target).last().val();
      var $form = $(target).parents('form');
      $form.append('<input type="hidden" name="op" value="' + op + '"/>');
      $(target).remove();
      $form.submit();
    });
  });

  // Proxy change.
  $context.find('.debut-proxy-change').once('debut-proxy-change', function (delta) {
    $(this).change(function () {
      var target = $(this).attr('data-proxy-target');
      var op = $(target).val($(this).val());
    });
}
