<?php
/**
 * @file
 *
 * Template (admin) for the debut-content-2col-stacked layout.
 */
?>
<div class="outer-page-wrapper">
  <table border="1px">
    <tr>
      <td colspan="3"><?php
        if (isset($content['top'])) {
          print $content['top'];
        }
      ?></td>
    </tr>
    <tr>
      <td colspan="3"><?php
        if (isset($content['content_pre'])) {
          print $content['content_pre'];
        }
      ?></td>
    </tr>
    <tr>
      <td width="25%"><?php
        if (isset($content['content_left'])) {
          print $content['content_left'];
        }
      ?></td>
      <td><?php
        if (isset($content['content_center'])) {
          print $content['content_center'];
        }
      ?></td>
    </tr>
  </table>
</div>
