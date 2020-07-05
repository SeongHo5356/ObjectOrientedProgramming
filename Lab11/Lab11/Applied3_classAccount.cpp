#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
	string Id;
	string name;
	int balance;
	static int Sumbalance;
public:
	Account(string _Id = "", string _name = "" ,int _balance = 0 )
		:Id(_Id), name(_name), balance(_balance ){};
	void setId(string _Id) { Id = _Id; }
	void setName(string _name) { name = _name; }
	void setBalance(int _balance) { balance = _balance; }
	~Account() {
		Sumbalance += balance;
	}
	int getSumbalance() { return Sumbalance; }

};
int Account :: Sumbalance = 0;

int main() {
	int DesignateNum = 0;
	cout << "총 학생 수 입력 : " ;
	cin >> DesignateNum;
	Account* Student = new Account[DesignateNum];
	vector<string> StuId ;
	string Id;
	string name;
	int balance;
	int studentNum = 1;
	while (studentNum <= DesignateNum) {
		cout << studentNum << "번째 학생 계좌 입력 : 학번 : ";
		cin >> Id;
		cout << endl;
		//중복된 학번이 있는 지 검사
		bool CheckInIt = false;
		if (studentNum != 1) {
			for (int k = 0; k < StuId.size(); k++) {
				if (Id == StuId[k]) {
					CheckInIt = true;
					break; 
				}
			}
		}
		StuId.push_back(Id);
		//중복된 학번 존재시 프로그램 종료
		if (CheckInIt == true) {
			break;
		}
		
		cout << "이름 : ";
		cin >> name;
		cout << endl;
		cout << "잔액 : ";
		cin >> balance;
		Student[studentNum - 1].setId(Id);
		Student[studentNum - 1].setName(name);
		Student[studentNum - 1].setBalance(balance);
		cout << "=================================================\n" << endl;
		studentNum++;
	}
	
	delete[] Student;
	
	cout << "회수된 금액 : " << Student->getSumbalance();

	return 0;
}