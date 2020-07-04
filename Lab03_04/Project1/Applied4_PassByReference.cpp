#include<iostream>
using namespace std;

int swap_call_by_value(int x,int y) {
	int temp ;
	temp = y;
	y = x;
	x = temp;

	return 0;
}
int swap_call_by_reference(int& x,int& y) {
	int temp;
	temp = y;
	y = x;
	x = temp;

	return 0;
}
int get_data() {
	int num;
	cin >> num;
	return num;
}
int main() {
	int x, y;
	
	cout << "x 입력 : ";
	x = get_data();
	cout << "y 입력 : ";
	y = get_data();

	cout << "swap_call_by_value 함수 사용 전 " << endl;
	cout << "x = " << x << " y = " << y << endl;
	swap_call_by_value(x, y);

	cout << "swap_call_by_value 함수 사용 후 " << endl;
	cout << "x = " << x << " y = " << y << endl << endl;

	cout << "swap_call_by_reference 함수 사용 전 " << endl;
	cout << "x = " << x << " y = " << y << endl;
	swap_call_by_reference(x, y);

	cout << "swap_call_by_reference 함수 사용 후 " << endl;
	cout << "x = " << x << " y = " << y << endl;

	return 0;

}