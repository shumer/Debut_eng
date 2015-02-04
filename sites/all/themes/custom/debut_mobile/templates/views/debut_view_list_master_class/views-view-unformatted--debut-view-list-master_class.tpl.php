<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
  <div class="block-share">
    <span><?php print t('Share page'); ?></span>
  </div>
<?php print $_html['social_links']; ?>
