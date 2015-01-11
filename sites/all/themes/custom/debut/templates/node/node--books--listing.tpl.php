<?php
/**
 *
 * @file
 * Template file.
 */
?>
<div class="news node-item books-item contextual-links-region">
  <?php print $_html['contextual_links']; ?>
  <?php if (!empty($_html['image'])) : ?>
    <div class="book-image">
      <?php print $_html['image']; ?>
    </div>
  <?php endif; ?>
  <div class="book-content">
    <div class="books-title">
      <?php print $_html['title']; ?>
    </div>
    <?php print $_html['description']; ?>
  </div>
  <?php if (!empty($_html['authors'])): ?>
    <div class="authors">
      <h2><?php print t('Authors'); ?></h2>
      <?php print $_html['authors']; ?>
    </div>
  <?php endif; ?>
  <div class="clear"></div>
  <div class="publication"><?php print $_html['publication']; ?></div>
  <div class="clear"></div>
  <div class="separator"></div>
</div>
