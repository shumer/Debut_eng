/**
 * @file
 * Ajax JS.
 */

// Namespace.
var qtools = qtools || {};

/**
 * IE7 trim supports.
 * @see http://stackoverflow.com/questions/2308134/trim-in-javascript-not-working-in-ie
 */
if(typeof String.prototype.trim !== 'function') {
  String.prototype.trim = function() {
    return this.replace(/^\s\s*/, '').replace(/\s\s*$/, '');
  }
}

/**
 * Execution time test function.
 */
qtools.devTestTime = function(callback, loop_count) {
  var start = new Date().getTime();
  loop_count = loop_count || 1;
  for (var i = 1; i <= loop_count; i++) {
    callback();
  }
  var spend = new Date().getTime() - start;
  return [loop_count, spend, spend / loop_count];
}

/**
 * Local storage Get.
 */
qtools.localStorageGet = function (bin, key, def_value, type) {
  var value = def_value;
  var lskey = bin + '-' + key;
  if ('localStorage' in window) {
    if (typeof(window.localStorage[lskey]) != 'undefined') {
      value = window.localStorage[lskey];

      // Set proper type.
      if (type == 'i') {
        value = parseInt(value);
      }
      else if (type == 'f') {
        value = parseFloat(value);
      }
    }
  }

  // Return value.
  return value;
}

/**
 * Local storage Set.
 */
qtools.localStorageSet = function (bin, key, value) {
  var lskey = bin + '-' + key;
  if ('localStorage' in window) {
    window.localStorage[lskey] = value;
    return true;
  }
  // Return false if storage not available.
  return false;
}

/**
 * Local storage Remove.
 */
qtools.localStorageRemove = function (bin, key) {
  var lskey = bin + '-' + key;
  if ('localStorage' in window) {
    window.localStorage.removeItem(lskey);
  }
}

/**
 * Local storage List.
 */
qtools.localStorageList = function (bin) {
  var result = [];
  if ('localStorage' in window) {
    for (i in window.localStorage) {
      if (i.indexOf(bin) == 0) {
        // Remove bin from index.
        var key = i.replace(bin + '-', '');
        result.push(key);
      }
    }
  }
  return result;
}

/**
 * Url parser.
 */
qtools.parseUrl = function (href) {
  if (!qtools.parseUrl._parser) {
    qtools.parseUrl._parser = document.createElement('a');
  }
  qtools.parseUrl._parser.href = href;
  var result = {
    hash: qtools.parseUrl._parser.hash,
    href: (qtools.parseUrl._parser.hostname != "") ? qtools.parseUrl._parser.href : '',
    host: qtools.parseUrl._parser.hostname,
    path: qtools.parseUrl._parser.pathname,
    search: qtools.parseUrl._parser.search
  };

  return result;
}

/**
 * Unescape function not finished.
 */
qtools.unescape = function (string) {
  string = string.replace(/\\\//g, '/');
  string = string.replace(/\\b/g, "\b");
  string = string.replace(/\\f/g, "\f");
  string = string.replace(/\\n/g, "\n");
  string = string.replace(/\\0/g, "\0");
  string = string.replace(/\\r/g, "\r");
  string = string.replace(/\\t/g, "\t");
  string = string.replace(/\\v/g, "\v");
  string = string.replace(/\\'/g, "'");
  string = string.replace(/\\"/g, '"');
  return string;
}

/**
 * Create onload event.
 */
qtools.addEventListener = function(c, b, a) {
  if("undefined" != typeof(window.attachEvent)) {
    return window.attachEvent("on" + c, b);
  }
  else {
    if (window.addEventListener) {
      return window.addEventListener(c, b, a);
    }
  }
};

/**
 * Add onload listener.
 */
qtools.addOnLoadListener = function (d, e) {
  var a = document.readyState;
  if (typeof a === "undefined") {
    e = 0;
  }
  var f = function () {
    setTimeout(d, e);
  }
  if (a === "complete") {
    f();
  }
  else {
    if (typeof a === "undefined") {
      var c = function () {
        var e = document.getElementsByTagName("*");
        return e[e.length - 1];
      };
      var b = c();
      setTimeout(function () {
        if(c() === b && typeof document.readyState === "undefined") {
          f();
        }
      }, 500);
    }
    else {
      qtools.addEventListener("load", f, false);
    }
  }
};

/**
 * Set cookie.
 * @see http://www.w3schools.com/js/js_cookies.asp
 */
qtools.cookie_set = function (cname, cvalue, exdays, domain) {
  if (domain) {
    domain = 'domain=' + domain + '; ';
  }
  else {
    domain = '';
  }
  var d = new Date();
  d.setTime(d.getTime() + (exdays * 24 * 60 * 60 * 1000));
  var expires = "expires=" + d.toGMTString();
  var newCookie = cname + "=" + cvalue + "; " + expires + "; " + domain +  "path=/";
  document.cookie = newCookie;
}

/**
 * Remove cookies "."+document.location.hostname;
 */
qtools.cookie_del = function (cname)   {
  // Remove site cookies.
  qtools.cookie_set(cname, "", -14);

  // Remove foreign cookies.
  path = ";path=" + "/";
  domain = ";domain=" + "." + document.location.hostname;
  var expiration = "Thu, 01-Jan-1970 00:00:01 GMT";
  document.cookie = cname + "=" + path + domain + ";expires=" + expiration;
}

/**
 * Get cookie.
 * @see http://www.w3schools.com/js/js_cookies.asp
 */
qtools.cookie_get = function (cname) {
  var name = cname + "=";
  var ca = document.cookie.split(';');
  for(var i = 0; i < ca.length; i++) {
    var c = ca[i].trim();
    if (c.indexOf(name) == 0) return c.substring(name.length,c.length);
  }
  return "";
}

/**
 * Check if cookie enabled.
 */
qtools.cookie_enabled = function () {
  var enabled = false;
  qtools.cookie_set("qtoolsCookiesEnabled", "enabled", 1);
  if (qtools.cookie_get("qtoolsCookiesEnabled") == "enabled") {
    enabled = true;
    qtools.cookie_det("qtoolsCookiesEnabled");
  }
  return enabled;
}

/**
 * Log function.
 */
qtools.log = function(text, data) {
  // Check if log disabled.
  if (qtools_settings && qtools_settings.base && qtools_settings.base.log) {
    if (typeof console == "object" && typeof console.log == "function")  {
      if (data) {
        console.log(text, data);
      }
      else {
        console.log(text);
      }
    }
  }
}
