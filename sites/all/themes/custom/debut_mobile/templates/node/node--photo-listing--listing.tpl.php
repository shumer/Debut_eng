<?php
/**
 * @file
 * Template file.
 */
?>
<div class="photo node-item photo-listing-item">
  <div class="title">
    <h3><?php print $_html['title']; ?></h3>
  </div>
  <div class="slider-wrapper">
    <div class="<?php print $_data['class']; ?>" data-wrapper-class="photo-main-control-wrap-<?php print $_data['wrapper_class']; ?>">
      <?php print $_html['images']; ?>
    </div>
  </div>
  <div class="separator"></div>
  <div class="photo-main-control-wrap-<?php print $_data['wrapper_class']; ?> "></div>
  <div class="node-page-link">
    <?php print $_html['node_page_link']; ?>
  </div>
</div>
<div class="clearfix"></div>
