#include "../prep/matrix.h"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <typename matrix_type, typename coord_type, typename visited_type>
void recursive_find_graph_components(matrix_type const &m, coord_type x, coord_type y, visited_type &visited) {
	visited(x, y) = true;

	if(x && !visited(x - 1, y) && m(x - 1, y) == m(x, y)) {
		recursive_find_graph_components(m, x - 1, y, visited);
	}

	if(y && !visited(x, y - 1) && m(x, y - 1) == m(x, y)) {
		recursive_find_graph_components(m, x, y - 1, visited);
	}

	if(x < m.width() - 1 && !visited(x + 1, y) && m(x + 1, y) == m(x, y)) {
		recursive_find_graph_components(m, x + 1, y, visited);
	}

	if(y < m.height() - 1 && !visited(x, y + 1) && m(x, y + 1) == m(x, y)) {
		recursive_find_graph_components(m, x, y + 1, visited);
	}
}

template <typename matrix_type>
unsigned recursive_find_graph_components(matrix_type const &m) {
	unsigned count = 0;

	matrix<bool> visited(m.width(), m.height(), false);

	for(auto y = m.height(); y--; ) {
		for(auto x = m.width(); x--; ) {
			if(visited(x, y)) continue;

			++count;

			recursive_find_graph_components(m, x, y, visited);
		}
	}

	return count;
}

template <typename matrix_type>
unsigned iterative_find_graph_components(matrix_type const &m) {
	unsigned count = 0;

	matrix<bool> visited(m.width(), m.height(), false);

	stack<pair<typename matrix_type::size_type, typename matrix_type::size_type>> s;

	for(auto y = m.height(); y--; ) {
		for(auto x = m.width(); x--; ) {
			if(visited(x, y)) continue;

			++count;

			s.push(make_pair(x, y));

			while(!s.empty()) {
				auto i = s.top().first;
				auto j = s.top().second;
				s.pop();

				visited(i, j) = true;

				if(i && !visited(i - 1, j) && m(i - 1, j) == m(i, j)) {
					s.push(make_pair(i - 1, j));
				}

				if(j && !visited(i, j - 1) && m(i, j - 1) == m(i, j)) {
					s.push(make_pair(i, j - 1));
				}

				if(i < m.width() - 1 && !visited(i + 1, j) && m(i + 1, j) == m(i, j)) {
					s.push(make_pair(i + 1, j));
				}

				if(j < m.height() - 1 && !visited(i, j + 1) && m(i, j + 1) == m(i, j)) {
					s.push(make_pair(i, j + 1));
				}
			}
		}
	}

	return count;
}

int main(int argc, char **argv) {
	size_t width;
	size_t height;

	if(!((cin >> width) && (cin >> height))) {
		cerr << "parse error in input header" << endl;
		return 1;
	}

	matrix<char> m(width, height);

	size_t y = 0;
	for(string s; cin >> s; ++y) {
		if(y >= m.height() || s.size() != m.width()) {
			cerr << "parse error in input contents" << endl;
			return 2;
		}

		for(size_t x = 0; x < m.width(); ++x) {
			m(x, y) = s[x];
		}
	}

	if(y != m.height()) {
		cerr << "parse error in input contents" << endl;
		return 3;
	}

	cout << "Matrix:" << endl;
	print_matrix(m, cout);
	cout << endl;

	cout << "Number of components (recursive): " << recursive_find_graph_components(m) << endl;
	cout << "Number of components (iterative): " << iterative_find_graph_components(m) << endl;

	return 0;
}
