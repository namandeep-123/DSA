#include <iostream>
#include "LinkedList.cpp"
using namespace std;

Node *head = NULL;
void insert(int data, int n)
{

    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }
    if (n == 1)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *prev = head;
    for (int i = 1; i < n - 1 && prev->next; i++)
        prev = prev->next;

    Node *newNode = new Node(data);
    newNode->next = prev->next;
    prev->next = newNode;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    insert(1, 1);
    insert(3, 2);
    insert(5, 3);
    insert(7, 4);
    insert(2, 2);
    print();
    return 0;
}