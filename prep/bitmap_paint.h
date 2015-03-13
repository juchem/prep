#include "../prep/color.h"
#include "../prep/matrix.h"

#include <utility>

class bitmap_paint {
	typedef matrix<color> bitmap_type;

public:
	typedef color color_type;
	typedef bitmap_type::size_type size_type;
	typedef size_type dimension;
	typedef std::pair<dimension, dimension> coord;

private:
	bitmap_type bitmap;

public:
	bitmap_paint(size_type width, size_type height, color_type bg = color_type::black()):
		bitmap(width, height, bg)
	{
	}

	void dot(dimension x, dimension y, color_type c) { bitmap(x, y) = c; }
	color_type const pick(dimension x, dimension y) const { return bitmap(x, y); }

	size_type const width() const { return bitmap.width(); }
	size_type const height() const { return bitmap.height(); }
};
