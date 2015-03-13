#include "../prep/binary_tree.h"

#include <iostream>
#include <iomanip>

using namespace std;

template <typename node_type>
bool is_binary_tree_balanced(node_type *node, size_t &left, size_t &right) {
	if(!node) {
		left = right = 0;
		return true;
	}

	if(!is_binary_tree_balanced(node->left(), left, right)) return false;
	size_t l = 1 + max(left, right);

	if(!is_binary_tree_balanced(node->right(), left, right)) return false;
	size_t r = 1 + max(left, right);

	left = l;
	right = r;

	return (left > right ? left - right : right - left) <= 1;
}

template <typename node_type>
bool is_binary_tree_balanced(node_type *node) {
	size_t left = 0;
	size_t right = 0;

	return is_binary_tree_balanced(node, left, right);
}

int main() {
	auto balanced = build_balanced_binary_tree();
	cout << "balanced = " << boolalpha
		<< is_binary_tree_balanced(balanced.get())
		<< endl;

	auto unbalanced = build_unbalanced_binary_tree();
	cout << "unbalanced = " << boolalpha
		<< is_binary_tree_balanced(unbalanced.get())
		<< endl;

	return 0;
}
