#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>//for_each, copy, transform
using namespace std;
// template 와 functional 을 사용하면 overriding 없이 동적바인딩 ?
// template 와 overloading
// tempalte : 공통점(함수 이름이 같다), 입력 매개 변수 갯수 고정
// overloading : 공통점(함수 이름이 같다), 입력 매개변수 갯수가 다를  수 있다
// 동적 바인딩 : 상속, 부모 class의 method를 자식클래스에서 재정의(함수의 이름, 입력 , 출력 데이터 타입 동일)


// pointer :주소값을 저장하는			'변수' : pt++  *pt, pt1 != pt2 , Pt3+=1
// iterator: element 위치를 저장하는	'객체' ite++, *iter, iter1 != iter2, iter+=2(x) , iter-=3(x)

int main() {
	vector<int> v1{ 1,2,3,4 };
	for (int elem : v1) {
		cout << elem << '\t'; //lambda [](int elem){cout << elem << '\t';}
	}
	cout << endl;

	// for_each(iter_begin, iter_end, lambda)
	// -특징 : lambda 함수의 return이 없음(void) 
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) {elem += 1; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	// for_each + closure (외부변수 사용) 
	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem += a; });
	for_each(begin(v1), end(v1), [](int& elem) {cout << elem << '\t'; });
	cout << endl << endl;

	vector<int> v2(v1.size());
	// v1 ={20 ,30. 40 ,50}
	// v2 = {0,0,0,0}
	//copy() : src의 element를 dst로 복사
	//copy(iter_begin(src), iter_end(src), iter_begin(dst));
	copy(begin(v1)+1, end(v1)-1, begin(v2)+2); // iter+2, iter-2가 용남되는 container, 용남되지 않는 containerr 거의 vector에서만 가능
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl << endl;

	// transform() : for_each + copy()
	// transform(iter_begin(src), iter_end(src), iter_begin(dst), lambda )
	// 특징 :lambda 함수의 return 이 존재한다(void 아님)
	transform(begin(v1), end(v1), begin(v2), [](int elem) {return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) {cout << elem * elem << '\t'; });
	cout << endl << endl;

	return 0;
}

/*
//[closure]: 외부 변수를 lambda 함수 내부로 전달
//[a] : 변수 a를 pass by value 로 lambda 함수에 전달
//[&a] : 변수 a를 pass by reference로 전달
//[=] : 모든 외부 변수를 pass by value 로 전달
//[&] : 모든 외부 변수를 pass by reference 로 전달
// - 사용시 주의사항 : closure를 사용할 경우, 함수 입력 type : funtion 객체
int evaluate2(function<int(int, int)> f, int x, int y) {
	return f(x, y);
}

int main() {

	int a = 10, b = 20;

	[&](int x) {
		cout << "x = " << x << endl;
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		a = 1000;
	}(10);

	cout << "a= " << a << endl;

	cout << evaluate2([](int x, int y) {return x + y; }, 2, 3);
	//	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3); ::lambda함수를 함수포인터에 집어넣을 수 없음
	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3);


	return 0;
}
*/