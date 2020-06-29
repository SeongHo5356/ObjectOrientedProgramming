#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool is_prime(int num) {
	if (num < 2)
		return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

vector<int> primes(int lower, int upper) {
	vector<int> v;
	for (int i = lower; i <= upper; i++) {
		if (is_prime(i) == 1) {
			v.push_back(i);
		}
	}
	return v;
}

int main() {
	int lower = 10, upper = 100;
	vector<int> vec = primes(lower, upper);
	for (int elem : vec)
		cout << elem << setw(5);
	cout << endl;

	return 0;
}