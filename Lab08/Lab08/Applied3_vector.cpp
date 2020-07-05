#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void rev(vector<int>& v) {
	reverse(v.begin(), v.end());
}


void print(vector<int> v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << setw(4) <<v[i];
	
	cout << endl;
}

int main() {
	vector<int> vec(10);
	for (unsigned i=0;i<vec.size();i++){
		vec[i] = i + 1;
	}
	cout << "�⺻ Vector �� : " << endl;
	print(vec);

	rev(vec);

	cout << "�Լ� ���� �� Vector �� : "<<endl;
	print(vec);

	return 0;
}