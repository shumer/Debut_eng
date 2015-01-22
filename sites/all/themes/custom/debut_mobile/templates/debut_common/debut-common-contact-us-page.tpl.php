<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="block debut-contact-form">
  <div class="form-header">
    <h3><?php print t('Write a message to Debut site administration.'); ?></h3>
    <p><?php print t('If you have some questions, or whish to say your opinion please use form below.'); ?></p>
  </div>
  <div class="form-body">
    <?php print $_html['messages']; ?>
    <?php print $_html['form']; ?>
    <div class="line-separator"></div>
    <div class="buttons">
      <div class="button button-e">
        <a class="debut-proxy-click comment-submit" ontouchstart="return true;" data-proxy-target="#debut-common-contact-us-form .form-submit" href="javascript: void(0)">
          <span ontouchstart="return true;"><?php print t('Submit'); ?></span>
        </a>
      </div>
    </div>
  </div>
</div>
