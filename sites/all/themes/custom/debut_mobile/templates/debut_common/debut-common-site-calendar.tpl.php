<?php
/**
 * @file
 * Template.
 */
?>
<div class="calendar-placeholder" style="display: none;">
  <div class="block-titled block calendar-block">
    <div class="block-content">
      <div class="calendar-run" data-ajax-name="debut_common_site_calendar" data-ajax-url="<?php print $_data['ajax_url']; ?>"></div>
      <div class="wrapper">
        <div class="debut_common_site_calendar_text debut_site_changes_text"><?php print $_html['links']; ?></div>
      </div>
    </div>
  </div>
</div>
