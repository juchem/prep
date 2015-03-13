#include "../prep/random.h"
#include "../prep/matrix.h"

#include <iostream>
#include <iomanip>

#include <cstdlib>

using namespace std;

template <typename T>
void fill_matrix(T &m) {
	vector<bool> fill_x(m.width(), false);
	vector<bool> fill_y(m.height(), false);

	for(typename T::size_type y = 0; y < m.height(); ++y) {
		for(typename T::size_type x = 0; x < m.width(); ++x) {
			if(!m(x, y)) {
				fill_x[x] = true;
				fill_y[y] = true;
			}
		}
	}

	for(typename T::size_type x = 0; x < m.width(); ++x) {
		if(fill_x[x]) {
			cerr << "filling column " << x << endl;

			for(typename T::size_type y = 0; y < m.height(); ++y) {
				m(x, y) = false;
			}
		}
	}

	for(typename T::size_type y = 0; y < m.height(); ++y) {
		if(fill_y[y]) {
			cerr << "filling row " << y << endl;

			for(typename T::size_type x = 0; x < m.width(); ++x) {
				m(x, y) = false;
			}
		}
	}
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 4 ? atoi(argv[4]) : 0) << endl;

	matrix<bool> m(
		argc > 2 ? atoi(argv[2]) : 15,
		argc > 3 ? atoi(argv[3]) : 10,
		true
	);

	for(auto i = argc > 1 ? atoi(argv[1]) : 3; i--; ) {
		m(get_random(m.width()), get_random(m.height())) = false;
	}

	cout << "Matrix:" << endl;
	print_matrix(m, cout);
	cout << endl;

	fill_matrix(m);

	cout << "Output:" << endl;
	print_matrix(m, cout);
	cout << endl;

	return 0;
}
