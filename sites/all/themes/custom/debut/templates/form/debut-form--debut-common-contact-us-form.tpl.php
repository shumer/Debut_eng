<?php
/**
 * @file
 * Form template.
 */
?>
<div class="form-items">
  <?php print $_html['name']; ?>
  <?php print $_html['email']; ?>
  <?php print $_html['message']; ?>
  <?php print $_html['captcha']; ?>
  <div class="form-button">
    <a href="javascript: void(0);" class="form-button-submit debut-proxy-click" data-proxy-target="#debut-common-contact-us-form .form-submit">
  	  <span><?php print t('Send'); ?></span>
    </a>
  </div>
</div>
<div class="hidden">
  <?php print $_html['form']; ?>
</div>
