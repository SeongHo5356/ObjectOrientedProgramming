#include <iostream>

using namespace std;

int** buildTable(int n) {
	int** table = new int*[n];
	for (int i =0; i <n;i++)
		table[i] = new int[n];



	for (int k = 0; k < n; k++)
		for (int a = 0; a < n; a++)
			table[k][a] = 0;
	return table;
}

void make_identity_matrix(int** table, int n) {
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			if (i == k)
				table[i][k] = 1;


}
void printTable(int** table, int n) {
	cout << "Output :" << endl;
	int i = 0;
	while ( i < n) {
		int k = 0;
		while (k < n) {
			cout << table[i][k]<<'\t';
			k++;
		}
		cout << endl;
		i++;
	}
}

int main() {
	int n = 0;
	cout << "N을 입력하시오: ";
	cin >> n;
	if (n < 1) {
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int** table = buildTable(n);
	make_identity_matrix(table, n);
	printTable(table, n);
	
	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete table;

	return 0;
}