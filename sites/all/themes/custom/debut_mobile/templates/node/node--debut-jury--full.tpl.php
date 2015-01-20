<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-jury">
  <h1><?php print $_html['title']; ?></h1>
  <figure>
    <?php print $_html['image']; ?>
  </figure>
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
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
