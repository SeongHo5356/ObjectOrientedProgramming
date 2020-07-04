#include<iostream>
using namespace std;

int print_DOB(int x=1900, int y=1, int z=1) {
	if (x==1900 && y == 1 && z==1)
	{
		cout << "생년월일은 " << x << "년 " << y << "월 " << z << "일입니다." << endl;
	}
	else
	{
		cout << "year 입력 : " << x << endl;
		cout << "month 입력 : " << y << endl;
		cout << "day 입력 : " << z << endl;
		cout << "생년월일은 " << x << "년 " << y << "월 " << z << "일입니다." << endl;
	}
	
	return 0;
	
}
int main() {
	
	print_DOB();
	print_DOB(1988, 9, 8);
	return 0;
}