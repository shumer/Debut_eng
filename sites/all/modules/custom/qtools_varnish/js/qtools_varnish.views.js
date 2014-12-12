/**
 * @file
 * Contains custom ajax integration.
 */

/**
 * Override default drupal ajax to allow us to hook into send process.
 */
Drupal.ajax.prototype.eventResponse = function (element, event) {
  // Create a synonym for this to reduce code confusion.
  var ajax = this;

  // Do not perform another ajax command if one is already in progress.
  if (ajax.ajaxing) {
    return false;
  }

  // Set GET method if specified.
  if (ajax.options.data && ajax.options.data.qtools_varnish_use_get) {
    ajax.options.type = "GET";
  }

  try {
    if (ajax.form) {
      // If setClick is set, we must set this to ensure that the button's
      // value is passed.
      if (ajax.setClick) {
        // Mark the clicked button. 'form.clk' is a special variable for
        // ajaxSubmit that tells the system which element got clicked to
        // trigger the submit. Without it there would be no 'op' or
        // equivalent.
        element.form.clk = element;
      }
      ajax.form.ajaxSubmit(ajax.options);
    }
    else {
      ajax.beforeSerialize(ajax.element, ajax.options);
      $.ajax(ajax.options);
    }
  }
  catch (e) {
    // Unset the ajax.ajaxing flag here because it won't be unset during
    // the complete response.
    ajax.ajaxing = false;
    alert("An error occurred while attempting to process " + ajax.options.url + ": " + e.message);
  }

  // For radio/checkbox, allow the default event. On IE, this means letting
  // it actually check the box.
  if (typeof element.type != 'undefined' && (element.type == 'checkbox' || element.type == 'radio')) {
    return true;
  }
  else {
    return false;
  }

};

/**
 * Override default beforeSerialize().
 */
Drupal.ajax.prototype.beforeSerialize = function (element, options) {

  // Allow detaching behaviors to update field values before collecting them.
  // This is only needed when field values are added to the POST data, so only
  // when there is a form such that this.form.ajaxSubmit() is used instead of
  // $.ajax(). When there is no form and $.ajax() is used, beforeSerialize()
  // isn't called, but don't rely on that: explicitly check this.form.
  if (this.form) {
    var settings = this.settings || Drupal.settings;
    Drupal.detachBehaviors(this.form, settings, 'serialize');
  }

  // Add ids if not specified otherwise.
  if (!options.data.qtools_varnish_strip_ids) {
    // Prevent duplicate HTML ids in the returned markup.
    // @see drupal_html_id()
    options.data['ajax_html_ids[]'] = [];
    $('[id]').each(function () {
      options.data['ajax_html_ids[]'].push(this.id);
    });
  }

  // Allow Drupal to return new JavaScript and CSS files to load without
  // returning the ones already loaded.
  // @see ajax_base_page_theme()
  // @see drupal_get_css()
  // @see drupal_get_js()
  options.data['ajax_page_state[theme]'] = Drupal.settings.ajaxPageState.theme;
  options.data['ajax_page_state[theme_token]'] = Drupal.settings.ajaxPageState.theme_token;

  // Add resources if not specified otherwise.
  if (!options.data.qtools_varnish_strip_resources) {
    for (var key in Drupal.settings.ajaxPageState.css) {
      options.data['ajax_page_state[css][' + key + ']'] = 1;
    }
    for (var key in Drupal.settings.ajaxPageState.js) {
      options.data['ajax_page_state[js][' + key + ']'] = 1;
    }
  }

};
