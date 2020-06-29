#include <iostream>
using namespace std;

/*
//pass by value (int a, int b) int a = x; int b = y;
//pass by reference (int& a, int& b) int& a = x, int& y = b 
//pass by pointer (int* a, int* b) int* a = &x, int* b = &y
void swap(int* a, int* b) {
	int temp; 
	temp = *a;  //int �� int* ������ �ٸ�
 	*a = *b;
	*b = temp;   
}


int main() {
	int x = 10;  int y = 20;
	cout << x << ", " << y << endl;
	swap(&x, &y);
	cout << x << ", " << y << endl;
	return 0;
}*/

/*
// &a: a�� �ּҰ��� ��ȯ
// int* pa; (int*) ������ ������ �޸� �ּҰ��� �����ϴ� data type 
// float* �Ǽ��� ������ �޸� �ּҰ��� �����ϴ� data type

int main() {
	int a = 10;
	int* pa = &a; //pa��� �������� ������ a�� �ּҰ��� �Ҵ�
	
	cout << &a << ", " << a << endl;
	cout << pa << ", " << *pa << endl;
	
	return 0;
}*/

/*int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int(*func)(int, int), int a, int b) {
	return func(a, b);
}
int main() {
	int(*func)(int, int); //�Լ������� : �Լ��� �����ּҰ��� �����ϴ� ����
	
	func = &sum;
	cout << func(10, 20) << endl;

	func = &mult;
	cout << func(10, 20) << endl;
	
	cout << evaluate(&sum, 10, 20) << endl;
	cout << evaluate(&mult, 10, 20) << endl;
	
	return 0;
}*/

