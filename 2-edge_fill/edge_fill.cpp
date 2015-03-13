#include "../prep/bitmap_paint.h"

#include <utility>
#include <stack>

#include <cassert>

using namespace std;

struct edge_fill {
	typedef bitmap_paint bitmap_type;
	typedef bitmap_type::color_type color_type;
	typedef bitmap_type::dimension dimension;
	typedef bitmap_type::coord coord;

private:
	bitmap_type &bitmap;

	void recursive_fill(matrix<bool> mark, dimension x, dimension y, color_type c, color_type bg) {
		mark(x, y) = true;

		if(bitmap.pick(x, y) != bg) {
			bitmap.dot(x, y, c);
			return;
		}

		if(x > 0 && !mark(x - 1, y)) recursive_fill(mark, x - 1, y, c, bg);
		if(y > 0 && !mark(x, y - 1)) recursive_fill(mark, x, y - 1, c, bg);
		if(x < bitmap.width() - 1 && !mark(x + 1, y)) recursive_fill(mark, x + 1, y, c, bg);
		if(y < bitmap.height() - 1 && !mark(x, y + 1)) recursive_fill(mark, x, y + 1, c, bg);
	}

public:
	edge_fill(bitmap_type &bitmap):
		bitmap(bitmap)
	{
	}

	void fill(dimension x, dimension y, color_type c, bool recursive = false) {
		assert(x < bitmap.width() && y < bitmap.height());

		auto bg = bitmap.pick(x, y);

		matrix<bool> mark(bitmap.width(), bitmap.height(), false);

		if(recursive) {
			recursive_fill(mark, x, y, c, bg);
			return;
		}

		stack<coord> s;
		s.push(make_pair(x, y));

		while(!s.empty()) {
			x = s.top().first;
			y = s.top().second;
			s.pop();

			mark(x, y) = true;

			if(bitmap.pick(x, y) != bg) {
				bitmap.dot(x, y, c);
			}

			if(x > 0 && !mark(x - 1, y)) s.push(make_pair(x - 1, y));
			if(y > 0 && !mark(x, y - 1)) s.push(make_pair(x, y - 1));
			if(x < bitmap.width() - 1 && !mark(x + 1, y)) s.push(make_pair(x + 1, y));
			if(y < bitmap.height() - 1 && !mark(x, y + 1)) s.push(make_pair(x, y + 1));
		}
	}
};

int main() {
	// TODO: Implement test case
	return 0;
}
