<?php

global $default_attributes;

$default_attributes = array();

if ( !empty($svgmap->settings['default_attributes']) ) {
	$def = new SimpleXMLElement('<svg ' . $svgmap->settings['default_attributes'] . ' />');

	foreach ( $def->attributes() as $key => $value ) {
		$default_attributes[(string) $key] = (string) $value;
	}
}

add_shortcode( $svgmap->id, 'svgmap_shortcode' );
function svgmap_shortcode($args) {

	global $svgmap;
	global $default_attributes;

	$sprite = $args['sprite'];

	if ( $sprite ) {
		$attr = "";

		$attributes = array_merge($default_attributes, $args);
		unset($attributes['sprite']);

		if ( $svgmap->settings['add_default_classes'] ) {
			$attributes['class'] = trim($attributes['class'] . ' svgmap svgmap--' . $sprite);
		}

		foreach($attributes as $key => $value) {
			$attr .= ' ' . $key . '="' . esc_attr($value) . '"';
		}

		return '<svg' . $attr . '><use xlink:href="' . esc_url($svgmap->svg_url . '#:'. $sprite) . '"></svg>';
	} else {
		return false;
	}
}

include 'svgmap_shortcode.settings.inc';