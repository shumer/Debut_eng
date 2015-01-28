<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-document">
    <h1><?php print $_html['title']; ?></h1>
  <div class="document-body">
    <?php print $_html['text']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
