<?php

function svgmap_upload_mimes($mimes) {
	global $svgmap;

	if (!array_key_exists($svgmap->ext, $mimes)) {
		$mimes[$svgmap->ext] = $svgmap->mime;
	}

	return $mimes;
}
