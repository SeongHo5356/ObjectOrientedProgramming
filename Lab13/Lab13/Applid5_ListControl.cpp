
#include <iostream>
#include <array>

using namespace std;

template<typename T>
class Queue {
private:
    T* p_list;
    int size;
    int MAX_SIZE;

public:
    Queue(int _MAX_SIZE = 1000)
        :p_list(), size(0), MAX_SIZE(_MAX_SIZE)
    {
        p_list = new T[MAX_SIZE];
        size = 0;
    }
    ~Queue() {
        delete[] p_list;
    }
    int find_index(T _item) {
        for (int i = 0; i < size; i++)
        {
            if (p_list[i] == _item) {
                return i;
            }
        }
        return -1;
    }
    void Enqueue(T _item) {
        if (size == MAX_SIZE) {
            cout << "Error: out of memory" << endl;
            return;
        }
        else if(find_index(_item) == -1 ){
            p_list[size]=_item;
            size++;
        }
    }
    T Dequeue() {
        if (size == 0) {
            cout << "Error: NO item exists in the list" << endl;

        }
        else {
            T result = p_list[0];
            for (int i = 0; i < size - 1 ; i++)
                p_list[i] = p_list[i + 1];
            size--;
            return result;
        }
    }
    void print() const {
        cout << "Items in the list : ";
        for (int i = 0; i < size; i++) {
            cout << p_list[i] << ", ";
        }
        cout << endl;
    }

    int get_size() {
        return size;
    }

    T get_item(int _index) {
        return p_list[_index];
    }
};

int main()
{
    Queue<int> int_queue;
    Queue<float> float_queue;
    Queue<char> char_queue;

    int_queue.Enqueue(1);
    int_queue.Enqueue(2);
    int_queue.Enqueue(2);
    int_queue.Enqueue(5);

    float_queue.Enqueue(4.3);
    float_queue.Enqueue(2.5);
    float_queue.Enqueue(3.7);
    float_queue.Enqueue(3.7);

    char_queue.Enqueue('b');
    char_queue.Enqueue('b');
    char_queue.Enqueue('c');
    char_queue.Enqueue('a');

    cout << "<Before Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();

    int_queue.Dequeue();
    float_queue.Dequeue();
    float_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();
    char_queue.Dequeue();

    cout << "<After Dequeue>" << endl;
    int_queue.print();
    float_queue.print();
    char_queue.print();

    return 0;
}
