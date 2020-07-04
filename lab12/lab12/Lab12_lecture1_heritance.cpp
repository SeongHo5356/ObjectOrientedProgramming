#include <iostream>
#include <vector>

using namespace std;

// private(class �� ���ٰ���), protected(class �� ���ٰ���), public(class ��/�� ���ٰ���)
// - protected : ����� ���ؼ� �����Ѵ� type, base class���� ��밡��
// base type | inheritance type       | derived type
// ----------I------------------------I----------------
// private   | ��� ����              | ���� �Ұ�(base�� accessible�� method�� ���ؼ� ���� ����)
// protected | ��� ����              | private 
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

	
	//function overriding ������ �Է� �Ķ���Ͱ� �����ؾ���-->����� ���� �� ������ �ٲ�
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


	//�Լ� overriding : base class�� method �� derived class���� ���� �̸����� ������
	//���� ���ε�(static binding): compile�� ��ü�� �  method�� ȣ���� �� �̸� ����(���� x)
	base.print();
	derived.print();
	cout << endl;

	//���� ���ε�(dynamic binding ): run-time �� ȣ���� method���� ��Ȳ�� �°� ����
	// -base class�� pointer�� derived class�� �ּҰ� �Ҵ� ����
	// -�ٽ� Ű���� : virtual, override 
	// -�������� ���� : single interface(base class�� pointer) �� �پ��� entities(derive class ��ü) �� ��� ����
	Base* pBase = &derived;
	pBase->print();
	pBase = &base;
	pBase->print();

	//������ ����
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
