#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CText.h"
using namespace std;

class FixedText : public Text {
public:
	FixedText() : Text::Text("Fixed") {}
	string get() override;
	void append(string _extra) override;
};

