#include <iostream>
#include <string>
using namespace std;

void trans(string* a) {
	string ChanVal;
	cout << "input> ";
	getline(cin, ChanVal);
	*a = ChanVal;

}

int main() {
	string str = "This is default value";
	cout << "�⺻�� ��� > " << str << endl;
	trans(&str);
	cout << "��ȯ�� �� ���> " << str << endl;
	return 0;
}