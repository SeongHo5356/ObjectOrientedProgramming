#include <iostream>
using namespace std;

int main() {
	int A, B;
	cout << "Please enter two integer values :" << endl;
	cout << "A : ";
	cin >> A;
	cout << "B : ";
	cin >> B;
	swap(A, B);
	cout << "value of A is : " << A << endl;
	cout << "value of B is : " << B << endl;

}

