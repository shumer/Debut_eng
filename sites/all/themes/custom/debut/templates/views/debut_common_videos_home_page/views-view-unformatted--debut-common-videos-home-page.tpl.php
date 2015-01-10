<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php $count = 1; ?>
<ul class="video-list">
<?php foreach ($rows as $id => $row): ?>
  <li <?php if ($count%3 == 0) { print ' class="last"';  } ?>>
    <?php print $row; ?>
  </li>
  <?php $count++; ?>
<?php endforeach; ?>
</ul>
