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
				<!-- header -->
				<td class="header" height="60" colspan="3" style="background-color: #fb7700; text-align: center;">
          <a href="<?php print $_data['url']['site_link']; ?>" target="_blank"><img border="0" style="width: 89px; height: 35px;" src="../../html/images/debut.png" alt="<?php print t('Pokolenie Debut'); ?>" width="89" height="35" /></a>
				</td>
			</tr>
			<tr>
				<!-- header -->
				<td class="header" height="60" colspan="3" style="background-color: #fb7700; text-align: center;">
          <a href="<?php print $_data['url']['site_link']; ?>" target="_blank"><img border="0" style="width: 89px; height: 35px;" src="data:image/png;base64,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" alt="<?php print t('Pokolenie Debut'); ?>" width="89" height="35" /></a>
				</td>
			</tr>
			<tr>
				<!-- header -->
				<td class="header" height="60" colspan="3" style="background-color: #fb7700; text-align: center;">
          <a href="<?php print $_data['url']['site_link']; ?>" target="_blank"><img border="0" style="width: 89px; height: 35px;" src="http://debut.kei/sites/all/themes/custom/debut_mobile/html/images/debut.png" alt="<?php print t('Pokolenie Debut'); ?>" width="89" height="35" /></a>
				</td>
			</tr>
			<tr>
				<!-- header -->
				<td class="header" height="60" colspan="3" style="background-color: #fb7700; text-align: center;">
          <a href="<?php print $_data['url']['site_link']; ?>" target="_blank"><img border="0" style="width: 89px; height: 35px;" src="sites/all/themes/custom/debut_mobile/html/images/debut.png" alt="<?php print t('Pokolenie Debut'); ?>" width="89" height="35" /></a>
				</td>
			</tr>

			<tr>
				<!-- main content -->
				<td width="25"></td>
				<td style="text-align: center; color: #000; max-width: 640px;">
					<div class="center" style="max-width: 640px; margin: 0 auto 1em;">
            <?php print $_html['body']; ?>
					</div>
				</td>
				<td width="25"></td>
			</tr>
			<tr>
				<td colspan="3">
					<!-- footer -->
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
