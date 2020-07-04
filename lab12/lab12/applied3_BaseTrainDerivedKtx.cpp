#include <iostream>

using namespace std;

class Train {
public:
	Train(){}
	Train(int people){
		mPeople = people;
	}
	~Train(){}
	virtual int station (int takeOff, int takeOn ){
		Train::mPeople -= takeOff;
		Train::mPeople += takeOn;
		return Train::mPeople;
	}
protected:
	int mPeople;
};

class Ktx : public Train {
public:
	int getPPeople() { return Train::mPeople; }
	Ktx()
		:Train::Train(0){}
	Ktx(int people)
		:Train::Train(people){}
	~Ktx(){}
	//기차에 사람이 타고 내리는 함수
	int station (int takeOff, int takeOn) override {
		Train::mPeople -= takeOff;
		Train::mPeople += takeOn;
		if (mPeople < 0) {
			cout << "정원 미달입니다." << endl;
		}
		if (mPeople > 300) {
			cout << "정원초과입니다." << endl;
		}
		return Train::mPeople;
	}
	int getPeople() {
		return Train::mPeople;
	}
};

int main() {
	Ktx k;
	int i = 0;
	int out, in, a;
	while (i<5) {
		if (i == 0) {
			a = k.getPeople();
		}
		cout << i + 1 << "번역 :";
		cin >> out >> in;
		k.station(out, in);
		i++;

		if (a > k.getPeople()) {
			a = a;
		}
		else {
			a = k.getPeople();
		}
	}

	cout << "가장 많은 사람이 탑승 했을 때의 사람 수 : " << a << endl;
	return 0;
}