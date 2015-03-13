#include "../12-lru_cache/lru_cache.h"

#include <iostream>
#include <string>

using namespace std;

string query_value(int key) {
	cout << "Cache MISS for key " << key << ", enter its value: ";
	string s;
	cin >> s;
	cout << endl;
	return s;
}

bool query_key(int &key) {
	cout << "Enter key to lookup: ";
	bool result = static_cast<bool>(cin >> key);
	cout << endl;
	return result;
}

int main(int argc, char **argv) {
	lru_cache<int, string> cache(argc > 1 ? atoi(argv[1]) : 5, query_value);

	cout << "Cache capacity: " << cache.capacity() << endl;

	for(int key; query_key(key); ) {
		auto &value = cache[key];
		cout << "Value for key " << key << ": " << value << endl;

		cout << "LRU Cache contents:";
		for(auto &i: cache) {
			cout << " [" << i.first << "]:" << i.second;
		}
		cout << endl;
	}

	cout << "Cache statistics: "
		<< cache.hits() << " hits, "
		<< cache.misses() << " misses, "
		<< (cache.hit_ratio() * 100) << "% hit ratio"
		<< endl;
}
