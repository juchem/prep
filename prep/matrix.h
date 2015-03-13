#ifndef INCLUDED__matrix_h
#define INCLUDED__matrix_h

#include <iostream>
#include <vector>

#include <cassert>

template <typename T>
class matrix {
	typedef std::vector<T> array_type;
	typedef typename array_type::reference reference;
	typedef typename array_type::const_reference const_reference;

	array_type m;
	typename array_type::size_type w;
	typename array_type::size_type h;

public:
	typedef typename array_type::value_type value_type;
	typedef typename array_type::size_type size_type;

	matrix(size_type width, size_type height, T const &value = T()):
		m(width * height, value),
		w(width),
		h(height)
	{
	}

/*
	template <typename U>
	matrix(U filler, size_type width, size_type height):
		m(width * height),
		w(width),
		h(height)
	{
		for(size_type y = 0; y < h; ++y) {
			for(size_type x = 0; x < w; ++x) {
				m[y * w + x] = filler(x, y);
			}
		}
	}
*/

	reference operator()(size_type const x, size_type const y) {
		assert(x >= 0 && x < w);
		assert(y >= 0 && y < h);

		return m[y * w + x];
	}

	const_reference operator()(size_type const x, size_type const y) const {
		assert(x >= 0 && x < w);
		assert(y >= 0 && y < h);

		return m[y * w + x];
	}

	size_type const width() const { return w; }
	size_type const height() const { return h; }
};

template <typename T, typename O, typename F>
void print_matrix(T const &m, O &out, F format) {
	for(typename T::size_type y = 0; y < m.height(); ++y) {
		for(typename T::size_type x = 0; x < m.width(); ++x) {
			out << format(m(x, y));
		}

		out << std::endl;
	}
}

template <typename T, typename O>
void print_matrix(T const &m, O &out) {
	print_matrix(m, out, [](typename T::value_type const &o){ return o; });
}

#endif // INCLUDED__matrix_h
