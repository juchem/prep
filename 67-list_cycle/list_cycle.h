#ifndef INCLUDED__list_cycle_h
#define INCLUDED__list_cycle_h

#include "../prep/slist.h"

template <typename node_type>
node_type *find_cycle(node_type *head) {
	node_type *prev = 0;
	auto slow = head;
	auto fast = head;

	while(fast && fast->next()) {
		fast = fast->next()->next();
		prev = slow;
		slow = slow->next();

		if(slow == fast) break;
	}

	if(!prev || slow != fast) return 0;

	for(fast = head; fast != slow; fast = fast->next()) {
		prev = slow;
		slow = slow->next();
	}

	return prev;
}

template <typename node_type>
bool break_cycle(node_type *head) {
	auto prev = find_cycle(head);

	if(!prev) return false;

	prev->next(0);

	return true;
}

#endif // INCLUDED__list_cycle_h
