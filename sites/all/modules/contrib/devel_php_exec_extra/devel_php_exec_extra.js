(function($){
	
	Drupal.behaviors.develPhpExecExtra = {
		phpFunctionRegex: /^[a-zA-Z_][a-zA-Z0-9_]*$/,
		updated: false,
			
		attach: function (context, settings) {
			if(context != document) return;
			var self = this;
			Drupal.develPhpExecExtra = {};
			Drupal.settings.devel_php_exec_extra.scripts = $.extend({}, Drupal.settings.devel_php_exec_extra.scripts);
			
			var textarea = $('#edit-code');
			Drupal.develPhpExecExtra.codemirror = CodeMirror.fromTextArea(
				textarea[0],
				Drupal.settings.devel_php_exec_extra
			);
			
			Drupal.develPhpExecExtra.completionContainer = $('<div id="devel_php_autocomplete" class="CodeMirror-completions" />');
			Drupal.develPhpExecExtra.completionSelect = $('<select multiple />').appendTo(Drupal.develPhpExecExtra.completionContainer);
			Drupal.develPhpExecExtra.completionContainer.hide();
			$(document.body).append(Drupal.develPhpExecExtra.completionContainer);
			
			Drupal.develPhpExecExtra.completionSelect.dblclick(Drupal.develPhpExecExtra.codemirror, this.doubleClickHandler);
			
			Drupal.develPhpExecExtra.codemirror.on('update', function(editor){self.updateHandler.call(self, editor);});
			
			var wrapper = textarea.parent();
			var scripts = Drupal.settings.devel_php_exec_extra.scripts;
			var nav_tabs = Drupal.develPhpExecExtra.navTabs = $('<ul />').addClass('ui-tabs-nav ui-helper-reset ui-helper-clearfix ui-widget-header ui-corner-all');
			for(var name in scripts){
				this.addTab(name);
			}
			$('<a href="#" />')
				.text('Add Tab')
				.click(name, function(e){e.preventDefault();self.addScript.call(self);})
				.append(
					$('<span role="presentation" />')
						.addClass('ui-icon ui-icon-plusthick')
				)
				.prependTo($('#devel-execute-form'));
			wrapper.prepend(nav_tabs).addClass('ui-tabs ui-widget ui-widget-content ui-corner-all');

			if(
				Drupal.settings.devel_php_exec_extra.currentScript === undefined || 
				Drupal.settings.devel_php_exec_extra.scripts[Drupal.settings.devel_php_exec_extra.currentScript] === undefined
			){
				if(this.countScripts() == 0){
					this.addScript();
				}
				else{
					this.switchTab(0);
				}
			}
			else{
				var current = Drupal.settings.devel_php_exec_extra.currentScript;
				Drupal.settings.devel_php_exec_extra.currentScript = null;
				this.switchTab(current);
			}
			
			window.setInterval(function(){
				if(self.updated){
					self.scriptSync();
					self.updated = false;
				}
			}, 3000);
			
			$(window).keypress(function(e){
				if(e.ctrlKey && e.which == 115){
					e.preventDefault();
					$('#devel-execute-form').submit();
				}
			});
		},
		
		countScripts: function(){
		    var size = 0, key = null;
		    for (key in Drupal.settings.devel_php_exec_extra.scripts) {
		        if (Drupal.settings.devel_php_exec_extra.scripts.hasOwnProperty(key)) size++;
		    }
		    return size;
		},
		
		switchTab: function(tab){
			if(typeof tab == 'number'){
				tab = Drupal.develPhpExecExtra.navTabs.children().eq(tab).children('a').text();
			}
			if(tab != Drupal.settings.devel_php_exec_extra.currentScript){
				var script = Drupal.settings.devel_php_exec_extra.scripts[tab];
				if(script === undefined) return false;

				Drupal.settings.devel_php_exec_extra.currentScript = tab;
				Drupal.develPhpExecExtra.codemirror.setValue(script);

				Drupal.develPhpExecExtra.navTabs.children('li').removeClass('ui-tabs-selected');
				Drupal.develPhpExecExtra.navTabs.children('li:contains(' + tab + ')').addClass('ui-tabs-selected');
			}
			
			return tab;
		},
		
		removeScript: function(tab){
			if(typeof tab == 'number'){
				tab = Drupal.develPhpExecExtra.navTabs.children().eq(tab).children('a').text();
			}
			
			Drupal.develPhpExecExtra.navTabs.children('li:contains(' + tab + ')').remove();
			delete Drupal.settings.devel_php_exec_extra.scripts[tab];
			
			if(this.countScripts() == 0){
				this.addScript();
			}
			else if(Drupal.settings.devel_php_exec_extra.currentScript == tab){
				this.switchTab(0);
			}
		},
		
		addScript: function(){
			var newScriptTab;
			var n = 1;
			do{
				newScriptTab = 'New Script ' + (n++);
			} while(Drupal.settings.devel_php_exec_extra.scripts[newScriptTab] !== undefined);

			Drupal.settings.devel_php_exec_extra.scripts[newScriptTab] = '';

			this.addTab(newScriptTab);

			this.switchTab(newScriptTab);
		},
		
		renameScript: function(oldname, newname){
			if(Drupal.settings.devel_php_exec_extra.scripts[oldname] !== undefined){
				Drupal.settings.devel_php_exec_extra.scripts[newname] = Drupal.settings.devel_php_exec_extra.scripts[oldname];
				delete Drupal.settings.devel_php_exec_extra.scripts[oldname];
				Drupal.develPhpExecExtra.navTabs.find('li a:contains(' + oldname + ')').text(newname);
				this.switchTab(newname);
			}
		},
		
		addTab: function(name){
			var self = this;
			$('<li />')
				.addClass('ui-state-default ui-corner-top')
				.hover(function(){$(this).toggleClass('ui-state-hover');})
				.append(
					$('<a href="#" />')
						.text(name)
						.click(function(e){
							e.preventDefault();
							self.switchTab.call(self, $(this).text());
						})
						.dblclick(function(e){
							e.preventDefault();
							$this = $(this);
							var text = $this.text();
							$this.hide().after($('<input type="text" />').val(text).bind('blur keypress', function(e){
								if(e.type == 'keypress' && e.which != 13){
									return;
								}
								e.preventDefault();
								$this.show();
								$(this).remove();
								self.renameScript.call(self, text, $(this).val());
								self.updated = true;
							}));
						})
				)
				.append(
					$('<span role="presentation" />').addClass('ui-icon ui-icon-closethick').text('Remove Tab').click(name, function(e){
						self.removeScript.call(self, e.data);
					})
				)
				.appendTo(Drupal.develPhpExecExtra.navTabs);
		},
		
		scriptSync: function(){
			$.post('/devel_php_exec_extra/update_scripts', {
				'scripts': JSON.stringify(Drupal.settings.devel_php_exec_extra.scripts),
				'currentScript': Drupal.settings.devel_php_exec_extra.currentScript
			});
		},
		
		updateHandler : function(editor){
			var self = this;
			var token = editor.getTokenAt(editor.getCursor());
			if(token.string.length > 3 && token.type == 'variable' && self.phpFunctionRegex.test(token.string)){
				$.getJSON('/devel_php_exec_extra/function_list/' + token.string, null, function(data, textStatus, jqXHR){
					self.ajaxCallback.call(self, data, textStatus, jqXHR, editor);
				});
			}
			else{
				Drupal.develPhpExecExtra.completionContainer.hide();
			}
			
			Drupal.settings.devel_php_exec_extra.scripts[Drupal.settings.devel_php_exec_extra.currentScript] = editor.getValue();

			self.updated = true;
		},
		
		ajaxCallback : function(data, textStatus, jqXHR, editor){
			var container = Drupal.develPhpExecExtra.completionContainer;
			var select = Drupal.develPhpExecExtra.completionSelect;
			var self = this;
			
			select.empty();
			container.hide();
			if(data.internal.length > 0 || data.user.length > 0){
				$.each(data.internal, function(i, value){
					self.stringToOption(value, select, ['internal']);
				});
				$.each(data.user, function(i, value){
					self.stringToOption(value, select, ['user']);
				});
			
				var pos = editor.cursorCoords();
				container.css({'top': pos.bottom, 'left': pos.left});
				container.show();
			}
		},
		
		stringToOption: function(string, parent, classes){
			$('<option />').val(string).html(string).addClass(classes.join(' ')).appendTo(parent);
		},
		
		doubleClickHandler: function(e){
			e.preventDefault();
			var editor = e.data;
			var container = Drupal.develPhpExecExtra.completionContainer;
			var functionName = $(e.target).text();
			var cursor = editor.getCursor();
			var token = editor.getTokenAt(cursor);
			var line = cursor.line;
			editor.replaceRange(functionName + '()', {'line': line, 'ch': token.start}, {'line': line, 'ch': token.end});
			editor.setCursor({'line': line, 'ch': token.start + functionName.length + 1});
			container.hide();
		},
	};

}(jQuery));