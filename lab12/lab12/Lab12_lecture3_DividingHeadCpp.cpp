#include <iostream>
#include <string>
#include <vector>
#include "CFancyText.h"
#include "CText.h" //�����൵ �ǰ� �������൵ ��
#include "CFixedText.h"

using namespace std;
// 1. class�� ����ο� �����θ� ����
// 2. ����θ� ���(.h), �����θ� �ҽ�(.cpp)���Ͽ� �и��ؼ� ����

int main(){
	//�θ�Ŭ������ �ּҰ��� ������ element�� ������ ��
	vector<Text*> vec{ new FancyText("Fancy","<<",">>","**"), new FixedText() };
	//�߻� Ŭ������ �����ͷθ� ��밡�� 
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
	//���� �Ҵ� ����
	for (auto elem : vec) {
		delete elem;
	}
	
	return 0;
}