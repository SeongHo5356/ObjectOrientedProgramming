#include <iostream>
#include <stdlib.h>

using namespace std;


int main() {

	int size;
	//마방진에 행, 열 수를 입력받음
	cout << "홀수를 입력해주세요 : ";
	cin >> size;
	
	//마방진을 위해서 size*size 이차원 동적배열을 생성함
	int** magicArray = new int* [size];
	for (int i = 0; i < size; i++) {
		magicArray[i] = new int[size];
	}
	int i = 0;
	int j = size / 2;
	int k;
	int nmg;

	for (k = 1; k <= size * size; k++) {
		magicArray[i][j] = k;
		nmg = k % size;
		if (nmg == 0) {
			i++;
		}
		else {
			if (i-- < 0) {
				i = size - 1;
			}if (j++ == size) {
				j = 0;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int m = 0; m < size; m++) {
			cout << magicArray[i][m] << '\t';
		}
		cout << endl;
	}



}