#include <iostream>
#include <vector>

using namespace std;

template <typename iterator>
size_t find_shift(iterator begin, iterator end) {
	if(begin == end || *begin < *--end) return 0;

	auto l = begin;

	for(auto r = end; l < r; ) {
		auto p = l + ((r - l) / 2);

		if(*p > *(p + 1)) return p - begin + 1;

		if(*p < *begin) {
			r = p;
		}
		else if(*p > *begin) {
			l = p + 1;
		}
		else {
			// fall-back to linear search
			for(p = end; p > begin; --p) {
				if(*(p - 1) > *p) break;
			}

			return p - begin;
		}
	}

	return l - begin;
}

int main() {
	vector<int> v;
	size_t expected;

	if(!(cin >> expected)) return 1;

	cout << "Input:";
	for(int x; cin >> x; ) {
		v.push_back(x);
		cout << ' ' << x;
	}
	cout << endl;

	cout << "Expected k: " << expected << endl;

	auto k = find_shift(begin(v), end(v));

	cout << "Actual k: " << k << " -> "
		<< (k == expected ? "correct" : "WRONG")
		<< endl
		<< endl;

	return 0;
}
