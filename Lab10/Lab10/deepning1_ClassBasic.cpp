#include <iostream>
#include <string>

using namespace std;

class CStudent {
private:
	int studentId;
	string name;
	string major;
public:
	CStudent(int _stuId = 2018000000, string _name = "ȫ�浿", string _major = "��ǻ�Ͱ��а�")
		: studentId(_stuId), name(_name), major(_major) {}
	void Display() {
		cout << "�й� : " << studentId << endl << "�̸� : " << name << endl << "���� : " << major << endl<<endl;
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
	CStudent s2(1999000000, "����ö", "���ؿ�ȭ��"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("�ΰ���");
	s1.setMajor("����Ʈ���");
	cout << "�й� :" << s1.getNumber() << endl;
	cout << "�̸� :" << s1.getName() << endl;
	cout << "���� :" << s1.getMajor() << endl;
	return 0;
}
