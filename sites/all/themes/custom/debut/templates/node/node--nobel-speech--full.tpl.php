<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="person node-item person-item nobel-speech-item">
  <div class="part part-a">
    <div class="pic">
      <div class="pic-inner">
        <?php print $_html['image']; ?>
      </div>
      <span class="legende"><?php print $_html['image_legende']; ?></span>
    </div>
    <?php if (!empty($_html['title'])): ?>
      <h1><?php print $_html['title']; ?></h1>
      <h2><?php print $_html['author']; ?></h2>
    <?php else: ?>
      <h1><?php print $_html['author']; ?></h1>
    <?php endif; ?>
  </div>
  <div class="news-body">
    <?php print $_html['body']; ?>
  </div>
  <div class="clear"></div>
  <span class="date"><?php print $_html['press_date']; ?></span>
</div>
<div class="clear"></div>
