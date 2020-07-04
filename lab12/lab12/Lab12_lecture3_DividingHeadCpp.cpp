#include <iostream>
#include <string>
#include <vector>
#include "CFancyText.h"
#include "CText.h" //적어줘도 되고 안적어줘도 됨
#include "CFixedText.h"

using namespace std;
// 1. class의 선언부와 구현부를 구분
// 2. 선언부를 헤더(.h), 구현부를 소스(.cpp)파일에 분리해서 저장

int main(){
	//부모클래스의 주소값을 벡터의 element로 가지게 함
	vector<Text*> vec{ new FancyText("Fancy","<<",">>","**"), new FixedText() };
	//추상 클래스는 포인터로만 사용가능 
	Text* pText;
	pText = new FancyText("Fancy2", "(", ")", "-"); //pText = 0X00
	vec.push_back(pText); // vec[2] = 0X00
	pText = new FixedText; // pText = 0X01
	vec.push_back(pText); //vec[3] = 0X01 
	pText = NULL;
	
	for (Text* elem : vec) {
		elem->append("A");
	}
	for (auto elem : vec) {
		cout << elem->get() << endl;
	}
	//동적 할당 해제
	for (auto elem : vec) {
		delete elem;
	}
	
	return 0;
}