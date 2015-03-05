<?php
/**
 * @file
 * Template file.
 */
?>
<div class="block-person">
  <h1><?php print $_html['title']; ?></h1>

  <!-- photo and tags -->
  <div class="person-head-wrapper">
    <div class="person-photo">
      <?php print $_html['image']; ?>
    </div>
    <div class="tags">
      <?php if (!empty($_html['tags'])) : ?>
        <span class="ico"></span>
        <?php print implode(', ', $_html['tags']); ?>
      <?php endif; ?>
    </div>
  </div>
  <div class="clearfix"></div>
  <!-- end photo and tags -->

  <!-- biography block -->
  <?php if (!empty($_html['biography_short'])) : ?>
    <h2 class="sub-title"><?php print t('Biography'); ?></h2>
    <div class="biography-short">
      <?php print $_html['biography_short']; ?>
    </div>
    <?php if (!empty($_html['biography'])) : ?>
      <div class="block-button-more" data-target="biography-long-<?php print $_data['nid']; ?>">
        <span><?php print t('onward'); ?></span>
      </div>
      <div class="biography-long biography-long-<?php print $_data['nid']; ?>" style="display: none">
        <?php print $_html['biography']; ?>
      </div>
    <?php endif; ?>
  <?php endif; ?>
  <!-- end biography block -->

  <!-- autocomment block -->
  <?php if (!empty($_html['autocomment_short'])) : ?>
    <h2 class="sub-title"><?php print t('Autocomment'); ?></h2>
    <div class="inner">
      <div class="content">
        <div class="biography-short">
          <?php print $_html['autocomment_short']; ?>
        </div>
        <?php if (!empty($_html['autocomment'])) : ?>
          <div class="block-button-more" data-target="autocomment-long-<?php print $_data['nid']; ?>">
            <span><?php print t('onward'); ?></span>
          </div>
          <div class="autocomment-long autocomment-long-<?php print $_data['nid']; ?>" style="display: none">
            <?php print $_html['autocomment']; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  <?php endif; ?>
  <!-- end autocomment block -->

  <!-- bibliography block -->
  <?php if (!empty($_html['bibliography'])) : ?>
    <h2 class="sub-title"><?php print t('Bibliography'); ?></h2>
    <?php print $_html['bibliography']; ?>
    <?php foreach ($_data['nobel'] as $nobel) : ?>
      <div class="bibliography-item">
        <h3 class="sub-title"><?php print $nobel['title']; ?></h3>
        <?php print $nobel['short']; ?>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
  <!-- end bibliography block -->

  <!-- resources block -->
  <?php if (!empty($_html['resources'])) : ?>
    <h2 class="sub-title"><?php print t('Help resources'); ?></h2>
    <div class="help-resources">
      <?php print $_html['resources']; ?>
    </div>
  <?php endif; ?>
  <!-- end resources block -->

  <!-- video block -->
  <?php if (!empty($_html['video'])) : ?>
    <h2 class="sub-title"><?php print t('Video'); ?></h2>
    <div class="separator"></div>
    <section class="video">
      <?php print $_html['video']; ?>
    </section>
  <?php endif; ?>
  <!-- end video block -->

  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</div>
