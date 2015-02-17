<?php
/**
 *
 * @file
 * Template file.
 */
?>
<div class="compact-books-item">
  <?php if (!empty($_html['field_book_image'])) : ?>
    <div class="book-image">
      <?php print $_html['field_book_image']; ?>
    </div>
    <div class="title"><?php print $_html['title']; ?></div>
    <div class="book-description">
      <?php print $_html['description']; ?>
    </div>
  <?php endif; ?>
  <div class="clearfix"></div>
  <div class="publication"><?php print $_html['publication']; ?></div>
  <div class="clearfix"></div>
</div>
