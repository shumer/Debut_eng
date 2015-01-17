<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="documents node-item documents-item-full master-class-section">
  <div class="documents-title">
    <?php print $_html['title']; ?>
  </div>
  <div class="documents-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="clear"></div>
  <?php if (!empty($_html['texts'])) : ?>
    <div class="master-class-texts">
      <?php print $_html['texts']; ?>
    </div>
    <div class="clear"></div>
  <?php endif; ?>
  <?php if (!empty($_html['master'])) : ?>
    <div class="master">
      <h3><?php print t('Conducted a master class'); ?></h3>
      <?php print $_html['master']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($_html['interviews'])) : ?>
    <div class="interview">
      <h3><?php print t('Interviews with participants'); ?></h3>
      <?php print $_html['interviews']; ?>
    </div>
  <?php endif; ?>
</div>
