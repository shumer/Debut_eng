<?php
/**
 * @file
 * Template file.
 */
?>
<div class="page">
  <?php if (!empty($content['header'])): ?>
    <header class="header">
      <?php print $content['header']; ?>
    </header>
  <?php endif; ?>
  <div class="content">
    <?php if (!empty($content['content'])): ?>
      <?php print $content['content']; ?>
    <?php endif; ?>
  </div>
  <?php if (!empty($content['footer'])): ?>
    <?php print $content['footer']; ?>
  <?php endif; ?>
</div>
