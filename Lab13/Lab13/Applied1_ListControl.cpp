#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int command() {
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
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
	}// list가 비어 있으면 1, 아니면 0

	bool IsFull() {
		if (m_Length == 5) {
			return true;
		}
		else
			return false;
	}// list가 꽉 차 있으면 1, 아니면 0
	
	void Add(T data) 
	{
		for (int i = 0; i < m_Length; i++) {
			if (m_Array[i] == data) {
				cout << "중복된 데이터가 존재합니다." << endl;
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
	}// list에 데이터 추가

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
	} // list에 데이터 삭제
	void Print() {
		cout << endl;
		cout << "Current List" << endl;
		for (int i = 0; i < m_Length; i++) {
			cout << m_Array[i] << " ";
		}
	}// list에 데이터 출력


private:
	T m_Array[5];
	int m_Length;

};




int main()
{
	CList<int> list; // type형으로 list 선언
	int input; // list에 입력 할 데이터
	int com; // 선택한 기능
	while (1)
	{
		com = command(); // 기능을 선택
		switch (com)
		{
		case 1: // 추가
			cout << "\n추가할 데이터 : ";
			cin >> input;
			list.Add(input);
			break;
		case 2: // 삭제
			cout << "\n삭제할 데이터 : ";
			cin >> input;
			list.Delete(input);
			break;
		case 3: // 출력
			list.Print();
			break;
		case 4: // 프로그램 종료
			cout << "\n\t프로그램을 종료합니다\n";
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
