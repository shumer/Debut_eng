/**
 * @file
 * Ajax JS.
 */

// Namespace.
var qtools_ajax = qtools_ajax || {
  _fingerprints: {},
  _antispam: {},
  _queue: {},
  _windows: {}
};

// jQuery sign.
(function ($) {

/**
 * Custom commant do invoke ajax.
 */
Drupal.ajax.prototype.commands.qtools_command_ajax = function (ajax, command, status) {

  // Invoke ajax as specified in command.
  if (command.type == 'view') {
    qtools_ajax.ajax_view(command.key);
  }
  else if (command.type == 'form') {
    qtools_ajax.ajax_form(command.key);
  }
  else if (command.type == 'call') {
    qtools_ajax.ajax_call(command.name, command.key, command.data, command.method, command.spam);
  }
}

/**
 * Custom command do log info.
 */
Drupal.ajax.prototype.commands.qtools_command_log = function (ajax, command, status) {
  qtools.log(command.title, command.data);
}

/**
 * Add an extra function to the Drupal ajax object
 * which allows us to trigger an ajax response without
 * an element that triggers it.
 */
Drupal.ajax.prototype.specifiedResponse = function() {
  var ajax = this;

  // Do not perform another ajax command if one is already in progress.
  if (ajax.ajaxing) {
    return false;
  }

  // Wrap success and error functions.
  ajax._success = ajax.success;
  ajax.success = ajax._successNew;
  ajax.error = ajax._errorNew;

  try {
    $.ajax(ajax.options);
  }
  catch (err) {
    alert('An error occurred while attempting to process ' + ajax.options.url);
    return false;
  }

  // Signal others that ajax is started.
  $(document).trigger('qtools_ajax_start', [ajax.element_settings]);

  return false;
};

/**
 * Handler for the form redirection error.
 */
Drupal.ajax.prototype._errorNew = function (response, uri) {
  qtools.log(Drupal.ajaxError(response, uri));
  // Remove the progress element.
  if (this.progress.element) {
    $(this.progress.element).remove();
  }
  if (this.progress.object) {
    this.progress.object.stopMonitoring();
  }
  // Undo hide.
  $(this.wrapper).show();
  // Re-enable the element.
  $(this.element).removeClass('progress-disabled').removeAttr('disabled');
  // Reattach behaviors, if they were detached in beforeSerialize().
  if (this.form) {
    var settings = response.settings || this.settings || Drupal.settings;
    Drupal.attachBehaviors(this.form, settings);
  }
};

/**
 * Add an extra function to the Drupal ajax object
 * which allows us to trigger an ajax response without
 * an element that triggers it.
 */
Drupal.ajax.prototype._successNew = function(arg1, arg2, arg3, arg4) {
  var ajax = this;

  // Signal others that ajax is succeed.
  $(document).trigger('qtools_ajax_success', [ajax.element_settings, arg1]);

  // Extract commands that needs to be delayed or spreaded.
  spreadCommands = [];
  for (i in arg1) {

    // Add to spread list.
    if (!arg1[i].stopSpread) {
      spreadCommands.push(arg1[i]);
    }

    if (arg1[i].timeout) {

      // Create a timeout before execute command.
      setTimeout(function(command) {
        qtools_ajax.process_commands([command]);
      }, arg1[i].timeout, arg1[i]);

      // Delete command from default thread.
      delete arg1[i];
    }
  }

  // Call original handler.
  $return = ajax._success(arg1, arg2, arg3, arg4);

  // Unlock ajax calls, giving time for commands to fire.
  if (ajax.element_settings.fingerid && qtools_ajax._fingerprints[ajax.element_settings.fingerid]) {
    delete qtools_ajax._fingerprints[ajax.element_settings.fingerid];
  }

  // Pass this to all child windows.
  if (spreadCommands.length > 0) {
    for (name in qtools_ajax._windows) {
      var window_item = qtools_ajax._windows[name];
      if (window_item['window'].location && window_item['window'].qtools_ajax && window_item['window']._qtools_ajax_window_fingerprint) {
        if (window_item['window']._qtools_ajax_window_fingerprint == window_item['fingerprint']) {
          window_item['window'].qtools_ajax.process_commands(spreadCommands);
        }
      }
    }
  }

  // Call original handler.
  return $return;
};

Drupal.ajax.prototype.commands.insert = function (ajax, response, status) {
  // Get information from the response. If it is not there, default to
  // our presets.
  var wrapper = response.selector ? $(response.selector) : $(ajax.wrapper);
  var method = response.method || ajax.method;
  var effect = ajax.getEffect(response);

  // We don't know what response.data contains: it might be a string of text
  // without HTML, so don't rely on jQuery correctly iterpreting
  // $(response.data) as new HTML rather than a CSS selector. Also, if
  // response.data contains top-level text nodes, they get lost with either
  // $(response.data) or $('<div></div>').replaceWith(response.data).
  var new_content_wrapped = $('<div></div>').html(response.data);
  var new_content = new_content_wrapped.contents();

  // For legacy reasons, the effects processing code assumes that new_content
  // consists of a single top-level element. Also, it has not been
  // sufficiently tested whether attachBehaviors() can be successfully called
  // with a context object that includes top-level text nodes. However, to
  // give developers full control of the HTML appearing in the page, and to
  // enable Ajax content to be inserted in places where DIV elements are not
  // allowed (e.g., within TABLE, TR, and SPAN parents), we check if the new
  // content satisfies the requirement of a single top-level element, and
  // only use the container DIV created above when it doesn't. For more
  // information, please see http://drupal.org/node/736066.
  if (new_content.length != 1 || new_content.get(0).nodeType != 1) {
    // We do not wrap items here.
    //new_content = new_content_wrapped;
  }

  // If removing content from the wrapper, detach behaviors first.
  switch (method) {
    case 'html':
    case 'replaceWith':
    case 'replaceAll':
    case 'empty':
    case 'remove':
      var settings = response.settings || ajax.settings || Drupal.settings;
      Drupal.detachBehaviors(wrapper, settings);
  }

  // Add the new content to the page.
  wrapper[method](new_content);

  // Immediately hide the new content if we're using any effects.
  if (effect.showEffect != 'show') {
    new_content.hide();
  }

  // Determine which effect to use and what content will receive the
  // effect, then show the new content.
  if ($('.ajax-new-content', new_content).length > 0) {
    $('.ajax-new-content', new_content).hide();
    new_content.show();
    $('.ajax-new-content', new_content)[effect.showEffect](effect.showSpeed);
  }
  else if (effect.showEffect != 'show') {
    new_content[effect.showEffect](effect.showSpeed);
  }

  // Attach all JavaScript behaviors to the new content, if it was successfully
  // added to the page, this if statement allows #ajax['wrapper'] to be
  // optional.
  if (new_content.parents('html').length > 0) {
    // Apply any settings from the returned JSON if available.
    var settings = response.settings || ajax.settings || Drupal.settings;
    Drupal.attachBehaviors(new_content, settings);
  }
}

/**
 * Manual command process.
 */
qtools_ajax.process_commands = function (commands) {

  // Create Fake ajax.
  var custom_settings = {};
  custom_settings.url = '';
  custom_settings.event = 'onload';
  custom_settings.keypress = false;
  custom_settings.prevent = false;
  custom_settings.submit = {};
  custom_settings.fingerid = false;

  // Create new ajax and execute.
  var ajax = new Drupal.ajax(null, $(document.body), custom_settings);
  ajax.success(commands);

  qtools.log('manual commands:', commands);
}

/**
 * Process queue.
 */
qtools_ajax.queue_process = function (_fingerid, _fingerprint, info, msg) {

  // Ad item to queue if specified.
  if (_fingerid && info) {
    qtools_ajax._queue[_fingerid] = {
      '_fingerprint': _fingerprint,
      'info': info
    };

    // Log spam.
    qtools.log(msg);
  }
  // Or attempt to call one of the queued items.
  else {

    var time_now = new Date().getTime();
    for (_fingerid in qtools_ajax._queue) {
      // Load info.
      info = qtools_ajax._queue[_fingerid]['info'];
      _fingerprint =  qtools_ajax._queue[_fingerid]['_fingerprint'];

      // Check if we have newer data already send, then we discard this queue item.
      if (qtools_ajax._antispam[_fingerid] != _fingerprint) {
        delete qtools_ajax._queue[_fingerid];
        qtools.log('resend canceled: ', info.name);
      }
      // Do recall.
      if (qtools_ajax._queue[_fingerid]) {
        var result = qtools_ajax.ajax_call(info.name, info.url, info.data, info.method, info.spam, info.unlock, true);
        if (typeof(result) == 'string') {
          qtools.log('resend declined: ', result);
        }
        else {
          qtools.log('resend success: ', info.name);
          delete qtools_ajax._queue[_fingerid];
        }
      }
    }
  }

  // See if we need to recheck this later.
  var recheck = false;
  var items = [];
  for (_fingerid in qtools_ajax._queue) {
    items.push(_fingerid);
    recheck = true;
  }

  // Update timeout if we need to recheck.
  if (recheck) {
    setTimeout(function () {
      qtools_ajax.queue_process();
    }, 500);
  }
  qtools.log('ajax queue:', items.length + ' ' + items.join(', '));
}

/**
 * Simple ajax call wrapper.
 */
qtools_ajax.ajax_call = function (name, url, data, method, spam, unlock, skip_queue) {

  // If name empty - default it to URL.
  if (!name || name == '') {
    name = url;
  }

  // Check for spam and save firngerprint.
  spam = spam || 1000;
  unlock = unlock || spam + 1000;
  skip_queue = skip_queue || false;
  var forbidden = '';
  if (spam > 0 || unlock > 0) {
    var _fingerid = name;
    var _fingerprint = new Date().getTime();

    // If current request is in progress and we not reached unlock time - queue this request.
    if (qtools_ajax._fingerprints[_fingerid]) {
      if (_fingerprint - qtools_ajax._fingerprints[_fingerid] < unlock) {
        forbidden = 'locked:' + name;
      }
    }
    else {
      // If current request is finished we check for antispam.
      if (qtools_ajax._antispam[_fingerid]) {
        if (_fingerprint - qtools_ajax._antispam[_fingerid] < spam) {
          forbidden = 'spammed:' + name;
        }
      }
    }
  }

  // If we have this request forbidden.
  if (forbidden != '') {
    // We might want to skip queue in case this is done during queue check.
    if (!skip_queue) {
      // Save this request as awaiting to get processed, this will overwrite
      // Any other requests that wait in same queue (_fingerid).
      qtools_ajax.queue_process(_fingerid, qtools_ajax._antispam[_fingerid], {
        'name': name,
        'url': url,
        'data': data,
        'method': method || 'post',
        'spam': spam,
        'unlock' : unlock
      }, forbidden);
      return;
    }
    else {
      return forbidden;
    }
  }

  // Simple settings.
  var custom_settings = {};
  custom_settings.name = name;
  custom_settings.url = url;
  custom_settings.event = 'onload';
  custom_settings.keypress = false;
  custom_settings.prevent = false;
  custom_settings.submit = data;
  custom_settings.fingerid = _fingerid || false;

  // Create new ajax and execute.
  Drupal.ajax[name] = new Drupal.ajax(null, $(document.body), custom_settings);

  if (Drupal.ajax[name]) {
    // Save fingerprint if we got valid object.
    qtools_ajax._fingerprints[_fingerid] = _fingerprint;
    qtools_ajax._antispam[_fingerid] = _fingerprint;

    // Swap ajax mehod if required.
    Drupal.ajax[name].options.type = method || 'post';

    // Trigger ajax call.
    Drupal.ajax[name].specifiedResponse();
  }

  // Return object for future user.
  return Drupal.ajax[name];
}

/**
 * Find view settings function.
 * View must be created as ajax view in Drupal and present on the page load.
 */
qtools_ajax.view_settings = function (name, limited) {
  var viewSettings = false;
  var viewDomID = false;
  if (Drupal.settings.views && Drupal.settings.views.ajaxViews) {
    for (domID in Drupal.settings.views.ajaxViews) {
      if (Drupal.settings.views.ajaxViews[domID].view_name == name) {
        viewDomID = domID;
        viewSettings = jQuery.extend(true, {}, Drupal.settings.views.ajaxViews[domID]);
      }
    }
  }

  // Add on page settings to the view.
  if (!limited && viewSettings && viewSettings.view_dom_id) {
    var $view = $('.view-dom-id-' + viewSettings.view_dom_id);

    // Add exposed form values.
    var $form = $view.find('form');
    if ($form.length > 0) {
      var formValues = $form.serializeArray();
      for (i in formValues) {
        viewSettings[formValues[i].name] = formValues[i].value;
      }
    }

    // Add pager.
    var $pager = $view.find('.pagination');
    if ($pager.length) {
      var page = $pager.find('.active').text();
      viewSettings.page = parseInt(page) - 1;
    }
  }
  return viewSettings;
}

/**
 * Views ajax call wrapper.
 */
qtools_ajax.ajax_view = function (name, data, method, spam) {

  // Get view settings.
  data = data || qtools_ajax.view_settings(name);

  // Invoke ajax call.
  qtools_ajax.ajax_call(name, '/views/ajax', data, method, spam);
}

/**
 * Views ajax call wrapper.
 */
qtools_ajax.ajax_form = function (domID, spam, extraData) {
  var $form = $('form#' + domID);
  if ($form.length < 1) {
    // TODO log error.
    return;
  }

  // Serialize form.
  var data = $('#' + domID).serializeArray();
  if (extraData) {
    for (i in extraData) {
      data.push(extraData[i]);
    }
  }

  var url = $form.attr('action');
  var method = $form.attr('method');

  // Invoke ajax call.
  qtools_ajax.ajax_call(domID, url, data, method, spam);
}

/**
 * Connect new window to the ajax routine.
 */
qtools_ajax.window_set = function (new_window, name) {
  if (new_window) {
    new_window._qtools_ajax_window_fingerprint = new Date().getTime();
    qtools_ajax._windows[name] = {
      'window': new_window,
      'fingerprint': new_window._qtools_ajax_window_fingerprint
    };
  }
  else if (qtools_ajax._windows[name]) {
    delete qtools_ajax._windows[name];
  }
}

})(jQuery);
