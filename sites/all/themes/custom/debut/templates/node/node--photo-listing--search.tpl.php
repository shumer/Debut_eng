<?php
/**
 * @file
 * Template file.
 */
?>
<div class="photo node-item photo-listing-item">
  <div class="title">
    <?php print $node->_html['title']; ?>
  </div>
  <?php foreach ($node->_html['images'] as $image) : ?>
    <?php print $image; ?>
  <?php endforeach; ?>
  <div class="separator"></div>
</div>
