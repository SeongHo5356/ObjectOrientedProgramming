#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
void search(string a, string keyword, string word) {
    if (a.find(keyword) != 4294967295) {
        cout << word << '\t';
    }
}
int main() {
    string data = "���,���α׷���,����,����ǹٺ�,���뿪,õ���ǻ��,�����,��ü����";
    string keyword;
    cout << "Ű���� : ";
    cin >> keyword;

    cout << "�˻� ���: ";
    search(data.substr(0, 4), keyword, "���");
    search(data.substr(5, 10), keyword, "���α׷���");
    search(data.substr(16, 4), keyword, "����");
    search(data.substr(21, 10), keyword, "����ǹٺ�");
    search(data.substr(32, 6), keyword, "���뿪");
    search(data.substr(39, 10), keyword, "õ���ǻ��");
    search(data.substr(50, 6), keyword, "�����");
    search(data.substr(57, 8), keyword, "��ü����");

}