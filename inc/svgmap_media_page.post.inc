<?php

if ( wp_verify_nonce($_REQUEST['_wpnonce'], 'svgmap_submit') ) {

	$svg_string = '<svg xmlns="http://www.w3.org/2000/svg">' . PHP_EOL;
	$id_array = array();

	foreach ($_POST as $id => $name) {
		if ( is_numeric($id) ) {
			$url = wp_get_attachment_image_src($id);

			if ( $url ) {
				$path = str_replace($wp_upload_dir['baseurl'], $wp_upload_dir['basedir'], $url[0]);

				$svg = simplexml_load_file($path);

				if ( $svg ) {
					array_push($id_array, $id);

          $viewbox = $svg->attributes()->viewBox;

					$svg_string .= '<symbol id=":'.$name.'" viewBox="' . $viewbox . '">';

					foreach ($svg->children() as $child) {
						$svg_string .= preg_replace('/(\t|\n)+/',' ',$child->asXML());
					}

					$svg_string .= '</symbol>' . PHP_EOL;
				}
			}
		}
	}

	$svg_string .= '</svg>';

	file_put_contents($svgmap->svg_path, $svg_string);
	file_put_contents($svgmap->ids_path, json_encode($id_array));

}