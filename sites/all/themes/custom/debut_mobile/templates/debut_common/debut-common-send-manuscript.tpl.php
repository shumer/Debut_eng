<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="panel-send-manuscript">
  <div class="label">
    <h3><?php print t('Для отправки рукописи воспользуйтесь формой:'); ?></h3>
  </div>
  <div class="transparent manuscript-form-wrap ">
    <span class="champs">
      <?php print t('Required fields'); ?>
      <span class="required form-required">*</span>
    </span>
    <?php print $_html['form']; ?>
  </div>
</div>
