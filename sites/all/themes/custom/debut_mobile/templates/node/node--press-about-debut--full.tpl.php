<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-press">
  <h1><?php print $_html['title']; ?></h1>
  <h2 class="sub-title"><?php print $_html['field_publication_date']; ?></h2>
  <?php if (!empty($_html['press_link'])) : ?>
    <div class="link-press link-press-text">
      <?php print $_html['press_link']; ?>
    </div>
    <?php if (!empty($_html['author'])) : ?>
      <div class="author-press">
        <?php print $_html['author']; ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>
  <div class="press-body">
    <?php print $_html['field_press_text']; ?>
  </div>
  <?php if (!empty($_html['press_link'])) : ?>
    <div class="link-press">
      <?php print $_html['press_link']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($_html['author'])) : ?>
    <div class="author-press">
      <?php print $_html['author']; ?>
    </div>
  <?php endif; ?>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
