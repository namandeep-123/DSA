#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            size = 1;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    T top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return head->data;
    }
    T pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = temp->next;
        delete temp;
        size--;
        return ans;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
    cout << s.getSize();
}