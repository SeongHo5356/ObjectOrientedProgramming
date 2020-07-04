#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;
    static int numCreatedObjects;
public:
    //�⺻ ������
    Point() : x(0), y(0) {
        numCreatedObjects++;
    }
    //�Է��Ķ���͸� ���� ������
    Point(int _x, int _y) :x(_x), y(_y) {
        numCreatedObjects++;
    }
    ~Point() {
        cout << "Destructed..." << endl;
    }
    void setXY(int _x, int _y) {
        //this ->�� �̿���  �ʱ�ȭ
        this->x = _x, this->y = _y;
    }
    int getX() const { return x; }
    int getY() const { return y; }

    // *this + pt2 ->
    Point operator+(const Point& p12) { //& �� �ִ�~
        Point result(this->x + p12.getX(), this->y + p12.getY());
        return result;
    }

    //operator overloading(������ �����ε�)
    Point& operator=(Point& pt) {
        this -> x = pt.x;
        this -> y = pt.y;
        Point result(x, y);
        return result;
    }

    static int getNumCreatedObject() { return numCreatedObjects; }
    friend void print(const Point& pt);
    friend ostream& operator<<(ostream& cout, const Point& pt);
    friend class SpyPoint;
};

//static �ɹ� ���� �ʱ�ȭ (numCreatedObjects)
int Point::numCreatedObjects = 0;

//��ü call by reference �� : const�� �Լ� �Է½� const method �� �Լ����� ��밡��
//const : ��ü ������ member data�� ���(������ �ʴ´�)

void print(const Point& pt) { // �޼��� �ƴϰ� �Լ�ó�� ��� �����ϴ�.
    cout << pt.x << ", " << pt.y << endl;
}

ostream& operator<<(ostream& cout, const Point& pt) {
    cout << pt.getX() << ", " << pt.getY();
    return cout;
}

class SpyPoint {
public:
    void hack_all_info(const Point& pt) {
        cout << "Hacked by SpyPoint" << endl;
        cout << "x: " << pt.x << endl; 
        cout << "y: " << pt.y << endl;
        cout << "numCreatedObj.: " << Point::getNumCreatedObject() << endl;
    }
};

int main() {
    Point pt1(1, 2);
    cout << "pt1 : ";
    print(pt1);
    cout << endl;
    // ������
    Point* pPt1 = &pt1;
    // pPt1�� ���� ���� getX, getY�� ȣ���Ͽ� ���
    cout << "pt1 : " << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
    cout << "pt1 : " << pPt1->getX() << ", " << pPt1->getY() << endl;
    cout << endl;
    //�������� Point* pPt2�Ҵ��Ͽ� 10,20���� �� ->����Ͽ� ���(pt1 ��� ����)
    auto* pPt2 = new Point(10, 20);
    cout << "pt2 : " << pPt2->getX() << ", " << pPt2->getY() << endl;
    cout << endl;

    //pPt1, pPt2�� �޸� ����
    pPt1 -> ~Point();
    delete pPt2;
    cout << "pt1 NumCreatedObject : ";
    cout << pt1.getNumCreatedObject() << endl;
    
    //������ �����ε�
    //pt4 = pt2, pt3�� ���ϱ�
    Point pt2(10, 20);
    Point pt3(30, 40);
    Point pt4 = pt2 + pt3;

    cout << "pt2 : ";
    cout << pt2 << endl;
    cout << "pt3 : ";
    cout << pt3 << endl;
    cout << "pt4 : ";
    cout << pt4 << endl;
    cout << "pt1 NumCreatedObject : ";
    cout << pt1.getNumCreatedObject() << endl << endl;

    // object array
    int size = 5;
    Point* ptAry = new Point[size];
    cout << "pt2 NumCreatedObject : ";
    cout << pt2.getNumCreatedObject() << endl;
    cout << endl;
    // ptAry �޸� ����
    delete[] ptAry;
    cout << endl;
    // friend class
    SpyPoint spy;
    cout << "pt1 info" << endl;
    spy.hack_all_info(pt1);
    cout << endl;
    cout << "pt4 info" << endl;
    spy.hack_all_info(pt4);
    return 0;
}