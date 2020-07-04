#include <iostream>

using namespace std;

float PI = 3.14;

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point; mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter : empty" << endl; }
	virtual void calcArea() { cout << "Area : empty" << endl; }

protected:
	int mPoint; //꼭지점의 개수
	double mLength; // 한 변의 길이
};

class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon::Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter()override { cout << "Perimeter : " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area : " << mLength * mLength << endl; }
};

class Triangle : public Polygon {
public:
	Triangle(int point, float length)
		:Polygon::Polygon(point, length) {}
	~Triangle() {}
	void calcPerimeter()override { cout << "Perimeter : " << mPoint * mLength << endl; }
	void calcArea() override { cout << "Area : " << mLength * mLength * sqrt(3) / 4 << endl; }
};

class Circle : public Polygon {
public:
	Circle(int point, float r)
		:Polygon::Polygon(point, r) {}
	~Circle() {}
	void calcPerimeter()override { cout << "Perimeter : " << 2 * PI * mLength << endl; }
	void calcArea() override { cout << "Area : " << PI * mLength * mLength << endl; }
};


int main() {

	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();


	return 0;
}