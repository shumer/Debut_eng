<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-news">
  <h1><?php print $_html['title']; ?></h1>
  <h2 class="sub-title"><?php print $_html['field_publication_date']; ?></h2>
  <div class="news-body">
    <?php print $_html['text']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
<div class="clear-bottom"></div>
