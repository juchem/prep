#include <unordered_set>
#include <iostream>

using namespace std;

class word_counter {
	unordered_set<char> letter;
	size_t lbound;

	bool const isLetter(char c) const {
		return letter.find(c) != letter.end();
	}

public:
	word_counter(
		size_t lbound = 0,
		char const *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"
	):
		lbound(lbound)
	{
		while(*letters) {
			letter.insert(*letters++);
		}
	}

	size_t operator()(char const *text) const {
		size_t words = 0;
		decltype(lbound) len = 0;

		for(; *text; ++text) {
			if(isLetter(*text)) ++len;
			else {
				if(len > lbound) ++words;

				len = 0;
			}
		}

		if(len > lbound) ++words;

		return words;
	}
};

int main(int argc, char **argv) {
	if(argc <= 2) {
		cout << "Usage: " << argv[0] << " lower_bound text1 [text2 [... [textN]]]" << endl;
		return 1;
	}

	int lbound = atoi(argv[1]);

	if(lbound < 0) {
		cout << "invalid lower bound" << endl;
		return 2;
	}

	word_counter count(static_cast<size_t>(lbound));

	for(int i = 2; i < argc; ++i) {
		cout << argv[i] << endl
			<< "\twords: " << count(argv[i]) << endl;
	}

	return 0;
}
