#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;


//container-generic fuction
//	-template와 iterator의 활용으로 만들 수 있음
template<class Iter>
void print(Iter iter_begin, Iter iter_end) {
	for (Iter iter = iter_begin; iter != iter_end; iter++) {
		cout << *iter << '\t';
	}
	cout << endl;
}

int main() {
	vector<int> v{ 1, 2, 3 };
	list<double> l{ 1.1, 2.2, 3.3 };
	string sAry[] = { "Apple", "Bear", "Carrot" };
	
	
	print(begin(v), end(v));
	print(begin(l), end(l));
	print(begin(sAry), end(sAry));

	return 0;
}


/*
// itertor: pointer like object(container의 element 위치를 저장)
// - 주요 함수 : begin(v), end(v)
// - 주요 연산자 : iter++, *iter, iter1 != iter2
// - 추가 연산자 : iter--, iter += 5, iter -= 5 (container에 따라 overloading된 경우도 있음)


int main() {
	vector <int> v{ 1, 2, 3 };
	vector<int>::iterator iter_begin = v.begin();
	auto iter_end = v.end();
	for (auto iter = iter_begin; iter != iter_end; iter++) {
		cout << *iter << '\t';
	}
	cout << endl;


	return 0;
}


//pointer 
int main() {
	int ary[] = { 1,2,3 };
	int* begin = ary;
	int* end = ary + 3;
	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	
	cout << endl;
	return 0;
}

*/

/*
// class template
template <class T>
class Point {
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX() const;
	T getY() const;
	void print() const;
};
template<class T>
Point<T>::Point(T _x, T _y) :x(_x), y(_y) {}

template<class T>
void Point<T>::setXY(T _x, T _y) { x = _x; y = _y; }

template<class T>
T Point<T>::getX() const { return x; }

template<class T>
T Point<T>::getY() const { return y; }

template<class T>
void Point<T>::print() const { cout << x << "," << y << endl; }

int main() {
	Point<int>pt1(1, 2);
	Point<double>pt2(1.1, 2.2);
	Point<string>pt3("ABC", "XYZ");
	pt1.print();
	pt2.print();
	pt3.print();
	return 0;
}
*/

/*
//generic function
//다양한 데이터타입을 입력으로 받을 수 있음
template<class T, class V>//<typename T>
//template를 쓸시 무조건 한번 이상식 사용 해야함, 아니면 오류가 남

bool less_than(const T& a,const V& b) {
	return a < b;
}

template <class T>
T sum(const vector<T>& v) {
	T result = 0;
	for (T elem : v) {
		result += elem;
	}
	return result;
}


int main() {
	cout << less_than(2, 3) << endl;
	cout << less_than(2.2, 2.7) << endl;
//	cout << less_than(2, 2.7) << endl; (T는 하나의 type만 받을 수 있음)
	cout << less_than(2, 2.7) << endl; //입력 파라미터를 T,V로 바꿔줘서 굳이 동일한 타입일 필요를 없애줌
	string s1 = "ABC";
	string s2 = "X";
	cout << less_than(s1, s2) << endl;

	vector<int> v1{ 1,2,3 };
	vector<double> v2{ 1.1,2.2,3.3 };
	cout << sum(v1) << endl;
	cout << sum(v2) << endl;

	return 0;
}*/