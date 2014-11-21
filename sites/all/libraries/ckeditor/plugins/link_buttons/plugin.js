(function($) {

  // Get a CKEDITOR.dialog.contentDefinition object by its ID.
  var getById = function(array, id, recurse) {
    for (var i = 0, item; (item = array[i]); i++) {
      if (item.id == id) return item;
      if (recurse && item[recurse]) {
        var retval = getById(item[recurse], id, recurse);
        if (retval) return retval;
      }
    }
    return null;
  };

  CKEDITOR.plugins.add('link_buttons', {

    init: function(editor, pluginPath) {
      CKEDITOR.on('dialogDefinition', function(e) {
        if ((e.editor != editor) || (e.data.name != 'link')) return;

        // Overrides definition.
        var definition = e.data.definition;
        var infoTab = definition.getContents('info');


        definition.onOk = CKEDITOR.tools.override(definition.onOk, function(original) {
          return function(data) {
            var editor = this.getParentEditor();
            original.call(this);
              var value = this.getValueOf('info', 'LinkButton');
            var options = ['button-green', 'button-blue-big', 'button-blue', 'button-orange-big', 'button-orange'],
            length = options.length, selection = CKEDITOR.plugins.link.getSelectedLink(editor);

            if (selection != null) {
              for (var i = 0; i < length; i++) {
                selection.removeClass(options[i]);
              }
              if (value != "") {
                selection.addClass(value);
              }
            }
          };
        });

        definition.onShow = CKEDITOR.tools.override(definition.onShow, function(original) {
          return function(data) {
            var editor = this.getParentEditor();
            original.call(this);
            var options = ['button-green', 'button-blue-big', 'button-blue', 'button-orange-big', 'button-orange'],
              length = options.length, selection = CKEDITOR.plugins.link.getSelectedLink(editor);
            if (selection != null) {
              for (var i = 0; i < length; i++) {
                if (selection.$.className.indexOf(options[i]) != -1) {
                  this.setValueOf('info', 'LinkButton', options[i]);
                  break;
                }
              }
            }
          };
        });

        // Append new element.
        infoTab.elements.unshift(
          {
            id: 'LinkButton',
            type: 'select',
            label: 'Visual Type',
            'default': '',
            items: [
              [ '', '' ],
              [ 'Green button', 'button-green' ],
              [ 'Blue button', 'button-blue' ],
              [ 'Blue big button', 'button-blue-big' ],
              [ 'Orange button', 'button-orange' ],
              [ 'Orange big button', 'button-orange-big' ]
            ]
          }
        );
      });
    }
  });
})(jQuery);
