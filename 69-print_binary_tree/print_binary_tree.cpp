#include "../69-print_binary_tree/print_binary_tree.h"
#include "../prep/binary_tree.h"

int main() {
	auto balanced = build_balanced_binary_tree();
	print_binary_tree("Balanced:", balanced.get());

	auto unbalanced = build_unbalanced_binary_tree();
	print_binary_tree("Unbalanced:", unbalanced.get());

	return 0;
}
