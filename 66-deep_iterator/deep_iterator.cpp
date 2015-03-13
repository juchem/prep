#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;

template <typename TBase, typename TElement, typename TCollection>
class deep_iterator {
	stack<TBase *> s;
	stack<size_t> index;

public:
	deep_iterator(TBase *root) {
		s.push(root);

		if(s.top()->is_collection()) {
			index.push(0);
			++*this;
		}
	}

	TElement const *operator ->() const { return static_cast<TElement *>(s.top()); }

	deep_iterator &operator ++() {
		if(!s.top()->is_collection()) {
			s.pop();
			if(!index.empty()) {
				++index.top();
			}
		}

		while(!s.empty()) {
			auto c = static_cast<TCollection *>(s.top());

			if(index.top() == c->size()) {
				s.pop();
				index.pop();
				if(!index.empty()) {
					++index.top();
				}
			}
			else {
				s.push(c->at(index.top()));

				if(!s.top()->is_collection()) break;

				index.push(0);
			}
		}

		return *this;
	}

	explicit operator bool() const { return !s.empty(); }
};

struct base {
	virtual ~base() {}
	virtual bool is_collection() = 0;
};

class element:
	public base
{
	string m_value;
	virtual bool is_collection() { return false; }

public:
	element(string const &value):
		m_value(value)
	{
	}

	string const &value() const { return m_value; }
};

class collection:
	public base
{
	typedef vector<base *> collection_type;
	collection_type m_values;
	virtual bool is_collection() { return true; }

public:
	typedef collection_type::size_type size_type;
	typedef collection_type::const_iterator const_iterator;
	typedef collection_type::const_reference const_reference;

	~collection() {
		for(auto i = m_values.begin(); i != m_values.end(); ++i) {
			delete *i;
		}
	}

	template <typename T>
	T *add(T *value) {
		m_values.push_back(value);
		return value;
	}

	size_type size() { return m_values.size(); }
	const_iterator begin() const { return m_values.begin(); }
	const_iterator end() const { return m_values.end(); }
	const_reference at(size_type i) const { return m_values.at(i); }
};

template <typename T>
unique_ptr<collection> parse_collection(T &in) {
	unique_ptr<collection> c(new collection);

	stack<collection *> s;
	s.push(c.get());

	for(string v; in >> v; ) {
		if(v == "[") {
			for(auto i = s.size(); i--; ) { cerr << '\t'; }
			cerr << "begin collection" << endl;
			s.push(s.top()->add(new collection));
		}
		else if(v == "]") {
			if(s.size() <= 1) {
				throw runtime_error("trying to close a collection which wasn't open");
			}

			s.pop();
			for(auto i = s.size(); i--; ) { cerr << '\t'; }
			cerr << "end collection" << endl;
		}
		else {
			for(auto i = s.size(); i--; ) { cerr << '\t'; }
			cerr << "new element " << v << endl;
			s.top()->add(new element(v));
		}
	}

	if(s.size() != 1) {
		throw runtime_error("missing closing of a collection");
	}

	return c;
}

void deep_print_elements(base *root, char const *message = "Iteration:") {
	cout << message;
	for(deep_iterator<base, element, collection> i(root); i; ++i) {
		cout << ' ' << i->value();
	}
	cout << endl;
}

int main() {
	try {
		element e("test");
		deep_print_elements(&e, "Single element:");

		auto c = parse_collection(cin);
		deep_print_elements(c.get(), "Collection from stdin:");
	}
	catch(runtime_error &e) {
		cerr << "ERROR: " << e.what() << endl;
	}
	return 0;
}
