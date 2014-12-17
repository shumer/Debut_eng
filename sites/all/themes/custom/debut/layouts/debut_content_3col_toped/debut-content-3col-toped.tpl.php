<?php
/**
 * @file
 * Template (front) for the debut-content-3col-stacked layout.
 */
?>

<?php if (!empty($content['top'])) : ?>
  <div class="underheader">
    <?php print $content['top'];?>
  </div>
<?php endif; ?>

<?php if (!empty($content['content_pre'])) : ?>
  <section class="pre-content">
    <?php print $content['content_pre'];?>
  </section>
<?php endif; ?>

<div class="content cols-3 panel-3col">

  <aside class="col-a col panel-col-first">
    <?php print $content['content_left'];?>
  </aside>

  <div class="col-b col panel-col">
    <div class="messages-target message-container"></div>
    <?php print $content['content_center'];?>
  </div>

  <aside class="col-c col panel-col-last">
    <?php print $content['content_right'];?>
  </aside>

</div>
