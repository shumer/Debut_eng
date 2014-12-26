<?php
/**
 * @file
 * Template file.
 */
?>
<div data-role="page" class="page">
  <?php if (!empty($content['header'])): ?>
    <?php print $content['header']; ?>
  <?php endif; ?>
  <div role="main" class="ui-content">
   <div class="block center-block">
    <?php if (!empty($content['content'])): ?>
      <?php print $content['content']; ?>
    <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($content['footer'])): ?>
    <footer class="footer ui-footer ui-bar-inherit" data-role="footer" role="contentinfo">
      <div class="footer-inner">
        <?php print $content['footer']; ?>
      </div>
    </footer>
  <?php endif; ?>
</div>
