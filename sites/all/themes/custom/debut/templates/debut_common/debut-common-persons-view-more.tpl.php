<?php
/**
 * @file
 * Template placeholder.
 */

?>
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
