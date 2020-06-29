#include <iostream>
using namespace std;

int main() {
	char key;
	cout << "Enter a key ( p or q ) : ";
	cin >> key;
	switch (key) {
	
	case 'P':
	case 'p':
		cout << "Pause" << endl;
		break;
	
	case 'Q':
	case 'q':
		cout << "Quit" << endl;
		break;
	
	default:
		cout << "Default" << endl;
	}
}