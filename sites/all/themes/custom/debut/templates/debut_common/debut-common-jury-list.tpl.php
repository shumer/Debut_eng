<?php
/**
 * @file
 * Template placeholder.
 */
?>
<div class="block-persons-list jury-list block-persons">
  <?php print $_html['jury_list_teaser'];?>
  <?php if (isset($_html['jury_list_listing'])) : ?>
    <div class="block-jury-list-listing compact-listing">
      <?php print $_html['jury_list_listing'];?>  
    </div>
  <?php endif; ?>
</div>
