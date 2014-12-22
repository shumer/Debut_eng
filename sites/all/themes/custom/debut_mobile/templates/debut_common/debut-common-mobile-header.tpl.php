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
    <div class="logo">
      <a href="<?php print $_html['logo_link']; ?>" data-ajax="false">
      </a>
    </div>

    <?php print $_html['messages']; ?>
  </div>

</header>
