#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream read1;
	ifstream read2;
	ofstream write;
	string s1,s2;


	read1.open("text1.txt");
	read2.open("text2.txt");
	write.open("text3.txt");

	if (!read1 || !read2 || !write) {
		cout << "File open error" << endl;
		exit(100);
	}

	while (getline(read1, s1)) {
		write << s1 << endl;
	}
	write << endl;

	while (getline(read2, s2)) {
		write << s2 << endl;
	}
	
	read1.close();
	read2.close();
	write.close();

	return 0;
}