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
	int matrix[2][3]; //2X 3 정적 2차원 배열 
//	vector<vector<int>> v(2, vector<int>(3));

	int nRow = 2, nCol = 3;
	int** matrix2 = new int* [nRow]; //(int*)* int* 형 변수의 주소값
	for (int i = 0; i < nRow; i++)
		matrix2[i] = new int[nCol];

	//사용;
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


//정적 배열(static array) : 프로그램 실행 중(run-time) 크기가 고정
//동적 배열(dynamic array) :  프로그램 실행 중 할당/해제가 가능 
int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 }; //정적 배열 
	
	int length;
	cout << "Enter the length : ";
	cin >> length;
	int* list2 = new int[length]; //동적 배열 1. 메모리공간 할당 2. 시작 주소값 반화 3. 

	int* begin = list2;
	int* end = list2 + length;

	get_data(begin, end);
	print(begin, end);

	delete[] list2; //동적배열 핟당 해제
	
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

//문자열(const char* s = "phrase")
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