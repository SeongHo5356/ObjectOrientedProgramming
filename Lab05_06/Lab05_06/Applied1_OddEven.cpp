#include <iostream>
using namespace std;

int main() {
	int input_num;
	int num = 1;
	while (num <= 5) {


		cout << num << "��° ���� : ";
		cin >> input_num;
		if (input_num % 2 == 0)
			cout << input_num << "��(��) ¦���Դϴ�." << endl;
		else
			cout << input_num << "��(��) Ȧ���Դϴ�." << endl;

		num += 1;
	}
	return 0;
}