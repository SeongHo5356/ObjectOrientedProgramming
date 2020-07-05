#include <iostream>
#include <string>
#include<fstream>
#include<iomanip>
using namespace std;

int main() {
    int length, a, b, c;
    char ch;
    ifstream fin;
    ofstream fout;
    fin.open("Applied_5.txt");
    fout.open("Applied_5-2.txt");
    cout << "length = ";
    cin >> length;
    c = length;
    if (!fin) {
        cout << "Error : no such file exists" << endl;
        exit(100);
    }
    for (a = 1; fin; a++) {
        for (b = 1; b <= length; b++) {
            while (fin) {
                fin.get(ch);
                if (ch == '\n') b++, length++;
                else
                    fout << ch;
                break;
            }
        }
        b = 1;
        length = c;
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}