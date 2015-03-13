#include "../14-shuffle/shuffle.h"
#include "../prep/random.h"

#include <iostream>
#include <vector>
#include <iterator>

#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	vector<int> v(argc > 1 ? atoi(argv[1]) : 10);

	for(size_t i = 0; i < v.size(); ++i) {
		v[i] = rand() % 100;
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

	sort(begin(v), end(v));
	cout << "Re-sorted input:" << endl;
	for(auto i = begin(v); i != end(v); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	return 0;
}
