#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ofstream fout("Applied_3.txt");
	int row=0;
	while (row < 10) {
		int col = 0;
		while (col < 10) {
			fout << rand() % 101 << ' ';
			col++;
		}
		fout << endl;
		row++;
	}
	fout.close();

	return 0;
}