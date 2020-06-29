#include<iostream>
using namespace std;
int mymul(int a, int b) {
	return a * b;
}

int GuGuDan(int input_num) {
	for (int i = 1; i <= 9; i++)
		cout << input_num << " * " << i << " = " << mymul(input_num, i) << endl;
	
	cout << ' '<<endl;
	return 0;
}


int main() {
	int input_num;


	do {	
		cout << "단 수를 입력하세요 : ";
		cin >> input_num;


		if (input_num != -1) {

			if (input_num >= 1 && input_num < 10)
				GuGuDan(input_num);
				
			else if (input_num >= 10 || input_num < 0)
				cout << "1 부터 9까지의 정수를 입력해주세요." << endl<<endl;
		}
	} while (input_num != -1);

	if (input_num == -1)
			cout << "종료합니다" << endl;


}
