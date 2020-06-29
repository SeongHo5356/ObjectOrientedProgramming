/*#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

//소수 : 2개의 약수(1과 자기자신)을 가지는 수
void print(const vector<int>& v) {
	for (int elem : v)
		cout << setw(4) << elem;
	cout << endl;
}

bool is_prime(int n) {
	if (n <= 1)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}


vector<int> primes(int low, int high) {
	vector<int> vec;
	for (int i = low; i <= high; i++)
		if (is_prime(i))
			vec.push_back(i);
	return vec;
}

int main() {
	int low, high;
	cin >> low >> high;
	vector<int> vec = primes(low, high);

	print(vec);
	return 0;
}

////////////

void print(const Matrix& v) {
//	for (int row = 0; row < v.size(); row++) {
//		for (int col = 0; col < v[row].size(); col++)
//			cout << setw(4) << v[row][col];
//		cout << endl;
//	}
	for (const auto row : v) {
		for (auto col : row)
			cout << setw(4) << col;
		cout << endl;
	}
}
int main() {
//	vector<vector<int>> vec(2, vector<int>(3)); //2X3
//	vec[0][0] = 1;
//	vec[0][1] = 2;
//	vec[0][2] = 3;
//	vec[1][0] = 4;
//	vec[1][1] = 5;
//	vec[1][2] = 6;

	vector<vector<int>> vec{ {1,2,3},
							{4,5,6} };

	print(vec);
//유추 가능한 경우, 자료형 부분을 auto로 치환 가능
	auto a = 10;
	auto b = 10.0;
	auto c = 'c';
//	int d;


	return 0;
}

/////////

int sum(int* list, int size) {//int list[] = int* list
	int result = 0;
	for (int i = 0; i < size; i++)
		result += list[i];
	return result;


}
void print(int* begin, int* end) {
	int* curr = begin;
	while (curr != end) {
		cout << setw(4) << *curr;
		curr++;
	}
	cout << endl;
}

//pointr +1 :다음 element의 주소값으로 이동 
//list : 배열의 0번째 element의 주소값(배열의 시작 주소값)저장 
int main() {
	int list[] = { 10, 20 ,30 };
//	cout << sum(list, 3 ) << endl;
	cout << list << '\t' << *list << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;
	cout << (list + 2) << '\t' << *(list + 2) << endl;

	int* begin = list;
	int* end = list + 3;

	print(begin, end);
	return 0;
}
*/



