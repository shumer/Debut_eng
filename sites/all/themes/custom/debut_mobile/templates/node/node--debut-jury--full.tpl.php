<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-jury">
  <h1><?php print $_html['title']; ?></h1>

  <!-- photo and tags -->
  <div class="jury-head-wrapper">
    <div class="jury-photo">
      <?php print $_html['image']; ?>
    </div>
    <div class="tags">
      <?php if (count($_html['tags'])): ?>
        <span class="ico"></span>
        <?php print implode(', ', $_html['tags']); ?>
      <?php endif; ?>
    </div>
  </div>
  <div class="clearfix"></div>
  <!-- end photo and tags -->

  <!-- profile block -->
  <h2 class="sub-title"><?php print t('Profile'); ?></h2>
  <div class="profile-short">
    <?php print $_html['field_jury_profile_short'] ; ?>
  </div>
  <?php if (!empty($_html['field_jury_body'])): ?>
    <div class="block-button-more" data-target="profile-long-<?php print $_data['nid']; ?>">
      <span><?php print t('View more'); ?></span>
    </div>
    <div class="profile-long profile-long-<?php print $_data['nid']; ?>" style="display: none">
      <?php print $_html['field_jury_body'] ; ?>
    </div>
  <?php endif; ?>
  <!-- end profile block -->

  <!-- self portrait block -->
  <h2 class="sub-title"><?php print t('(Авто)портрет'); ?></h2>
  <div class="self-portrait-wrapper">
    <div class="self-portrait-short">
      <?php print $_html['field_jury_self_short'] ; ?>
    </div>
    <?php if (!empty($_html['field_jury_self_long'])): ?>
      <div class="self-portrait-long self-portrait-long-<?php print $_data['nid']; ?>" style="display: none">
        <?php print $_html['field_jury_self_long'] ; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if (!empty($_html['field_jury_self_long'])): ?>
    <div class="block-button-more" data-target="self-portrait-long-<?php print $_data['nid']; ?>">
      <span><?php print t('View more'); ?></span>
    </div>
  <?php endif; ?>
  <!-- end self portrait  block -->

  <!-- resources block -->
  <?php if (!empty($_html['field_person_resources'])): ?>
    <h2 class="sub-title"><?php print t('Справочные ресурсы'); ?></h2>
    <div class="help-resources">
      <?php print $_html['field_person_resources'] ; ?>
    </div>
  <?php endif; ?>
  <!-- end resources block -->

  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
