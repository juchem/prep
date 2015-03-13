#ifndef INCLUDED_square_root_h
#define INCLUDED_square_root_h

#include <algorithm>

#include <cmath>

template <typename T>
T square_root(T n, T precision, unsigned &iterations) {
	T pivot = n;

	iterations = 0;

	for(T last = 0; precision < std::abs(pivot - last); ++iterations) {
		last = pivot;
		pivot = (pivot + (n / pivot)) / T(2);
	}

	return pivot;
}

#endif // INCLUDED_square_root_h
