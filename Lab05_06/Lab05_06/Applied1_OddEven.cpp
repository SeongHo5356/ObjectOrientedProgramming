#include <iostream>
using namespace std;

int main() {
	int input_num;
	int num = 1;
	while (num <= 5) {


		cout << num << "번째 정수 : ";
		cin >> input_num;
		if (input_num % 2 == 0)
			cout << input_num << "은(는) 짝수입니다." << endl;
		else
			cout << input_num << "은(는) 홀수입니다." << endl;

		num += 1;
	}
	return 0;
}