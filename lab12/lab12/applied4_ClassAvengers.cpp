#include <iostream>
#include <string>

using namespace std;

//�����ͷμ� ���� 
class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0; 
		health = 0;
	}
	~Avengers() {}
		// ĳ���� ���� �Լ�
		virtual void set(string _name, int _attack, int _defense, int _health) {
			name = _name;
			attack_point = _attack;
			defense_point = _defense;
			health = _health;
		}
		// ���� �Լ�
		virtual int attack() { return 0; }
		// ��� �Լ�
		virtual void defense(int _attack_point) { }
		// ĳ���� ���� ��� �Լ�
		virtual void print_info() {  }
	
protected:
	string name; // ĳ���� �̸�
	int attack_point; // ���ݷ�
	int defense_point; // ����
	int health; // ü��
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