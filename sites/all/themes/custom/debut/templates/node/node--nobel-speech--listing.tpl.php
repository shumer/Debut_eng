<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="news node-item news-item press-item">
  <div class="news-title press-title">
    <?php print $_html['title']; ?>
  </div>
  <?php if (!empty($_html['author'])) : ?>
    <div class="author-press">
      <?php print $_html['author']; ?>
    </div>
  <?php endif; ?>
  <div class="clear"></div>
  <span class="date"><?php print $_html['press_date']; ?></span>
</div>
<div class="clear"></div>