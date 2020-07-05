#include <iostream>

using namespace std;

int main() {
	string city, area, street, building;
	cout << "시 : ";
	cin >> city;
	cout << "구 :";
	cin >> area;
	cout << "로 : ";
	cin >> street;
	cout << "건물명 : ";
	cin >> building;

	cout << "집 주소 : " << city << area << street << building << endl;

	return 0;
}