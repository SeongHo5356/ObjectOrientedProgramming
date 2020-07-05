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
	cout << "�й� : " << student.name << ", �̸� : " << student.id << ", �ܾ� : " << student.balance << endl;
	return cout;
}
//acnt1�� ���¿��� ���� ��� ��������
Account operator-(const Account& acnt1, const Account& acnt2) {
	Account result = acnt1;
	result.balance = 0;
	return result;
}

//acnt1�� ���¿� acnt2�� ���̵���
Account operator+(const Account& acnt1, const Account& acnt2) {
	Account result = acnt1;
	result.balance = acnt1.balance + acnt2.balance;
	return result;
}



int main() {
	Account acnt[3] = {
		Account("����ȣ", "2014", 10000),
		Account("������", "2019", 0),
		Account("������", "2013", 5000),
	};
	string idget;
	string idgive;
	vector<string> studentIds;
	for (int i = 0; i < 3; i++) {
		string a = acnt[i].getId();
		studentIds.push_back(a);
	}

	while (true) {
		cout << "���� ���� �л��� �й��� �Է��ϼ��� : ";
		cin >> idgive;
		if (idgive == "����") {
			cout << "�����մϴ�" << endl;
			for (int i = 0; i < 3; i++) {
				cout << acnt[i] ;
			}
			break;
		}

		cout << "���� ���� �л��� �й����Է��ϼ��� :";
		cin >> idget;

		//������ ���� �л��� ����, �ε��� ����
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
			//�ִ� ����� �޴� ����� ��ġ�ϴ� ���
			if (idgive == idget) {
				cout << "�۱��ϴ� �л��� �۱ݹ޴� �л��� ��ġ�մϴ�" << endl;
				break;
			}
			//�ִ� ����̳� �޴� ����� �������� �ʴ°��
			else if (CheckGetter ==false || CheckGiver == false) {	
				cout << "������ �л� �Ǵ� ���� �л��� �й��� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
				break;
			}
			//������ �й��� �������� �ʴ� ���� �Ÿ�-->GiverIndex != -1
			else if (acnt[GiverIndex].getBalance() == 0) {
				cout << "������ �л��� �ܾױ� �����մϴ�." << endl;
				break;
			}
			//��ü ������ ���
			else {
				acnt[GetterIndex] = acnt[GetterIndex] + acnt[GiverIndex];
				acnt[GiverIndex] = acnt[GiverIndex] - acnt[GetterIndex];
				cout << "���� �л��� �ܾ� => " << acnt[GiverIndex] ;
				cout << "���� �л��� �ܾ� => " << acnt[GetterIndex] ;
				break;
			}
			
		}
	}
}