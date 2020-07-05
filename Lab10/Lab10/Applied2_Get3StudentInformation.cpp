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
		cout << i << "학생정보" << endl;
		cout << "학번 : " << s.getStudentId() << endl;
		cout << "이름 : " << s.getname() << endl;
		cout << "전공 : " << s.getMajor() << endl<<endl;
	}
};
int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	while (1) {
		cout <<  length + 1 << " 번쨰 학생 입력" << endl;
		cout << "학번 : " ;
		cin >> inputNumber;
		cout << "이름 : ";
		cin >> inputName;
		cout << "전공 : ";
		cin >> inputMajor;
		if (length == 0) {
			s[length].setMajor(inputMajor);
			s[length].setName(inputName);
			s[length].setstudentID(inputNumber);

			cout << "※입력완료\n" << endl;
			length += 1;
		}
		else if (length >= 1) {
			bool repearcheck = false;
			for (int k = 0; k < length; k++) {
				if (s[k].getstudentId() == int(inputNumber)) {
					cout << "※중복된 학번이 존재합니다\n" << endl;
					repearcheck = true;
					break;
				}

			}if (repearcheck == false) {
				s[length].setMajor(inputMajor);
				s[length].setName(inputName);
				s[length].setstudentID(inputNumber);

				cout << "※입력완료\n" << endl;
				length += 1;

			}
		}
		
		if (length == 3) {
			cout << "----모든입력이 완료되었습니다----" << endl;
			for (int i = 0; i < 3; i++) {
				s[i].print(i+1, s[i]);
			}
			break;
		}	
	}

	return 0;
}
