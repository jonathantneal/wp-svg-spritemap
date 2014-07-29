<?php

function svgmap_admin_menu() {
	global $svgmap;

	add_media_page($svgmap->name, $svgmap->name, $svgmap->permissions, $svgmap->id, 'svgmap_media_page');
}
