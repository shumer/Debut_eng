<?php
/**
 * @file
 * Template for a Debut main page layout.
 */
?>

<div id="page">
  <div id="page-inner">
  <?php if (!empty($content['header'])): ?>
    <?php print $content['header']; ?>
  <?php endif ?>

  <?php if (!empty($content['content'])): ?>
    <?php print $content['content']; ?>
  <?php endif ?>

  <?php if (!empty($content['footer'])): ?>
    <?php print $content['footer']; ?>
  <?php endif ?>
  </div>
</div>

