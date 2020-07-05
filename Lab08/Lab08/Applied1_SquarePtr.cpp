#include <iostream>

using namespace std;

void sqn( int* a ) {
	*a = (*a) * (*a);

}

int main() {
	int input_num;
	cout << "input> ";
	cin >> input_num;

	sqn(&input_num);

	cout << "Á¦°ö°ª> ";
	cout << input_num;

}