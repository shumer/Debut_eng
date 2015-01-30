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

debut_custom.gallery_a = function($context, settings){

  $context.find('.photo-listing-item').once('debut-gallery-a', function() {

    var $this = $(this).find('.flexslider');
    $this.flexslider();
  });
};

// Attach proxy.
debut_custom.attach_home_page = function ($context, settings) {

  // Coda slider init for news block.
  $context.find('.home-page-news-gallery').once('debut-home-page-news-gallery', function (delta) {
    $(this).codaSlider({
      autoHeight: true,
      dynamicTabsPosition: "bottom",
      autoSlide: true,
      autoSlideInterval: 10000,
      autoSlideStopWhenClicked: true
    });
  });
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
};

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

  // Attach newsletters subscription.
  debut_custom.attach_newsletters($context, settings);

  // Attach fancy.
  debut_custom.attach_fancy($context, settings);

  // Attach selects.
  debut_custom.attach_selects($context, settings);

  // Attach search form.
  debut_custom.attach_search_form($context, settings);

  // Attach expand button.
  debut_custom.attach_expand_button($context, settings);

  // Attach prizes toggle.
  debut_custom.attach_prizes_show($context, settings);

  // Attach View more buttons.
  debut_custom.attach_view_more($context, settings);

  // Attach home page.
  debut_custom.attach_home_page($context, settings);

  // Attach home page.
  debut_custom.attach_fb_plugin_show($context, settings);

  // Attach gallery a.
  debut_custom.gallery_a($context, settings);

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

  // File upload on manuscript form.
  $context.find('.page-send-manuscript .item-upload input').customFileInput();

  debut_custom.init_calendar($context, settings);

  // Resize fancy if we inside.
  if ((self != parent) && (location.protocol != 'https:')) {
    var height = 0;
    var width  = 0;

    $('body').wrapInner('<div id="popup-wraper"/>');

    $('#popup-wraper').css('float', 'left');
    height = $('#popup-wraper').height();

    parent.debut_fancy_resize(height);
    setTimeout('height = $("#popup-wraper").height(); parent.debut_fancy_resize(height);', 1000)
  }

  $context.find('.show-popup-book').each(function () {
    $(this).fancybox({
      'width' : 772,
      'height' : 500,
      'padding' : 0,
      'margin' : 0,
      'scrolling' : 'no',
      'autoScale' : true,
      'transitionIn' : 'none',
      'transitionOut' : 'none',
      'type' : 'iframe',
      afterLoad: function () {
        height = $('#popup-wraper').height();
        parent.debut_fancy_resize(height);
      },
      afterShow: function () {
        height = $('#popup-wraper').height();
        parent.debut_fancy_resize(height);
      },
      'href' : $(this).attr('href')
    });
  });

  // Change popup links actions.
  $context.find('.popup a').click(function () {
    var href = $(this).attr('href');
    if ((self != top) && ($(this).attr('target') != '_blank') && (href.indexOf('javascript') == -1)) {
      parent.location.href = href;
      return false;
    }
  });
}

/**
 * Init calendar block.
 */
debut_custom.init_calendar = function ($context, settings) {

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

// Attach expandable button.
debut_custom.attach_expand_button = function ($context, settings) {
  $context.find('.js-expand-button').once('debut-js-expandable', function (delta) {
    $(this).click(function() {
      $(this).hide();
      var target = '#' + $(this).attr('data-ref-id');
      console.log(target);
      $(target).show();
    });
  });
}

// Attach prizes toggle function.
debut_custom.attach_prizes_show = function ($context, settings) {
  $context.find('.js-prizes-show').once('debut-js-prizes-show', function (delta) {
    $(this).click(function() {
      debut_custom.hide_all_prizes();
      var target = '#' + $(this).attr('data-ref-id');
      $(target).show();
    });
  });
}

//Hide all prizes.
debut_custom.hide_all_prizes = function () {
  $('.prem_list').hide();
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
  });
}

// Check email address.
debut_custom.is_email = function (email) {
  var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
  return regex.test(email);
}

// Attach newsletters subscription.
debut_custom.attach_newsletters = function ($context, settings) {

  // Proxy clicks.
  $context.find('.block-newsletters .form-button-submit').once('debut-newsletters-block', function (delta) {
    $(this).click(function () {
      var $this = $(this);
      var email = $('.block-newsletters .email-input').val();
      if (!debut_custom.is_email(email)) {
        var $messages = $('.block-newsletters .messages').clone();
        $('.messages-target').html($messages);
        $('html, body').animate({scrollTop:0}, 'slow');
      }
      else {
        var name = $this.attr('newsletter-subscribe');
        var url = $this.attr('data-ajax-url');
        var data = {'email': email};
        qtools_ajax.ajax_call(name, url, data);
      }
    });
  });
};

// Attach Facebook plugin show.
debut_custom.attach_fb_plugin_show = function ($context, settings) {
  $context.find('.facebook-plugin-block .fb-plugin-button').once('fb-plugin-click', function (delta) {
    var $panel = $('#facebook-plugin-block');
    
    $(this).click(function(e) {
      e.preventDefault();
      if ($panel.hasClass('visible')) {
        $panel.animate({
            right: '-=400',
        }, 100, function() {
            $(this).removeClass('visible');
        });
      }
      else {
        $panel.animate({
            right: '+=400',
        }, 100, function() {
            $(this).addClass('visible');
        });
      }
    });
  });
}

// Attach fancybo call.
debut_custom.attach_fancy = function ($context, settings) {

  // Contact us popup call.
  $context.find(".block-contact-us .fancy-call").once('debut-contact-us', function () {
    var target = ($(this).attr('data-src') != null) ? $(this).attr('data-src') : $(this).attr('href');
    $(this).fancybox({
      href: target,
      width : 420,
      minWidth : 420,
      height: 625,
      minHeight: 625,
      padding: 0,
      scrolling: 'no',
      autoResize: false,
      autoCenter: false,
      'type' : 'iframe',
      closeBtn : false,
      title: null,
    });
  })

  // Photo node action.
  $context.find('.gallery_elements').once('debut-gallery-elements', function () {
    $(this).fancybox({
      nextEffect  : 'none',
      prevEffect  : 'node'
    });
  });

  if ($context.find(".popup .close.nojs").size() > 0) {
    $context.find(".popup .close:not(.nojs), .popup .popup-close").hide();
  }
  else {
    $context.find(".popup .close, .popup .popup-close").click(function(){
      parent.$.fancybox.close();
    });
  }
};

/**
 * Extend window object to support fancy resize.
 */
window.debut_fancy_resize = function (fancy_height) {
  $('.fancybox-inner').height(fancy_height);
  $('.fancybox-outer').height(fancy_height);
  $('.fancybox-wrap').height(fancy_height);
}

// Attach selects.
debut_custom.attach_selects = function ($context, settings) {

  $context.find('.form-type-select').once('debut_selects-1', function(){

    // Years list select.
    $(this).find('select.years-select').selectmenu({
      style: 'dropdown',
      select: function( event, ui ) {
        var year = $(this).val();
        var url = settings.debut_common.years_list[year];
        debut_custom.redirect(url);
      }
    });
  });
}

// Redirect actions.
debut_custom.redirect = function ($url) {
  window.location.href = $url;
};

// Search form actions.
debut_custom.attach_search_form = function($context, settings) {
  $context.find('.header .search-bar').once('search-page-form', function () {
    var $this = $(this);

    // Submit button.
    $this.find('.search-form-submit').click(function () {
      var search_value = encodeURIComponent($('.header .search-bar .search-form-text').val());
      if (search_value) {
       search_value = '/'+ search_value;
      }
      var url = settings.debut_common.search_page_url + search_value;
      debut_custom.redirect(url);
    });

    // Input.
    $this.find('.search-form-text').keyup(function (event) {
      if (event.keyCode == 13) {
        var path = [];
        var search_value = encodeURIComponent($(this).val());
        if (search_value) {
          search_value = '/'+ search_value;
        }
        var url = settings.debut_common.search_page_url + search_value ;
        debut_custom.redirect(url);
      }
    });
  });
};

debut_custom.attach_view_more = function($context, settings) {
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
