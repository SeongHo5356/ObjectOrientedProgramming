#include <iostream>
#include <string>

using namespace std;

class CStudent {
private:
	int studentId;
	string name;
	string major;
public:
	CStudent(int _stuId = 2018000000, string _name = "홍길동", string _major = "컴퓨터공학과")
		: studentId(_stuId), name(_name), major(_major) {}
	void Display() {
		cout << "학번 : " << studentId << endl << "이름 : " << name << endl << "전공 : " << major << endl<<endl;
	}
	void setNumber(int _stuId) { studentId = _stuId; }
	void setName(string _name) { name = _name; }
	void setMajor(string _major) { major = _major; }
	int getNumber(){return studentId;}
	string getName() { return name; }
	string getMajor() { return major; }
};

int main() {
	CStudent s1; // A
	s1.Display();
	CStudent s2(1999000000, "공지철", "연극영화과"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("민경훈");
	s1.setMajor("포스트모던");
	cout << "학번 :" << s1.getNumber() << endl;
	cout << "이름 :" << s1.getName() << endl;
	cout << "전공 :" << s1.getMajor() << endl;
	return 0;
}
