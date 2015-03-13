#include "../prep/random.h"

#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <stdexcept>

#include <cstdlib>
#include <cassert>

using namespace std;

template <typename T>
pair<T, T> binary_division(T a, T b) {
	assert(b);

	size_t diff = 1;

	while(b < a) {
		++diff;
		b <<= 1;
	}

	T result = 0;

	while(diff--) {
		result <<= 1;

		if(a >= b) {
			a -= b;
			result |= 1;
		}

		b >>= 1;
	}

	return make_pair(result, a);
}

template <typename T>
string message(T dividend, T divisor, T quotient, T remainder) {
	stringstream s;

	s << dividend << " / " << divisor << " = " << quotient
		<< " (remainder = " << remainder << ')';

	if(quotient * divisor + remainder != dividend) {
		s << " WRONG, expected " << (dividend / divisor)
			<< " (remainder = " << (dividend % divisor) << ')';
	}

	return s.str();
}

size_t stdin_test() {
	size_t n = 0;

	for(unsigned a, b; (cin >> a) && (cin >> b); ++n) {
		auto result = binary_division(a, b);

		if(result.first * b + result.second != a) {
			throw runtime_error(message(a, b, result.first, result.second));
		}
	}

	return n;
}

size_t random_test(size_t iterations) {
	for(auto i = iterations; i--; ) {
		unsigned a = get_random();
		unsigned b = 0;

		do {
			b = get_random();
		} while(!b || b > a);

		auto result = binary_division(a, b);

		if(result.first * b + result.second != a) {
			throw runtime_error(message(a, b, result.first, result.second));
		}
	}

	return iterations;
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	try {
		auto n = stdin_test()
			+ random_test(argc > 1 ? atoi(argv[1]) : 1000000);

		cout << "Success after " << n << " iterations" << endl;
	}
	catch(exception &e) {
		cerr << "Error: " << e.what() << endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
