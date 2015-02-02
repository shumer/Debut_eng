<?php
/**
 * @file
 * Form template.
 */
?>
<div class="form-item send-manuscript form-wrapper">
  <?php print $_html['messages']; ?>
  <div class="form-items">
    <?php print $_html['name']; ?>
    <?php print $_html['email']; ?>
    <?php print $_html['message']; ?>
    <?php print $_html['file_upload']; ?>
    <div class="line-separator"></div>
    <div class="buttons">
      <div class="button button-e">
        <a href="javascript: void(0);" class="form-button-submit debut-proxy-click" data-proxy-target="#debut-common-send-manuscript-form .form-submit">
      	  <span><?php print t('Send'); ?></span>
        </a>
      </div>
    </div>
  </div>
  <div class="hidden">
    <?php print $_html['form']; ?>
  </div>
</div>
