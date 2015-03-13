#include "../prep/random.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename iterator>
iterator partition_uniques_duplicates(iterator begin, iterator end) {
	if(begin == end) return end;

	sort(begin, end);

	auto write = begin;

	for(auto read = begin + 1; read != end; ++read) {
		if(*read != *write) {
			swap(*read, *++write);
		}
	}

	return ++write;
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	vector<int> v(argc > 1 ? atoi(argv[1]) : 10);

	size_t dups = v.size() / 3;
	cout << "Generating at least "  << dups << " duplicates" << endl;

	cout << "Input values:" << endl;
	for(size_t i = dups; i < v.size(); ++i) {
		v[i] = rand() % 100;
		cout << ' ' << v[i];
	}
	for(size_t i = 0; i < dups; ++i) {
		v[i] = v[i + dups];
		cout << ' ' << v[i];
	}
	cout << endl;

	auto duplicates = partition_uniques_duplicates(begin(v), end(v));

	cout << "Uniques:" << endl;
	for(auto i = begin(v); i != duplicates; ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	cout << "Duplicates:" << endl;
	for(auto i = duplicates; i != end(v); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	sort(begin(v), end(v));
	cout << "Sorted values:" << endl;
	for(auto i = begin(v); i != end(v); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;

	return 0;
}
