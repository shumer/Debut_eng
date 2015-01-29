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
