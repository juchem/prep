#ifndef INCLUDED__reverse_linked_list_h
#define INCLUDED__reverse_linked_list_h

template <typename node_type>
node_type *recursive_reverse_slist(node_type *node, node_type *prev = 0) {
	if(!node) return prev;

	auto last = recursive_reverse_slist(node->next(), node);
	node->next(prev);

	return last;
}

template <typename node_type>
node_type *reverse_slist(node_type *node) {
	node_type *prev = 0;

	for(node_type *next; node; node = next) {
		next = node->next();
		node->next(prev);
		prev = node;
	}

	return prev;
}

#endif // INCLUDED__reverse_linked_list_h
