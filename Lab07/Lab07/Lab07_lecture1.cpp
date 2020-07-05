#include <iostream>
#include <fstream>
using namespace std;
bool readStu(ifstream& fin, int& id, int& score1, int& score2, int& score3) {
	fin >> id >> score1 >> score2 >> score3;
	if (!fin)
		return false;
	else
		return true;
}
void calcGrade(int& score1,int& score2,int& score3,int& avg,char& grade){
	avg = (score1 + score2 + score3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else if (avg >= 70)
		grade = 'C';
	else if (avg >= 60)
		grade = 'D';
	else
		grade = 'F';

}
void writeStu(ofstream& fout,int id,int avg,char grade) {
	fout.width(4);
	fout.fill('0');
	fout<< id;
	
	fout.fill(' ');
	fout.width(3);
	fout << avg;

	fout.width(2);
	fout << grade << endl;
}

int main() {
	double a = 13.345678;

	cout << a << endl;
	
	cout.width(15);
	cout.precision(4);
	cout.fill('-');
	cout << a << endl;

	
	return 0;
}

/*int main() {
	char ch;

	cin.setf(ios::skipws);
	cin >> ch;
	cout << '(' << ch << ')' << endl;

	return 0;
}*/

/*int main() {
	//C:\Users\kjeng\source\repos\lab7_2019102129_����Ʈ���������а�_����ȣ\lab7_2019102129_����Ʈ���������а�_����ȣ\
	// line by line ���� �ݺ� 
		// 1) �л� ������ ���Ϸκ��� 1�پ� �Է¹ޱ�(id ,sc1, sc2, s3)
		// 2) sc1, sc2, sc3�� ������ ��հ��� grade ���ϱ�
		// 3) grade.txt���ٰ� �л��� id, avg, grade�� ���� 
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");
	int id, score1, score2, score3, avg;
	char grade;

	if (!fin || !fout) {
		cout << "File open error" << endl;
		exit(100);
	}

	//getline(fin, s)
	while (readStu(fin, id, score1, score2, score3)) {
		calcGrade(score1, score2, score3, avg, grade);
		writeStu(fout, id, avg, grade);
	}
	cout << "Finish" << endl;


	fin.close();
	fout.close();

	return 0;
}*/
