/**
 * @file
 * Custom js.
 */

// jQuery sign.
var $ = $ || jQuery;

// Namespace.
var debut_mobile_custom = debut_mobile_custom || {
  _inited: false
};

// Attach behavior.
Drupal.behaviors.debut_mobile_custom = {
  'attach' : function (context, settings) {
    debut_mobile_custom.attach($(context), settings);
  }
};

// Attach handler.
debut_mobile_custom.attach = function ($context, settings) {

  // Init.
  if (!debut_mobile_custom._inited) {
    debut_mobile_custom.init();
  }

  debut_mobile_custom.attach_calendar($context, settings);

  // Attach search form.
  debut_mobile_custom.attach_search_form($context, settings);

  // Attach selects.
  debut_mobile_custom.attach_selects($context, settings);

  // Attach addthis.
  debut_mobile_custom.attach_addthis($context, settings);

  // Attach view more button.
  debut_mobile_custom.attach_view_more($context, settings);
};

// Init routine, will be called once.
debut_mobile_custom.init = function ($context, settings) {
  $context = $(document);

  // Mark this as inited.
  debut_mobile_custom._inited = true;
  document.addEventListener("touchstart", function(){}, true);
}

/**
 * Init calendar block.
 */
debut_mobile_custom.attach_calendar = function ($context, settings) {

  $context.find('.header .header-calendar-button').once('debut-calendar', function () {
    $(this).click(function() {
      $('.calendar-block-target').toggle('slideDown');
      $('.search-block-target').slideUp();
    });
  });

  var calendar = $context.find('.calendar-placeholder').html();
  $context.find('.calendar-block-target').html(calendar);
  $context.find('.calendar-placeholder').remove();
  $context.find('.calendar-run').once('debut-calendar', function () {
    var calendar_monthes = Drupal.settings.debut_common_site_calendar.calendar_monthes;
    var calendar_monthes_short = Drupal.settings.debut_common_site_calendar.calendar_monthes_short;
    var calendar_days = Drupal.settings.debut_common_site_calendar.calendar_days;
    var calendar_days_min = Drupal.settings.debut_common_site_calendar.calendar_days_min;
    var calendar_days_short = Drupal.settings.debut_common_site_calendar.calendar_days_short;
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
      beforeShowDay: debut_mobile_custom.calendar_event_days,
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
debut_mobile_custom.calendar_event_days = function(date) {
  var eveDays = Drupal.settings.debut_common_site_calendar.days;
  for (i = 0; i < eveDays.length; i++) {
    if (date.getMonth() == eveDays[i][0] - 1 && date.getDate() == eveDays[i][1] && date.getFullYear() == eveDays[i][2]) {
      return [true, 'ui-state-custom'];
    }
  }
  return [true, ''];
}

// Redirect actions.
debut_mobile_custom.redirect = function ($url) {
  window.location.href = $url;
};

// Search form actions.
debut_mobile_custom.attach_search_form = function($context, settings) {
  $context.find('.header .header-search-button').once('debut-search', function () {
    $(this).click(function() {
      $('.search-block-target').toggle('slideDown');
      $('.calendar-block-target').slideUp();
    });
  });

  $context.find('.header .search-bar').once('search-page-form', function () {
    var $this = $(this);

    // Submit button.
    $this.find('.search-form-submit').click(function () {
      var search_value = encodeURIComponent($('.header .search-bar .search-form-text').val());
      if (search_value) {
       search_value = '/'+ search_value;
      }
      var url = settings.debut.page_url + search_value;
      debut_mobile_custom.redirect(url);
    });

    // Input.
    $this.find('.search-form-text').keyup(function (event) {
      if (event.keyCode == 13) {
        var path = [];
        var search_value = encodeURIComponent($(this).val());
        if (search_value) {
          search_value = '/'+ search_value;
        }
        var url = settings.debut.page_url + search_value ;
        debut_mobile_custom.redirect(url);
      }
    });

    $this.find('.search-form-text').watermark(Drupal.t('Search'));
  });
};

// Attach selects.
debut_mobile_custom.attach_selects = function ($context, settings) {

  $context.find('.form-selectmenu').once('debut_selects-1', function(){

    // Years list select.
    $(this).find('.years-select').on('change', function () {
      var year = $(this).val();
      var url = settings.debut_common.years_list[year];
      debut_mobile_custom.redirect(url);
    });
  });
};

// Attach addthis.
debut_mobile_custom.attach_addthis = function ($context, settings) {
  var script = '//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-525d1ec751799799#domready=1';
  if (window.addthis) {
    window.addthis = null;
    window._adr = null;
    window._atc = null;
    window._atd = null;
    window._ate = null;
    window._atr = null;
    window._atw = null;
  }
  $.getScript(script, function() {
    addthis.init();
  });
};

// Attach view more.
debut_mobile_custom.attach_view_more = function ($context, settings) {
  $context.find('.block-button-more').once('debut_view_more', function(){
    var $this = $(this);
    $this.click(function () {
      var $this = $(this);
      var $target = $('.' + $this.attr('data-target'));console.log($this.attr('data-target'));
      $this.remove();
      $target.fadeIn();
    });
  });
};
