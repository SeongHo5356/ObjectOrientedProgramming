#include <iostream>
#include <string>
#include <vector>

using namespace std;

//function overloading 
//function overriding : ��ӿ� ���ؼ� ���� -> virtual in base class override in derived class
//override virtual ���־���� ���� ���ε� ����
//Dervied class is a Base class 
//but the base class is not a base class
//�Ҵ� ���� t1 = t2 �׷��� ���⼺�� ����

//
class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	//virtual string get() { return text; }
	virtual string get() = 0; //���� ���� �Լ�
	virtual void append(string _extra) { text += _extra; }

};

class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _c)
	//�����ڸ� ���� text ����
		:	Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_c){}
	//public method�� ���ؼ� text�� ����
	string get() override { return left_brac + Text::get() + right_brac; }
	void append(string _extra) override { 
		Text::append(connector + _extra);
	}


};

class FixedText : public Text {
public:
	FixedText() : Text::Text("Fixed"){}
	void append(string _extra) override { 
	// No Operation
	}

};
int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", " <<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	
	//up-casting(�ڽ��� �θ𿡰� �Ҵ� ����)
	t1 = t3;// base class <- derived class ���� 
	cout << t1.get() << endl;
	
	//down -cating �Ұ���
	//t2 = t1;
	//cout << t2.get() << endl;
	//�������ִ� ������ ũ���� ����

	//static binding
	//dynamic binding
	//vtable and virtual funtion make it possible
	//Polymorphism(������) ���� ���� ---> finally we arrived ! !!!�⸻���迡 ����
	
	//������ ����
	//��ü�� �ּҰ� ���� 
	vector<Text*> vec{
		new Text("Plain"),
		new FancyText("Fancy", "(", ")", "-"),
		new FixedText()
	};
		
	Text* pText;
	pText = new FancyText("Fancy2", "{", "}", "^");
	vec.push_back(pText);
	pText = new Text("Plain2");
	vec.push_back(pText);

	for (auto& elem : vec) {
		//��ü�� �ּҰ��� �����ϰ� �ֱ� ������ . �ƴ� -> ���
		elem->append("A");
	}
	for (auto& elem : vec) {
		cout << elem->get() << endl;
	}
	for (auto& elem : vec) {
		delete elem;
	}
	//�θ� class ���� protected ���� ����
	//�θ� �ڽ� ��� private class �� ������

	return 0;
}