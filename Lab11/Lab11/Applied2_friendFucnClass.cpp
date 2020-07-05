#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
	string name;
	string id;
	int balance;
public:
	Account(string _name , string _id, int _balance)
		:name (_name), id(_id), balance(_balance){}

	string getName() const { return name; }
	string getId() const { return id; }
	int getBalance() const { return balance; }


	friend ostream& operator<<(ostream& cout, const Account& student);
	friend Account operator-(const Account& acnt1, const Account& acnt2);
	friend Account operator+(const Account& acnt1, const Account& acnt2);

};


ostream& operator<<(ostream& cout, const Account& student) {
	cout << "학번 : " << student.name << ", 이름 : " << student.id << ", 잔액 : " << student.balance << endl;
	return cout;
}
//acnt1의 계좌에서 돈이 모두 빠져나감
Account operator-(const Account& acnt1, const Account& acnt2) {
	Account result = acnt1;
	result.balance = 0;
	return result;
}

//acnt1의 계좌에 acnt2의 돈이들어옴
Account operator+(const Account& acnt1, const Account& acnt2) {
	Account result = acnt1;
	result.balance = acnt1.balance + acnt2.balance;
	return result;
}



int main() {
	Account acnt[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유민", "2019", 0),
		Account("박진배", "2013", 5000),
	};
	string idget;
	string idgive;
	vector<string> studentIds;
	for (int i = 0; i < 3; i++) {
		string a = acnt[i].getId();
		studentIds.push_back(a);
	}

	while (true) {
		cout << "돈을 보낼 학생의 학번을 입력하세요 : ";
		cin >> idgive;
		if (idgive == "종료") {
			cout << "종료합니다" << endl;
			for (int i = 0; i < 3; i++) {
				cout << acnt[i] ;
			}
			break;
		}

		cout << "돈을 받을 학생의 학번을입력하세요 :";
		cin >> idget;

		//보내고 받을 학생의 유무, 인덱스 추출
		bool CheckGiver = false;
		bool CheckGetter = false;
		int GiverIndex = -1;
		int GetterIndex = -1;
		for (int i = 0; i < 3; i++) {
			if (studentIds[i] == idgive) {
				CheckGiver = true;
				GiverIndex = i;
				break;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (studentIds[i] == idget){
					CheckGetter = true;
					GetterIndex = i;
					break;
			}	
		}

		while (true) {		
			//주는 사람과 받는 사람이 일치하는 경우
			if (idgive == idget) {
				cout << "송금하는 학생과 송금받는 학생이 일치합니다" << endl;
				break;
			}
			//주는 사람이나 받는 사람이 존재하지 않는경우
			else if (CheckGetter ==false || CheckGiver == false) {	
				cout << "보내는 학생 또는 받은 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
				break;
			}
			//위에서 학번이 존재하지 않는 경우는 거름-->GiverIndex != -1
			else if (acnt[GiverIndex].getBalance() == 0) {
				cout << "보내는 학생의 잔액기 부족합니다." << endl;
				break;
			}
			//이체 가능한 경우
			else {
				acnt[GetterIndex] = acnt[GetterIndex] + acnt[GiverIndex];
				acnt[GiverIndex] = acnt[GiverIndex] - acnt[GetterIndex];
				cout << "보낸 학생의 잔액 => " << acnt[GiverIndex] ;
				cout << "받은 학생의 잔액 => " << acnt[GetterIndex] ;
				break;
			}
			
		}
	}
}