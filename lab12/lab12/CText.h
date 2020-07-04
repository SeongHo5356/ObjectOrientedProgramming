#pragma once
#include <iostream>
#include <string>
using namespace std;

//�߻�(abstract) Ŭ����
// - ��� �ϳ��� ���� ���� �Լ��� ����
// - instance(��ü) ȭ �� �� ����(pointer�θ� ����)
// - ���� �����Լ��� �ݵ�� �ڽ� Ŭ�������� overriding�� �����

class Text {
protected:
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() = 0;
	virtual void append(string _extra) = 0;
};
