<?php
/**
 * @file
 *
 * Template layout.
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

<div class="content cols-2 panel-2col">

  <aside class="col-a col panel-col-first">
    <?php print $content['content_left'];?>
  </aside>

  <div class="col-b col panel-col">
    <div class="messages-target"></div>
    <?php print $content['content_center'];?>
  </div>

</div>
