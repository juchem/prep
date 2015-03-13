#include "../9-reverse_linked_list/reverse_linked_list.h"

#include "../prep/slist.h"
#include "../prep/random.h"

#include <iostream>
#include <vector>
#include <stack>

#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

template <typename node_type>
void reverse_print_modifiable_list(node_type *node) {
	for(node = reverse_slist(node); node; node = node->next()) {
		cout << ' ' << node->value();
	}
}

template <typename node_type>
void recursive_reverse_print_list(node_type *node) {
	if(!node) return;

	recursive_reverse_print_list(node->next());

	cout << ' ' << node->value();
}

template <typename node_type>
void reverse_print_list(node_type *node) {
	std::stack<node_type *> s;

	while(node) {
		s.push(node);
		node = node->next();
	}

	while(!s.empty()) {
		cout << ' ' << s.top()->value();
		s.pop();
	}
}

template <typename node_type>
void constant_memory_reverse_print_list(node_type *node) {
	size_t size = 0;

	for(auto i = node; i; i = i->next()) {
		++size;
	}

	for(auto n = size; n--; ) {
		auto i = node;

		for(auto k = n; k--; ) {
			assert(i);
			i = i->next();
		}

		assert(i);
		cout << ' ' << i->value();
	}
}

template <typename node_type>
void sublinear_mem_subquadratic_speed_reverse_print_list(node_type *node) {
	if(!node) return;

	size_t size = 0;

	for(auto i = node; i; i = i->next()) {
		++size;
	}

	vector<node_type *> index(ceil(sqrt(size)));
	size_t sqrt_n = sqrt(size);

	auto i = node;
	for(size_t k = 0, j = 0, next = 0; k < size; ++k, i = i->next()) {
		assert(i);

		if(k == next) {
			assert(j < index.size());

			next += sqrt_n;
			index[j++] = i;
		}
	}

	for(auto k = size; k--; ) {
		size_t j = k / sqrt_n;
		assert(j < index.size());

		i = index[j];

		for(j *= sqrt_n; j < k; ++j) {
			assert(i);
			i = i->next();
		}

		assert(i);
		cout << ' ' << i->value();
	}
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	auto list = build_list(argc > 1 ? atoi(argv[1]) : 10);

	cout << "Input list:" << endl;
	for(auto node = list.get(); node; node = node->next()) {
		cout << ' ' << node->value();
	}
	cout << endl;

	cout << "recursive_reverse_print_list:" << endl;
	recursive_reverse_print_list(list.get());
	cout << endl;

	cout << "reverse_print_list:" << endl;
	reverse_print_list(list.get());
	cout << endl;

	cout << "constant_memory_reverse_print_list:" << endl;
	constant_memory_reverse_print_list(list.get());
	cout << endl;

	cout << "sublinear_mem_subquadratic_speed_reverse_print_list:" << endl;
	sublinear_mem_subquadratic_speed_reverse_print_list(list.get());
	cout << endl;

	cout << "reverse_print_modifiable_list:" << endl;
	reverse_print_modifiable_list(list.get());
	cout << endl;

	return 0;
}
