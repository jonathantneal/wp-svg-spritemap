<?php

function svgmap_media_page() {
	global $svgmap;

	$wp_upload_dir = wp_upload_dir();

	if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		include 'svgmap_media_page.post.inc';
	}

	$id_array = file_exists($svgmap->ids_path) ? json_decode(file_get_contents($svgmap->ids_path)) : array();

	$id_array_length = count($id_array);

	$wp_query_args = array(
		'orderby' => 'none',
		'post_mime_type' => 'image/svg+xml',
		'post_status' => 'inherit',
		'post_type' => 'attachment',
		'posts_per_page' => -1,
	);

	$wp_query = new WP_Query($wp_query_args);

	$wp_query_posts = array_map(function ($post) use ($wp_upload_dir) {
		$post->path = str_replace($wp_upload_dir['baseurl'], '', $post->guid);
		$post->full_path = str_replace($wp_upload_dir['baseurl'], $wp_upload_dir['basedir'], $post->guid);
		$post->size = filesize($post->full_path);

		return $post;
	}, $wp_query->posts);

	$wp_query_posts_count = count($wp_query_posts);

	include 'svgmap_media_page.show.inc';
}
