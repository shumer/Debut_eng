<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-interview">
  <h1><?php print $_html['title']; ?></h1>
  <?php if (!empty($_html['author'])) : ?>
    <figure class="interview-photo">
      <?php print $_html['author']; ?>
    </figure>
  <?php endif; ?>
  <div class="interview-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>