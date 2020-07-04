#include <iostream>
using namespace std;
int get_num();
int myadd(int x, int y);
int mysub(int x, int y);
int mymul(int x, int y);
float mydiv(int x, int y);
int addmul(int x, int y, int z);
float subdivsub(int x, int y, int z);
int addmuladd(int x, int y, int z);
float muldiv(int x, int y, int z);

float main() {
	float x, y, z;
	x = get_num();
	y = get_num();
	z = get_num();
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << float(muldiv(x, y, z)) << endl;
	cout << "(x + y) * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;
	return 0;
}
int get_num() {
	float num;
	cout << "Enter a number: " ;
	cin >> num;
	return num;
}
int myadd(int x, int y) {
	return x + y;
}
int mysub(int x, int y) {
	return float(x) - float(y);
}
int mymul(int x, int y) {
	return x * y;
}
float mydiv(int x, int y) {
	return float(x) / y;
}
int addmul(int x, int y, int z) {
	int k;
	k = myadd(x, y);
	return mymul(k, z);
}
float muldiv(int x, int y, int z) {
	int k;
	k = mymul(x, y);
	return float(mydiv(k, z));
}
int addmuladd(int x, int y, int z) {
	int s;
	int k;
	int r;
	k = myadd(x, y);
	s = myadd(y, z);
	r = mymul(k, s);
	return r;
}
float subdivsub(int x, int y, int z) {
	int k;
	float r;
	int s;
	k = mysub(x, y);
	s = mysub(y, z);
	r = mydiv(k, s);
	return r;
}