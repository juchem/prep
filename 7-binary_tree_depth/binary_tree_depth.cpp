#include "../prep/binary_tree.h"
#include "../69-print_binary_tree/print_binary_tree.h"

#include <iostream>

using namespace std;

template <typename node_type>
size_t binary_tree_depth(node_type *node) {
	if(!node) return 0;

	return 1 + max(
		binary_tree_depth(node->left()),
		binary_tree_depth(node->right())
	);
}

int main() {
	auto balanced = build_balanced_binary_tree();
	print_binary_tree("balanced", balanced.get());
	cout << "depth = " << binary_tree_depth(balanced.get())
		<< endl;

	auto unbalanced = build_unbalanced_binary_tree();
	print_binary_tree("unbalanced", unbalanced.get());
	cout << "depth = " << binary_tree_depth(unbalanced.get())
		<< endl;

	return 0;
}
