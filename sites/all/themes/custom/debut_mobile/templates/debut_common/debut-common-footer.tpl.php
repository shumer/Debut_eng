<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<?php print $_html['footer_links'];?>
<div class="contact">
  <?php print $_html['contact_us'];?>
</div>
<?php if (!empty($_html['first_text_block'])) : ?>
  <div class="level-2">
  	<?php print $_html['first_text_block']; ?>
  </div>
<?php endif; ?>
<?php if (!empty($_html['second_text_block'])) : ?>
  <div class="level-3 copyright">
    <?php print $_html['second_text_block']; ?><br />
    <?php print t('Last updated on : @date', array('@date' => $_html['last_updated_date'])); ?>
  </div>
<?php endif; ?>

