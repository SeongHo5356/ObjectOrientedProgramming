#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Avengers {
public:
    Avengers() {
        name = " ";
        attack_point = 0;
        defense_point = 0;
        health = 0;
    }
    ~Avengers() {}
    // ĳ���� ���� �Լ�
    virtual void set(string _name, int _attack, int _defense, int _health) {}
    // ���� �Լ�
    virtual int attack() { return 0; }
    // ��� �Լ�
    virtual void defense(int _attack_point) { }
    // ĳ���� ���� ��� �Լ�
    virtual void print_info() { }
protected:
    string name; // ĳ���� �̸�
    int attack_point; // ���ݷ�
    int defense_point; // ����
    int health; // ü��
};
class Character : public Avengers {
public:
    Character(){}
    Character(string _name, int _attack, int _defense, int _health){
        name = _name;
        attack_point = _attack;
        defense_point = _defense;
        health = _health;

    }
    void set(string _name, int _attack, int _defense, int _health) override {
        name = _name;
        attack_point = _attack;
        defense_point = _defense;
        health = _health;
    }
    string getName() { return name; }
    int attack() override { return attack_point; }
    void defense(int _attack_point) override {
        this->health = this->health - (_attack_point - this->defense_point);
    }
    void print_info() override {
        cout << "Name: " << name << endl;
        cout << "Attack_Point: " << attack_point << endl;
        cout << "Defense_Point: " << defense_point << endl;
        cout << "Health: " << health << endl;
    }
    int get_health() { return health; }
};
int main() {
    Character my_char;
    Character enemy_char;
    string character;
    cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
    cin >> character;

    vector<Character*> vec;
    Character* pCharacters;
    pCharacters = new Character( "Ironman" ,70, 40, 100);
    vec.push_back(pCharacters);
    pCharacters = new Character("CaptainAmerica", 60, 50, 100);
    vec.push_back(pCharacters);
    pCharacters = new Character("Thor", 80, 30, 100);
    vec.push_back(pCharacters);
    
    int findCharacter =0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i]->getName() == character)
            findCharacter = i;
    }
    int findEnemy = 0;
    srand((unsigned)time(NULL));
    findEnemy = rand()%3;

    my_char = *vec[findCharacter];
    cout << "--My Character--\n";
    my_char.print_info();
    enemy_char= *vec[findEnemy];
    cout << "--Enemy Character--\n";
    enemy_char.print_info();

    cout << endl << "--Battle--" << endl;
    cout << "My Life: " << my_char.get_health() << "\t"
        << "Enemy Life:" << enemy_char.get_health() << endl;

    while (1) {

        enemy_char.defense(my_char.attack());
        if (enemy_char.get_health() <= 0) {
            cout << "You Win!\n";
            break;
        }
        cout << "My Life: " << my_char.get_health() << "\t"
            << "Enemy Life:" << enemy_char.get_health() << endl;
        my_char.defense(enemy_char.attack());
        if (my_char.get_health() <= 0) {
            cout << "You Win!\n";
            break;
        }
        cout << "My Life: " << my_char.get_health() << "\t"
            << "Enemy Life:" << enemy_char.get_health() << endl;
    }
    return 0;
}