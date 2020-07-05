#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0)
		:x(_x), y(_y) {};
	Point operator-(const Point& pt2) {
		Point result(x - pt2.x, y - pt2.y);
		return result;
	}
	Point operator*(const Point& pt2) {
		Point result(x * pt2.x, y * pt2.y);
		return result;
	}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	//이 함수 다시짜기
	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
};



int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "첫번째 좌표(x1, y1)을 입력하세요 : ";
	cin >> x1 >> y1;
	cout << "두번째 좌표(x2, y2)을 입력하세요 : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);

	//pP2->setPoint(x2, y2);----->>문제인 부분
	pP3 = new Point(); //x,y가 0으로 초기화

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	// pP3를 활용하여 거리값을 구함
	int Result = (*pP3).getX() + (*pP3).getY();
	cout << "두 좌표 사이의 길이는 " << sqrt(Result) <<"입니다. " << endl;
	return 0;
}