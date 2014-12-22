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
}

// Init routine, will be called once.
debut_mobile_custom.init = function () {
  $context = $(document);

  // Mark this as inited.
  debut_mobile_custom._inited = true;

}
