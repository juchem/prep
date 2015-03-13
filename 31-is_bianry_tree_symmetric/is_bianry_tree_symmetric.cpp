#include "../prep/binary_tree.h"

#include <iostream>
#include <iomanip>

using namespace std;

template <typename node_type>
bool is_simmetric(node_type *left, node_type *right) {
	if(!left) return !right;
	if(!right) return false;

	return is_simmetric(left->left(), right->right())
		&& is_simmetric(left->right(), right->left());
}

template <typename node_type>
bool is_simmetric(node_type *node) {
	return !node || is_simmetric(node->left(), node->right());
}

int main() {
	auto balanced = build_balanced_binary_tree();
	cout << boolalpha << "simmetric = " << is_simmetric(balanced.get())
		<< endl;

	auto unbalanced = build_unbalanced_binary_tree();
	cout << boolalpha << "simmetric = " << is_simmetric(unbalanced.get())
		<< endl;

	return 0;
}
