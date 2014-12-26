<?php
/**
 * @file
 * Template.
 */
?>
<?php if (!empty($_html['main_menu'])) : ?>
  <div data-role="panel" data-display="push" class="main-menu" id="main-menu">
    <div class="ui-panel-inner">
      <?php print $_html['main_menu']; ?>
    </div>
  </div>
<?php endif; ?>
<header id="header" data-role="header"  class="header ui-panel-animate">
  <div class="header-inner">
    <?php if (!empty($_html['main_menu'])) : ?>
      <a class="panel-trigger" href="#main-menu">
        <span></span>
        <span></span>
        <span></span>
      </a>
    <?php endif; ?>
    <?php print $_html['messages']; ?>
  </div>
  <div class="header-placeholders-block">
    <div class="calendar-block-target" style="display: none;"></div>
  </div>
  <section class="banner">
    <?php print $_html['banner']; ?>
  </section>
</header>

