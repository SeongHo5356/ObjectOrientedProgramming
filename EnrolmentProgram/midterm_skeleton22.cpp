#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			break;
		}
		else if (user == -1) { // Exit command
			break;
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}

	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

//student.txt���� ������ ���Ϳ� ��Ҹ� ���� ����� �ε��� ����
int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

//lecture.txt���� ����ϳ��� �� ��Ұ� ����ִ� ���� �� �� �ε��� ����
int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (code == lectureCodes[i])
			return i;
	}
	return -1;
}

// ��Ҹ� �� �ش� ������ �ε��� �ڸ����� ���� 
void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

// students.txt���Ͽ� �����ϴ� �л� ������ �о�� 
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin;

	string stu, studentId, password, name;
	int credit, NumsForApplied;
	vector<int> a;

	fin.open("students.txt");

	while (getline(fin, stu)) {//���پ� �Է¹���

		//�Ǳ����� �����̽��� ���ؼ� ������ �켱 �� ��ġ�� ã�Ƴ���
		int FirstTab = stu.find('\t');
		int SecondTab = stu.find('\t', FirstTab + 1);
		int ThirdTab = stu.find('\t', SecondTab + 1);
		int FourthTab = stu.find('\t', ThirdTab + 1);
		int LastTab = stu.find('\t', FourthTab + 1);

		//�� ������ �������� ������ �о��
		studentId = stu.substr(0, FirstTab);
		password = stu.substr(FirstTab + 1, SecondTab - FirstTab - 1);
		name = stu.substr(SecondTab + 1, ThirdTab - SecondTab - 1);
		credit = stoi((stu.substr(ThirdTab + 1, FourthTab - ThirdTab - 1)));
		NumsForApplied = stoi((stu.substr(FourthTab + 1, LastTab - FourthTab - 1)));

		//���� ��û�� ������� ����ؼ� appliedlecturecodes�� �ش��ϴ� ������� ������ ���� ���͸� �����ص�
		vector<string> CourseName(NumsForApplied);
		int i = 0;
		int Tab = LastTab;
		while (i < NumsForApplied) {
			string lecturename = stu.substr(LastTab + (8 * i) + 1, 7);//�����ڵ�� 7�ڸ��� �̷����
			CourseName[i] = lecturename;
			i++;
		}
		//������û�� ������ �ش��л��� appliedlecturecodes�� ������
		appliedLectureCodes.push_back(CourseName);

		//�ش��ϴ� ���Ϳ� ���� �������
		studentIds.push_back(studentId);
		passwords.push_back(password);
		names.push_back(name);
		credits.push_back(credit);
		a.push_back(NumsForApplied);

	}
	fin.close();
}

//lectures.txt���� ������� �о��
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin;

	string stu, lectureCode, lecturName;
	int lectureCredit, limit;

	fin.open("lectures.txt");

	while (getline(fin, stu)) {//���پ� �Է¹���

		lectureCode = stu.substr(0, stu.find('\t'));
		//�м��ڵ� �������� ����		
		lecturName = stu.substr(stu.find('\t') + 1, stu.find('\t', 8) - stu.find('\t') - 1);
		//������� ���̰� �����Ǿ����� ����
		lectureCredit = stoi(stu.substr(stu.find('\t', 8) + 1, 1));
		//���� �ش��ϴ� ������ �׻� ���ڸ� �ڿ���(�ִ�����3��)
		limit = stoi(stu.substr(stu.find('\t', 8) + 3));
		//�������� �ο� ���Ѿ���

		//������ �ش��ϴ� ���Ϳ� �߰���
		lectureCodes.push_back(lectureCode);
		lectureNames.push_back(lecturName);
		lectureCredits.push_back(lectureCredit);
		limits.push_back(limit);
	}
	fin.close();
}

//���α׷� ���� �� ������ �л� ������ �����ϴ� �Լ�
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout;
	fout.open("students.txt");
	//���ٿ� �й�, ��й�ȣ, �̸�, ������û��������, ������ �����, ������ �����̸����� '\t'�������� �� ���Ͽ� ��
	for (unsigned i = 0; i < studentIds.size(); i++) {//�л� �Ѹ� ������ �����ͼ� �Է��ϰ� �����л����� �Ѿ
		fout << studentIds[i] << '\t' << passwords[i] << '\t' << names[i] << '\t' << credits[i] << '\t' << appliedLectureCodes[i].size() << '\t';
		for (unsigned k = 0; k < appliedLectureCodes[i].size(); k++) {
			fout << appliedLectureCodes[i][k] << ' ';
		}
		fout << endl;
	}
	fout.close();
}


//���α׷� ���� �� ������ ���� ��Ȳ�� �����ϴ� �Լ�
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout;
	fout.open("lectures.txt");
	//���پ� �����ڵ�, �����̸� , ���� ����, ���������ο��� '\t' �������� ����� ���Ͽ� ��
	for (unsigned i = 0; i < lectureCodes.size(); i++) {//���� �ϳ��ϳ��� ������ �����ͼ� �Է��ϰ� ���� �������� �Ѿ
		fout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	}
	fout.close();
}

//�л� ���̵�(�й�)�� �Է¹޴� �Լ�, �й� return
string getInputId() {
	string Id;
	cout << "���̵� : ";
	cin >> Id;
	return Id;
}

//�л� ��й�ȣ�� �Է¹޴� �Լ�, ��й�ȣ return 
string getInputPassword() {
	string password;
	cout << "��й�ȣ : ";
	cin >> password;
	return password;

}

//�л��� �Է��� �й��� ��й�ȣ�� �������� �л�����Ȯ���� �α��� ���, �α��� ���ɽ� �л��� �ε��� return, �Ұ����ҽ� -1 return (�α��� ��ȸ 3��)
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	//��ȯ��: ����(�л� ���̵� ���� �������� �ε���), ����(-1)
	int trial = 1;

	int IdIndex = -1;
	bool checkPw = false;

	while (trial <= 3) {//3ȸ���� �α��� �õ� ����
		IdIndex = -1;

		//�л��� �й��� ��й�ȣ�� �Է¹���
		string InputId = getInputId();
		string InputPw = getInputPassword();

		//�л��� ���̵�(�й�)�� �ε����� ã�� --> �������� �ʴ� �й��Ͻ� return -1, ������ �� �й��� �ε��� return
		IdIndex = findStudentById(studentIds, InputId);

		//�л��� ���̵�(�й�)�� �������� �ʴ� �й��� �� ����ȸ�� �α��νõ��� �Ѿ
		if (IdIndex == -1) {
			cout << "�α��� " << trial << "ȸ ���� (3ȸ ���н� ����)" << endl;
		}
		//�л��� ���̵�(�й���) ������ �� �л��� ��й�ȣ �л��� �Է��� ��й�ȣ�� �� -->��ġ�ҽ� �α��� ����, ����ġ�� ����ȸ�� �α��νõ��� �Ѿ 
		else {
			if (passwords[IdIndex] == InputPw) {
				checkPw = true;
				break;
			}
			else {
				cout << "�α��� " << trial << "ȸ ���� (3ȸ ���н� ����)" << endl;
			}
		}
		trial++;
	}
	//�л� �α��μ��� �� �л��� �ε��� return
	if (checkPw) {
		return IdIndex;
	}
	//�л� �α��� ���� ���
	else {
		return -1;
	}
}

//������ �α��� ���̵� ��й�ȣ ��� admin�� �� return true , �ƴ� �� false return (�Է±�ȸ 3ȸ)
bool adminLogin() {
	int trial = 1;
	while (trial < 4) {
		//�����ڿ��� ���̵�� ��й�ȣ�� �Է¹���
		string Id = getInputId();
		string Password = getInputPassword();
		
		//������ ��й�ȣ�� ���̵�� ��� admin
		if (Id == "admin" && Password == "admin")
			return true;
		
		//�α��� ������ ����Ȯ�ҽ� 3ȸ���� �Է±�ȸ�� ����
		else
			cout << "�α��� " << trial << "ȸ ���� (3ȸ ���н� ����)" << endl;
		trial++;
	}
	return false;
}


//�α����� �������� �ۿ��� �����ϴ� �Լ�
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	int Choosed;
	//�α��� ���� ������ ���� �޴�
	cout << "------------------------------------------------------------------------------------------------\n" << "1. �л� �α���\n" << "2. ������ �α���\n" << "0. ����\n" << "------------------------------------------------------------------------------------------------" << endl << ">> ";
	cin >> Choosed;

	//�л� �α���(1)�� ������ �� 
	if (Choosed == 1)
	{
		int a = studentLogin(studentIds, passwords);//studentlogin() return ��  --> ������ �л� �ε��� �Ǵ� ���н� -1
		if (a != -1)
			return a;	//�α��� ���� �� �����Լ����� (//Student login success) ���� ��
		else
			return -999;	// �α��� ���н� return -999�� ���༭ �����Լ����� (//login fail)���� ��
	}

	//������ �޴�(2) ������ ��
	else if (Choosed == 2)
	{
		bool a = adminLogin();	//adminlogin() return �� --> ������ true or ���н� false
		if (a == true)
			return -100;	//�α��� ���� �� �����Լ����� (// Admin login success) ���� ��
		else
			return -999;	// �α��� ���н� return -999�� ���༭ �����Լ����� (//login fail)���� �� 
	}
	else//1,2 �̿��� ���� �Է½� main �Լ��� ���α׷� ����� ���� ���� ���ؼ�
		return -1;
}

//���� ����� ����ϱ� ���� �Լ�
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	//�л����� �α��� �� �л� ������û ��ϸ��� ���
	if (user != -100) {
		cout << "------------------------------------------------------------------------------------------------\n�����ڵ�\t���Ǹ�\t\t����\t���������ο�\n------------------------------------------------------------------------------------------------" << endl;
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {//�л��� ��û�� ���� �� ��ŭ �ݺ��� ����
			int findId = -1;
			// ���� ���� ��û�� ������ �����ڵ�� ���� �ڵ帣 ���� ����� �ε����� lectureCodes���� ����
			for (unsigned k = 0; k < lectureCodes.size(); k++)
			{
				if (appliedLectureCodes[user][i] == lectureCodes[k]) {
					findId = k;
					break;
				}
			}
			//�ε����� ��ã�� �� (�л��� ������û�� ������ �ϳ��� ���� ��)
			if (findId == -1) {
				cout << "------------------------------------------------------------------------------------------------" << endl;
			}
			//�ε��� ã�� �� �ٷ� �� �����ڵ�, �����̸�, ���� ����, ���� ���������ο� ���
			else {
				cout << appliedLectureCodes[user][i] << '\t' << lectureNames[findId] << '\t' << lectureCredits[findId] << '\t' << limits[findId] << '\n';
			}
		}
		cout << "------------------------------------------------------------------------------------------------\n" << endl;
	}
	// ����ڰ� ������û �Ǵ� �����ڰ� �α��� �� ��� ���� ���
	else if (user == -100) {
		cout << "------------------------------------------------------------------------------------------------\n�����ڵ�\t���Ǹ�\t\t����\t���������ο�\n------------------------------------------------------------------------------------------------" << endl;
		for (unsigned i = 0; i < lectureCodes.size(); i++) {//��� ������ ��� 
			cout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << '\n';
		}
		cout << "------------------------------------------------------------------------------------------------\n";
	}
}

//�л� �߰�
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	system("cls");

	//�߰��� �л��� ������ �й�, ��й�ȣ, �̸� ������ �Է¹���
	string studentId, password, name;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "�й� : ";
	cin >> studentId;
	cout << "��й�ȣ : ";
	cin >> password;
	cout << "�л� �̸� : ";
	cin >> name;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	//�л��� �й��� �����ĺ��ڷμ� �����ϱ� ���� ������ �����ϴ� �й���� �Է¹��� �й��� �� ���� �й� ����� return true ���� �� return false
	bool ChekInIt = false;
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentId == studentIds[i]) {
			ChekInIt = true;
		}
	}


	if (ChekInIt == true) {//�����й� �����ҽ� �� �л� �޴��� ���ư� 
		cout << "�̹� �����ϴ� �й��Դϴ�." << endl;
		system("pause");
		return;
	}
	else if (ChekInIt == false) {//�ߺ��� �й� ��������  ���� �� �л��� ������ ������ ������ �������� �������, �������������� 18, �����Ѱ������ 0���� ������ �߰� 
		studentIds.push_back(studentId);
		passwords.push_back(password);
		names.push_back(name);
		credits.push_back(18);
		appliedLectureCodes.push_back(vector<string>(0));
		cout << "���������� ��ϵǾ����ϴ�. " << endl;
		system("pause");
		return;
	}
}

// ���ο� ������ �����ϱ� ���� �Լ�
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	system("cls");
	string lectureName, lectureCode; int limit, lectureCredit;

	//������ ������ �����ڵ�, �����̸� ,����, ���������ο� ������ �Է¹��� 
	cout << "------------------------------------------------------------------------------------------------\n" << "�����ڵ� :";
	cin >> lectureCode;
	cout << "����� :";
	cin >> lectureName;
	cout << "���� :";
	cin >> lectureCredit;
	cout << "�����ο� : ";
	cin >> limit;
	cout << "------------------------------------------------------------------------------------------------\n";

	//������ ������ �����ڵ� ���� �����ĺ��ڷ� Ȱ���ϱ� ������, �ߺ��� �����ڵ� �˻� 
	if (findLectureByCode(lectureCodes, lectureCode) != -1) {//�ߺ��� ���� �ڵ� ������ �� 
		cout << "�̹� �����ϴ� �����ڵ��Դϴ�.\n";
		system("PAUSE");
		return;

	}
	else if (findLectureByCode(lectureCodes, lectureCode) == -1) {//�ߺ��� �����ڵ� �������� ���� �� �Է��� ������ ������ ���Ϳ� �߰����� 
		lectureCodes.push_back(lectureCode);
		lectureNames.push_back(lectureName);
		lectureCredits.push_back(lectureCredit);
		limits.push_back(limit);
		cout << "���������� ��ϵǾ����ϴ�.\n";
		system("PAUSE");
		return;

	}
}

//������ ������ �󰭽�Ŵ
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	while (true) {
		system("cls");
		//1. ���� �����Ǿ� �ִ� ������ ��� ǥ��
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
		string CodForDel;
		int lectindx = -1;

		//������ ������ �ڵ帣 �Է¹��� 
		cout << "������ ���� �ڵ� (0: �ڷΰ���) >> ";
		cin >> CodForDel;

		//�����Ϸ��� �����ڵ尡 ������ �������� Ȯ���ϴ� ������ ��ġ�� ��, �����ҽ� CheckInIt = true, �������� ���� �� CheckInIt = false 
		bool ChekInIt = false;
		for (unsigned i = 0; i < lectureCodes.size(); i++) {
			if (CodForDel == lectureCodes[i]) {
				ChekInIt = true;
				break;
			}
			else {
				ChekInIt = false;
			}
		}

		// �����Ϸ��� ������ �����Ǿ��ִ� �����߿� �������� ���� 
		if (ChekInIt == false) {
			if (CodForDel == "0") {//������ �޴��� ���ư��� '0'�� �Է����� ��
				system("pause");
				return;
			}

			//�����Ϸ��� �ϴ� �����ڵ尡 �������� ���� �� 
			cout << "��ġ�ϴ� �ڵ尡 �����ϴ�." << endl;
			system("pause");

		}
		//�����Ϸ��� �ϴ� �����ڵ尡 ������ �� 
		else if (ChekInIt == true) {
			//������ ������ �ε����� lectindx�� ����
			lectindx = findLectureByCode(lectureCodes, CodForDel);
			//�� ������ ������û�� �л����� ��� ã�ƾ��ϱ� ������ �л�����ŭ�� �ݺ����� ������ 
			for (unsigned k = 0; k < appliedLectureCodes.size(); k++) {
				//Ư�� �л����� �л��� ������û�� ����� ��ŭ�� �ݺ����� ���� 
				for (unsigned i = 0; i < appliedLectureCodes[k].size(); i++) {
					//������ �ڵ尡 �л��� ������û�� �����߿� ������ �� --> (�л��� ������������ + ������ �����ڵ��� ����), 
					//(������ ������ ���������ο� +1), (�л��� ������û �����Ͽ��� �ش���� ����)�� ������� ����  
					if (CodForDel == appliedLectureCodes[k][i]) {
						credits[k] += lectureCredits[lectindx];
						limits[lectindx] += 1;
						deleteElement(appliedLectureCodes[k], i);
					}
				}
			}

			// �� ������ �ε���(lectindx)�� ��Ҹ� ���� ���� ���Ϳ��� ��� ����
			deleteElement(lectureCodes, lectindx);
			deleteElement(lectureNames, lectindx);
			lectureCredits.erase(lectureCredits.begin() + lectindx);
			limits.erase(limits.begin() + lectindx);
			cout << "���������� ���ǰ� ���Ǿ����ϴ�." << endl;

			system("pause");
		}
	}
}

//�������� �α����� ���հ����ϴ� �Ŵ� �����Լ�
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	while (true) {//���� ���� �޴�(0) �Է��� �� ���� �Լ� ����
		system("cls");
		int ChosNum = -1;
		cout << "------------------------------------------------------------------------------------------------\n1. �л� �߰�\n2. ���� ����\n3. ���� ����\n4. �α׾ƿ�\n0. ����\n------------------------------------------------------------------------------------------------" << endl << ">> ";
		cin >> ChosNum;

		if (ChosNum == 1) {//���� �߰�
			addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
		}
		else if (ChosNum == 2) {//���� �߰�
			addLecture(lectureCodes, lectureNames, lectureCredits, limits);
		}
		else if (ChosNum == 3) {//�������
			deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
		}
		else if (ChosNum == 4) {//�α׾ƿ�
			system("cls");
			return -1;
		}
		else if (ChosNum == 0) {//����
			return 1;
		}
	}
}

//�л��� ������ ����ϴ� �Լ�
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "�й�: " << studentIds[user] << '\t' << "�̸� :" << names[user] << '\t' << "������������: " << credits[user] << "\n------------------------------------------------------------------------------------------------\n";
}


//�л��� ������û �� �� �ֵ��� �ϴ� �Լ�
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {

	while (true) {
		system("cls");
		//�л��� ����, ������û ������ ������� ���
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
		string CodeForApply;

		//�л����� ��û�� �����ڵ带 �Է¹���
		cout << "��û�� ���� �ڵ�(0 : �ڷΰ���) >> ";
		cin >> CodeForApply;

		if (CodeForApply == "0") {
			system("pause");
			return;
		}
		else {
			int index = findLectureByCode(lectureCodes, CodeForApply);
			if (index == -1) {
				cout << "�������� �ʴ� �����ڵ��Դϴ�." << endl;
				system("pause");
			}
			else {
				// ���� ���� ��Ͽ� ���� �ڵ尡 ���� �� true
				bool CheckInit = false;
				for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++)
					if (CodeForApply == appliedLectureCodes[user][i]) {
						CheckInit = true;
						break;
					}
				//�ڵ�� �ٸ����� �̸��� ���� �����׸����� �񱳸� ���� �� ��������� �̸� ������ ���� ������ �����ڵ�� ���������ڵ���� �񱳸� ���� ���������ڵ��� �ε���
				vector<int> Namofappllec;
				for (unsigned k = 0; k < appliedLectureCodes[user].size(); k++) {
					for (unsigned l = 0; l < lectureCodes.size(); l++)
						if (appliedLectureCodes[user][k] == lectureCodes[l])
							Namofappllec.push_back(l);
				}
				bool CheckRepeat = false;
				for (unsigned o = 0; o < Namofappllec.size(); o++) {
					if (lectureNames[Namofappllec[o]] == lectureNames[index])
						CheckRepeat = true;
				}
				//������ ���������ο��� 0������ ���̻� ������û�� ���� �� ���� ��
				if (limits[index] == 0) {
					cout << "���� �ο��� �� á���ϴ�." << endl;
					system("pause");
				}
				//�л��� �������������� �ش� ������ ������ ���� ������ ��
				else if (credits[user] < lectureCredits[index]) {
					cout << "�������������� �����մϴ�." << endl;
					system("pause");
				}
				//�л��� �̹� �ش� ������ ��û���� ��
				else if (CheckInit == true) {
					cout << "�̹� �ش� ������ ��û�߽��ϴ�." << endl;
					system("pause");
				}
				//�л��� �̹� ������ �̸��� ���� �ٸ��ڵ��� ������ ��û���� ��
				else if (CheckRepeat == true) {
					cout << "�̹� ���ϸ��� ������ ��û�߽��ϴ�." << endl;
					system("pause");
				}
				//������û ������ ���
				else {
					appliedLectureCodes[user].push_back(CodeForApply);
					cout << "[" << CodeForApply << "] " << lectureNames[index] << " ��(��) ���������� ��û�Ͽ����ϴ�." << endl;
					//�л� �������� ���� ����
					credits[user] -= lectureCredits[index];
					//�ش� ������ ���� ���� �ο� ����;
					limits[index] -= 1;
					system("pause");
				}
			}
		}
	}

}

//������û öȸ�� ���� �޴�
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	while (true) {
		system("cls");
		//�л��� ������û����� �����
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		string LectureCodeForDisapply;

		//����öȸ�� �����ڵ� �Է¹���
		cout << "öȸ�� ���� �ڵ�(0 : �ڷΰ���) >> ";
		cin >> LectureCodeForDisapply;

		//�Է¹��� �ڵ尡 '0'�Ͻ� �л��޴��� ���ư�
		if (LectureCodeForDisapply == "0") {
			system("PAUSE");
			return;
		}
		//���� ���� öȸ�� �ڵ��� ���� �ε����� user�� ���� ��� ���Ϳ��� �˻�
		int findIndex = findLectureByCode(appliedLectureCodes[user], LectureCodeForDisapply);

		//���� ������ ��� �߿� öȸ�� �׸��� ���� ��
		if (findIndex == -1) {
			cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�. " << endl;
			system("pause");
		}
		else {
			//���� öȸ�� �ڵ带 ���� ��������߿� ����
			deleteElement(appliedLectureCodes[user], findIndex);
			//öȸ ������ ���������ο�+1
			int findcreditindex = findLectureByCode(lectureCodes, LectureCodeForDisapply);
			limits[findcreditindex] += 1;

			//���� credit ȸ��
			credits[user] += lectureCredits[findcreditindex];

			cout << "[" << LectureCodeForDisapply << "] " << lectureNames[findcreditindex] << "(��)�� öȸ�Ͽ����ϴ�. " << endl;
			system("PAUSE");
		}
	}

}

//�л��� ��й�ȣ�� �ٲٱ� ���� �Լ�
void changePassword(vector<string>& passwords, const int& user) {
	string InputPassword = "";
	//�л��� ��й�ȣ�� �ٽ��ѹ� �Է¹���
	cout << "------------------------------------------------------------------------------------------------" << "\n��й�ȣ�� �� �� �� �Է����ּ���. \n" << "��й�ȣ : ";
	cin >> InputPassword;
	cout << "------------------------------------------------------------------------------------------------\n";

	//�л����� �Է¹��� ��й�ȣ�� �ش� �л��� ��й�ȣ�� ��ġ �� �� ��й�ȣ ���� ���
	if (InputPassword == passwords[user]) {
		string NewPassword;
		cout << "------------------------------------------------------------------------------------------------\n" << "���� ������ ��й�ȣ�� �Է��ϼ���.\n" << "��й�ȣ : ";
		//������ ��й�ȣ �Է�
		cin >> NewPassword;
		passwords[user] = NewPassword;
		cout << "����Ǿ����ϴ�.\n" << "------------------------------------------------------------------------------------------------\n";
		system("pause");
		return;
	}
	//�л����� �Է¹��� ��й�ȣ�� �ش� �л��� ��й�ȣ�� ��ġ���� ���� �� �л� �޴��� ���ư�
	else {
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
		system("pause");
		return;
	}
}

//��ü���� �л� ���� �޴��� ����ϴ� �Լ�
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	while (true) {//�л��� 0���� ������ ���α׷��� ���� ��ų������ �۵�
		system("cls");
		int ChosNum = -1;
		//�޴����
		cout << "------------------------------------------------------------------------------------------------\n1. ���� ��û\n2. ���� ��Ȳ\n3. ���� öȸ\n4. ��й�ȣ ����\n5. �α׾ƿ�\n0. ����\n------------------------------------------------------------------------------------------------" << endl;
		cin >> ChosNum;
		//1���� ������ ������û�޴��� ���� ���
		if (ChosNum == 1) {
			system("cls");
			applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
		//2���� ������ ���� ��Ȳ�� ������ ���
		else if (ChosNum == 2) {
			system("cls");
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("pause");
			system("cls");
		}
		//3���� ������ ������ öȸ�Ϸ��� ���
		else if (ChosNum == 3) {
			system("cls");
			disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
		//4���� ������ ��й�ȣ�� �����Ϸ��� ���
		else if (ChosNum == 4) {
			system("cls");
			changePassword(passwords, user);
		}
		//5���� ������ �α׾ƿ��� �Ϸ��� ���
		else if (ChosNum == 5) {
			system("cls");
			return -1;
		}
		//0���� ������ ���α׷��� �����Ϸ��� ���
		else if (ChosNum == 0) {
			return 1;

		}
	}
}