#include "../prep/point.h"
#include "../prep/line.h"

#include <iostream>
#include <vector>

#include <cstdlib>

using namespace std;

template <typename point_t>
bool input_point(point_t &p) {
	cerr << "Enter coordinates for a point:" << endl;
	cerr << "\tx = ";
	if(!(cin >> p.x())) return false;
	cerr << endl << "\ty = ";
	if(!(cin >> p.y())) return false;
	cerr << endl;
	return true;
}

int main() {
	typedef double coord_t;
	size_t n = 3;
	vector<point<coord_t>> p(n);

	for(decltype(n) i = 0; i < n; ++i) {
		if(!input_point(p[i])) {
			return EXIT_FAILURE;
		}
	}

	bool colinear = line_equation<coord_t>(p[0], p[1])
		== line_equation<coord_t>(p[1], p[2]);

	cout << "The points ";
	p[0].print(cout) << "; ";
	p[1].print(cout) << " and ";
	p[2].print(cout) << (colinear ? " WON'T" : " WILL")
		<< " form a triangle" << endl;

	return EXIT_SUCCESS;
}
