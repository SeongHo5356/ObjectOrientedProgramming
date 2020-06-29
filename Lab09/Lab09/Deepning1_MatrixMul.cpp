#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>

using namespace std;

void print_matrix(vector<vector<int>> vec) {
    for (vector<int>& row : vec) {
        for (int col : row) {
            cout << setw(4) << col;
        }
        cout << endl;
    }

}


vector<vector<int>> make_matrix(int irow, int icol) {
    vector < vector<int>> vec(irow, vector<int>(icol));
    for (int k = 0; k < irow; k++) {
        for (int i = 0; i < icol; i++) {
            vec[k][i] = rand() % 19 - 9; 
        }
    }
    return vec;

}

vector<vector<int>> mul(int rowA, int colA, int colB, vector<vector<int>>& vec1, vector<vector<int>>& vec2)
{
    vector<vector<int>> vec(rowA, vector<int>(colB));
    int result = 0;
    for (int i = 0; i < rowA; i++) {
        for (int a = 0; a < colB; a++) {
            for (int k = 0; k < colA; k++) {
                result = vec1[i][k] * vec2[k][a];
            }
            vec[i][a] = result;
        }
    }
    return vec;
}

int main()
{
    srand(int(time(0)));
    int frow, fcol;
    int srow, scol;
    cout << "A�� ��, ���� ũ�⸦ �Է����ּ��� : ";
    cin >> frow >> fcol;
    cout << "B�� ��, ���� ũ�⸦ �Է����ּ��� : ";
    cin >> srow >> scol;
    if (frow == 0 || srow == 0 || fcol == 0 || scol == 0) {
        cout << "����� ������ �� �����ϴ�. ";
        		exit(EXIT_FAILURE);
    }

    if (fcol != srow) {
        cout << "�� ����� ���� �� �����ϴ�.";

    }

    else {
        vector<vector<int>> A = make_matrix(frow, fcol);
        cout << "A�� ���: " << endl;
        print_matrix(A);
        vector<vector<int>> B = make_matrix(srow, scol);
        cout << "B�� ���: " << endl;
        print_matrix(B);
        cout << "AB ����� : " << endl;
        print_matrix(mul(frow, fcol, scol, A, B));
    }
}
