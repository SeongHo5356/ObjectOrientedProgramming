/*#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int sum(vector<int> v) {
	int result = 0;
	for (int elem : v)
		result += elem;

	return result;
}

void print(vector<int>& v) {
	for (int t = 0; t < v.size(); t++ )
		cout << setw(4) << v[t];
	cout << endl;
}


int main() {
	// index :       0   1   2   3(==size()-1)
	vector<int> vec{ 10, 20, 30, 40 };
	
	cout << vec.size() << endl;
	print(vec);

	vec[0] = 100;
	vec.at(1) = 200;
	print(vec);

	vec.push_back(50); //인덱스 맨 끝에 값 추가
	print(vec);

	vec.pop_back();
	print(vec);

//	for (int i = 0;i < vec.size(); i++)
//		cin >> vec[i];

	//int& elem = vec[0] -> body(cin >> elem )
	//int& elem = vec[1] -> body(cin >> elem )
	//int& elem = vec[2] -> body(cin >> elem )
	//int& elem = vec[3] -> body(cin >> elem )
	//마지막 element 까지 

	for (int& elem : vec)
		cin >> elem;

	//int elem = vec[0]; //body(cout<<endl)
	//int elem = vec[1]; //body(cout<<endl)
	//마지막 element 까지
	for (int elem : vec)
		cout << setw(4) << elem;
	
	cout << endl;

	cout << sum(vec) << endl;

	print(vec);

	return 0;
}*/
