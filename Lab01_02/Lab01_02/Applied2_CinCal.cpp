#include <iostream>
using namespace std;

int main() {
	int A, B,add,sub,mult,mod;
	float div;
	cout << "Please enter two integer values : ";
	cin >> A >> B;
	add = A + B;
	sub = A - B;
	mult = A * B;
	div = float(A) / float(B);
	mod = A % B;
	cout << A<< " + " <<B<< " = " << add << endl;
	cout << A<< " - " <<B<< " = " << sub << endl;
	cout << A<< " * " <<B<< " = " << mult << endl;
	cout << A<< " / " <<B<< " = " << div << endl;
	cout << A<< " % " <<B<< " = " << mod << endl;
}
