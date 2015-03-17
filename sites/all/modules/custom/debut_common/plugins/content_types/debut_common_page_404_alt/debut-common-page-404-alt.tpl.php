<?php
/**
 * @file
 * Template page 404 placeholder.
 */
?>

<div class="wrap-404">
	<!---start-header---->
		<div class="header-404">
			<div class="logo">
				<h1><a href="#"><img src="<?php print drupal_get_path('theme', 'debut')?>/html/images/content/header_pokolenie_logo.gif" title="error" /></a></h1>
        <div class="logo-image"></div>
			</div>
		</div>
	<!---End-header---->
	<!--start-content------>
	<div class="content-404">
  <div class="image-404" title="Error loading page"></div>
		<p><?php print $_html['text'];?></p>
		<?php print $_html['home_link'];?>
		<div class="copy-right">
			<p><?php print $_html['footer_text'];?></p>
		</div>
		</div>
</div>