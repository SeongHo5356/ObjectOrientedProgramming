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
    string data = "사랑,프로그래머,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
    string keyword;
    cout << "키워드 : ";
    cin >> keyword;

    cout << "검색 결과: ";
    search(data.substr(0, 4), keyword, "사랑");
    search(data.substr(5, 10), keyword, "프로그래머");
    search(data.substr(16, 4), keyword, "의자");
    search(data.substr(21, 10), keyword, "사랑의바보");
    search(data.substr(32, 6), keyword, "영통역");
    search(data.substr(39, 10), keyword, "천년의사랑");
    search(data.substr(50, 6), keyword, "냉장고");
    search(data.substr(57, 8), keyword, "객체지향");

}