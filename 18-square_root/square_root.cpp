#include "../18-square_root/square_root.h"

#include <iostream>
#include <vector>

#include <cmath>
#include <cassert>

using namespace std;

template <typename T>
void test(T n, T precision) {
	cout << "testing " << n << endl;

	unsigned iterations = 0;
	auto result = square_root(n, precision, iterations);
	cout << "sqrt(" << n << ") = " << result << " after " << iterations << " iterations"
		<< endl;

	assert(abs(result * result - n) < precision);

	cout << endl;
}

int main() {
	vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 64, 99, 100, 4096};

	for(auto &i: v) {
		test(i, .000001);
	}

	return 0;
}
