<div class="wrap">
	<h2><?php print $svgmap->name; ?></h2>

	<ul class="subsubsub">
		<li><span class="svg-count-label">All</span> <span class="svg-count all">(<?php print($wp_query_posts_count); ?>)</span> |</li>
		<li><span class="svg-count-label">In Use</span> <span class="svg-count inuse">(<?php print($id_array_length); ?>)</span></li>
	</ul>

	<br class="clear">

	<form class="svg-list" method="post">
		<?php
		foreach ($wp_query_posts as $post) {
			$checked = in_array($post->ID, $id_array) ? ' checked' : '';
		?>
		<label class="svg-listitem">
			<input class="svg-checkbox" type="checkbox" name="<?php print $post->ID; ?>" value="<?php print $post->post_name; ?>"<?php print $checked; ?> data-size="<?php print $post->size; ?>">
			<span class="svg-details">
				<img class="svg-image" src="<?php print $post->guid; ?>">
				<span class="svg-name"><?php print $post->post_name; ?></span>
			</span>
		</label>
		<?php } ?>

		<div class="svg-panel">
			<p class="svg-panelitem">
				Spritemap URL: <input class="svg-url" value="<?php print $svgmap->svg_url; ?>" type="text">
			</p>

			<hr>

			<p class="svg-panelitem">
				<span>Estimated filesize: <strong class="svg-filesize">Unknown</strong></span>

        <?php wp_nonce_field('svgmap_submit'); ?>
				<button class="svg-submit button button-primary" type="submit">Update <?php print $svgmap->name; ?></button>
			</p>
		</div>
	</form>
</div>

<style><?php include $svgmap->path.'/style.css'; ?></style>
<script><?php include $svgmap->path.'/script.js'; ?></script>
