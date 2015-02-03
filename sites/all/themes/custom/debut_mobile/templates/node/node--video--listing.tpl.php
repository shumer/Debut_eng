<?php
/**
 * @file
 * Node template.
 */
?>
<article class="block-video listing <?php print $_data['class']; ?>">
  <div class="video-listing">
    <h1><?php print $_html['title']; ?></h1>
    <div class="player">
      <?php print $_html['image']; ?>
    </div>
    <div class="description">
      <?php print $_html['body']; ?>
    </div>
  </div>
  <div class="clear"></div>
</article>
