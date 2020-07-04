#include <iostream>
#include <string>
#include <vector>

using namespace std;

//function overloading 
//function overriding : 상속에 한해서 정의 -> virtual in base class override in derived class
//override virtual 써주어야지 동적 바인딩 가능
//Dervied class is a Base class 
//but the base class is not a base class
//할당 가능 t1 = t2 그러나 방향성이 있음

//
class Text {
private:
	string text;
public:
	Text(string _t) : text(_t) {}
	//virtual string get() { return text; }
	virtual string get() = 0; //순수 가상 함수
	virtual void append(string _extra) { text += _extra; }

};

class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _c)
	//생성자를 통해 text 접근
		:	Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_c){}
	//public method를 통해서 text에 접근
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
	
	//up-casting(자식이 부모에게 할당 가능)
	t1 = t3;// base class <- derived class 가능 
	cout << t1.get() << endl;
	
	//down -cating 불가능
	//t2 = t1;
	//cout << t2.get() << endl;
	//가지고있는 정보의 크기의 차이

	//static binding
	//dynamic binding
	//vtable and virtual funtion make it possible
	//Polymorphism(다형성) 구현 가능 ---> finally we arrived ! !!!기말시험에 나옴
	
	//다형성 응용
	//객체의 주소값 저장 
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
		//객체의 주소값을 저장하고 있기 때문에 . 아닌 -> 사용
		elem->append("A");
	}
	for (auto& elem : vec) {
		cout << elem->get() << endl;
	}
	for (auto& elem : vec) {
		delete elem;
	}
	//부모 class 에서 protected 선언 가능
	//부모 자식 모두 private class 로 설정됨

	return 0;
}