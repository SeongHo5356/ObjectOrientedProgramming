#include<iostream>
#include<string>
#include <vector>
#include <list>
#include <functional>
using namespace std;

// [closure]: �ܺκ����� �����Լ� ���η� ����
// [a] : �ܺ� ���� a�� pass by value�� �����Լ� ���η� ����
// [&a] : �ܺ� ���� a pass by reference�� �����Լ� ���η� ����
// [=] : ��� �ܺ� ������ pass by value �� �����Լ��� ����
// [&] : ��� �ܺ� ������ pass by reference�� �����Լ��� ����
// -������ �� : closure ����� ��� �Է� type �� �ݵ�� function ��ü
int evaluate2(function<int(int, int)>f, int x, int y) {
	return f(x, y);
}


int main() {
	int a = 0, b = 20;

	//[a]�� �ϸ� lambda �Լ� ���ο��� a ������ ����� �� �ֵ��� ���
	[&](int x) {
		cout << "x = " << x << endl;
		cout << "a = " << a << endl;
		a = 1000;
		b = 2000;
		//a = 1000;-->���� �����Ұ��� but [&a]�� ���� pass by reference �Ͻ� ���� ����
	}(10);

	cout << "a = " << a <<endl;
	cout << "b = " << b << endl;


	//�����Լ��� ��ü�� -->Ŭ������� ����� ����ϴ� ���� ��ü�μ� ���, Ŭ������ ������� �ʾƾ� �Լ��� ���� ��밡�� 
	cout << evaluate2([a](int x, int y) { return a + x + y; }, 20, 30) << endl;

	return 0;
}



/*
int sum(int x, int y) { return x + y; }
int mult(int x, int y) { return x * y; }
int evaluate(int(*f)(int x, int y), int x, int y) {
	return f(x, y);
}



int main() {
	//�̷��� sum, mult�� �׻� �޸𸮿� ���� -->��ȿ���� �޸𸮿
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;
	
	// lambda �Լ�: [](�Էº���)->����Ÿ��{����}
	// sum(): [](int x, int y)->int {return x + y;}
	cout << evaluate([](int x, int y)->int {return x + y; }, 20, 30) << endl;
	
	// simplified lambda�Լ� ǥ��: [](int x, int y){return x + y;}   ����Ÿ�� ��������
	// [](int x, int y){return x+y;}   int mult(int x, int y){return x *y;}���� �պκ� []�� ġȯ�ϸ� ��
	cout << evaluate([](int x, int y){return x + y; }, 20, 30) << endl;
	cout << evaluate([](int x, int y) { return x * y; }, 20, 30) << endl;

	// lambda�Լ� ����-ȣ�� ���ÿ�
	[](int x, int y) {cout << x << "," << y << endl; }(100, 200);

	//lambda �Լ��� local function
	//auto�� �ڷ��� ġȯ����
	//int(*f)(int, int) = [](int x, int y) {return x - y; };
	auto f = [](int x, int y) {return x - y; };
	cout << f(1000, 2000) << endl;
	
	return 0;
}
*/

/*
template<class Iter, class T>
int count_value(Iter iter_begin, Iter iter_end, T key_value) {
	int count = 0;
	for (Iter iter = iter_begin; iter != iter_end; iter++){
		if (*iter == key_value) {
			count++;
		}
	}
	
	return count;
}

int main() {
	vector<int> v{ 1,2,3,2,2,2};
	list<double>l{ 1.1,2.2,3.3,1.1,1.1 };
	string sAry[] = { "Apple","Bear","Carrot","Apple","Apple" };


	cout << count_value(begin(v), end(v), 2) << endl;
	cout << count_value(begin(l), end(l), 1.1) << endl;
	cout << count_value(begin(sAry), end(sAry), "Apple") << endl;

	struct Point {
		int x;
		int y;
		bool operator==(const Point& pt) {
			return (x == pt.x) && (y == pt.y);
		}
	};

	Point pts[] = { {1,2},{3,4},{5,6},{1,2},{1,2} };
	cout << count_value(begin(pts), end(pts), Point{1,2})<<endl;

	return 0;

}
*/


/*
int main() {
	Point<int> pt1(1, 2);
	Point<double> pt2(1.1, 2.2);
	Point<string> pt3("ABC", "XYZ");
	pt1.print();
	pt2.print();
	pt3.print();

}
*/