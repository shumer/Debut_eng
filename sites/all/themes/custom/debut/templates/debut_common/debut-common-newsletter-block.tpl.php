<?php
/**
 * @file
 * Template.
 */
?>
<div class="block block-newsletters">
  <div class="block-content">
    <h4 class="block-title">
      <span class="mid"><?php print $_html['title']; ?></span>
    </h4>
    <div class="form">
      <div class="text">
        <?php print t('Здесь вы можете подписаться на новости:'); ?>
      </div>
      <div class="form-item">
        <label for="edit-contact-form-email"><?php print t('E-mail'); ?> <span class="form-required" title="<?php print t('Это поле обязательно для заполнения.'); ?>">*</span></label>
        <div class="form-text-wrap">
          <div class="form-text-wrap-inner">
            <input id="newsletters" class="form-text email-input" type="text" value="" size="15" name="newsletters" maxlength="128" />
          </div>
        </div>
      </div>
      <div class="form-item">
        <div class="form-button">
          <a class="form-button-submit" href="javascript: void(0);" data-ajax-url="<?php print $_data['url']; ?>">
    	     <span><?php print t('Subscribe'); ?></span>
          </a>
        </div>
      </div>
    </div>
  </div>
  <div class="hidden">
    <div class="newsletter-messages" id="newsletter-messages"></div>
    <div class="messages error">
      <?php print t('Email address is incorrect.'); ?>
    </div>
  </div>
</div>
