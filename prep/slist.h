#ifndef INCLUDED__slist_h
#define INCLUDED__slist_h

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
#include <memory>

#include <cstdlib>
#include <cassert>

template <typename T>
class sl_node {
	sl_node *n;
	T v;

public:
	sl_node(T const &value, sl_node *next = 0):
		n(next),
		v(value)
	{
	}

	~sl_node() {
		delete n;
	}

	sl_node const *next() const { return n; }
	sl_node *next() { return n; }
	sl_node *next(sl_node *next) { return n = next; }

	T const &value() const { return v; }
	T &value() { return v; }
};

using namespace std;
std::unique_ptr<sl_node<int>> build_list(size_t n, int ubound = 100) {
	if(!n) {
		return std::unique_ptr<sl_node<int>>();
	}
	std::unique_ptr<sl_node<int>> head(
		new sl_node<int>(std::rand() % ubound)
	);

	for(auto node = head.get(); --n; node = node->next()) {
		node->next(
			new sl_node<int>(std::rand() % ubound)
		);
	}

	return head;
}

template <typename output>
unique_ptr<sl_node<int>> build_cyclic_list(size_t size, size_t cycleAt, output &out) {
	assert(size > 0);
	assert(cycleAt < size);

	unique_ptr<sl_node<int>> head(new sl_node<int>(0));

	out << "List: " << head->value();

	auto last = head.get();
	auto start = head.get();

	while(--size) {
		last = last->next(new sl_node<int>(last->value() + 1));
		out << ' ' << last->value();

		if(cycleAt) {
			start = last;
			--cycleAt;
		}
	}
	out << std::endl;

	last->next(start);

	return head;
}

template <typename node_type, typename output>
void print_list(node_type const *head, char const *message, output &out) {
	out << message;
	for(; head; head = head->next()) {
		out << ' ' << head->value();
	}
	out << endl;
}

template <typename node_type, typename output>
void print_list(node_type const *head, size_t size, char const *message, output &out) {
	out << message;
	for(; head && size--; head = head->next()) {
		out << ' ' << head->value();
	}
	out << std::endl;
}

#endif // INCLUDED__slist_h
