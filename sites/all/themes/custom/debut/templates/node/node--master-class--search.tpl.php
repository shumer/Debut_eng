<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="documents node-item documents-item-full master-class-section">
  <div class="master-class-title">
    <?php print $node->_html['title']; ?>
  </div>
  <div class="clear"></div>
  <?php if (!empty($node->_html['texts'])) : ?>
    <div class="master-class-texts">
      <?php print $node->_html['texts']; ?>
    </div>
    <div class="clear"></div>
  <?php endif; ?>
  <div class="author">
    <?php if (!empty($node->_html['master'])) : ?>
      <div class="master">
        <h3><?php print t('Conducted a master class'); ?></h3>
        <?php print $node->_html['master']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($node->_html['interviews'])) : ?>
      <div class="interview">
        <h3><?php print t('Interviews with participants'); ?></h3>
        <?php print $node->_html['interviews']; ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="clear"></div>
</div>
