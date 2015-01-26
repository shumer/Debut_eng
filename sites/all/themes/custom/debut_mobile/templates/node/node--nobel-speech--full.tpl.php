<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-nobel-speech full">
  <h1><?php print $_html['title']; ?></h1>
  <div class="part part-a">
    <div class="pic">
      <div class="pic-inner">
        <?php print $_html['image']; ?>
      </div>
      <span class="legende"><?php print $_html['image_legende']; ?></span>
    </div>
  </div>
  <?php if (!empty($_html['title'])): ?>
    <!--h1><?php print $_html['title']; ?></h1>
    <h2><?php print $_html['author']; ?></h2-->
  <?php else: ?>
    <!--h1><?php print $_html['author']; ?></h1-->
  <?php endif; ?>
  <h2 class="sub-title"><?php print $_html['press_date']; ?></h2>
  <div class="news-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="clear"></div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
<div class="clear-bottom"></div>
