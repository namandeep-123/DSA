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
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    T size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size = 1;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    T front()
    {
        if (!head)
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        return head->data;
    }
    T dequeue()
    {
        if (!head)
        {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        T data = head->data;
        Node<T> *temp = head;
        head = temp->next;
        delete temp;
        size--;
        return data;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout << q.dequeue();
    cout << q.front();
    cout << q.getSize();
    cout << q.isEmpty();
}