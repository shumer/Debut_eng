<?php
/**
 * @file
 * Template file.
 */
?>
<div class="person node-item person-item">
  <div class="part part-a">
    <div class="pic">
      <div class="pic-inner">
        <?php print $_html['image']; ?>
      </div>
    </div>
    <h1><?php print $_html['title']; ?></h1>
    <?php if (!empty($_html['tags'])) : ?>
      <div class="tags">
        <span class="ico"></span>
        <?php print implode(', ', $_html['tags']); ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if (!empty($_html['profile_short'])) : ?>
  <div class="part part-b biography">
    <h2><?php print t('Profile'); ?></h2>
    <?php print $_html['profile_short']; ?>
    <?php if (!empty($_html['profile'])) : ?>
      <div id="biography_full" class="hidden">
        <?php print $_html['profile']; ?>
      </div>
      <div id="biography_full_button" data-ref-id="biography_full" class="next form-buttons js-expand-button form-submit">
        <?php print t('onward'); ?>
      </div>
    <?php endif; ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($_html['jury_self_short'])) : ?>
  <div class="part part-b autocomment">
    <h2><?php print t('Self-portreit'); ?></h2>
    <div class="inner">
      <div class="content">
        <?php print $_html['jury_self_short']; ?>
        <?php if (!empty($_html['jury_self'])) : ?>
          <div id="jury_self_full" class="hidden">
            <?php print $_html['jury_self']; ?>
          </div>
          <div id="jury_self_full_button" data-ref-id="jury_self_full" class="next form-buttons js-expand-button form-submit">
            <?php print t('onward'); ?>
          </div>
          <div class="clear"></div>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <?php endif; ?>

  <?php if (!empty($_html['resources'])) : ?>
  <div class="part part-d">
    <h2><?php print t('Help resources'); ?></h2>
    <?php print $_html['resources']; ?>
  </div>
  <?php endif; ?>
  <div class="clear"></div>
</div>
