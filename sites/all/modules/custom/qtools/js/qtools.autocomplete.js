/**
 * @file
 * Autiocomplete extension JS.
 */

// jQuery sign.
(function ($) {

/**
 * Overrige autocomplete if lib is present.
 */
if (Drupal.ACDB && Drupal.jsAC) {
  /**
   * Performs a cached and delayed search.
   */
  Drupal.ACDB.prototype.search = function (searchString) {
    var db = this;
    this.searchString = searchString;

    // See if this string needs to be searched for anyway.
    searchString = searchString.replace(/^\s+|\s+$/, '');
    if (searchString.length <= 0 ||
      searchString.charAt(searchString.length - 1) == ',') {
      return;
    }

    // See if this key has been searched for before.
    if (this.cache[searchString]) {
      return this.owner.found(this.cache[searchString]);
    }

    // Initiate delayed search.
    if (this.timer) {
      clearTimeout(this.timer);
    }
    this.timer = setTimeout(function () {
      db.owner.setStatus('begin');

      // Gather all additional info we might need for this request.
      var $input = $(db.owner.input);
      var info_class = $input.attr('data-site-autocomplete-extra-info');
      var extra_info = {};
      if (info_class && info_class != '') {
        $input.parents('form').find('.' + info_class).each(function () {
          var name = $(this).attr('name');
          var value = $(this).val();
          if (name != '') {
            extra_info[name] = value;
          }
        });
      }

      // Ajax GET request for autocompletion. We use Drupal.encodePath instead of
      // encodeURIComponent to allow autocomplete search terms to contain slashes.
      $.ajax({
        type: 'GET',
        data: extra_info,
        url: db.uri + '/' + Drupal.encodePath(searchString),
        dataType: 'json',
        success: function (matches) {
          if (typeof matches.status == 'undefined' || matches.status != 0) {
            // Do not store cache.
            // ORIG: db.cache[searchString] = matches;
            // Verify if these are still the matches the user wants to see.
            if (db.searchString == searchString) {
              db.owner.found(matches);
            }
            db.owner.setStatus('found');
          }
        },
        error: function (xmlhttp) {
          alert(Drupal.ajaxError(xmlhttp, db.uri));
        }
      });
    }, this.delay);
  };

  /**
   * Puts the currently highlighted suggestion into the autocomplete field.
   */
  Drupal.jsAC.prototype.select = function (node) {
    // If this is custom autocomplete we store data value in another field.
    var $input = $(this.input);
    var target_name = $input.attr('data-site-autocomplete-target');
    if (target_name && target_name != '') {
      // Split value by column.
      var autocompleteValue = $(node).data('autocompleteValue').split(':');
      var $target = $input.parents('form').find('[name="' + target_name +'"]');
      if ($target.length > 0) {
        $target.val(autocompleteValue[1]);
      }
      // Updated value will be passed further.
      $(node).data('autocompleteValue', autocompleteValue[0]);
    }

    // Default behavior.
    this.input.value = $(node).data('autocompleteValue');

    // Trigger autocomplete cahnge.
    if (target_name && target_name != '') {
      $input.trigger('site-autocomplete-change');
    }
  };

  /**
   * Hides the autocomplete suggestions.
   */
  Drupal.jsAC.prototype.hidePopup = function (keycode) {
    // Select item if the right key or mousebutton was pressed.
    if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
      // Pass this to same select function.
      this.select(this.selected);
      // ORIG: this.input.value = $(this.selected).data('autocompleteValue');
    }
    // Hide popup.
    var popup = this.popup;
    if (popup) {
      this.popup = null;
      $(popup).fadeOut('fast', function () { $(popup).remove(); });
    }
    this.selected = false;
    $(this.ariaLive).empty();
  };
}

})(jQuery);