#ifndef INCLUDED__print_binary_tree_h
#define INCLUDED__print_binary_tree_h

#include <iostream>
#include <iomanip>

// In-order reversed traversal
template <typename node_type>
void print_binary_tree(node_type const *node, unsigned depth, char prepend, char const *indent = "  ") {
	if(!node) return;

	print_binary_tree(node->right(), depth + 1, '/', indent);

	for(auto i = depth; i--; ) {
		std::cout << indent;
	}

	std::cout << prepend << node->value()
		<< std::endl;

	print_binary_tree(node->left(), depth + 1, '\\', indent);
}

template <typename node_type>
void print_binary_tree(char const *caption, node_type const *node, char const *indent = "  ") {
	std::cout << caption << std::endl;

	print_binary_tree(node, 0, '-', indent);

	std::cout << std::endl;
}

#endif // INCLUDED__print_binary_tree_h
