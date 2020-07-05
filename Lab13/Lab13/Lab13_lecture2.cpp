#include<iostream>
#include<string>
#include <vector>
#include <list>
#include <functional>
using namespace std;

// [closure]: 외부변수를 람다함수 내부로 전달
// [a] : 외부 변수 a를 pass by value로 람다함수 내부로 전달
// [&a] : 외부 변수 a pass by reference로 람다함수 내부로 전달
// [=] : 모든 외부 변수를 pass by value 로 람다함수에 전달
// [&] : 모든 외부 변수를 pass by reference로 람다함수에 전달
// -주의할 점 : closure 사용할 경우 입력 type 은 반드시 function 객체
int evaluate2(function<int(int, int)>f, int x, int y) {
	return f(x, y);
}


int main() {
	int a = 0, b = 20;

	//[a]로 하면 lambda 함수 내부에서 a 변수를 사용할 수 있도록 허용
	[&](int x) {
		cout << "x = " << x << endl;
		cout << "a = " << a << endl;
		a = 1000;
		b = 2000;
		//a = 1000;-->본래 수정불가능 but [&a]와 같이 pass by reference 일시 수정 가능
	}(10);

	cout << "a = " << a <<endl;
	cout << "b = " << b << endl;


	//람다함수도 객체임 -->클로저라는 기능을 사용하는 순간 객체로서 기능, 클로저를 사용하진 않아야 함수와 같이 사용가능 
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
	//이럴때 sum, mult는 항상 메모리에 상주 -->비효율적 메모리운영
	cout << evaluate(&sum, 2, 3) << endl;
	cout << evaluate(&mult, 2, 3) << endl;
	
	// lambda 함수: [](입력변수)->리턴타입{본문}
	// sum(): [](int x, int y)->int {return x + y;}
	cout << evaluate([](int x, int y)->int {return x + y; }, 20, 30) << endl;
	
	// simplified lambda함수 표현: [](int x, int y){return x + y;}   리턴타입 생략가능
	// [](int x, int y){return x+y;}   int mult(int x, int y){return x *y;}에서 앞부분 []로 치환하면 끝
	cout << evaluate([](int x, int y){return x + y; }, 20, 30) << endl;
	cout << evaluate([](int x, int y) { return x * y; }, 20, 30) << endl;

	// lambda함수 생성-호출 동시에
	[](int x, int y) {cout << x << "," << y << endl; }(100, 200);

	//lambda 함수를 local function
	//auto로 자료형 치환가능
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