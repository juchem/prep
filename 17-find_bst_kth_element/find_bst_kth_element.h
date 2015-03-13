#ifndef INCLUDED__find_bst_kth_element_h
#define INCLUDED__find_bst_kth_element_h

#include <stack>
#include <functional>
#include <algorithm>

#include <cstddef>

template <typename node_type>
class find_bst_kth_element {
	bool const max;

	node_type const *recursive_find_call(node_type const *node, std::size_t &k) {
		if(!node) return 0;

		auto left = recursive_find_call(node->child(max), k);
		if(left) return left;

		if(!k--) return node;

		return recursive_find_call(node->child(!max), k);
	}

public:
	find_bst_kth_element(bool max = false):
		max(max)
	{
	}

	node_type const *find(node_type const *node, std::size_t k) {
		if(!node) return 0;

		std::stack<decltype(node)> s;

		while(true) {
			if(node) {
				s.push(node);
				node = node->child(max);
			}
			else if(s.empty()) {
				break;
			}
			else {
				node = s.top();
				s.pop();

				if(!k--) break;

				node = node->child(!max);
			}
		}

		return node;
	}

	node_type const *recursive_find(node_type const *node, std::size_t k) {
		return recursive_find_call(node, k);
	}
};

#endif // INCLUDED__find_bst_kth_element_h
