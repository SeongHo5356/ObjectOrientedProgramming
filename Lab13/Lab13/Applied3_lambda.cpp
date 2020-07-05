
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
        cout << "문자열 하나를 입력해보세요 : ";
        cin >> s;
        if (s == "Q" || s == "q") {
            break;
        }
        cout << "입력하신 문자열의 역순 : " << f(s) << endl;
        if (s == f(s)) {
            cout << "이 문자는 회문입니다.\n";
        }
        else {
            cout << "이 문자는 회문이 아닙니다.\n";
        }
        cout << endl;
  
    }
}