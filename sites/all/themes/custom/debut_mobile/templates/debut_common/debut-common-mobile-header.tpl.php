<?php
/**
 * @file
 * Template.
 */
?>
<!-- Main menu -->
<?php if (!empty($_html['main_menu'])) : ?>
  <div data-role="panel" data-display="push" class="main-menu" id="main-menu">
    <div class="ui-panel-inner">
      <?php print $_html['main_menu']; ?>
    </div>
  </div>
<?php endif; ?>
<!-- End of Main menu -->
<header id="header" data-role="header"  class="header ui-panel-animate">
  <!-- Main menu button -->
  <div class="header-inner">
    <?php if (!empty($_html['main_menu'])) : ?>
      <a class="panel-trigger" href="#main-menu">
        <span></span>
        <span></span>
        <span></span>
      </a>
    <?php endif; ?>
    <!-- End of Main menu button -->
    <div class="button-wrapper">
      <div class="vertical-divider"></div>
      <div class="header-search-button"></div>
      <div class="vertical-divider"></div>
      <div class="header-calendar-button"></div>
    </div>
    <!-- Messages -->
    <?php print $_html['messages']; ?>
  </div>
  <!-- Placeholders -->
  <div class="header-placeholders-block">
    <!-- Placeholder for calendar block -->
    <div class="calendar-block-target" style="display: none;"></div>
    <!-- Search bar block -->
    <div class="search-block-target" style="display: none;">
      <div class="search-bar">
        <div class="form-item form-type-textfield form-item-keys">
          <div class="form-text-wrap">
            <div class="form-text-wrap-inner">
              <input type="text" name="keys" value="" size="60" maxlength="128" class="form-text search-form-text" />
            </div>
          </div>
        </div>
        <input type="submit" id="edit-submit--2" name="op" value="Ok" class="form-submit search-form-submit" />
      </div>
    </div>
  </div>
  <!-- Header banner -->
  <section class="banner">
    <?php print $_html['banner']; ?>
  </section>
</header>

