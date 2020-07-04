#pragma once
#include <iostream>
#include <string>
using namespace std;

//추상(abstract) 클래스
// - 적어도 하나의 순수 가상 함수를 가짐
// - instance(객체) 화 할 수 없음(pointer로만 사용됨)
// - 순수 가상함수는 반드시 자식 클래스에서 overriding해 줘야함

class Text {
protected:
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() = 0;
	virtual void append(string _extra) = 0;
};
