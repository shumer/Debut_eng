<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<h3><?php print $_html['title']; ?></h3>
<?php print $_html['short']; ?>
<?php if (!empty($_html['hidden'])) : ?>
  <div id="<?php print $_data['id']; ?>" class="hidden">
    <?php print $_html['hidden']; ?>
    <div class="clear"></div>
  </div>
  <div id="<?php print $_data['id']; ?>_button" data-ref-id="<?php print $_data['id']; ?>" class="next form-buttons form-submit js-expand-button">
    <?php print t('onward'); ?>
  </div>
  <div class="clear"></div>
<?php endif; ?>
