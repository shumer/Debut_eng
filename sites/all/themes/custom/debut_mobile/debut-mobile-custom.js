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
  debut_mobile_custom.attach_view_more_button($context, settings);

  // Attach proxy.
  debut_mobile_custom.attach_proxy($context, settings);

  // Attach newsletters.
  debut_mobile_custom.attach_newsletters($context, settings);

  // Attach sliders.
  debut_mobile_custom.attach_sliders($context, settings);

  // Attach main menu.
  debut_mobile_custom.main_menu_fold($context, settings);

  // Attach flexslider resize on pageshow.
  debut_mobile_custom.flexslider_resize($context, settings);

  // Attach footer show/hide.
  debut_mobile_custom.footer_toggle($context, settings);

  // Attach prizes toggle.
  debut_mobile_custom.attach_prizes_show($context, settings);

  // Attach View more buttons.
  debut_mobile_custom.attach_view_more($context, settings);
};

// Init routine, will be called once.
debut_mobile_custom.init = function ($context, settings) {
  $context = $(document);

  // Mark this as inited.
  debut_mobile_custom._inited = true;
  document.addEventListener("touchstart", function(){}, true);

};

/**
 * Init calendar block.
 */
debut_mobile_custom.attach_calendar = function ($context, settings) {

  $context.find('.header .header-calendar-button').once('debut-calendar', function () {
    $(this).click(function() {
      $('.calendar-block-target').toggle('slideDown');
      $('.search-block-target').hide();
      $('.newsletter-block-target').hide();
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
};

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
};

// Redirect actions.
debut_mobile_custom.redirect = function ($url) {
  window.location.href = $url;
};

// Search form actions.
debut_mobile_custom.attach_search_form = function($context, settings) {
  $context.find('.header .header-search-button').once('debut-search', function () {
    $(this).click(function() {
      $('.search-block-target').toggle('slideDown');
      $('.calendar-block-target').hide();
      $('.newsletter-block-target').hide();
    });
  });

  $context.find('.header .search-bar').once('header-search-form', function () {
    var $this = $(this);

    // Input.
    $this.find('.search-form-text').addClass('search-processed').keydown(function (event) {
      if (event.keyCode == 13) {
        var path = [];
        var search_value = encodeURIComponent($(this).val());
        if (search_value) {
          search_value = '/'+ search_value;
        }
        var url = settings.debut_common.search_page_url + search_value ;
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
debut_mobile_custom.attach_view_more_button = function ($context, settings) {
  $context.find('.block-button-more').once('debut_view_more', function(){
    var $this = $(this);
    $this.click(function () {
      var $this = $(this);
      var $target = $('.' + $this.attr('data-target'));
      $this.remove();
      $target.fadeIn();
    });
  });
};

// Attach proxy.
debut_mobile_custom.attach_proxy = function ($context, settings) {

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
  });
};

// Attach newsletters.
debut_mobile_custom.attach_newsletters = function ($context, settings) {
  $context.find('.header .header-newsletter-button').once('debut-newsletters', function () {
    $(this).click(function() {
      $('.newsletter-block-target').toggle('slideDown');
      $('.calendar-block-target').hide();
      $('.search-block-target').hide();
    });
  });

  $context.find('.newsletter-bar .newsletter-form-text').once('debut-newsletters-block', function (delta) {
    $(this).keydown(function (event) {
      if (event.keyCode == 13) {
        var $this = $(this);
        var email = $('.newsletter-bar .newsletter-form-text').val();
        if (!debut_mobile_custom.is_email(email)) {
          var $messages = $('.newsletter-bar .messages').clone();
          $('.newsletter-messages-target').html($messages);
        }
        else {
          $('.messages-container').html('');
          $('.newsletter-messages-target').hide();
          var name = 'newsletter-subscribe';
          var url = $this.attr('data-ajax-url');
          var data = {'email': email};
          qtools_ajax.ajax_call(name, url, data);
          debut_mobile_custom.hide_keyboard($(this));
          $('.newsletter-block-target').toggle('slideUp');
        }
      }
    });
    $(this).watermark(Drupal.t('Subcribe for newsletters here'));
  });
};

// Check email address.
debut_mobile_custom.is_email = function (email) {
  var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  return regex.test(email);
};

// Hide phone keyboard. element with current focus required.
debut_mobile_custom.hide_keyboard = function(element) {
  element.attr('readonly', 'readonly');
  element.attr('disabled', 'true');
  setTimeout(function() {
    element.blur();

    // Remove readonly attribute after keyboard is hidden.
    element.removeAttr('readonly');
    element.removeAttr('disabled');
  }, 100);
};

// Attach sliders.
debut_mobile_custom.attach_sliders = function ($context, settings) {

  // SLider on photo node.
  $('.node-photo-item', $context).once('debut-photo-main-slider', function () {

    var $this = $(this);

    $this.find('.flexslider').flexslider({
      animation: 'slide',
      directionNav: true,
      controlNav: true,
      animationLoop: false,
      prevText: ' ',
      nextText: ' ',
      slideshow: false,
      controlsContainer: '.photo-main-control-wrap'
    });
  });

  // SLider on photo node.
  $('.photo-listing-item', $context).once('debut-photo-main-slider', function () {

    var $this = $(this);
    var wrapper_class = $this.find('.flexslider').attr('data-wrapper-class');
    $this.find('.flexslider').flexslider({
      animation: 'slide',
      directionNav: true,
      controlNav: true,
      animationLoop: false,
      prevText: ' ',
      nextText: ' ',
      slideshow: false,
      controlsContainer: '.' + wrapper_class
    });
  });

  $('.block-jury-years', $context).once('debut-jury-prize-slider', function () {
    var $this = $(this);

    $this.find('.slider-wrapper').flexslider({
      animation: "slide",
      animationLoop: false,
      slideshow: false,
      itemWidth: 70,
      controlNav: false,
      directionNav: true,
      minItems: Drupal.settings.debut_common_jury_years.flexslider_years_list_items_count,
      maxItems: Drupal.settings.debut_common_jury_years.flexslider_years_list_items_count,
      startAt: Drupal.settings.debut_common_jury_years.flexslider_years_list_startAt,
      selector: ".years-slides > a",
    });
  });

  $('.block-alphabet', $context).once('debut-alphabet-slider', function () {
    var $this = $(this);

    $this.find('.slider-wrapper').flexslider({
      animation: "slide",
      animationLoop: false,
      slideshow: false,
      itemWidth: 25,
      controlNav: false,
      directionNav: true,
      minItems: Drupal.settings.debut_common_alphabet_header.flexslider_alphabet_list_items_count,
      maxItems: Drupal.settings.debut_common_alphabet_header.flexslider_alphabet_list_items_count,
      startAt:  Drupal.settings.debut_common_alphabet_header.flexslider_alphabet_list_startAt,
      selector: ".letter-slides > li",
    });
  });

  $('.home-page-news-gallery', $context).once('debut-home-page-news-slider', function () {
    var $this = $(this);

    $this.find('.view-content').flexslider({
      animation: 'slide',
      directionNav: true,
      controlNav: false,
      animationLoop: true,
      prevText: ' ',
      nextText: ' ',
      slideshowSpeed: 10000,
      slideshow: true,
      selector: ".slides > li",
      smoothHeight: true
    });
  });

  $('.home-page-books-gallery', $context).once('debut-home-page-books-slider', function () {
    var $this = $(this);

    $this.find('.view-content').flexslider({
      animation: 'slide',
      directionNav: true,
      controlNav: false,
      animationLoop: true,
      prevText: ' ',
      nextText: ' ',
      slideshowSpeed: 7000,
      slideshow: false,
      selector: ".slides > li",
      smoothHeight: true
    });
  });

  $('.home-page-video-gallery', $context).once('debut-alphabet-slider', function () {
    var $this = $(this);

    $this.find('.slider-wrapper').flexslider({
      animation: "slide",
      animationLoop: false,
      slideshow: false,
      itemWidth: 240,
      controlNav: false,
      directionNav: false,
      selector: ".slides > li",
    });
  });
};

// Flexslider resize on page show.
debut_mobile_custom.flexslider_resize = function(context, settings) {
  context.on("pageshow", function() {
    $slider = $('.slider-wrapper');
    $slider.resize();
  });
}

// Flexslider resize on page show.
debut_mobile_custom.footer_toggle = function(context, settings) {
  context.on("pagebeforeshow", function() {
    $footer = $('.footer');
    $footer.hide();
  });

  context.on("pageshow", function() {
    $footer = $('.footer');
    $footer.show();
  });
}

debut_mobile_custom.main_menu_fold = function(context, settings) {

  $('#main-menu', context).once('debut-main-menu-fold', function () {

    $(this).on('click', '.foldable > a', function(event) {
      event.preventDefault();
      $(this).parent().toggleClass('active');
    });

  });
}

// Attach prizes toggle function.
debut_mobile_custom.attach_prizes_show = function ($context, settings) {
  $context.find('.js-prizes-show').once('debut-js-prizes-show', function (delta) {

    $(this).click(function() {
      debut_mobile_custom.hide_all_prizes(this);
      var target = '#' + $(this).attr('data-ref-id');
      $(this).addClass('active-link');
      $(target).show();
    });
  });
}

// Hide all prizes.
debut_mobile_custom.hide_all_prizes = function (elem) {
  $parent = $(elem).parent().parent();

  $captions = $parent.find('.winners-links');
  $captions.find('.js-prizes-show').removeClass('active-link');

  // Hide all articles.
  $articles = $parent.find('.articles-list');
  $($articles).find('.prem_list').hide();
  $($articles).find('.full').hide();
}

// Attach View more buttons.
debut_mobile_custom.attach_view_more = function($context, settings) {
  $context.find('.persons-view-more-button').once('persons-view-more', function () {
    var $this = $(this);
    $this.click(function () {
      var $this = $(this);
      var name = 'persons-view-more';
      var url = $this.attr('data-ajax-url');
      qtools_ajax.ajax_call(name, url, [], 'get');
      $this.remove();
    });
  });
};
