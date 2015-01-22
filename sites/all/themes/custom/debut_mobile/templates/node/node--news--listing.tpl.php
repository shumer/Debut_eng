<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<article class="block-news listing <?php print $_data['class']; ?>">
  <h1><?php print $_html['title']; ?></h1>
  <div class="news-body">
    <?php print $_html['text']; ?>
  </div>
  <span class="publish-date"><?php print $_html['news_date']; ?></span>
</article>
