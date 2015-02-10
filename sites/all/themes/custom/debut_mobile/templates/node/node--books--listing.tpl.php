<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-books listing <?php print $_data['class']; ?>">
  <h1><?php print $_html['title']; ?></h1>
  <?php if (!empty($_html['image'])) : ?>
    <div class="book-image">
      <?php print $_html['image']; ?>
    </div>
  <?php endif; ?>
  <div class="book-description">
    <?php print $_html['description']; ?>
  </div>
  <div class="clearfix"></div>
  <?php if (!empty($_html['authors'])): ?>
    <div class="authors">
      <h2 class="sub-title"><?php print t('Authors'); ?></h2>
      <?php print $_html['authors']; ?>
    </div>
  <?php endif; ?>
  <div class="clearfix"></div>
  <div class="publication"><?php print $_html['publication']; ?></div>
  <div class="clearfix"></div>
  <div class="separator"></div>
</article>
