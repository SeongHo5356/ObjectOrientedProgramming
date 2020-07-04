#include <iostream>
using namespace std;

// this pointer : ���� ��ü �ڱ��ڽ��� �����ּҰ��� ������ �ִ� pointer
class Point {
private:
	int x;
	int y;
	static int numCreatedObj;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {
		numCreatedObj++;
	}

	int getX() const { return this->x; } //const method
	int getY() const { return this->y; } //const method
	void setXY(int x, int y) { this->x = x; this->y = y; }

	//pt2 + pt3 ==pt2.(pt3)
	Point operator+(const Point& pt) {
		Point result(this->x + pt.x, this->y + pt.y);
		return result;
	}
	//a = b =c
	Point operator= (const Point& pt) {

	}
	static int getNumCreatedObject() { return numCreatedObj; }
	//Point class�� print()�� ģ���� ����
	// -print()���� Point ��ü�� private ������ ��밡��
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint;
};

//static member ���� �ʱ�ȭ�� class  �ܺο� �ð���
int Point::numCreatedObj = 0;


//��ü�� �Ű����� ���� : pass by ref, const(optional)
//-const�� ���� �� �ݵ�� �Լ� �� const method�� ��밡��
//void print(const Point& pt) {
//	cout << pt.getX() << ", " << pt.getY() << endl;
//}

//friend �Լ��̱� ������ ������밡��
void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}


void print(int a) {
	cout << a << endl;
}

//Point operator+( const Point& pt1, const Point& pt2) {
//	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
//	return result;
//}

ostream& operator<<(ostream& cout,const Point& pt) {
	cout << pt.x << ", " << pt.y;
	return cout;
}

class SpyPoint {
public:
	void hack_all_info(const Point& pt) {
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "numCreatedObj: " << pt.numCreatedObj << endl;
		cout << endl;
	}

	

};

int main() {
	//pass by reference with const 
	Point pt1(10, 20);
	print(pt1);
	cout << pt1.getNumCreatedObject() << endl;
	cout << endl;
	
	//Point* pPt1 = &pt1;
	//Pointer �� �����Ҵ�
	Point* pPt = new Point(10, 20); //pointer : (.) ��� ->�� access
	cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	cout << pPt->getX() << ", " << pPt->getY() << endl;
	delete pPt; 
	cout << pt1.getNumCreatedObject() << endl;
	cout << endl;

	//������ �����ε�
	int a = 2 + 3; // +(2,3) -> int 
	Point pt2(10, 20), pt3(30, 40);
	Point pt4 = pt2 + pt3; // +(pt2, pt3) -> Point  or  pt2.+(pt3)
	cout << pt2 << endl; // <<(cout, pt2)->ostream 
	cout << pt3 << endl;
	cout << pt4 << endl;
	cout << pt1.getNumCreatedObject() << endl;
	cout << endl;
	
	SpyPoint spy;
	spy.hack_all_info(pt1);
	spy.hack_all_info(pt4); 
	return 0;
}