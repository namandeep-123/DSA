#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    T *data;
    int frontIndex, lastIndex, size, capacity;

public:
    Queue()
    {
        data = new T[4];
        lastIndex = 0;
        frontIndex = -1;
        size = 0;
        capacity = 4;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[frontIndex];
    }
    void enqueue(int element)
    {
        if (size == capacity)
        {
            T *newData = new T[capacity * 2];
            int j = 0;
            for (int i = frontIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newData[j] = data[i];
            }
            delete[] data;
            data = newData;
            frontIndex = 0;
            lastIndex = capacity;
            capacity *= 2;
        }
        data[lastIndex] = element;
        lastIndex = (lastIndex + 1) % capacity;
        size++;
        if (frontIndex == -1)
        {
            frontIndex = 0;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        int element = data[frontIndex];
        frontIndex += 1;
        size -= 1;
        if (size == 0)
        {
            frontIndex = -1;
            lastIndex = 0;
        }
        return element;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(30);
    q.enqueue(30);

    cout << q.front() << endl;
    cout << q.getSize() << endl;
}