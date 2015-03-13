#include <unordered_set>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

template <typename T>
void print_set(T const &s, char const *caption = "Set") {
	cout << caption << ':';
	for(auto i = s.begin(); i != s.end(); ++i) {
		cout << ' ' << *i;
	}
	cout << endl;
}

/* O(n^2)
template <typename iterator>
list<int> intersection(iterator i, iterator end) {
	if(i == end) return list<int>();
	
	list<int> s(i->begin(), i->end());
	
	while(++i != end) {
		for(auto j = s.begin(); j != s.end(); ) {
			if(i->find(*j) == i->end()) {
				j = s.erase(j);
			}
			else {
				++j;
			}
		}
	}
	
	return s;
}
/*/
template <typename iterator>
unordered_set<int> intersection(iterator i, iterator end) {
	if(i == end) return unordered_set<int>();

	auto prev = i;

	for(++i; i != end; prev = i++) {
		for(auto k = i->begin(); k != i->end(); ) {
			if(prev->find(*k) == prev->end()) {
				k = i->erase(k);
			}
			else {
				++k;
			}
		}
	}
	
	return *prev;
}
//*/

int main() {
	vector<unordered_set<int>> v;
	int n;

	unordered_set<int> s;

	while(cin >> n) {
		if(!n) {
			v.push_back(s);
			s.clear();
			continue;
		}

		s.insert(n);
	}

	if(!s.empty()) v.push_back(s);

	for(size_t i = 0; i < v.size(); ++i) {
		print_set(v[i]);
	}

	print_set(intersection(v.begin(), v.end()), "Intersection");
}
