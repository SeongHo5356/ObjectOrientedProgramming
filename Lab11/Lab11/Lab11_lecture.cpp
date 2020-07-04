#include <iostream>
using namespace std;

// this pointer : 현재 객체 자기자신의 시작주소값을 가지고 있는 pointer
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
	//Point class는 print()를 친구로 인정
	// -print()에서 Point 객체의 private 데이터 사용가능
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint;
};

//static member 변수 초기화는 class  외부에 ㅓ가능
int Point::numCreatedObj = 0;


//객체의 매개변수 전달 : pass by ref, const(optional)
//-const로 전달 시 반드시 함수 내 const method만 사용가능
//void print(const Point& pt) {
//	cout << pt.getX() << ", " << pt.getY() << endl;
//}

//friend 함수이기 떄문에 직접사용가능
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
	//Pointer 와 동적할당
	Point* pPt = new Point(10, 20); //pointer : (.) 대신 ->로 access
	cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	cout << pPt->getX() << ", " << pPt->getY() << endl;
	delete pPt; 
	cout << pt1.getNumCreatedObject() << endl;
	cout << endl;

	//연산자 오버로딩
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