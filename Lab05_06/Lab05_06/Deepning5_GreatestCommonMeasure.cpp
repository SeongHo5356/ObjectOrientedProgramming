#include <iostream>
using namespace std;

int gcd(int x, int y) {
	int z;
	if (x < y) {
		z = x;
		x = y;
		y = z;
	}
	int rest;
	while (y != 0) {
		rest = x % y;
		x = y;
		y = rest;
	}
	return x;
}

int main() {
	int x, y;
	int result;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;

	result = gcd(x, y);
	cout << result;
	
	return 0;

}