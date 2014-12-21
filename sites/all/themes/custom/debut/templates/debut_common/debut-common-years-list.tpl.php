<?php
/**
 * @file
 *
 * Template.
 */
?>
<div class="years-select-wrapper">
  <span class="year-select-text"><?php print t('Change year: '); ?></span>
<?php print drupal_render($_html['options']); ?>
</div>
<div class="clear"></div>
