#ifndef INCLUDED__lru_cache_h
#define INCLUDED__lru_cache_h

#include <unordered_map>
#include <list>
#include <utility>
#include <functional>

#include <cassert>

template <typename K, typename V>
class lru_cache {
	typedef std::pair<K, V> entry_type;
	typedef std::list<entry_type> list_type;

public:
	typedef K key_type;
	typedef V value_type;
	typedef typename list_type::size_type size_type;
	typedef typename list_type::const_iterator const_iterator;

private:
	list_type cache;
	std::unordered_map<key_type, typename list_type::iterator> map;
	size_type c;
	std::function<value_type(key_type)> query;
	unsigned hit;
	unsigned miss;

public:
	template <typename query_type>
	lru_cache(size_type capacity, query_type query):
		c(capacity),
		query(query),
		hit(0),
		miss(0)
	{
		assert(capacity);
	}

	value_type &operator [](key_type const &key) {
		auto i = map.find(key);

		if(i == map.end()) {
			++miss;

			if(cache.size() == c) {
				map.erase(cache.back().first);
				cache.pop_back();
			}

			cache.push_front(std::move(
				std::make_pair(
					key,
					std::move(query(key))
				)
			));

			map[key] = cache.begin();
		}
		else {
			++hit;
			cache.splice(cache.begin(), cache, i->second);
		}

		return cache.front().second;
	}

	const_iterator begin() const { return cache.begin(); }
	const_iterator end() const { return cache.end(); }
	const_iterator cbegin() const { return cache.begin(); }
	const_iterator cend() const { return cache.end(); }

	size_type const size() const { return cache.size(); }
	size_type const capacity() const { return c; }

	unsigned hits() const { return hit; }
	unsigned misses() const { return miss; }
	double hit_ratio() const { return static_cast<double>(hit) / (hit + miss); }

	void reset() {
		hit = miss = 0;
	}
};

#endif // INCLUDED__lru_cache_h
