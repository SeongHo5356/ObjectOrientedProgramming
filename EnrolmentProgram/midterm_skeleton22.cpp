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

//student.txt에서 저장한 벡터와 요소를 비교후 요소의 인덱스 추출
int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

//lecture.txt에서 요소하나와 그 요소가 들어있는 벡터 알 시 인덱스 추출
int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (code == lectureCodes[i])
			return i;
	}
	return -1;
}

// 요소를 그 해당 벡터의 인덱스 자리에서 지움 
void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

// students.txt파일에 존재하는 학생 정보를 읽어옴 
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	ifstream fin;

	string stu, studentId, password, name;
	int credit, NumsForApplied;
	vector<int> a;

	fin.open("students.txt");

	while (getline(fin, stu)) {//한줄씩 입력받음

		//탭기준의 슬라이싱을 위해서 그전에 우선 탭 위치를 찾아놓음
		int FirstTab = stu.find('\t');
		int SecondTab = stu.find('\t', FirstTab + 1);
		int ThirdTab = stu.find('\t', SecondTab + 1);
		int FourthTab = stu.find('\t', ThirdTab + 1);
		int LastTab = stu.find('\t', FourthTab + 1);

		//탭 정보를 바탕으로 정보를 읽어옴
		studentId = stu.substr(0, FirstTab);
		password = stu.substr(FirstTab + 1, SecondTab - FirstTab - 1);
		name = stu.substr(SecondTab + 1, ThirdTab - SecondTab - 1);
		credit = stoi((stu.substr(ThirdTab + 1, FourthTab - ThirdTab - 1)));
		NumsForApplied = stoi((stu.substr(FourthTab + 1, LastTab - FourthTab - 1)));

		//수강 신청한 과목수에 기반해서 appliedlecturecodes에 해당하는 과목수의 공간을 가진 벡터를 선점해둠
		vector<string> CourseName(NumsForApplied);
		int i = 0;
		int Tab = LastTab;
		while (i < NumsForApplied) {
			string lecturename = stu.substr(LastTab + (8 * i) + 1, 7);//과목코드는 7자리로 이루어짐
			CourseName[i] = lecturename;
			i++;
		}
		//수강신청한 과목을 해당학생의 appliedlecturecodes에 저장함
		appliedLectureCodes.push_back(CourseName);

		//해당하는 벡터에 각각 집어넣음
		studentIds.push_back(studentId);
		passwords.push_back(password);
		names.push_back(name);
		credits.push_back(credit);
		a.push_back(NumsForApplied);

	}
	fin.close();
}

//lectures.txt에서 과목들을 읽어옴
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	ifstream fin;

	string stu, lectureCode, lecturName;
	int lectureCredit, limit;

	fin.open("lectures.txt");

	while (getline(fin, stu)) {//한줄씩 입력받음

		lectureCode = stu.substr(0, stu.find('\t'));
		//학술코드 길이제한 없음		
		lecturName = stu.substr(stu.find('\t') + 1, stu.find('\t', 8) - stu.find('\t') - 1);
		//과목명은 길이가 고정되어있지 않음
		lectureCredit = stoi(stu.substr(stu.find('\t', 8) + 1, 1));
		//과목에 해당하는 학점은 항상 한자리 자연수(최대학점3점)
		limit = stoi(stu.substr(stu.find('\t', 8) + 3));
		//수강가능 인원 제한없음

		//각각의 해당하는 벡터에 추가함
		lectureCodes.push_back(lectureCode);
		lectureNames.push_back(lecturName);
		lectureCredits.push_back(lectureCredit);
		limits.push_back(limit);
	}
	fin.close();
}

//프로그램 실행 후 수정된 학생 사항을 저장하는 함수
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout;
	fout.open("students.txt");
	//한줄에 학번, 비밀번호, 이름, 수강신청가능학점, 수강한 과목수, 수강한 과목이름들을 '\t'기준으로 띄어서 파일에 씀
	for (unsigned i = 0; i < studentIds.size(); i++) {//학생 한명씩 정보를 가져와서 입력하고 다음학생으로 넘어감
		fout << studentIds[i] << '\t' << passwords[i] << '\t' << names[i] << '\t' << credits[i] << '\t' << appliedLectureCodes[i].size() << '\t';
		for (unsigned k = 0; k < appliedLectureCodes[i].size(); k++) {
			fout << appliedLectureCodes[i][k] << ' ';
		}
		fout << endl;
	}
	fout.close();
}


//프로그램 실행 후 수정된 과목 상황을 저장하는 함수
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout;
	fout.open("lectures.txt");
	//한줄씩 과목코드, 과목이름 , 과목 학점, 수강가능인원을 '\t' 기준으로 띄워서 파일에 씀
	for (unsigned i = 0; i < lectureCodes.size(); i++) {//과목 하나하나씩 정보를 가져와서 입력하고 다음 과목으로 넘어감
		fout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	}
	fout.close();
}

//학생 아이디(학번)를 입력받는 함수, 학번 return
string getInputId() {
	string Id;
	cout << "아이디 : ";
	cin >> Id;
	return Id;
}

//학생 비밀번호를 입력받는 함수, 비밀번호 return 
string getInputPassword() {
	string password;
	cout << "비밀번호 : ";
	cin >> password;
	return password;

}

//학생이 입력한 학번과 비밀번호를 바탕으로 학생정보확인후 로그인 허용, 로그인 가능시 학생의 인덱스 return, 불가능할시 -1 return (로그인 기회 3번)
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	//반환값: 성공(학생 아이디 벡터 내에서의 인덱스), 실패(-1)
	int trial = 1;

	int IdIndex = -1;
	bool checkPw = false;

	while (trial <= 3) {//3회까지 로그인 시도 가능
		IdIndex = -1;

		//학생의 학번과 비밀번호를 입력받음
		string InputId = getInputId();
		string InputPw = getInputPassword();

		//학생의 아이디(학번)의 인덱스를 찾음 --> 존재하지 않는 학번일시 return -1, 존재할 시 학번의 인덱스 return
		IdIndex = findStudentById(studentIds, InputId);

		//학생의 아이디(학번)이 존재하지 않는 학번일 시 다음회차 로그인시도로 넘어감
		if (IdIndex == -1) {
			cout << "로그인 " << trial << "회 실패 (3회 실패시 종료)" << endl;
		}
		//학생의 아이디(학번이) 존재할 시 학생의 비밀번호 학생이 입력한 비밀번호를 비교 -->일치할시 로그인 성공, 불일치시 다음회차 로그인시도로 넘어감 
		else {
			if (passwords[IdIndex] == InputPw) {
				checkPw = true;
				break;
			}
			else {
				cout << "로그인 " << trial << "회 실패 (3회 실패시 종료)" << endl;
			}
		}
		trial++;
	}
	//학생 로그인성공 시 학생의 인덱스 return
	if (checkPw) {
		return IdIndex;
	}
	//학생 로그인 실패 경우
	else {
		return -1;
	}
}

//관리자 로그인 아이디 비밀번호 모두 admin일 시 return true , 아닐 시 false return (입력기회 3회)
bool adminLogin() {
	int trial = 1;
	while (trial < 4) {
		//관리자에게 아이디와 비밀번호를 입력받음
		string Id = getInputId();
		string Password = getInputPassword();
		
		//관리자 비밀번호와 아이디는 모두 admin
		if (Id == "admin" && Password == "admin")
			return true;
		
		//로그인 정보가 부정확할시 3회까지 입력기회를 가짐
		else
			cout << "로그인 " << trial << "회 실패 (3회 실패시 종료)" << endl;
		trial++;
	}
	return false;
}


//로그인의 통합적인 작용을 관리하는 함수
int login(const vector<string>& studentIds, const vector<string>& passwords) {
	int Choosed;
	//로그인 형태 선택을 위한 메뉴
	cout << "------------------------------------------------------------------------------------------------\n" << "1. 학생 로그인\n" << "2. 관리자 로그인\n" << "0. 종료\n" << "------------------------------------------------------------------------------------------------" << endl << ">> ";
	cin >> Choosed;

	//학생 로그인(1)을 선택할 시 
	if (Choosed == 1)
	{
		int a = studentLogin(studentIds, passwords);//studentlogin() return 값  --> 성공시 학생 인덱스 또는 실패시 -1
		if (a != -1)
			return a;	//로그인 성공 시 메인함수에서 (//Student login success) 경우로 감
		else
			return -999;	// 로그인 실패시 return -999를 해줘서 메인함수에서 (//login fail)경우로 감
	}

	//관리자 메뉴(2) 선택할 시
	else if (Choosed == 2)
	{
		bool a = adminLogin();	//adminlogin() return 값 --> 성공시 true or 실패시 false
		if (a == true)
			return -100;	//로그인 성공 시 메인함수에서 (// Admin login success) 경우로 감
		else
			return -999;	// 로그인 실패시 return -999를 해줘서 메인함수에서 (//login fail)경우로 감 
	}
	else//1,2 이외의 숫자 입력시 main 함수의 프로그램 종료와 연결 짓기 위해서
		return -1;
}

//과목 목록을 출력하기 위한 함수
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	//학생으로 로그인 시 학생 수강신청 목록만을 출력
	if (user != -100) {
		cout << "------------------------------------------------------------------------------------------------\n과목코드\t강의명\t\t학점\t수강가능인원\n------------------------------------------------------------------------------------------------" << endl;
		for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++) {//학생이 신청한 과목 수 만큼 반복문 실행
			int findId = -1;
			// 내가 수강 신청한 과목의 과목코드와 같은 코드르 갖는 요소의 인덱스를 lectureCodes에서 추출
			for (unsigned k = 0; k < lectureCodes.size(); k++)
			{
				if (appliedLectureCodes[user][i] == lectureCodes[k]) {
					findId = k;
					break;
				}
			}
			//인덱스를 못찾을 시 (학생이 수강신청한 과목이 하나도 없을 시)
			if (findId == -1) {
				cout << "------------------------------------------------------------------------------------------------" << endl;
			}
			//인덱스 찾을 시 바로 그 과목코드, 과목이름, 과목 학점, 과목 수강가능인원 출력
			else {
				cout << appliedLectureCodes[user][i] << '\t' << lectureNames[findId] << '\t' << lectureCredits[findId] << '\t' << limits[findId] << '\n';
			}
		}
		cout << "------------------------------------------------------------------------------------------------\n" << endl;
	}
	// 사용자가 수강신청 또는 관리자가 로그인 시 모든 과목 출력
	else if (user == -100) {
		cout << "------------------------------------------------------------------------------------------------\n과목코드\t강의명\t\t학점\t수강가능인원\n------------------------------------------------------------------------------------------------" << endl;
		for (unsigned i = 0; i < lectureCodes.size(); i++) {//모든 과목을 출력 
			cout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << '\n';
		}
		cout << "------------------------------------------------------------------------------------------------\n";
	}
}

//학생 추가
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	system("cls");

	//추가할 학생의 정보를 학번, 비밀번호, 이름 순으로 입력받음
	string studentId, password, name;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "학번 : ";
	cin >> studentId;
	cout << "비밀번호 : ";
	cin >> password;
	cout << "학생 이름 : ";
	cin >> name;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	//학생의 학번이 고유식별자로서 존재하기 위해 기존에 존재하는 학번들과 입력받은 학번을 비교 동일 학번 존재시 return true 없을 시 return false
	bool ChekInIt = false;
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentId == studentIds[i]) {
			ChekInIt = true;
		}
	}


	if (ChekInIt == true) {//동일학번 존재할시 전 학생 메뉴로 돌아감 
		cout << "이미 존재하는 학번입니다." << endl;
		system("pause");
		return;
	}
	else if (ChekInIt == false) {//중복된 학번 존재하지  않을 시 학생의 정보를 각각의 벡터의 마지막에 집어넣음, 수강가능학점은 18, 수강한과목수는 0으로 설정후 추가 
		studentIds.push_back(studentId);
		passwords.push_back(password);
		names.push_back(name);
		credits.push_back(18);
		appliedLectureCodes.push_back(vector<string>(0));
		cout << "성공적으로 등록되었습니다. " << endl;
		system("pause");
		return;
	}
}

// 새로운 과목을 개설하기 위한 함수
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	system("cls");
	string lectureName, lectureCode; int limit, lectureCredit;

	//개설한 과목을 과목코드, 과목이름 ,학점, 수강가능인원 순으로 입력받음 
	cout << "------------------------------------------------------------------------------------------------\n" << "과목코드 :";
	cin >> lectureCode;
	cout << "과목명 :";
	cin >> lectureName;
	cout << "학점 :";
	cin >> lectureCredit;
	cout << "수강인원 : ";
	cin >> limit;
	cout << "------------------------------------------------------------------------------------------------\n";

	//개설할 과목의 과목코드 또한 고유식별자로 활용하기 때문에, 중복된 과목코드 검사 
	if (findLectureByCode(lectureCodes, lectureCode) != -1) {//중복된 과목 코드 존재할 시 
		cout << "이미 존재하는 과목코드입니다.\n";
		system("PAUSE");
		return;

	}
	else if (findLectureByCode(lectureCodes, lectureCode) == -1) {//중복된 과목코드 존재하지 않을 시 입력한 정보를 각각의 벡터에 추가해줌 
		lectureCodes.push_back(lectureCode);
		lectureNames.push_back(lectureName);
		lectureCredits.push_back(lectureCredit);
		limits.push_back(limit);
		cout << "성공적으로 등록되었습니다.\n";
		system("PAUSE");
		return;

	}
}

//개설된 과목을 폐강시킴
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	while (true) {
		system("cls");
		//1. 현재 개설되어 있는 과목을 모두 표시
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
		string CodForDel;
		int lectindx = -1;

		//삭제할 과목의 코드르 입력받음 
		cout << "삭제할 강의 코드 (0: 뒤로가기) >> ";
		cin >> CodForDel;

		//삭제하려는 과목코드가 개설된 과목인지 확인하는 절차를 거치게 됨, 존재할시 CheckInIt = true, 존재하지 않을 시 CheckInIt = false 
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

		// 삭제하려는 과목이 개설되어있는 과목중에 존재하지 않음 
		if (ChekInIt == false) {
			if (CodForDel == "0") {//관리자 메뉴로 돌아가는 '0'을 입력했을 시
				system("pause");
				return;
			}

			//삭제하려고 하는 과목코드가 존재하지 않을 시 
			cout << "일치하는 코드가 없습니다." << endl;
			system("pause");

		}
		//삭제하려고 하는 과목코드가 존재할 시 
		else if (ChekInIt == true) {
			//삭제할 과목의 인덱스를 lectindx에 저장
			lectindx = findLectureByCode(lectureCodes, CodForDel);
			//그 과목을 수강신청한 학생들을 모두 찾아야하기 때문에 학생수만큼의 반복문을 실행함 
			for (unsigned k = 0; k < appliedLectureCodes.size(); k++) {
				//특정 학생에서 학생이 수강신청한 과목수 만큼의 반복문을 실행 
				for (unsigned i = 0; i < appliedLectureCodes[k].size(); i++) {
					//삭제할 코드가 학생이 수강신청한 과목중에 존재할 시 --> (학생의 수강가능학점 + 삭제할 과목코드의 학점), 
					//(삭제할 과목의 수강가능인원 +1), (학생의 수강신청 과목목록에서 해당과목 삭제)를 순서대로 진행  
					if (CodForDel == appliedLectureCodes[k][i]) {
						credits[k] += lectureCredits[lectindx];
						limits[lectindx] += 1;
						deleteElement(appliedLectureCodes[k], i);
					}
				}
			}

			// 그 과목의 인덱스(lectindx)의 요소를 과목 관련 벡터에서 모두 삭제
			deleteElement(lectureCodes, lectindx);
			deleteElement(lectureNames, lectindx);
			lectureCredits.erase(lectureCredits.begin() + lectindx);
			limits.erase(limits.begin() + lectindx);
			cout << "성공적으로 강의가 폐쇄되었습니다." << endl;

			system("pause");
		}
	}
}

//관리자의 로그인을 통합관리하는 매뉴 관련함수
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	while (true) {//종료 관련 메뉴(0) 입력할 때 까지 함수 실행
		system("cls");
		int ChosNum = -1;
		cout << "------------------------------------------------------------------------------------------------\n1. 학생 추가\n2. 강의 개설\n3. 강의 삭제\n4. 로그아웃\n0. 종료\n------------------------------------------------------------------------------------------------" << endl << ">> ";
		cin >> ChosNum;

		if (ChosNum == 1) {//힉생 추가
			addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
		}
		else if (ChosNum == 2) {//과목 추가
			addLecture(lectureCodes, lectureNames, lectureCredits, limits);
		}
		else if (ChosNum == 3) {//과목삭제
			deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
		}
		else if (ChosNum == 4) {//로그아웃
			system("cls");
			return -1;
		}
		else if (ChosNum == 0) {//종료
			return 1;
		}
	}
}

//학생의 정보를 출력하는 함수
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "학번: " << studentIds[user] << '\t' << "이름 :" << names[user] << '\t' << "수강가능학점: " << credits[user] << "\n------------------------------------------------------------------------------------------------\n";
}


//학생이 수강신청 할 수 있도록 하는 함수
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {

	while (true) {
		system("cls");
		//학생의 정보, 수강신청 가능한 과목들을 출력
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, -100);
		string CodeForApply;

		//학생에게 신청할 과목코드를 입력받음
		cout << "신청할 과목 코드(0 : 뒤로가기) >> ";
		cin >> CodeForApply;

		if (CodeForApply == "0") {
			system("pause");
			return;
		}
		else {
			int index = findLectureByCode(lectureCodes, CodeForApply);
			if (index == -1) {
				cout << "존재하지 않는 과목코드입니다." << endl;
				system("pause");
			}
			else {
				// 나의 수강 목록에 같은 코드가 있을 시 true
				bool CheckInit = false;
				for (unsigned i = 0; i < appliedLectureCodes[user].size(); i++)
					if (CodeForApply == appliedLectureCodes[user][i]) {
						CheckInit = true;
						break;
					}
				//코드는 다르지만 이름이 같은 수강항목존재 비교를 위해 내 수강목록의 이름 추출을 위해 내수강 과목코드와 기존과목코드와의 비교를 통해 기존과목코드의 인덱스
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
				//과목의 수강가능인원이 0명으로 더이상 수강신청을 받을 수 없을 시
				if (limits[index] == 0) {
					cout << "수강 인원이 꽉 찼습니다." << endl;
					system("pause");
				}
				//학생의 수강가능학점이 해당 과목의 학점에 비해 부족할 시
				else if (credits[user] < lectureCredits[index]) {
					cout << "수강가능학점이 부족합니다." << endl;
					system("pause");
				}
				//학생이 이미 해당 과목을 신청했을 시
				else if (CheckInit == true) {
					cout << "이미 해당 과목을 신청했습니다." << endl;
					system("pause");
				}
				//학생이 이미 동일한 이름을 가진 다른코드의 과목을 신청했을 시
				else if (CheckRepeat == true) {
					cout << "이미 동일명의 과목을 신청했습니다." << endl;
					system("pause");
				}
				//수강신청 가능한 경우
				else {
					appliedLectureCodes[user].push_back(CodeForApply);
					cout << "[" << CodeForApply << "] " << lectureNames[index] << " 을(를) 성공적으로 신청하였습니다." << endl;
					//학생 수강가능 학점 차감
					credits[user] -= lectureCredits[index];
					//해당 과목의 수강 가능 인원 차감;
					limits[index] -= 1;
					system("pause");
				}
			}
		}
	}

}

//수강신청 철회를 위한 메뉴
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	while (true) {
		system("cls");
		//학생의 수강신청목록을 출력함
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		string LectureCodeForDisapply;

		//수강철회할 과목코드 입력받음
		cout << "철회할 과목 코드(0 : 뒤로가기) >> ";
		cin >> LectureCodeForDisapply;

		//입력받은 코드가 '0'일시 학생메뉴로 돌아감
		if (LectureCodeForDisapply == "0") {
			system("PAUSE");
			return;
		}
		//내가 수강 철회할 코드의 과목 인덱스를 user의 수강 목록 벡터에서 검색
		int findIndex = findLectureByCode(appliedLectureCodes[user], LectureCodeForDisapply);

		//내가 수강한 목록 중에 철회할 항목이 없을 시
		if (findIndex == -1) {
			cout << "과목 코드가 올바르지 않습니다. " << endl;
			system("pause");
		}
		else {
			//내가 철회할 코드를 나의 수강목록중에 지움
			deleteElement(appliedLectureCodes[user], findIndex);
			//철회 과목의 수강가능인원+1
			int findcreditindex = findLectureByCode(lectureCodes, LectureCodeForDisapply);
			limits[findcreditindex] += 1;

			//나의 credit 회복
			credits[user] += lectureCredits[findcreditindex];

			cout << "[" << LectureCodeForDisapply << "] " << lectureNames[findcreditindex] << "(을)를 철회하였습니다. " << endl;
			system("PAUSE");
		}
	}

}

//학생의 비밀번호를 바꾸기 위한 함수
void changePassword(vector<string>& passwords, const int& user) {
	string InputPassword = "";
	//학생의 비밀번호를 다시한번 입력받음
	cout << "------------------------------------------------------------------------------------------------" << "\n비밀번호를 한 번 더 입력해주세요. \n" << "비밀번호 : ";
	cin >> InputPassword;
	cout << "------------------------------------------------------------------------------------------------\n";

	//학생에게 입력받은 비밀번호와 해당 학생의 비밀번호가 일치 할 시 비밀번호 변경 허용
	if (InputPassword == passwords[user]) {
		string NewPassword;
		cout << "------------------------------------------------------------------------------------------------\n" << "새로 설정할 비밀번호를 입력하세요.\n" << "비밀번호 : ";
		//변경한 비밀번호 입력
		cin >> NewPassword;
		passwords[user] = NewPassword;
		cout << "변경되었습니다.\n" << "------------------------------------------------------------------------------------------------\n";
		system("pause");
		return;
	}
	//학생에게 입력받은 비밀번호와 해당 학생의 비밀번호가 일치하지 않을 시 학생 메뉴로 돌아감
	else {
		cout << "비밀번호가 일치하지 않습니다.\n";
		system("pause");
		return;
	}
}

//전체적인 학생 관련 메뉴를 운용하는 함수
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	while (true) {//학생이 0번을 선택해 프로그램을 종료 시킬때까지 작동
		system("cls");
		int ChosNum = -1;
		//메뉴출력
		cout << "------------------------------------------------------------------------------------------------\n1. 수강 신청\n2. 수강 현황\n3. 수강 철회\n4. 비밀번호 변경\n5. 로그아웃\n0. 종료\n------------------------------------------------------------------------------------------------" << endl;
		cin >> ChosNum;
		//1번을 선택해 수강신청메뉴로 들어가는 경우
		if (ChosNum == 1) {
			system("cls");
			applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
		//2번을 선택해 수강 현황을 보려는 경우
		else if (ChosNum == 2) {
			system("cls");
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("pause");
			system("cls");
		}
		//3번을 선택해 수강을 철회하려는 경우
		else if (ChosNum == 3) {
			system("cls");
			disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
		//4번을 선택해 비밀번호를 변경하려는 경우
		else if (ChosNum == 4) {
			system("cls");
			changePassword(passwords, user);
		}
		//5번을 선택해 로그아웃을 하려는 경우
		else if (ChosNum == 5) {
			system("cls");
			return -1;
		}
		//0번을 선택해 프로그램을 종료하려는 경우
		else if (ChosNum == 0) {
			return 1;

		}
	}
}