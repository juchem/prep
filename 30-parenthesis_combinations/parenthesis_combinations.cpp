#include <iostream>
#include <string>

#include <cstdlib>
#include <cassert>

using namespace std;

template <
	typename fn_output,
	typename char_type = char,
	char_type opening = '(',
	char_type closing = ')'
>
void generate_balanced_parenthesis(fn_output out, size_t pairs) {
	struct generator {
		fn_output out;
		string buffer;
		size_t pairs;
		size_t maxDepth;

		void generate(size_t open = 0, size_t closed = 0, size_t position = 0, size_t depth = 0) {
			assert(open <= pairs);
			assert(closed <= open);

			if(depth > maxDepth) {
				maxDepth = depth;
			}

			if(position == buffer.size()) {
				out(buffer, maxDepth);
				return;
			}

			if(open < pairs) {
				assert(depth < pairs);
				size_t prev = maxDepth;

				buffer[position] = opening;
				generate(open + 1, closed, position + 1, depth + 1);

				if(prev < maxDepth) {
					maxDepth = prev;
				}
			}

			if(closed < open) {
				assert(depth);

				buffer[position] = closing;
				generate(open, closed + 1, position + 1, depth - 1);
			}
		}
	};

	generator g{out, string(pairs * 2, char_type(0)), pairs, 0};
	g.generate();
}

int main(int argc, char **argv) {
	auto out = [](string const &s, size_t maxDepth) {
		cout << s << ", maximum depth = " << maxDepth << endl;
	};

	generate_balanced_parenthesis<decltype(out)>(
		out, argc > 1 ? atoi(argv[1]) : 3
	);

	return 0;
}
