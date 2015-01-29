<?php
/**
 * @file
 * Form template.
 */
?>
<section class="newsletter-confirmation">
  <h4 class="block-title">
    <span class="top"></span>
    <span class="logo"></span>
    <span class="mid"><?php print t('Subscription confirmation'); ?></span>
    <span class="bottom"></span>
  </h4>
  <div class="form-items">
    <?php print $_html['question']; ?>
    <?php print $_html['description']; ?>
    <div class="line-separator"></div>
    <div class="buttons">
      <div class="button button-e">
        <a class="debut-proxy-click comment-submit" ontouchstart="return true;" data-proxy-target="#simplenews-confirm-add-form .form-submit" href="javascript: void(0)">
          <span ontouchstart="return true;"><?php print t('Confirm'); ?></span>
        </a>
      </div>
    </div>
    <div class="line-separator"></div>
    <div class="buttons">
      <div class="button button-e">
        <a class="comment-submit" ontouchstart="return true;" href="<?php print url(''); ?>">
          <span ontouchstart="return true;"><?php print t('Cancel'); ?></span>
        </a>
      </div>
    </div>
  </div>
  <div class="hidden">
    <?php print $_html['form']; ?>
  </div>
</section>
