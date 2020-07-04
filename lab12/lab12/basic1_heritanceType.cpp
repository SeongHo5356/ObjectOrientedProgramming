#include <iostream>
#include <string>

using namespace std;

class Base {
protected: // Base type
	void print_base() {
		cout << "Base" << endl;
	}

};
// Base type | 상속 type         | Derived type
// private   | 상관없음		     | 접근 불가( Base함수로 접근)
// protected | 상관없음			 | private
// public    | private/protected | private
// public    | public			 | public

class Derived : private Base {
public:
	void print_derived() {
		Base::print_base();
		cout << "Derived" << endl;
	}
};

int main() {
	Base base;
	Derived derived;

	derived.print_derived();

	return 0;
}

