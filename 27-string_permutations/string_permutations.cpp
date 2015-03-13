#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void print_permutations(T &s, size_t i, size_t n) {
	if(i == n) {
		cout << s << endl;
		return;
	}

	for(size_t k = i; k < n; ++k) {
		swap(s[i], s[k]);
		print_permutations(s, i + 1, n);
		swap(s[k], s[i]);
	}
}

template <typename T>
void print_permutations(T &s) {
	print_permutations(s, 0, s.size());
}

int main() {
	for(string s; cin >> s; ) {
		cout << "String: " << s << endl;
		cout << "Permutations:" << endl;
		print_permutations(s);
		cout << endl;
	}

	return 0;
}
