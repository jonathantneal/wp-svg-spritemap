# SVG Spritemap

**SVG Spritemap** is a [WordPress](//wordpress.org) plugin that lets you add SVGs with the Media Uploader, as well as create and manage an SVG spritemap from your Media Library.

![Screenshot](http://i.imgur.com/hx84168.png)

1. Install and activate the WordPress plugin.
2. Add SVG images through the Media Uploader.
3. Select the SVGs for the spritemap in **Settings** > **Media** > **SVG Spritemap**.

After selecting and updating the SVGs for your spritemap, a combined `defs.svg` SVG spritemap is automatically generated.

## Using Icons

A text field displays the URL to the SVG spritemap. Individuals sprites may be referenced by appending `#:` and the name of the sprite to the URL.

```html
<svg><use xlink:href="http://dev.wordpress/wp-content/plugins/svg-spritemap/defs.svg#:accounts"></svg>
```

## Shortcode

Simplify including icons within Wordpress by using the `[svgmap]` shortcode in the editors. Set the required `sprite` attribute and an `<svg>` tag will be inserted in your page/post with the desired SVG image. All other shortcode parameters will be added to the inserted `<svg>` as attributes, allowing you to set `class`, `fill`, `width`, `height` and more.

**Shortcode**
```html
[svgmap sprite="accounts" width="100" height="100" fill="#F00" class="icon"]
```

**Output:**
```html
<svg width="100" height="100" fill="#F00" class="icon"><use xlink:href="http://dev.wordpress/wp-content/plugins/svg-spritemap/defs.svg#:accounts"></svg>
```

*Note: To change the `fill` or `stroke` of your SVG, do not include those attributes in the uploaded SVG. The included SVG's attributes override anything set on the `<use>` or `<svg>`.*

## Filesize

The live, estimated filesize of the spritemap represents the combined filesize of all the individual SVGs, but it does not factor in additional gzip compression. More than likely, the estimation will be conservative and the filesize will actually be smaller than the estimation.

## Browser Support

Internet Explorer requires special assistance to display external SVGs. To resolve this issue, I have developed [SVG4Everybody](https://github.com/jonathantneal/svg4everybody).
