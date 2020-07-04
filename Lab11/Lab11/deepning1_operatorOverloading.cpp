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
	//�� �Լ� �ٽ�¥��
	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
};



int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;
	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);

	//pP2->setPoint(x2, y2);----->>������ �κ�
	pP3 = new Point(); //x,y�� 0���� �ʱ�ȭ

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

	// pP3�� Ȱ���Ͽ� �Ÿ����� ����
	int Result = (*pP3).getX() + (*pP3).getY();
	cout << "�� ��ǥ ������ ���̴� " << sqrt(Result) <<"�Դϴ�. " << endl;
	return 0;
}