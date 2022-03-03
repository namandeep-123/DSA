#include <iostream>
using namespace std;
template <typename T>
class Stack
{
    T *data;
    int index;
    int capacity;

public:
    Stack()
    {
        data = new T[4];
        capacity = 4;
        index = 0;
    }
    T size()
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
            T *newData = new T[2 * capacity];
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

    T top()
    {
        if (isEmpty())
            return 0;
        return data[index - 1];
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        index--;
        return data[index];
    }
};

int main()
{
    Stack<char> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if ((s.top() + 2 == str[i]) || (s.top() + 2 == str[i]) || (s.top() + 1 == str[i]))
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
    }

    if (s.isEmpty())
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
}