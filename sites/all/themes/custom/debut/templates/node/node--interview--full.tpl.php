<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="documents node-item documents-item-full interview-item-full">
  <div class="documents-title">
      <?php print $node->title; ?>
  </div>
  <?php if (!empty($node->_html['image'])) : ?>
    <figure class="interview-photo">
      <?php print $node->_html['image']; ?>
    </figure>
  <?php endif; ?>
  <div class="documents-body">
    <?php print $node->body; ?>
  </div>
</div>