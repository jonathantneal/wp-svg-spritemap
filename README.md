# SVG Spritemap

**SVG Spritemap** is a [WordPress](//wordpress.org) plugin that lets you add SVGs with the Media Uploader, as well as create and manage an SVG spritemap from your Media Library.

![Screenshot](http://i.imgur.com/hx84168.png)

1. Install and activate the WordPress plugin.
2. Add SVG images through the Media Uploader.
3. Select the SVGs for the spritemap in **Settings** > **Media** > **SVG Spritemap**.

After selecting and updating the SVGs for your spritemap, a combined `defs.svg` SVG spritemap is automatically generated.

A text field displays the URL to the SVG spritemap. Individuals sprites may be referenced by appending `#:` and the name of the sprite to the URL.

```html
<svg><use xlink:href="http://dev.wordpress/wp-content/plugins/svg-spritemap/defs.svg#:accounts"></svg>
```

The live, estimated filesize of the spritemap represents the combined filesize of all the individual SVGs, but it does not factor in additional gzip compression. More than likely, the estimation will be conservative and the filesize will actually be smaller than the estimation.

Internet Explorer requires special assistance to display external SVGs. To resolve this issue, I have developed [SVG4Everybody](https://github.com/jonathantneal/svg4everybody).
