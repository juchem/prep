#ifndef INCLUDED__random_h
#define INCLUDED__random_h

#include <cstdlib>
#include <ctime>

unsigned seed_random(unsigned seed = 0) {
	if(!seed) {
		seed = std::time(0);
		if(!seed) seed = 1;
	}

	std::srand(seed);

	return seed;
}

unsigned get_random(unsigned ubound, bool inclusive = false) {
	return rand() % (ubound + inclusive);
}

unsigned get_random() { return rand(); }

#endif // INCLUDED__random_h
