#include <string>
#include <iostream>

using namespace std;

class Account {
//private: //멤버변수
	string name;
	string id;
	double balance;
public://멤버 함수 (method)
	Account(string _name = "", string _id = "", double _balance = 0)
		:name(_name), id(_id), balance(_balance) {
		if (balance < 0)
			balance = 0;
	}
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt) {
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print() {
		cout << name << ", " << id << ", " << balance << endl;
	}
};

int main() {
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();

	int depo;
	cout << endl<<"예금할 금액을 입력하세요 : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();

	int wdrw;
	cout <<endl<< "출금할 금액을 입력하세요 : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "잔액이 부족합니다." << endl;
	ac1.print();
	return 0;
}