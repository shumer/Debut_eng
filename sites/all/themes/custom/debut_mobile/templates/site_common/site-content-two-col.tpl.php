<?php
/**
 * @file
 * Template file.
 */
?>
<div class="col-xs-2 sidebar">
  <?php if (!empty($content['left'])): ?>
    <?php print $content['left']; ?>
  <?php endif; ?>
</div>
<div class="col-xs-10 col-xs-offset-2 main">
  <?php if (!empty($content['content'])): ?>
    <?php print $content['content']; ?>
  <?php endif; ?>
</div>
