#include<iostream>
using namespace std;

int main() {
	int input_num;
	int sum=0 ;
	int i = 1;
	cout << "number : ";
	cin >> input_num;
	
	do{
		if (i % 2 != 0 && i % 3 != 0)
			sum = sum + i;
			i++;
	} while (i <= input_num);
	cout << sum << endl;
}