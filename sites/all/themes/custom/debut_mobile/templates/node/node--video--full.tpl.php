<?php
/**
 * @file
 * Node template.
 */
?>
<article class="block-video">
  <h1><?php print $_html['title']; ?></h1>
  <div class="description">
    <?php print $_html['body']; ?>
  </div>
  <div class="player">
    <?php print $_html['player']; ?>
  </div>
  <div class="clearfix"></div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
  <div class="clearfix"></div>
</article>
