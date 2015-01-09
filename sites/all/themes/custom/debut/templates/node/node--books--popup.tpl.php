<?php
/**
 *
 * @file
 * Template file.
 */
?>
<section class="popup popup-b popup-commenter popup-video">
	<div class="top"></div>
	<div class="mid">
		<h2 class="title">Книги </h2>
    <article class="book">
      <div class="news node-item books-item">
        <?php if (!empty($_html['image'])) : ?>
          <div class="book-image">
            <?php print $_html['image']; ?>
          </div>
        <?php endif; ?>
        <div class="book-content">
          <div class="books-title">
            <?php print $_html['title']; ?>
          </div>
          <?php print $_html['description']; ?>
        </div>
        <?php if (!empty($_html['authors'])): ?>
          <div class="authors">
            <h2><?php print t('Authors'); ?></h2>
            <?php print $_html['authors']; ?>
          </div>
        <?php endif; ?>
        <div class="clear"></div>
        <div class="publication"><?php print $_html['publication']; ?></div>
        <div class="clear"></div>
        <div class="separator"></div>
      </div>
    </article>
  </div>
	<a title="<?php  print t('Закрыть'); ?>" class="close-popup" href="javascript: void(0)"></a>
	</div>
	<div class="bottom"></div>
</section>
