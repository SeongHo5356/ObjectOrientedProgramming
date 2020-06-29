#include <iostream>
using namespace std;

/*
//pass by value (int a, int b) int a = x; int b = y;
//pass by reference (int& a, int& b) int& a = x, int& y = b 
//pass by pointer (int* a, int* b) int* a = &x, int* b = &y
void swap(int* a, int* b) {
	int temp; 
	temp = *a;  //int 와 int* 위상이 다름
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
// &a: a의 주소값을 반환
// int* pa; (int*) 정수형 변수의 메모리 주소값을 저장하는 data type 
// float* 실수형 변수의 메모리 주소값을 저장하는 data type

int main() {
	int a = 10;
	int* pa = &a; //pa라는 포이터형 변수에 a의 주소값을 할당
	
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
	int(*func)(int, int); //함수포인터 : 함수의 시작주소값을 저장하는 변수
	
	func = &sum;
	cout << func(10, 20) << endl;

	func = &mult;
	cout << func(10, 20) << endl;
	
	cout << evaluate(&sum, 10, 20) << endl;
	cout << evaluate(&mult, 10, 20) << endl;
	
	return 0;
}*/

