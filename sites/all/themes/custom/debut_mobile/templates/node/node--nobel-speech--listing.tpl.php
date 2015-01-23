<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-nobel-speech listing  <?php print $_data['class']; ?>">
  <h1><?php print $_html['title']; ?></h1>
  <?php if (!empty($_html['author'])) : ?>
    <div class="author-press">
      <?php print $_html['author']; ?>
    </div>
  <?php endif; ?>
  <div class="clear"></div>
  <span class="publish-date"><?php print $_html['press_date']; ?></span>
</article>
