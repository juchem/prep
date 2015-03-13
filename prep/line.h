#ifndef INCLUDED__line_h
#define INCLUDED__line_h

template <typename T>
struct line_equation {
	typedef T coord_t;

private:
	coord_t m;
	coord_t b;

public:
	explicit line_equation(coord_t const &m = 0, coord_t const &b = 0):
		m(m),
		b(b)
	{
	}

	template <typename point_t>
	line_equation(point_t const &a, point_t const &b):
		// TODO: Handle infinite tangent
		m((b.y() - a.y()) / (b.x() - a.x())),
		b(a.y() - m * a.x())
	{
	}

	line_equation(coord_t const &x1, coord_t const &y1, coord_t const &x2, coord_t const &y2):
		// TODO: Handle infinite tangent
		m((y2 - y1) / (x2 - x1)),
		b(y1 - m * x1)
	{
	}

	// TODO: Handle infinite tangent
	coord_t const y(coord_t x) const { return m * x + b; }
	// TODO: Handle infinite tangent
	coord_t const x(coord_t y) const { return (y - b) / m; }

	bool const operator !=(line_equation const &other) {
		return !(*this == other);
	}

	bool const operator ==(line_equation const &other) {
		return m == other.m
			&& b == other.b;
	}
};

#endif // INCLUDED__line_h
