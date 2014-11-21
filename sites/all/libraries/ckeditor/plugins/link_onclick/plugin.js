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

  CKEDITOR.plugins.add('link_onclick', {

    init: function(editor, pluginPath) {
      CKEDITOR.on('dialogDefinition', function(e) {
        if ((e.editor != editor) || (e.data.name != 'link')) return;

        // Overrides definition.
        var definition = e.data.definition;
        var advancedTab = definition.getContents('advanced');


        definition.onOk = CKEDITOR.tools.override(definition.onOk, function(original) {
          return function(data) {
            var editor = this.getParentEditor();
            original.call(this);
            var value = this.getValueOf('OnClick', 'OnClickTextarea');
            var selection = CKEDITOR.plugins.link.getSelectedLink(editor);

            if (selection != null) {
              selection.setAttribute( 'data-cke-pa-onclick', value);
            }
          };
        });

        definition.onShow = CKEDITOR.tools.override(definition.onShow, function(original) {
          return function(data) {
            var editor = this.getParentEditor();
            original.call(this);
            var selection = CKEDITOR.plugins.link.getSelectedLink(editor);
            if (selection != null) {
              if (selection.$.nodeName == 'A' && selection.$.attributes && selection.$.attributes['data-cke-pa-onclick']) {
                console.log(selection.$.attributes['data-cke-pa-onclick']['value']);
                this.setValueOf('OnClick', 'OnClickTextarea', selection.$.attributes['data-cke-pa-onclick']['value']);
              }
            }
          };
        });

        // Add a new tab to the "Link" dialog.
        definition.addContents({
          id : 'OnClick',
          label : 'OnClick',
          accessKey : 'M',
          elements : [
            {
              id: 'OnClickTextarea',
              type: 'textarea',
              rows: 10,
              label: 'OnClick event code'
            }
          ]
        });

      });
    }
  });
})(jQuery);
