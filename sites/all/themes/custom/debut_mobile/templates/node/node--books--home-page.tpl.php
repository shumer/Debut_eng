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
      <?php print $_html['title']; ?><?php print $_html['field_book_image']; ?>
    </div>
  <?php endif; ?>
</div>
