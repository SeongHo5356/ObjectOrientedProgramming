#include <iostream>
using namespace std;
int square(int a);

int main() {
	int x;
	x = 5;
	cout<< square(x) <<endl;
}

int square(int a) {
	int t;
	t = a * a;
	return t;
}