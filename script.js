(function ($) {
	/* global jQuery */

	'use strict';

	var
	sizes = ['B', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB'],
	svgmap = {
		fn: {
			size: function () {
				svgmap.el.checked = svgmap.el.form.find(':checked');

				var size = 0;

				svgmap.el.checked.each(function (index, checkbox) {
					if (checkbox.checked) {
						size += parseFloat(checkbox.getAttribute('data-size')) || 0;
					}
				});

				return size;
			},
			readable_size: function (size) {
				var string;

				if (size > 1) {
					var i = Math.floor(Math.log(size) / Math.log(1000));

					string = (size / Math.pow(1000, i)).toPrecision(3) + ' ' + sizes[i];
				} else {
					string = size + ' ' + sizes[0];
				}

				svgmap.fn.size.value = size;

				svgmap.el.size.text(string);
			},
			animate_size: function (size) {
				clearInterval(svgmap.fn.animate_size.interval);

				var
				count = 10,
				lastSize = svgmap.fn.size.value || 0,
				nextSize = size,
				diffSize = Math.round(Math.abs(lastSize - nextSize) / count * (nextSize > lastSize ? 1 : -1));

				function oninterval() {
					svgmap.fn.readable_size(lastSize);

					if (!--count) {
						clearInterval(svgmap.fn.animate_size.interval);

						svgmap.fn.readable_size(nextSize);
					} else {
						lastSize += diffSize;
					}
				}

				svgmap.fn.animate_size.interval = setInterval(oninterval, 17);
			}
		},
		el: {
			form: null,
			size: null,
			checked: null
		},
		on: {
			init: function () {
				svgmap.el.form = $('.svg-list');
				svgmap.el.size = $('.svg-filesize');
				svgmap.el.url  = $('.svg-url');

				svgmap.el.form.on('change', svgmap.on.change);

				svgmap.on.change();

				svgmap.el.url.css({
					width: svgmap.el.url.get(0).scrollWidth + 42
				});

				svgmap.el.url.on('focus', svgmap.on.focus);
			},
			change: function () {
				var
				is_change = arguments.length,
				size = svgmap.fn.size();

				if (is_change) {
					svgmap.fn.animate_size(size);
				} else {
					svgmap.fn.readable_size(size);
				}
			},
			focus: function () {
				var input = this;

				setTimeout(function (){
					input.select();
				});
			}
		}
	};

	$(svgmap.on.init);
})(jQuery);
