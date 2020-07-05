#include <iostream>
#include <string>

using namespace std;

class CStudent {
private:
	int studentId;
	string name;
	string major;
public:
	CStudent(int _studentId = 0, string _name="" , string _major = "")
		: studentId(_studentId), name(_name), major(_major) {
	}
	string getMajor() { return major; }
	string getname() { return name; }
	int getstudentId() { return studentId; }
	void setstudentID(int _studentId){studentId = _studentId;}
	void setMajor(string _major) {major = _major;}
	void setName(string _name) {name = _name;}
	int getStudentId() {return studentId;}
	void print(int i, CStudent s) {
		cout << i << "�л�����" << endl;
		cout << "�й� : " << s.getStudentId() << endl;
		cout << "�̸� : " << s.getname() << endl;
		cout << "���� : " << s.getMajor() << endl<<endl;
	}
};
int main() {
	CStudent s[3]; // 3���� �л������� ������ class �迭
	int inputNumber; // Ű����� �й��� �Է� ���� ����
	string inputName, inputMajor; // Ű����� �̸�, ������ �Է� ���� ����
	int length = 0; // ���� �Էµ� �л��� ��
	while (1) {
		cout <<  length + 1 << " ���� �л� �Է�" << endl;
		cout << "�й� : " ;
		cin >> inputNumber;
		cout << "�̸� : ";
		cin >> inputName;
		cout << "���� : ";
		cin >> inputMajor;
		if (length == 0) {
			s[length].setMajor(inputMajor);
			s[length].setName(inputName);
			s[length].setstudentID(inputNumber);

			cout << "���Է¿Ϸ�\n" << endl;
			length += 1;
		}
		else if (length >= 1) {
			bool repearcheck = false;
			for (int k = 0; k < length; k++) {
				if (s[k].getstudentId() == int(inputNumber)) {
					cout << "���ߺ��� �й��� �����մϴ�\n" << endl;
					repearcheck = true;
					break;
				}

			}if (repearcheck == false) {
				s[length].setMajor(inputMajor);
				s[length].setName(inputName);
				s[length].setstudentID(inputNumber);

				cout << "���Է¿Ϸ�\n" << endl;
				length += 1;

			}
		}
		
		if (length == 3) {
			cout << "----����Է��� �Ϸ�Ǿ����ϴ�----" << endl;
			for (int i = 0; i < 3; i++) {
				s[i].print(i+1, s[i]);
			}
			break;
		}	
	}

	return 0;
}
