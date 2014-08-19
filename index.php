<?php /*
Plugin Name: SVG Spritemap Manager
Plugin URI: http://github.com/jonathantneal/wp-svg-store
Description: Easily create and manage your SVG spritemap in Wordpress
Version: 0.1
Author: Jonathan Neal
Author URI: http://jonathantneal.com
Min WP Version: 2.0
Max WP Version: 3.9
License: Public Domain - https://creativecommons.org/publicdomain/zero/1.0/
*/

defined('ABSPATH') or die('Access denied');

$svgmap = (object) array(
	'ext'  => 'svg',
	'mime' => 'image/svg+xml',
	'path' => dirname(__FILE__),
	'permissions' => 'upload_files',
	'name' => 'SVG Spritemap',
	'id'   => 'svgmap',
);

$svgmap->svg_path = $svgmap->path.'/defs.svg';
$svgmap->ids_path = $svgmap->path.'/defs.json';

$svgmap->svg_url = plugins_url('defs.svg', __FILE__);
$svgmap->ids_url = plugins_url('defs.json', __FILE__);

include 'inc/svgmap_admin_head.inc';
include 'inc/svgmap_admin_menu.inc';
include 'inc/svgmap_media_page.inc';
include 'inc/svgmap_upload_mimes.inc';

add_action('admin_head', 'svgmap_admin_head');
add_action('admin_menu', 'svgmap_admin_menu');

add_filter('upload_mimes', 'svgmap_upload_mimes');
