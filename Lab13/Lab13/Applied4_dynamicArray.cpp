#include <iostream>
#include <stdlib.h>

using namespace std;


int main() {

	int size;
	//�������� ��, �� ���� �Է¹���
	cout << "Ȧ���� �Է����ּ��� : ";
	cin >> size;
	
	//�������� ���ؼ� size*size ������ �����迭�� ������
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