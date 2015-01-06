<?php
/**
 * @file
 * Template placeholder.
 */
dpm($_data);
?>
<section class="block block-article block-questions block-lexique">
  <?php foreach ($_data as $rows) : ?>
    <div class="prize-persons">
      <p class="winners-links">
        <?php foreach ($rows['titles'] as $title) : ?>
          <span class="winners"><?php print $title; ?></span>
        <?php endforeach; ?>
      </p>
    <?php foreach ($rows['data'] as $block) : ?>
      <article class=" <?php print $block['class']; ?>">
        <?php print $block['html']; ?>
      </article>
    <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
</section>
