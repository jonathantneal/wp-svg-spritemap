<?php

$svg_string = '<svg xmlns="http://www.w3.org/2000/svg">';
$id_array = array();

foreach ($_POST as $id => $name) {
	array_push($id_array, $id);

	$url = wp_get_attachment_image_src($id);

	$path = str_replace($wp_upload_dir['baseurl'], $wp_upload_dir['basedir'], $url[0]);

	$svg = simplexml_load_file($path);

	$viewbox = $svg->attributes()->viewBox;

	$svg_string .= '<symbol viewBox="'.$viewbox.'" id=":'.$name.'">';

	foreach ($svg->children() as $child) {
		$svg_string .= $child->asXML();
	}

	$svg_string .= '</symbol>';
}

$svg_string .= '</svg>';

file_put_contents($svgmap->svg_path, $svg_string);
file_put_contents($svgmap->ids_path, json_encode($id_array));
