#include<iostream>
using namespace std;

int print_DOB(int x=1900, int y=1, int z=1) {
	if (x==1900 && y == 1 && z==1)
	{
		cout << "��������� " << x << "�� " << y << "�� " << z << "���Դϴ�." << endl;
	}
	else
	{
		cout << "year �Է� : " << x << endl;
		cout << "month �Է� : " << y << endl;
		cout << "day �Է� : " << z << endl;
		cout << "��������� " << x << "�� " << y << "�� " << z << "���Դϴ�." << endl;
	}
	
	return 0;
	
}
int main() {
	
	print_DOB();
	print_DOB(1988, 9, 8);
	return 0;
}