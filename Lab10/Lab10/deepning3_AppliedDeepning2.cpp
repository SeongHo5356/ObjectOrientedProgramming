#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	int studentId;
	string major;
	vector<string> lectures;
	vector<char> grades;
public:
	Student(string _name= "default", int _studentId=0, string _major="depart")
		:name(_name), studentId(_studentId), major(_major) {}
	void setID(int _studentId) { studentId = _studentId; }
	void setName(string _name) { name = _name; }
	void setDpt(string _major) { major = _major; }
	void print() {
		cout << name << " " << " " << studentId << " " << major << endl;
	}
	void addGrade(string lecture, char grade){
		lectures.push_back(lecture);
		grades.push_back(grade);
	}
	void printGrades() {
		for (int i = 0; i < lectures.size(); i++)
			cout << lectures[i] << " " << grades[i] <<endl;
		cout << "GPA : "<<getGPA();
	}
		
	float getGPA() {
		vector<float> temp;
		for (auto elem : grades) {
			if (elem == 'A') {
				temp.push_back(4.0);
			}
			else if (elem == 'B') {
				temp.push_back(3.0);
			}
			else if (elem == 'C') {
				temp.push_back(2.0);
			}
			else if (elem == 'D') {
				temp.push_back(1.0);
			}
			else {
				temp.push_back(0.0);
			}
		}
		float sum = 0;
		for (float elem : temp) {
			sum += elem;
		}
		return (sum / temp.size());
	}
	void getYear(int year) {
		string temp = to_string(studentId);
		string Ntemp = temp.substr(0, 4);
		int NNtemp = year - stoi(Ntemp) + 1;
		if (NNtemp == 1) {
			cout << "Freshman(1학년)"<<endl;
		}
		else if (NNtemp == 2) {
			cout << "Sophomore(2학년)" << endl;
		}
		else if (NNtemp == 3) {
			cout << "Junoir(3학년)" << endl;
		}
		else if (NNtemp == 4) {
			cout << "Senoir(4학년)" << endl;
		}
		else {
			cout << "About to graduate(5학년 이상)" << endl;
		}
	}

};
int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";
	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";
	return 0;
}
