#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n, m;
	cout << "Enter n for n x m matrix : ";
	cin >> n;
	cout << "Enter m for n x m matrix : ";
	cin >> m;

	int row = 1;
	while (row <= n) {
		int col = 1;

		while (col <= m) {

			cout <<setw(4)<< row * col << setw(4);


			col++;
		}
	cout << endl;
	row++;
	}
	return 0;
}

