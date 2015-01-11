<?php
/**
 *
 * @file
 * Template file.
 */
?>
<div class="news node-item news-item contextual-links-region">
    <?php print $_html['contextual_links']; ?>
  <div class="news-title">
      <?php print $_html['title']; ?>
  </div>
  <?php if (!empty($news_image)) : ?>
    <div class="news-image-full">
      <?php print $news_image; ?>
    </div>
  <?php endif; ?>
  <div class="news-body">
    <?php print $_html['text']; ?>
  </div>
  <div class="clear"></div>
  <span class="date"><?php print $_html['news_date']; ?></span>
</div>
<div class="clear"></div>
