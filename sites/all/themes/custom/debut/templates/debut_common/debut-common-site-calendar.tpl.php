<?php
/**
 * @file
 * Template.
 */
?>
<div class="block-titled block calendar-block">
  <div class="block-content">
    <h4 class="block-title">
      <span class="top"></span>
      <span class="logo"></span>
      <span class="mid"><?php print $_html['title']; ?></span>
      <span class="bottom"></span>
    </h4>
    <div class="calendar-run" data-ajax-name="debut_common_site_calendar" data-ajax-url="<?php print $_data['ajax_url']; ?>"></div>
    <div class="debut_common_site_calendar_text debut_site_changes_text"><?php print $_html['links']; ?></div>
  </div>
</div>
