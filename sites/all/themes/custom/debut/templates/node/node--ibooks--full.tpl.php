<?php
/**
 *
 * @file
 * Template file.
 */
?>
<div class="news node-item books-item contextual-links-region">
  <?php print $_html['contextual_links']; ?>
  <div class="books-title">
      <?php print $_html['title']; ?>
  </div>
  <div class="books-ilink">
      <?php print $_html['ilink']; ?>
  </div>
  <?php if (!empty($_html['image'])) : ?>
    <div class="book-image">
      <?php print $_html['image']; ?>
      <div class="publication"><?php print $_html['publication']; ?></div>
    </div>
  <?php endif; ?>
  <div class="book-content">
    <h4><?php print $_html['stories_type']; ?></h4>
    <?php if (!empty($_html['authors'])) : ?>
      <?php foreach ($_html['authors'] as $author) : ?>
        <div class="book-author">
          <?php print $author['author']; ?>
          <div class="text">
            <?php print $author['stories']; ?>
          </div>
          <div class="clear"></div>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
  <div class="clear"></div>
  <div class="separator"></div>
</div>
