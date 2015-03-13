#include <iostream>
#include <string>
#include <algorithm>

#include <cassert>

using namespace std;

template <typename T, typename S>
void print_combinations(T const &s, S &subset, size_t i, size_t n, size_t j, size_t k) {
	if(j == k) {
		for(i = 0; i < k; ++i) {
			cout << subset[i];
		}
		cout << endl;

		return;
	}

	for(; i < n - (k - j) + 1; ++i) {
		subset[j] = s[i];
		print_combinations(s, subset, i + 1, n, j + 1, k);
	}
}

template <typename T>
void print_combinations(T const &s, size_t k) {
	assert(k <= s.size());
	vector<char> subset(s.size());

	print_combinations(s, subset, 0, s.size(), 0, k);
}

int main() {
	size_t k;
	for(string s; (cin >> k) && (cin >> s); ) {
		cout << "String: " << s << endl;
		cout << k << "-subsets (combinations):" << endl;
		print_combinations(s, k);
		cout << endl;
	}

	return 0;
}
