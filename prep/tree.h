#ifndef INCLUDED__tree_h
#define INCLUDED__tree_h

#pragma message "\n\
\n\
******************************************\n\
THIS CODE SHOULD NOT be used in production\n\
it's very limited and NOT EXCEPTION SAFE\n\
it may also contain UNDEFINED BEHAVIOR\n\
it's only intended for exercising purposes\n\
******************************************\n\
"

#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>

template <typename T>
class tree_node {
	// TODO: Use a vector instead
	typedef std::list<tree_node<T> *> children_type;
	children_type children;
	T v;

public:
	typedef typename children_type::const_iterator const_iterator;
	typedef typename children_type::size_type size_type;
	typedef typename children_type::value_type value_type;
	typedef typename children_type::reference reference;
	typedef typename children_type::const_reference const_reference;

	tree_node(T const &value):
		v(value)
	{
	}

	~tree_node() {
		while(!children.empty()) {
			delete children.front();
			children.pop_front();
		}
	}

	void insert(const_iterator position, T const &value) {
		children.insert(position, new tree_node(value));
	}

	const_iterator erase(const_iterator position) {
		return children.erase(position);
	}

	void clear() { children.clear(); }

	void swap(tree_node &other) {
		using namespace std;
		swap(v, other.v);
		children.swap(other.children);
	}

	void push_front(T const &value) { children.push_front(new tree_node(value)); }
	void push_back(T const &value) { children.push_back(new tree_node(value)); }
	void pop_front() { children.pop_front(); }
	void pop_back() { children.pop_back(); }
	reference front() { return children.front(); }
	const_reference front() const { return children.front(); }
	reference back() { return children.back(); }
	const_reference back() const { return children.back(); }

	const_iterator const begin() const { return children.begin(); }
	const_iterator const end() const { return children.end(); }
	const_iterator const cbegin() const { return children.cbegin(); }
	const_iterator const cend() const { return children.cend(); }
	const_iterator const rbegin() const { return children.rbegin(); }
	const_iterator const rend() const { return children.rend(); }
	const_iterator const crbegin() const { return children.crbegin(); }
	const_iterator const crend() const { return children.crend(); }

	T const &value() const { return v; }
};

template <typename node_type, typename value_printer>
void print_tree(node_type *node, value_printer print) {
	if(!node) return;

	std::cout << '[' << node->value() << ' ';

	std::stack<
		std::pair<typename node_type::const_iterator, typename node_type::const_iterator>
	> s;
	s.push(std::make_pair(node->begin(), node->end()));

	for(unsigned indent = 0; !s.empty(); ) {
		auto &i = s.top();

		if(i->first == i->second) {
			std::cout << ']';
			s.pop();
			continue;
		}

		std::cout << '[';
		print(std::cout, i->first->value());
		std::cout << ' ';
		
		auto next = std::make_pair(i.first->node->begin(), node->end());
		++i->first;
		s.push(next);
	}

	std::cout << ']' << std::endl;
}

template <typename node_type>
void print_tree(node_type *node) {
	print_tree(node, [](ostream &out, typename node_type::value_type const &value){ out << value; });
}

#endif // INCLUDED__tree_h
