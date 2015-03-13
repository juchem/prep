#ifndef INCLUDED__shuffle_h
#define INCLUDED__shuffle_h

#include <functional>
#include <algorithm>

#include <cstdlib>

template <typename iterator>
void shuffle(iterator begin, iterator end, std::function<int()> random = std::rand) {
	using namespace std;

	for(auto i = begin; i != end; ++i) {
		swap(*i, *(i + (rand() % (end - i))));
	}
}

#endif // INCLUDED__shuffle_h
