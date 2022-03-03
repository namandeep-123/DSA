#include <iostream>
#include <climits>
using namespace std;

class Stack
{
    int *data;
    int index;
    int capacity;

public:
    Stack()
    {
        data = new int[4];
        capacity = 4;
        index = 0;
    }
    int size()
    {
        return index;
    }
    bool isEmpty()
    {
        return index == 0;
    }

    void push(int element)
    {
        if (index == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[index] = element;
        index++;
    }

    int top()
    {
        if (isEmpty())
            return INT_MIN;
        return data[index - 1];
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        index--;
        return data[index];
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}