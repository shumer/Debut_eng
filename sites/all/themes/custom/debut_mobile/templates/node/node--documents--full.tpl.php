<?php
/**
 *
 * @file
 * Template file.
 */
?>
<article class="block-document">
  <h1><?php print $_html['title']; ?></h1>
  <h2 class="sub-title"><?php print $_html['field_publication_date']; ?></h2>
  <div class="document-body">
    <?php print $_html['field_document_body']; ?>
  </div>
  <div class="block-share">
    <span><?php print t('Share article'); ?></span>
  </div>
  <?php print $_html['social_links']; ?>
</article>
<div class="clear-bottom"></div>
