<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-travels">
  <h1><?php print $_html['title']; ?></h1>
  <div class="travels-description-list">
    <?php print $_html['content']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>  
</article>
