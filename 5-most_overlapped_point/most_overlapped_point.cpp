#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#include <cassert>

using namespace std;

class most_overlapped_point {
	priority_queue<int, vector<int>, greater<int>> q;

	int p;
	size_t max;

public:
	most_overlapped_point():
		max(0)
	{
	}

	void push(int start, int end) {
		assert(end > start);

		q.push(end);

		while(q.top() <= start) {
			q.pop();
		}

		if(q.size() > max) {
			max = q.size();
			p = start;
		}
	}

	int const point() const { return p; }
	size_t const count() const { return max; }
	size_t const current() const { return q.size(); }
};

struct interval {
	int start;
	int end;

	interval(int start, int end):
		start(start),
		end(end)
	{
	}

	bool operator <(interval const &other) const {
		return start < other.start || (start == other.start && end < other.end);
	}
};

int main() {
	most_overlapped_point p;
	vector<interval> v;

	for(int start, end; (cin >> start) && (cin >> end); ) {
		v.push_back(interval(start, end));
	}

	sort(v.begin(), v.end());

	for(auto i = v.begin(); i != v.end(); ++i) {
		cerr << "Interval: start = " << i->start
			<< ", end = " << i->end
			<< endl;

		p.push(i->start, i->end);

		cerr << "Point with most overlaps so far: "
			<< p.point() << " overlapping "
			<< p.count() << " intervals"
			<< endl;
	}

	cout << "Point with most overlaps: "
		<< p.point() << " overlapping "
		<< p.count() << " intervals"
		<< endl;
}
