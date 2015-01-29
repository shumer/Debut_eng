<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-master-class listing  <?php print $_data['class']; ?>">
  <h1><?php print $_html['title']; ?></h1>
  <?php if (!empty($_html['texts'])) : ?>
    <div class="master-class-texts">
      <?php print $_html['texts']; ?>
    </div>
  <?php endif; ?>
  <div class="author">
    <?php if (!empty($_html['master'])) : ?>
      <div class="master">
        <h3><?php print t('Conducted a master class'); ?></h3>
        <?php print $_html['master']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($_html['interviews'])) : ?>
      <div class="interview">
        <h3><?php print t('Interviews with participants'); ?></h3>
        <?php print $_html['interviews']; ?>
      </div>
    <?php endif; ?>
  </div>
</article>
