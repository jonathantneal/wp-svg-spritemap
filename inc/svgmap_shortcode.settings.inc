<?php

add_action( 'admin_init', 'svgmap_shortcode_init' );
function svgmap_shortcode_init() {
	global $svgmap;
	add_settings_section(
		'svgmap_settings_shortcode',
		__( 'Shortcode Settings', $svgmap->id ),
		'svgmap_settings_shortcode_description',
		$svgmap->id
	);

	add_settings_field(
		'default_attributes',
		__( 'Default Attributes', $svgmap->id ),
		'svgmap_settings_shortcode_attributes',
		$svgmap->id,
		'svgmap_settings_shortcode',
		array( 'label_for' => 'svgmap[default_attributes]' )
	);

	add_settings_field(
		'add_default_classes',
		__( 'Add Default Classes', $svgmap->id ),
		'svgmap_settings_shortcode_classes',
		$svgmap->id,
		'svgmap_settings_shortcode',
		array( 'label_for' => 'svgmap[add_default_classes]' )
	);
}

function svgmap_settings_shortcode_description() { ?>
	<p>SVG Sprites can be embedded in posts and pages using the <code>[svgicon sprite="&hellip;"]</code> shortcode. The <code>sprite</code> attribute is required to tell the shortcode which SVG to include. Additional attributes on the shortcode are passed to the inserted <code>&lt;svg&gt;</code> element, allowing you to set the <code>width</code>, <code>height</code>, <code>fill</code> and other attributes.</p>
<?php
}

function svgmap_settings_shortcode_attributes() {
	global $svgmap; ?>
	<code>&lt;svg </code><input type="text" id='svgmap[default_attributes]' name='svgmap[default_attributes]' placeholder='width="100" height="100" class="icon" fill="#000"...' value="<?php echo esc_attr($svgmap->settings['default_attributes']); ?>" style="width: 25em; max-width: 100%;"/><code>&gt;&lt;use xlink:href="&hellip;" /&gt;&lt;/svg&gt;</code>
	<p class="description">Attributes given to all shortcode SVGs. These may be overridden by shortcode attributes.</p>
	<?php
}

function svgmap_settings_shortcode_classes() {
	global $svgmap; ?>
	<input type='checkbox' id='svgmap[add_default_classes]' name='svgmap[add_default_classes]' value='1' <?php checked( $svgmap->settings['add_default_classes'], 1 ); ?>>
	<p class="description">Automatically add the default classes (<code>.svgmap</code> &amp; <code>.svgmap--<b>spritename</b></code>) to all shortcode SVGs, in addition to any classes added via default attributes or shortcode attributes.</p>
	<?php
}

