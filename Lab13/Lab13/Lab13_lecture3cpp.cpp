#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>//for_each, copy, transform
using namespace std;
// template �� functional �� ����ϸ� overriding ���� �������ε� ?
// template �� overloading
// tempalte : ������(�Լ� �̸��� ����), �Է� �Ű� ���� ���� ����
// overloading : ������(�Լ� �̸��� ����), �Է� �Ű����� ������ �ٸ�  �� �ִ�
// ���� ���ε� : ���, �θ� class�� method�� �ڽ�Ŭ�������� ������(�Լ��� �̸�, �Է� , ��� ������ Ÿ�� ����)


// pointer :�ּҰ��� �����ϴ�			'����' : pt++  *pt, pt1 != pt2 , Pt3+=1
// iterator: element ��ġ�� �����ϴ�	'��ü' ite++, *iter, iter1 != iter2, iter+=2(x) , iter-=3(x)

int main() {
	vector<int> v1{ 1,2,3,4 };
	for (int elem : v1) {
		cout << elem << '\t'; //lambda [](int elem){cout << elem << '\t';}
	}
	cout << endl;

	// for_each(iter_begin, iter_end, lambda)
	// -Ư¡ : lambda �Լ��� return�� ����(void) 
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [](int& elem) {elem += 1; });
	for_each(begin(v1), end(v1), [](int elem) {cout << elem << '\t'; });
	cout << endl;

	// for_each + closure (�ܺκ��� ���) 
	int a = 10;
	for_each(begin(v1), end(v1), [a](int& elem) {elem += a; });
	for_each(begin(v1), end(v1), [](int& elem) {cout << elem << '\t'; });
	cout << endl << endl;

	vector<int> v2(v1.size());
	// v1 ={20 ,30. 40 ,50}
	// v2 = {0,0,0,0}
	//copy() : src�� element�� dst�� ����
	//copy(iter_begin(src), iter_end(src), iter_begin(dst));
	copy(begin(v1)+1, end(v1)-1, begin(v2)+2); // iter+2, iter-2�� �볲�Ǵ� container, �볲���� �ʴ� containerr ���� vector������ ����
	for_each(begin(v2), end(v2), [](int elem) {cout << elem << '\t'; });
	cout << endl << endl;

	// transform() : for_each + copy()
	// transform(iter_begin(src), iter_end(src), iter_begin(dst), lambda )
	// Ư¡ :lambda �Լ��� return �� �����Ѵ�(void �ƴ�)
	transform(begin(v1), end(v1), begin(v2), [](int elem) {return elem * elem; });
	for_each(begin(v2), end(v2), [](int elem) {cout << elem * elem << '\t'; });
	cout << endl << endl;

	return 0;
}

/*
//[closure]: �ܺ� ������ lambda �Լ� ���η� ����
//[a] : ���� a�� pass by value �� lambda �Լ��� ����
//[&a] : ���� a�� pass by reference�� ����
//[=] : ��� �ܺ� ������ pass by value �� ����
//[&] : ��� �ܺ� ������ pass by reference �� ����
// - ���� ���ǻ��� : closure�� ����� ���, �Լ� �Է� type : funtion ��ü
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
	//	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3); ::lambda�Լ��� �Լ������Ϳ� ������� �� ����
	cout << evaluate2([a](int x, int y) {return a + x + y; }, 2, 3);


	return 0;
}
*/