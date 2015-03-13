#ifndef INCLUDED__point_h
#define INCLUDED__point_h

template <typename T>
struct point {
	typedef T coord_t;

private:
	coord_t m_x;
	coord_t m_y;

public:
	explicit point(coord_t const &x = 0, coord_t const &y = 0):
		m_x(x),
		m_y(y)
	{
	}

	coord_t const &x() const { return m_x; }
	coord_t &x() { return m_x; }
	coord_t const &y() const { return m_y; }
	coord_t &y() { return m_y; }

	template <typename U>
	U &print(U &out) { return out << '(' << m_x << ',' << m_y << ')'; }

	bool const operator !=(point const &other) { return !(*this == other); }

	bool const operator ==(point const &other) {
		return m_x == other.m_x
			&& m_y == other.m_y;
	}
};

#endif // INCLUDED__point_h
