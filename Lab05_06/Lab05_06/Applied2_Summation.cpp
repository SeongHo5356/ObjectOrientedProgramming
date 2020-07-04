#include <iostream>
using namespace std;


int main() {
	int i = 1;
	int total_num = 0;
	int input_num;
	cout << "number : ";
	cin >> input_num;
	while (i <= input_num) {
		total_num = total_num + i;
		i = i + 1;
	}
	
	cout << "Sum of 1 to "<<input_num<<" = "<<total_num << endl;

}