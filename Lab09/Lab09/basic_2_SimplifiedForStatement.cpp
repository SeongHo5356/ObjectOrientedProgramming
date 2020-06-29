#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using Matrix = vector<vector<int>>;

void print(const Matrix& mat) {
//	for (unsigned row = 0; row < mat.size(); row++) {
//		for (unsigned col = 0; col < mat[row].size(); col++) {
//			//mat.at(row).at(col);
//			cout << setw(4) << mat[row][col];
//		}
//		cout << endl;
//	}
//	for (const vector<int> row : mat) {
//		for (int col : row) {
//			cout << setw(4) << col;
//		}
//		cout << endl;
//	}
	
	//유추 가능한 경우, 자료형 부분을 auto로 치환가능
	//vector<int> row = mat[0];
	// == auto row = mat[0];
	//auto 와 벡터 원소를 이용하여 for문 구현
	for (const auto& row : mat) {
		for(auto col : row){
			cout << setw(4) << col;
		}
		cout << endl;
	}
}

int main() {
	Matrix mat{ {1, 2, 3},
	{4, 5, 6} };
//	mat[0][1] = 1; mat[1][1] = 4;
//	mat[0][2] = 2; mat[1][2] = 5;
//	mat[0][3] = 3; mat[1][3] = 6;

	print(mat);

	return 0;
}