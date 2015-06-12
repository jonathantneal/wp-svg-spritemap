=== SVG Spritemap ===
Contributors: jonathantneal
Donate link: http://jonathantneal.com/
Tags: images, map, media, sprite, spritemap, svg
Requires at least: 3.0.1
Tested up to: 4.1
Stable tag: "trunk"
License: GPLv2 or later
License URI: http://www.gnu.org/licenses/gpl-2.0.html

SVG Spritemap lets you add SVGs with the Media Uploader, as well as create and manage an SVG spritemap from your Media Library.

== Description ==

**SVG Spritemap** lets you add SVGs with the Media Uploader, as well as create and manage an SVG spritemap from your Media Library.

== Installation ==

1. Install and activate the WordPress plugin.
2. Add SVG images through the Media Uploader.
3. Select the SVGs for the spritemap in **Settings** > **Media** > **SVG Spritemap**.

== Frequently Asked Questions ==

= How do I use the SVG Spritemap? =

After selecting and updating the SVGs for your spritemap, a `defs.svg` SVG spritemap is automatically generated.

A text field displays the URL to the SVG spritemap. Individuals sprites may be referenced by appending `#:` and the name of the sprite to the URL.

	<svg><use xlink:href="http://dev.wordpress/wp-content/plugins/svg-spritemap/defs.svg#:accounts"></svg>

Simplify including icons within Wordpress by using the `[svgmap]` shortcode in the editors. Set the required `sprite` attribute and an `<svg>` tag will be inserted in your page/post with the desired SVG image. All other shortcode parameters will be added to the inserted `<svg>` as attributes, allowing you to set `class`, `fill`, `width`, `height` and more.

  [svgmap sprite="accounts" width="100" height="100" fill="#F00" class="icon"]

= How accurate is the estimated filesize? =

The live, estimated filesize of the spritemap represents the combined filesize of all the individual SVGs, but it does not factor in additional gzip compression. More than likely, the estimation will be conservative and the filesize will actually be smaller than the estimation.

= Why do I not see SVGs in Internet Explorer? =

Internet Explorer requires special assistance to display external SVGs. To resolve this issue, I have developed [SVG4Everybody](https://github.com/jonathantneal/svg4everybody).

== Screenshots ==

1. The SVG spritemap manager.

== Changelog ==

= 0.4 =
* Uses sanitized post_title instead of post_name for sprite references to allow for easy editing
= 0.3 =
* Added shortcode settings
= 0.2 =
* Added [svgmap] shortcode
= 0.1 =
* Initial release.

== Upgrade Notice ==

The first version was not compatible with its pre-existent self, but this subject is best left to philosophers.

== Contributing ==

The Git repository for the project may be accessed here: [https://github.com/jonathantneal/wp-svg-spritemap/](https://github.com/jonathantneal/wp-svg-spritemap/)
