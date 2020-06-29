#include <iostream>
#include <cstdlib>

using namespace std;

bool DuplCheck(int* list, int size) {
	for (int i = 0; i < size; i++)
		for (int k = i + 1; k < size; k++)
			if (list[i] == list[k])
				return true;

	return false;
}


void printArray(int* list, int size) {
	cout << "[Array]" << endl;
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
}

int* AlloArray(int*& list, int& size, int& number) {
	list = new int[size];
	for (int i = 0; i < size; i++)
		list[i] = rand() % size + 1;
	return list;
}


int main() {

	while (true) {
		int number, size;
		cout << "Please enter a number : ";
		cin >> number;
		if (number == 0) {
			cout << "Wrong number !!!";
			break;
		}

		cout << "Size of random array : ";
		cin >> size;

		int* list = new int[size];

		AlloArray(list, size, number);

		printArray(list, size);

		if (DuplCheck(list, size) == true) {
			cout << "Duplicates found" << endl;
		}
		else if (DuplCheck(list, size) == false)
		{
			cout << "Duplicates not found" << endl;

		}
		cout << endl;
	}

	return 0;
}