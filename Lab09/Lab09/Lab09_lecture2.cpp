#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
*/


/*
using namespace std;
void print(int** m, int nRow, int nCol) {
	for (int row = 0; row < nRow; row++) {
		for (int col = 0; col < nCol; col++)
			cout << setw(4) << m[row][col];
	}
	cout << endl;
}


int main() {
	int matrix[2][3]; //2X 3 ���� 2���� �迭 
//	vector<vector<int>> v(2, vector<int>(3));

	int nRow = 2, nCol = 3;
	int** matrix2 = new int* [nRow]; //(int*)* int* �� ������ �ּҰ�
	for (int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol];

	//���;
	matrix2[0][1] = 1;
	matrix2[0][2] = 2;
	matrix2[0][3] = 3;
	matrix2[1][1] = 4;
	matrix2[1][2] = 5;
	matrix2[1][3] = 6;

	print(matrix2, nRow, nCol);

	for (int i = 0; i < nRow; i++)
		delete[] matrix2[i];
	delete[] matrix2;

	return 0;

}
*/

/*
void get_data(int* begin, int* end) {
	cout << "Enter the element : ";
	for (int* curr = begin; curr != end; curr++)
		cin >> *curr;

}
void print(int* begin, int* end) {
	cout << "print output :";
	for (int* curr = begin; curr != end; curr++)
		cout << setw(4) << *curr;
	cout << endl;
}


//���� �迭(static array) : ���α׷� ���� ��(run-time) ũ�Ⱑ ����
//���� �迭(dynamic array) :  ���α׷� ���� �� �Ҵ�/������ ���� 
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 }; //���� �迭 
	
	int length;
	cout << "Enter the length : ";
	cin >> length;
	int* list2 = new int[length]; //���� �迭 1. �޸𸮰��� �Ҵ� 2. ���� �ּҰ� ��ȭ 3. 

	int* begin = list2;
	int* end = list2 + length;

	get_data(begin, end);
	print(begin, end);

	delete[] list2; //�����迭 ���� ����
	
	return 0;
}
*/

/*
bool find_char(const char* s, char ch) {
	while (*s != '\0') {
		if (*s == ch)
			return true;
		s++;
	}
	return false;
}

//���ڿ�(const char* s = "phrase")
//s = {'p' , 'h', 'r', 'a' , 's', 'e', '\0'}//NULL = '\0'
int main() {
	const char* phrase = "this is a phrase";
	
	for (char ch = 'a'; ch <= 'z'; ch++) {
		cout << ch << " is ";
		if (!find_char(phrase, ch))
			cout << "Not";
		
		cout << " in (" << phrase << ")" << endl;
	}
}
*/