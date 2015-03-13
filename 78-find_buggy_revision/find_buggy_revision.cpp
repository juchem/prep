#include <iostream>

#include <cassert>

using namespace std;

template <typename T>
int find_buggy_revision(int first, int last, T const &builder) {
	assert(first < last);

	while(first < last) {
		auto pivot = first + ((last - first) / 2);

		if(builder.build(pivot)) {
			first = pivot + 1;
		}
		else {
			last = pivot - 1;
		}
	}

	return first + builder.build(first);
}

class build_system {
	int first;
	int buggy;
	int last;

public:
	build_system(int first, int buggy, int last):
		first(first),
		buggy(buggy),
		last(last)
	{
		assert(buggy > first);
		assert(last >= buggy);
	}

	bool build(int revision) const {
		assert(revision >= first);
		assert(revision <= last);

		return revision < buggy;
	}

	bool did_introduce_bug(int revision) const {
		return revision == buggy;
	}
};

int main() {
	int first;
	if(!(cin >> first)) return 1;

	cout << "Build stream: ";
	int buggy = first;
	for(char outcome; cin >> outcome && outcome == 'g'; ++buggy) {
		cout << outcome;
	}
	cout << 'b';
	int last = buggy;
	for(char outcome; cin >> outcome; ++last) {
		assert(outcome == 'b');
		cout << outcome;
	}
	cout << endl;

	cout << "Previous build's revision (OK): " << first << endl;
	cout << "Last build's revision (broken): " << last << endl;
	cout << "Revision that broke the build: " << buggy << endl;

	build_system builder(first, buggy, last);
	auto result = find_buggy_revision(first, last, builder);

	cout << "Result given by search function: " << result
		<< (builder.did_introduce_bug(result) ? " correct" : " WRONG")
		<< endl;
}
