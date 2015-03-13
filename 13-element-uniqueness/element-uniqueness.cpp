#include "../14-shuffle/shuffle.h"
#include "../prep/random.h"

#include <iostream>
#include <vector>
#include <iterator>

#include <cstdlib>
#include <ctime>

using namespace std;

template <typename iterator>
iterator find_duplicate(iterator begin, iterator end) {
	if(begin == end) return end;

	sort(begin, end);

	for(auto i = begin; i + 1 != end; ++i) {
		if(*i == *(i + 1)) {
			return i;
		}
	}

	return end;
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	vector<int> v(argc > 1 ? atoi(argv[1]) : 10);

	for(size_t i = 0, value = rand() % 100, k = rand() % v.size(); i < v.size(); ++i) {
		v[i] = value;

		if(i != k) {
			++value;
		}
	}

	sort(begin(v), end(v));
	cout << "Sorted input:" << endl;
	for(auto i = begin(v); i != end(v); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	shuffle(begin(v), end(v));
	cout << "Shuffled input:" << endl;
	for(auto i = begin(v); i != end(v); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	auto i = find_duplicate(begin(v), end(v));
	if(i == end(v)) {
		cout << "No duplicated element" << endl;
	}
	else {
		cout << "Duplicated element: " << *i << endl;
	}

	return 0;
}
