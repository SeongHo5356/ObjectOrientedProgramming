#include<iostream>
using namespace std;

void applePrice(int a = 1000) {
	cout << "Price of an apple is " << a << endl;
}
// default augment Áß¿ä!
int main() {
	applePrice(1500);
	applePrice(500);
	applePrice();
	applePrice();
	return 0;
}