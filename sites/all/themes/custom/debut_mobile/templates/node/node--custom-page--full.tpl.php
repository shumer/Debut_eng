<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-interview">
  <h1><?php print $_html['title']; ?></h1>
  <div class="interview-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
