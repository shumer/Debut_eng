<?php
/**
 * @file
 * Template placeholder.
 */

?>
  <?php foreach ($_data['prizes'] as $rows) : ?>
    <div class="prize-persons">
      <p class="winners-links">
        <?php foreach ($rows['captions'] as $caption) : ?>
          <span class="winners <?php print $caption['class']; ?>"
            <?php if (!empty($caption['ref-id'])) : ?>
                data-ref-id="<?php print $caption['ref-id']; ?>">
            <?php else :?>
                onclick="debut_custom.hide_all_prizes($(this));">
            <?php endif; ?>
            <?php print $caption['title']; ?></span>
        <?php endforeach; ?>
      </p>
    <?php foreach ($rows['data'] as $block) : ?>
      <article class="<?php print $block['class']; ?>" id="<?php print $block['id']; ?>">
          <?php if (!empty($block['title'])) : ?>
            <h3><?php print $block['title']; ?></h3>
          <?php endif; ?>
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
