#include <iostream>
#include <string>

using namespace std;

//포인터로서 역할 
class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0; 
		health = 0;
	}
	~Avengers() {}
		// 캐릭터 설정 함수
		virtual void set(string _name, int _attack, int _defense, int _health) {
			name = _name;
			attack_point = _attack;
			defense_point = _defense;
			health = _health;
		}
		// 공격 함수
		virtual int attack() { return 0; }
		// 방어 함수
		virtual void defense(int _attack_point) { }
		// 캐릭터 정보 출력 함수
		virtual void print_info() {  }
	
protected:
	string name; // 캐릭터 이름
	int attack_point; // 공격력
	int defense_point; // 방어력
	int health; // 체력
};


class Character : public Avengers {
public :
	

	int get_health() { return health; }
};

int main() {
	Character my_char;
	Character enemy_char;
	string MY_CHAR;
	cout << "Choose your character(Ironman, CaptainAmerica, Thor) : ";
	cin >> MY_CHAR;

	cout << endl << "--Battle--" << endl;
	cout << "My Life : " << my_char.get_health() << "\t"
		<< "Enemy life : " << enemy_char.get_health() << endl;

	while (1) {

	}
	return 0;
}