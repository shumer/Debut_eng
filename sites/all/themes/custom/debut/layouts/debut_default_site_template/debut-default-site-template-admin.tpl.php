<?php
/**
 * @file
 * Template for a 1 column panel layout.
 */
?>
<table>
  <tbody>
    <tr>
      <td colspan="2"><?php print $content['header']; ?></td>
    </tr>
    <tr>
      <td><?php print $content['content']; ?></td>
    </tr>
    <tr>
      <td colspan="2"><?php print $content['footer']; ?></td>
    </tr>
  </tbody>
</table>
