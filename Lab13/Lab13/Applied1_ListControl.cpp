#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int command() {
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. ����Ʈ �߰�" << endl;
	cout << "\t2. ����Ʈ ����" << endl;
	cout << "\t3. ����Ʈ ���" << endl;
	cout << "\t4. ���α׷� ����" << endl;
	cout << "\n\t�Է� --> ";
	cin >> num;
	return num;
}

template <typename T>
class CList
{
public:
	CList(int _m_Length = 0)
		:m_Length(_m_Length), m_Array(){}
	~CList(){}

	bool IsEmpty()
	{
		if (m_Length == 0) {
			return true;
		}
		else
			return false;
	}// list�� ��� ������ 1, �ƴϸ� 0

	bool IsFull() {
		if (m_Length == 5) {
			return true;
		}
		else
			return false;
	}// list�� �� �� ������ 1, �ƴϸ� 0
	
	void Add(T data) 
	{
		for (int i = 0; i < m_Length; i++) {
			if (m_Array[i] == data) {
				cout << "�ߺ��� �����Ͱ� �����մϴ�." << endl;
				return;
			}
			else {
				if (CList::IsFull() == true) {
					cout << "list is full";
					return;
				}
			}
			
		}
		m_Array[m_Length] = data;
		m_Length++;
		sort(m_Array, m_Array + m_Length);
	}// list�� ������ �߰�

	void Delete(T data) {
		if (CList::IsEmpty() == true) {
			cout << "List is empty." << endl;
		}
		else {
			for (int i = 0; i < m_Length; i++) {
				if (m_Array[i] == data) {
					for (int k = i; k < m_Length-1; k++) {
						m_Array[k] = m_Array[k + 1];
					}
					m_Length--;
				}
			}
		}
	} // list�� ������ ����
	void Print() {
		cout << endl;
		cout << "Current List" << endl;
		for (int i = 0; i < m_Length; i++) {
			cout << m_Array[i] << " ";
		}
	}// list�� ������ ���


private:
	T m_Array[5];
	int m_Length;

};




int main()
{
	CList<int> list; // type������ list ����
	int input; // list�� �Է� �� ������
	int com; // ������ ���
	while (1)
	{
		com = command(); // ����� ����
		switch (com)
		{
		case 1: // �߰�
			cout << "\n�߰��� ������ : ";
			cin >> input;
			list.Add(input);
			break;
		case 2: // ����
			cout << "\n������ ������ : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3: // ���
			list.Print();
			break;
		case 4: // ���α׷� ����
			cout << "\n\t���α׷��� �����մϴ�\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
