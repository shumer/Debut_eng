<?php
/**
 * @file
 * Node template.
 */
?>
<div class="video contextual-links-region">
  <?php print $_html['contextual_links']; ?>
  <div class="video-listing">
    <h2><?php print $_html['title']; ?></h2>
    <div class="player">
      <?php print $_html['image']; ?>
    </div>
    <div class="description"><?php print $_html['body']; ?></div>
  </div>
  <div class="clear"></div>
</div>
