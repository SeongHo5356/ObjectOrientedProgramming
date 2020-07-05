
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class Iter>
void print(Iter iter_begin, Iter iter_end) {
	for (Iter iter = iter_begin; iter != iter_end; iter++) {
		cout << *iter << '\t';
	}
	cout << endl;
}

void allocatevector(vector<int>& v,int size) {
	vector<int>::iterator iter_begin = v.begin();
	vector<int>::iterator iter_end = v.end();
	for (vector<int>::iterator iter = iter_begin; iter != iter_end; iter++) {
		*iter = rand() % size + 1;
	}
}


int CalMax(vector<int> v1,  vector<int> v2) {
	int Max = 0;
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) {
		for (vector<int>::iterator iterv = v2.begin(); iterv != v2.end(); iterv++) {
			if (Max >= (*iter) * (*iterv)) {
				Max = Max;
			}
			else {
				Max = (*iter) * (*iterv);
			}
		}
	}
	return Max;
}

int CalMin(vector<int> v1, vector<int> v2) {
	int Min = 0;
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter++) {
		for (vector<int>::iterator iterv = v2.begin(); iterv != v2.end(); iterv++) {
			if (Min <= (*iter) * (*iterv)) {
				Min = Min;
			}
			else {
				Min = (*iter) * (*iterv);
			}
		}
	}
	return Min;
}



int main() {

	srand(time(NULL));
	vector<int> v1(10);
	allocatevector(v1, 10);
	vector<int> v2(10);
	allocatevector(v2, 20);

	cout << "<vector 1>" << endl;
	print(begin(v1), end(v1));
	cout << endl;

	cout << "<vector 2>" << endl;
	print(begin(v2), end(v2));
	cout << endl << endl;

	cout << "ÃÖ´ñ°ª : " << CalMax(v1, v2) << endl;
	cout << "ÃÖ¼Ú°ª : " << CalMin(v1, v2) << endl;


	return 0;
}