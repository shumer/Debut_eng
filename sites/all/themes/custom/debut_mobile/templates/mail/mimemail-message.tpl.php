<?php
/**
 * @file
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xmlns:v="urn:schemas-microsoft-com:vml" style="font-size: 100%;">
  <head>
  	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  	<title><?php print $_html['mail_title']; ?></title>
  	<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  	<style>
  		@media only screen and (max-width: 767px){

  			body{
  		    font-size: 0.875em !important; /*14px*/
  		  }

  			*[class="show"]{
  				max-height: inherit !important;
  				display: block !important;
  				overflow: visible !important;
  			}

  			*[class="hide"]{
  				display: none !important;
  				mso-hide: all;
  			}
  		}
  	</style>
  </head>
<body bg-color="#ffffff" style="padding: 0; margin: 0; background-color: #ffffff; font-size: 1em; line-height: 1.5; -webkit-text-size-adjust:none; -ms-text-size-adjust: 100%;">
	<table cellpadding="0" cellspacing="0" align="center" style="margin: 0 auto; width: 100%; max-width: 980px; color: #666666; font-family: Arial, sans-serif;">
		<tbody>
			<tr>
				<!-- header -->
				<td class="header" height="60" colspan="3" style="background-color: #fb7700; text-align: center;">
					<a href="<?php print $_data['url']['site_link']; ?>" target="_blank"><img border="0" style="width: 89px; height: 35px;" src="http://i.imgur.com/R8gXgjo.png" alt="<?php print t('Pokolenie Debut'); ?>" width="89" height="35" /></a>
				</td>
			</tr>
			<tr>
				<!-- main content -->
				<td width="25"></td>
				<td style="text-align: center; color: #999999; max-width: 640px;">
					<div class="center" style="max-width: 640px; margin: 0 auto 1em;">
            <?php print $_html['body']; ?>
					</div>
				</td>
				<td width="25"></td>
			</tr>
			<tr>
				<td colspan="3">
					<!-- footer -->
						<!-- mobile footer -->
					<!--[if !mso]><!-->
					<div class="show" style="display: none; max-height: 0; overflow: hidden;">
						<table cellpadding="0" cellspacing="0" bg-color="#363739" style=" width: 100%; background-color: #363739; text-align: center; text-transform: uppercase;">
							<tbody>
								<tr>
									<td>
										<table cellpadding="0" cellspacing="0" style="margin: 0 auto;">
											<tbody>
												<tr><td colspan="9" height="16"></td></tr>
												<tr>
                          <?php foreach ($_data['social_links'] as $social_link): ?>
                            <td><?php print $social_link; ?></td>
                            <td width="9"></td>
                          <?php endforeach; ?>
												<tr><td colspan="9" height="16"></td></tr>
											</tbody>
										</table>
									</td>
								</tr>
                  <?php $counter = 1; ?>
                  <?php $items_count = count($_data['footer_mobile_menu_links']); ?>
                  <?php foreach ($_data['footer_mobile_menu_links'] as $footer_menu_link): ?>
                    <tr>
                    <?php if ($counter != $items_count): ?>
										  <td colspan="9" style="border-top: 1px solid #505153; border-bottom: 1px solid #505153;">
										    <?php print $footer_menu_link; ?>
                      </td>
                    <?php else: ?>
										  <td colspan="9">
										    <?php print $footer_menu_link; ?>
                      </td>
                    <?php endif; ?>
                    <?php $counter++; ?>
                    </tr>
                  <?php endforeach; ?>
							</tbody>
						</table>
					</div>
					<!--<![endif]-->
						<!-- tablet footer -->
					<div class="hide">
						<table cellpadding="0" cellspacing="0" height="45" bg-color="#fb7700" style="width: 100%; background-color: #fb7700;">
							<tbody>
								<tr height="8"><td colspan="4"></td></tr>
								<tr height="28">
									<td width="25"></td>
									<td>
										<!-- social button -->
										<table cellpadding="0" cellspacing="0" style="text-align: center; color: #fff; font-size: 0.75em;">
											<tbody>
												<tr>
                          <td><?php print $_html['footer_text']; ?></td>
												</tr>
											</tbody>
										</table>
									</td>
									<td width="25"></td>
								</tr>
								<tr height="9"><td colspan="4"></td></tr>
							</tbody>
						</table>
					</div>
				</td>
			</tr>
		</tbody>
	</table>
</body>
</html>
