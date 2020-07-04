#include <iostream>
#include <vector>

using namespace std;

// private(class 내 접근가능), protected(class 내 접근가능), public(class 내/외 접근가능)
// - protected : 상속을 위해서 존재한는 type, base class에서 사용가능
// base type | inheritance type       | derived type
// ----------I------------------------I----------------
// private   | 상관 없음              | 접근 불가(base의 accessible한 method를 통해서 접근 가능)
// protected | 상관 없음              | private 
// public    | private/protected      | private
// public    | public                 | public


class Base {
public: //base type
	void print_base() { cout << "Base" << endl; }
	virtual void print() { cout << "Base::print()" << endl; }
	//function overloading
};

class Derived : public Base { //inheritance type
public: //derived type
	//void print_base(){cout<< "Base"<<endl;}
	void print_derived() {
		cout << "Derived" << endl;
		Base::print_base();
	}

	
	//function overriding 무조건 입력 파라미터가 동일해야함-->선언부 동일 단 동작이 바뀜
	void print() override { cout << "Derived::print()" << endl; }
	void print(int x) { ; }

};

int main() {
	Base base;
	Derived derived;
	base.print_base();
	derived.print_derived();
	derived.print_base();
	cout << endl;


	//함수 overriding : base class의 method 를 derived class에서 같은 이름으로 재정의
	//정적 바인딩(static binding): compile시 객체가 어떤  method를 호출할 지 미리 결정(변경 x)
	base.print();
	derived.print();
	cout << endl;

	//동적 바인딩(dynamic binding ): run-time 시 호출할 method들이 상황에 맞게 결정
	// -base class의 pointer에 derived class의 주소값 할당 가능
	// -핵심 키워드 : virtual, override 
	// -다형성을 구현 : single interface(base class의 pointer) 로 다양한 entities(derive class 객체) 를 사용 가능
	Base* pBase = &derived;
	pBase->print();
	pBase = &base;
	pBase->print();

	//다형성 응용
	vector<Base*> vec{ new Base, new Derived, new Base };
	pBase = new Derived;
	vec.push_back(pBase);

	cout << endl;
	for (auto& elem : vec) {
		elem->print();
	}

	for (auto& elem : vec) {
		delete elem;
	}

	return 0;
}
