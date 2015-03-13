#include "../prep/random.h"

#include <iostream>
#include <vector>
#include <iterator>

#include <cstdlib>

using namespace std;

template <typename iterator>
iterator pick_random_element(iterator begin, iterator end) {
	if(begin == end) return end;

	auto sample = begin;
	int weight = rand();

	for(++begin; begin != end; ++begin) {
		int w = rand();

		if(w > weight) {
			weight = w;
			sample = begin;
		}
	}

	return sample;
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0)
		<< endl;

	vector<int> v(argc > 1 ? atoi(argv[1]) : 100);

	for(auto i = v.size(); i--; ) {
		v[i] = i;
	}

	cout << "Size: " << v.size() << endl;

	auto sample = pick_random_element(begin(v), end(v));

	cout << endl;

	if(sample == end(v)) {
		cout << "No sample could be taken from an empty population" << endl;
	}
	else {
		cout << "Element picked: " << *sample << endl;
	}

	return 0;
}
