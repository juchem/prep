#ifndef INCLUDED__binary_tree_h
#define INCLUDED__binary_tree_h

#pragma message "\n\
\n\
******************************************\n\
THIS CODE SHOULD NOT be used in production\n\
it's very limited and NOT EXCEPTION SAFE\n\
it may also contain UNDEFINED BEHAVIOR\n\
it's only intended for exercising purposes\n\
******************************************\n\
"

#include <memory>
#include <initializer_list>
#include <iterator>
#include <stack>
#include <set>

#include <cassert>

template <typename T>
class bst_node {
	bst_node<T> *children[2];
	T v;

public:
	bst_node(T const &value, bst_node *left = 0, bst_node *right = 0):
		children{left, right},
		v(value)
	{
	}

	bst_node(std::initializer_list<T> values):
		children{0, 0},
		v(*begin(values))
	{
		auto i = begin(values);
		assert(i != end(values));

		while(++i != end(values)) {
			add(*i);
		}
	}

	~bst_node() {
		delete children[0];
		delete children[1];
	}

	void add(T const &value) {
		bst_node *parent = 0;

		for(auto node = this; node; node = node->child(value > node->value())) {
			parent = node;
		}

		std::unique_ptr<bst_node> child(new bst_node(value));
		parent->child(child.get(), value > parent->value());
		child.release();
	}

	size_t size() const {
		std::stack<bst_node const *> s;
		s.push(this);

		size_t n = 0;

		while(!s.empty()) {
			auto i = s.top();
			s.pop();

			++n;

			if(i->left()) s.push(i->left());
			if(i->right()) s.push(i->right());
		}

		return n;
	}

	bst_node const *left() const { return children[0]; }
	bst_node *left() { return children[0]; }
	bst_node *left(bst_node *left) { return children[0] = left; }

	bst_node const *right() const { return children[1]; }
	bst_node *right() { return children[1]; }
	bst_node *right(bst_node *right) { return children[1] = right; }

	bst_node const *child(bool right) const { return children[right]; }
	bst_node *child(bool right) { return children[right]; }
	bst_node *child(bst_node *child, bool right) { return children[right] = child; }

	T const &value() const { return v; }
	T &value() { return v; }
};

std::unique_ptr<bst_node<int>> build_random_tree(size_t size) {
	std::unique_ptr<bst_node<int>> tree;

	if(!size) return tree;

	class get_random {
		std::set<int> s;
	public:
		get_random(size_t size) {
			for(int i = size; i--; ) {
				s.insert(i);
			}
		}

		int get() {
			assert(!s.empty());

			int weight = rand();
			auto i = begin(s);
			auto j = i;

			while(++i != end(s)) {
				int w = rand();

				if(w > weight) {
					weight = w;
					j = i;
				}
			}

			int value = *j;
			s.erase(j);

			return value;
		}

		bool empty() const { return s.empty(); }
	} rnd(size);

	tree.reset(new bst_node<int>(rnd.get()));

	while(!rnd.empty()) {
		tree->add(rnd.get());
	}

	return tree;
}

std::unique_ptr<bst_node<int>> build_balanced_binary_tree() {
	return std::unique_ptr<bst_node<int>>(
		new bst_node<int>(4,
			new bst_node<int>(2,
				new bst_node<int>(1),
				new bst_node<int>(3)
			),
			new bst_node<int>(6,
				new bst_node<int>(5),
				new bst_node<int>(7)
			)
		)
	);
}

std::unique_ptr<bst_node<int>> build_unbalanced_binary_tree() {
	return std::unique_ptr<bst_node<int>>(
		new bst_node<int>(2,
			new bst_node<int>(7,
				new bst_node<int>(2),
				new bst_node<int>(6,
					new bst_node<int>(5),
					new bst_node<int>(11)
				)
			),
			new bst_node<int>(5,
				0,
				new bst_node<int>(9,
					new bst_node<int>(4),
					0
				)
			)
		)
	);
}

#endif // INCLUDED__binary_tree_h
