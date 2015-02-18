<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-press listing <?php print $_data['class']; ?>">
  <h1><?php print $_html['title']; ?></h1>
  <div class="press-body">
    <?php print $_html['field_press_text']; ?>
  </div>
  <?php if (!empty($_html['press_link'])) : ?>
    <div class="link-press">
      <?php print $_html['press_link']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($_html['author'])) : ?>
    <div class="author-press">
      <?php print $_html['author']; ?>
    </div>
  <?php endif; ?>
  <span class="publish-date"><?php print $_html['field_publication_date']; ?></span>
</article>
