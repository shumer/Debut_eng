<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-travel-description">
  <h1><?php print $_html['title']; ?></h1>
  <h2 class="sub-title"><?php print $_html['field_publication_date']; ?></h2>
  <div class="travel-description-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
<div class="clear-bottom"></div>