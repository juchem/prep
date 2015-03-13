#include "../69-print_binary_tree/print_binary_tree.h"
#include "../prep/binary_tree.h"

#include <algorithm>

template <typename node_type>
void reverse_binary_tree(node_type *node) {
	if(!node) return;

	reverse_binary_tree(node->left());
	reverse_binary_tree(node->right());

	node_type *tmp = node->left();
	node->left(node->right());
	node->right(tmp);
}

int main() {
	auto balanced = build_balanced_binary_tree();
	print_binary_tree("Before:", balanced.get());
	reverse_binary_tree(balanced.get());
	print_binary_tree("After:", balanced.get());

	auto unbalanced = build_unbalanced_binary_tree();
	print_binary_tree("Before:", unbalanced.get());
	reverse_binary_tree(unbalanced.get());
	print_binary_tree("After:", unbalanced.get());

	return 0;
}
