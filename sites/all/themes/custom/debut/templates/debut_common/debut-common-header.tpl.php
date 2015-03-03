<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="header">
  <div class="language">
    <?php print $_html['language_links']; ?>
  </div>
	<div class="logo-container">
		<div class="pic">
		  <?php print $_html['logo_image']; ?>
		</div>
	</div>
  <div class="search-bar">
    <div class="form-item form-type-textfield form-item-keys">
      <div class="form-text-wrap">
        <div class="form-text-wrap-inner">
          <input type="text" name="keys" value="<?php print $_html['input_value']; ?>" size="60" maxlength="128" class="form-text search-form-text"/>
        </div>
      </div>
    </div>
    <input type="submit" id="edit-submit--2" name="op" value="Ok" class="form-submit search-form-submit" />
  </div>
	<div class="pokolenie-logo-container">
		<div class="pic">
		  <?php print $_html['pokolenie_logo_image']; ?>
		</div>
	</div>
</div>
