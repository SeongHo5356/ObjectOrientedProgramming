
#include <iostream>
#include <string>
using namespace std;


int main() {
    auto f = [](string str)->string {
        int temp;
        for (int i = 0; i < str.length() / 2; i++) {
            temp = str[i];
            str[i] = str[str.length() - i - 1];
            str[str.length() - i - 1] = temp;
        }
        return str;
    };

    string str;
    while (true) {
        string s;
        cout << "���ڿ� �ϳ��� �Է��غ����� : ";
        cin >> s;
        if (s == "Q" || s == "q") {
            break;
        }
        cout << "�Է��Ͻ� ���ڿ��� ���� : " << f(s) << endl;
        if (s == f(s)) {
            cout << "�� ���ڴ� ȸ���Դϴ�.\n";
        }
        else {
            cout << "�� ���ڴ� ȸ���� �ƴմϴ�.\n";
        }
        cout << endl;
  
    }
}