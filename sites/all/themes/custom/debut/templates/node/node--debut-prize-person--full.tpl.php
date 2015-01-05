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
      <span class="legende"><?php print $_html['image_legende']; ?></span>
    </div>
    <h1><?php print $_html['title']; ?></h1>
    <?php if (!empty($_html['tags'])) : ?>
      <div class="tags">
        <span class="ico"></span>
        <?php print implode(', ', $_html['tags']); ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if (!empty($_html['biography_short'])) : ?>
  <div class="part part-b biography">
    <h2><?php print t('Biography'); ?></h2>
    <?php print $_html['biography_short']; ?>
    <?php if (!empty($_html['biography'])) : ?>
      <div id="biography_full" class="hidden">
        <?php print $_html['biography']; ?>
      </div>
      <div id="biography_full_button" data-ref-id="biography_full" class="next form-buttons js-expand-button form-submit">
        <?php print t('onward'); ?>
      </div>
    <?php endif; ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($_html['autocomment_short'])) : ?>
  <div class="part part-b autocomment">
    <h2><?php print t('Autocomment'); ?></h2>
    <div class="inner">
      <div class="content">
        <?php print $_html['autocomment_short']; ?>
        <?php if (!empty($_html['autocomment'])) : ?>
          <div id="autocomment_full" class="hidden">
            <?php print $_html['autocomment']; ?>
          </div>
          <div id="autocomment_full_button" data-ref-id="autocomment_full" class="next form-buttons js-expand-button form-submit">
            <?php print t('onward'); ?>
          </div>
          <div class="clear"></div>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!empty($_html['bibliography'])) : ?>
  <div class="part part-c bibliography">
    <h2><?php print t('Bibliography'); ?></h2>
    <?php print $_html['bibliography']; ?>
    <?php foreach ($_data['nobel'] as $nobel) : ?>
      <h3><?php print $nobel['title']; ?></h3>
      <?php print $nobel['short']; ?>
    <?php endforeach; ?>
  </div>
  <?php endif; ?>
  <?php if (!empty($_html['resources'])) : ?>
  <div class="part part-d">
    <h2><?php print t('Help resources'); ?></h2>
    <?php print $_html['resources']; ?>
  </div>
  <?php endif; ?>
  <?php if (!empty($_html['video'])) : ?>
    <div class="separator"></div>
    <section class="video">
      <?php print $_html['video']; ?>
    </section>
  <?php endif; ?>
</div>
