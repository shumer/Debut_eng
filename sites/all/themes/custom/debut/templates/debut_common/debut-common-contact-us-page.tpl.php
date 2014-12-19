<?php
/**
 *
 * @file
 *   Template file.
 */
?>
<div class="debut-popup">
  <section class="popup">
    <div class="inside">
      <a href="javascript: void(0)" class="close"><?php print t('Close'); ?></a>
      <header>
        <h3><?php print t('write a message: '); ?><span class="topic"><?php print $_html['product_title']; ?></span></h3>
      </header>
      <div class="content">
        <?php print $_html['messages']; ?>
        <div class="form-wrap hide-form-actions">
          <?php print $_html['form']; ?>
          <div class="line-separator"></div>
          <div class="buttons">
            <div class="button button-e">
              <a class="debut-proxy-click comment-submit" data-proxy-target="#debut-common-contact-us-form .form-submit" href="javascript: void(0)">
                <span><?php print t('Submit'); ?></span>
              </a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
</div>
