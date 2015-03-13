#include "../17-find_bst_kth_element/find_bst_kth_element.h"
#include "../69-print_binary_tree/print_binary_tree.h"

#include "../prep/binary_tree.h"
#include "../prep/random.h"

#include <iostream>
#include <iomanip>

#include <cstdlib>
#include <cassert>

using namespace std;

void test(bst_node<int> const *node, bst_node<int> const *kth, size_t k, size_t size, bool max) {
	if(!node || k >= size) {
		assert(!kth);
		return;
	}

	assert(kth);

	int expected = max ? size - k - 1 : k;

	cout << "Kth = " << kth->value() << endl;
	cout << "expected = " << expected << endl;

	assert(kth->value() == expected);

	cout << endl;
}

void test(bst_node<int> const *node, size_t size, bool max) {
	cout << "size = " << size << endl;
	cout << "max = " << boolalpha << max << endl;
	print_binary_tree("tree", node);

	find_bst_kth_element<bst_node<int>> finder(max);

	for(size_t k = 0; k <= size; ++k) {
		test(node, finder.find(node, k), k, size, max);
	}
}

void test(bst_node<int> const *node) {
	auto size = node ? node->size() : 0;

	test(node, size, false);
	test(node, size, true);
}

void test(bst_node<int> const &node) {
	test(&node);
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	auto ubound = argc > 1 ? atoi(argv[1]) : 10;
	cout << "Upper bound: " << ubound << endl;

	test(bst_node<int>{3, 1, 0, 2, 5, 4, 6});

	while(ubound--) {
		auto tree = build_random_tree(ubound);

		test(tree.get());
	}

	return 0;
}
