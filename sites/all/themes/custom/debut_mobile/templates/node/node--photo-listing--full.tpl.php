<?php
/**
 * @file
 * Template file.
 */
?>
<div class="node-photo-item photo-listing-item">
  <div class="title">
    <h1><?php print $_html['title']; ?></h1>
  </div>
  <div class="slider-wrapper">
    <div class="flexslider">
      <?php print $_html['images']; ?>
    </div>
  </div>
  <div class="separator"></div>
  <div class="photo-main-control-wrap"></div>

  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>

</div>
<div class="clearfix"></div>
