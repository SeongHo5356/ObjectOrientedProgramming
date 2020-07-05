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
	cout << "기본값 출력 > " << str << endl;
	trans(&str);
	cout << "변환된 값 출력> " << str << endl;
	return 0;
}