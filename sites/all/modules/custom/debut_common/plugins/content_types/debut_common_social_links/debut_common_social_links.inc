<?php
/**
 * @file
 *
 * CCT plugin file.
 */

$plugin = array(
  'title' => t('Debut Common: Social links block'),
  'description' => t('Debut Common: Social links  block'),
  'content_types' => 'debut_common_social_links',
  'single' => TRUE,
  'render callback' => 'debut_common_social_links_content_type_render',
  'edit form' => 'debut_common_social_links_content_type_edit_form',
  'admin title' => 'debut_common_social_links_content_type_admin_title',
  'hook theme' => 'debut_common_social_links_content_type_theme',
  'category' => t('Debut'),
  'icon' => NULL,
  'no title override' => TRUE,
  'required context' => array(new ctools_context_optional(t('Node'), 'node')),
);

/**
 * Render callback.
 */
function debut_common_social_links_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $_data = array();
  $_html = array();

  $current_context = reset($context);
  // Get title of node.
  $text = !empty($current_context->data)
    ? $current_context->data->title
    : NULL;
  $path = $_GET['q'];

  // Twitter link.
  $_html['tweet'] = '<a href="https://twitter.com/share" class="twitter-share-button" data-lang="ru" data-count="none">Tweeter</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>';

  // Facebook button.
  $url = url('http://www.facebook.com/plugins/like.php', array('query' => array(
    'href' => url($path, array('absolute' => TRUE)),
    'text' => $text,
    'height' => 22,
    'send' => 'false',
    'layout' => 'button_count',
    'width' => 136,
    'show_faces' => 'false',
    'action' => 'like',
    'locale' => 'ru_RU',
  )));
  $_html['fblike'] = '<iframe scrolling="no" frameborder="0" allowtransparency="true" style="border:none; overflow:hidden; width:136px; height:22px;" src="' . $url . '"></iframe>';

  // G+button.
  $_html['gplus'] = "<!-- Place this tag where you want the +1 button to render. -->
    <div class='g-plusone' data-size='medium' data-annotation='none'></div>

    <!-- Place this tag after the last +1 button tag. -->
    <script type='text/javascript'>
    window.___gcfg = {lang: 'ru'};

    (function() {
      var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
      po.src = 'https://apis.google.com/js/plusone.js';
      var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
    })();
  </script>";


  $_html['vk'] = "<script type=\"text/javascript\" src=\"http://userapi.com/js/api/openapi.js?50\"></script>
    <script type=\"text/javascript\">
      VK.init({apiId: 3357115, onlyWidgets: true});
    </script>

    <div id=\"vk_like\"></div>

    <script type=\"text/javascript\">
      VK.Widgets.Like(\"vk_like\", {type: \"button\"});
    </script>";

  $data['_data'] = $_data;
  $data['_html'] = $_html;

  $block->content = theme('debut_common_social_links', $data);
  return $block;
}

/**
 * Returns an edit form for the custom type.
 *
 * This is required to get access to the context.
 */
function debut_common_social_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#tree' => TRUE,
  );
  return $form;
}

/**
 * Presubmit hndler.
 *
 * This is required to get access to the context.
 */
function debut_common_social_links_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function debut_common_social_links_content_type_admin_title($subtype, $conf, $context) {
  return t('Debut Common: Social links block');
}

/**
 * Implements hook_content_type_theme().
 */
function debut_common_social_links_content_type_theme(&$theme, $plugin) {
  $theme['debut_common_social_links'] = array(
    'path'      => $plugin['path'],
    'template'  => 'debut-common-social-links',
    'variables' => array('params' => array()),
  );
}
