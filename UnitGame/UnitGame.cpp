#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Unit {
protected:
	int type;
	string name;
	int price;
public:
	Unit(int _type, string _name, int _price) 
		:type(_type),name(_name),price(_price){}
	virtual void print() = 0;
	virtual int action() = 0;
	int get_type() { return type; }
	string get_name() { return name; }
	int get_price() { return price; }
};

class Attacker : public Unit {
protected:
	int attack_point;
public:
	Attacker(int _type, string _name, int _price, int _attack_point)
		:Unit::Unit(_type, _name, _price), attack_point(_attack_point){}
	
	int action() override { return attack_point; }
	void print() override {
		cout << "Name : " << Unit::get_name
			<< "(Attack point : " << Attacker::attack_point
			<< "Price : " << Unit::get_price << ")" << endl;
	}
};

class Miner : public Unit {
protected:
	int mining_point;
public:
	Miner(int _type, string _name, int _price, int _mining_point)
		:Unit::Unit(_type, _name, _price), mining_point(_mining_point){}

	int action() override { return mining_point; }
	void print() override {
		cout << "Name : " << Unit::get_name
			<< "(Mining point : " << Miner::mining_point
			<< "Price : " << Unit::get_price << ")" << endl;
	}
};

class ApplicationType {
private:
	vector<Unit*> unit_list_in_barracks; // 고용가능한 unit list
	vector<Unit*> unit_list; // 고용된 unit list
	int curr_turn; // 현재 turn
	int MAX_turn; // 최대 turn
	int gold; // 유저가 사용가능한 금의 양
	int enemy_hp; // 적군의 체력
	int flag_status;// 게임 상태
public:
	ApplicationType() {};
	~ApplicationType() {
		for (auto& elem : unit_list_in_barracks){
			delete elem;
		}
		for (auto& elem : unit_list) {
			delete elem;
		}
	}
	void increase_turn() {
		curr_turn += 1;
		if (curr_turn == MAX_turn) {
			flag_status = 1;
			cout << "You Lose";
		}
	}
	void print_unit_list_in_barracks() {
		for (auto& elem : unit_list_in_barracks) {
			cout << elem->print << endl;
		}
	}
	void print_unit_list() {
		for (auto& elem : unit_list) {
			cout << elem->print << endl;
		}
	}
	void run();
	string get_command() {
		string inputNum;
		cout << "Turn : " << ApplicationType::curr_turn;
		cout << "Gold : " << ApplicationType::gold;
		cout << "Enemy Hp : " << ApplicationType::enemy_hp;
		cout << endl;
		cout << "1. Hire Unit" << endl;
		cout << "2. Attack to Enemy" << endl;
		cout << "3. Gather Money " << endl;
		cout << "4. Print Units" << endl;
		cout << "Input>";
		cin >> inputNum;
		return inputNum;
	}
	bool hire_unit() {
		string wantType;
		ApplicationType::print_unit_list_in_barracks;
		cin >> wantType;
		for (int i = 0; i < 4; i++) {
			if (wantType == unit_list_in_barracks[i]->get_name)
				if (ApplicationType::gold >= unit_list_in_barracks[i]->get_price) {
					ApplicationType::unit_list.push_back(unit_list_in_barracks[i]);
					cout << "Succenssfully hired"<<endl;
					increase_turn();
					return true;
				}
				else {
					cout << "Error : neither wrong name nor enough gold" << endl;
					return false;
				}
			else {
				cout << "Error : neither wrong name nor enough gold" << endl;
				return false;
			}
		}

	}
	void attack_to_enemy(){
		
	}
	void gather_money();
};

ApplicationType::ApplicationType() {
	Unit* pUnit;
	pUnit = new Attacker(1, "swordsman", 300, 10);
	unit_list_in_barracks.push_back(pUnit);
	pUnit = new Attacker(1, "champion", 1200, 16);
	unit_list_in_barracks.push_back(pUnit);
	pUnit = new Miner(0, "farmer", 200, 20);
	unit_list_in_barracks.push_back(pUnit);
	pUnit = new Miner(0, "landlord", 500, 50);
	unit_list_in_barracks.push_back(pUnit);
	curr_turn = 1; // 현재 turn (1턴부터 시작)
	MAX_turn = 50; // 종료될 때 까지의 총 turn
	gold = 1000; // 유저의 금의 양
	enemy_hp = 500; // 적군의 체력
	flag_status = 0;
}

void ApplicationType::ApplicationType::run() {
	string sOption;
	while (flag_status == 0) {
		sOption = get_command();
		if (sOption == "1") hire_unit();
		else if (sOption == "2") attack_to_enemy();
		else if (sOption == "3") gather_money();
		else if (sOption == "4") print_unit_list();
		else if (sOption == "5") break;
	}
	cout << "Exit the program..." << endl;
}

int main() {
	ApplicationType appType;
	appType.run();
	return 0;
}