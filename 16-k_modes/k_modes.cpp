#include "../prep/random.h"

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>

#include <cassert>

using namespace std;

template <typename T>
class mode_finder {
	// a space-efficient solution could use a count-sketch-like
	// data structure, see http://dl.acm.org/citation.cfm?id=684566
	// this is true specially for counting a large amount of elements
	// not implemented here due to its complexity
	unordered_map<T, size_t> counter;
	set<pair<size_t, T>> elements;
	size_t k;

public:
	mode_finder(size_t k):
		k(k)
	{
		assert(k);
	}

	void push(T const &value) {
		auto i = counter.find(value);

		if(i == counter.end()) {
			i = counter.insert(make_pair(value, 1)).first;
		}
		else {
			elements.erase(make_pair(i->second, i->first));
			++i->second;
		}

		elements.insert(make_pair(i->second, i->first));
	}

	vector<T> modes() const {
		vector<T> result;

		result.reserve(min(k, elements.size()));

		auto i = elements.crend();

		for(auto j = result.capacity(); j--; ++i) {
			result.push_back(i->second);
		}

		return result;
	}
};

template <typename T>
void display(T const &container, char const *message) {
	cout << message;

	for(auto &i: container) {
		cout << ' ' << i;
	}

	cout << endl;
}

template <typename T, typename stream_type>
void test_stream_modes(stream_type &input) {
	size_t k = 0;
	if(!(input >> k)) return;

	mode_finder<T> finder(k);

	cout << "Input:";
	for(T i; input >> i; ) {
		finder.push(i);
		cout << ' ' << i;
	}
	cout << endl;

	display(finder.modes(), "Modes:");
}

template <typename iterator>
void test_container_modes(size_t k, iterator begin, iterator end) {
	mode_finder<typename iterator_traits<iterator>::value_type> finder(k);

	cout << "Input:";
	for(; begin != end; ++begin) {
		finder.push(*begin);
		cout << ' ' << *begin;
	}
	cout << endl;

	display(finder.modes(), "Modes:");
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 3 ? atoi(argv[3]) : 0) << endl;

	cout << "Stream:" << endl;
	test_stream_modes<int>(cin);

	vector<unsigned> v(argc > 2 ? atoi(argv[2]) : 1000);
	for(auto &i: v) {
		i = get_random(20);
	}
	test_container_modes(argc > 1 ? atoi(argv[1]) : 5, begin(v), end(v));

	return 0;
}
