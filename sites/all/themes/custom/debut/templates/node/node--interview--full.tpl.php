<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="documents node-item documents-item-full interview-item-full">
  <div class="documents-title">
      <?php print $_html['title']; ?>
  </div>
  <?php if (!empty($_html['author'])) : ?>
    <figure class="interview-photo">
      <?php print $_html['author']; ?>
    </figure>
  <?php endif; ?>
  <div class="documents-body">
    <?php print $_html['body']; ?>
  </div>
</div>