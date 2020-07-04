#pragma once
#include <iostream>
#include<string>
#include "CText.h""

using namespace std;

class FancyText : public Text {

private:
	string left_brac;
	string right_brac;
	string connector;

public:
	FancyText(string _t, string _lb, string _rb, string _con)
		: Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}

	string get() override;
	void append(string _extra) override;

};

