<?php

add_shortcode( 'svgmap', 'svgmap_shortcode' );
function svgmap_shortcode($args) {

	global $svgmap;

	$sprite = $args['sprite'];
	unset($args['sprite']);

	if ( $sprite ) {
		$attr = "";

		foreach($args as $key => $value) {
			$attr .= ' ' . $key . '="' . esc_attr($value) . '"';
		}

		return '<svg' . $attr .'><use xlink:href="' . esc_url($svgmap->svg_url . '#:'. $sprite) . '"></svg>';
	} else {
		return false;
	}
}