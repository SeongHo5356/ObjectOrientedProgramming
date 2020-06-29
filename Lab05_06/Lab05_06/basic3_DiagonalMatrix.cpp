#include<iostream>
#include<iomanip>

using namespace std;
int main() {
	
	int row=1, column=1;

	while (row <= 10) {
		column = 1;
		while (column <= 10) {
			int num ;
			num = 0;
			
			if (row == column)
				num = 1;
			cout << setw(4) << num;
			column++;
		}
		row++;
		cout << endl;
	}

}