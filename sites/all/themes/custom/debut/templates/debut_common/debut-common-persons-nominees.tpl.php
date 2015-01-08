<?php
/**
 * @file
 * Template placeholder.
 */
dpm($_data);
?>
<section class="block block-article block-questions block-lexique persons-list">
  <?php foreach ($_data['prizes'] as $rows) : ?>
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

  <div class="view-more-target"></div>

  <?php if ($_data['show_more']) : ?>
    <span class="text-throbber">
		  <span class="button button-c">
			  <a href="javascript: void(0)" data-ajax-url="<?php print $_data['show_more_url']; ?>" class="persons-view-more-button">
			    <span>
				    <?php print t('Show more'); ?>
				  </span>
		    </a>
		  </span>
    </span>
  <?php endif; ?>
</section>
