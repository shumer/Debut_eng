<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-books">
  <h1><?php print $_html['title']; ?></h1>
  <?php if (!empty($_html['image'])) : ?>
    <div class="book-image">
      <?php print $_html['image']; ?>
      <div class="publication"><?php print $_html['publication']; ?></div>
    </div>
  <?php endif; ?>
  <?php if (!empty($_html['pdf_link'])) : ?>
    <div class="book-pdf-link">
      <?php print $_html['pdf_link']; ?>
    </div>
  <?php endif; ?>
  <div class="book-content">
    <h3 class="sub-title"><?php print $_html['stories_type']; ?></h3>
    <?php if (!empty($_html['authors'])) : ?>
      <?php foreach ($_html['authors'] as $author) : ?>
        <div class="book-author">
          <?php print $author['author']; ?>
          <div class="text">
            <?php print $author['stories']; ?>
          </div>
          <div class="clearfix"></div>
        </div>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
  <div class="clearfix"></div>
  <div class="separator"></div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
