#include "../prep/slist.h"

#include "../67-list_cycle/list_cycle.h"

#include <iostream>
#include <memory>

#include <cassert>

using namespace std;

int main() {
	size_t size = 0;
	size_t cycle = 0;

	if(!(cin >> size) || !(cin >> cycle)) {
		return 1;
	}

	cout << "size = " << size << endl
		<< "cycle = " << cycle << endl;

	if(size < 1) {
		cout << "The list must have at least one element" << endl;
		return 2;
	}

	if(cycle >= size) {
		cout << "The cycle must occur in a valid element" << endl;
		return 3;
	}

	auto head = build_cyclic_list(size, cycle, cout);
	print_list(head.get(), size * 2, "Cyclic list", cout);

	auto cyclic = break_cycle(head.get());
	cout << (cyclic ? "Cycle broken" : "No cycle detected") << endl;
	print_list(head.get(), "Non-cyclic list", cout);

	auto i = head->value();
	for(auto node = head.get(); node; node = node->next(), ++i) {
		assert(i == node->value());
	}
	assert(static_cast<decltype(size)>(i) == size);
	cout << "Resulting list is CORRECT" << endl;

	return 0;
}
