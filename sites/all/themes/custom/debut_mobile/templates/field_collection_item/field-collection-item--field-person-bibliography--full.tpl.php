<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="bibliography-item">
  <h3 class="sub-title"><?php print $_html['title']; ?></h3>
  <?php print $_html['short']; ?>
  <?php if (!empty($_html['hidden'])) : ?>
    <div class="block-button-more" data-target="bibliography-long-<?php print $_data['id']; ?>">
      <span><?php print t('onward'); ?></span>
    </div>
    <div class="bibliography-long bibliography-long-<?php print $_data['id']; ?>" style="display: none">
      <?php print $_html['hidden']; ?>
    </div>
    <div class="clearfix"></div>
  <?php endif; ?>
</div>
