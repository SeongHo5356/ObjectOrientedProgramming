#include <iostream>
#include <string>

using namespace std;

class Point {
private://클래서 내부에서만 사용가능
    int x; int y;//멤버 변수

public : //클래스 안팎으로 사용가능
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    void setXY(int _x, int _y) {
        x = _x;
        y = _y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }

    void print() {
        cout << x << ", " << y << endl;
    }

};

int main() {
    Point pt1(1, 2), pt2(3, 4);
    pt1.setXY(10, 20);
    pt1.print();
    pt2.print();

    cout << pt1.getX() << endl;
    cout << pt2.getY() << endl;
    return 0;
}