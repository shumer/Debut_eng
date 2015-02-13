<?php
/**
 * @file
 *
 * Template.
 */
?>
<div class="block-jury-years">
  <div class="block-jury-years-item">
    <div class="jury-years-wrapper slider-wrapper">
      <div class="years-slides">
        <?php foreach ($years as $link): ?>
          <?php print $link; ?>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</div>
<div class="clearfix"></div>