<?php
/**
 * @file
 * Node template placeholder.
 */
?>
<div><?php print t('placeholder %type__%mode', array('%type' => $node->type, '%mode' => $node->view_mode)); ?></div>
<?php print drupal_render($content); ?>