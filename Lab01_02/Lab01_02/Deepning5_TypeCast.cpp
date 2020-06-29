#include <iostream>
using namespace std;


int main() {
	double A, B;
	cout << "Please enter Fahrenheit value : ";
	cin >> A;
	B = 5.0 / 9.0 * (A - 32);
	cout << "Celsius value is : " << B << endl;
}

