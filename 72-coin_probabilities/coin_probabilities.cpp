#include <iostream>
#include <vector>

using namespace std;

template <typename P, typename O>
void print_outcomes_probability(P const &prob, size_t i, size_t n, O &outcome, double p, double &sum) {
	if(i == n) {
		sum += p;

		cout << "Outcome:";
		for(i = 0; i < n; ++i) {
			cout << ' ' << (outcome[i] ? "H" : "T");
		}
		cout << ": " << (p * 100) << '%' << endl;

		return;
	}

	// Heads
	outcome[i] = true;
	print_outcomes_probability(prob, i + 1, n, outcome, p * prob[i], sum);

	// Tails
	outcome[i] = false;
	print_outcomes_probability(prob, i + 1, n, outcome, p * (1 - prob[i]), sum);
}

template <typename P>
void print_outcomes_probability(P const &prob, size_t n) {
	cout << "Probabilities:";
	for(size_t i = 0; i < n; ++i) {
		cout << ' ' << prob[i];
	}
	cout << endl;

	vector<bool> outcome(n);
	double sum = 0;
	print_outcomes_probability(prob, 0, n, outcome, 1, sum);

	cout << "Probabilities summation: " << (sum * 100) << '%' << endl;
}

int main() {
	vector<double> prob;

	for(double p; cin >> p; ) {
		if(p < 0 || p > 1) {
			cerr << "invalid probability: " << p << endl;
			return 1;
		}

		prob.push_back(p);
	}

	print_outcomes_probability(prob, prob.size());
}
