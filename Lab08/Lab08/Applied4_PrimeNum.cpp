#include <iostream>
#include <vector>

using namespace std;

int inputGrade(float grade) {
	cin >> grade;
	if ((grade - (int)grade) != 0.0 || grade < 0 || grade >100) {
		cout << "invalid input!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
		return (int)grade;
}

int* topGrade(const vector<int>& grade){
	int i = 1;
	int k = grade[0];
	while ( i < grade.size()) {
		if (k <= grade[ i ])
			k = grade[ i ];
		else
			k = k;
		i++;
	}
	
	return &k;
}

int main() {
	vector<int> grades;
	float _grade = 0;
	for (int i = 0; i < 3; i++) {
		cout << "input " << i << "-th grade(0~100): ";
		int grade = inputGrade(_grade);
		grades.push_back(grade);
	}
	int k = *topGrade(grades);
	cout << "Top Grade : " << k;
		


	return 0;
}