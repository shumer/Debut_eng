<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<footer class="footer">
  <div class="inner">
    <?php print $_html['footer_links'];?>
    <?php if (!empty($_html['first_text_block'])) : ?>
      <div class="level-2">
      	<?php print $_html['first_text_block']; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($_html['second_text_block'])) : ?>
      <div class="level-3">
        <?php print $_html['second_text_block']; ?><br />
        <?php print t('Last updated on : @date', array('@date' => $_html['last_updated_date'])); ?>
      </div>
    <?php endif; ?>
  </div>
</footer>
