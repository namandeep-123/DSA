#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Pair
{
public:
    Node *head;
    Node *tail;
};
Node *takeInput()
{
    int data;
    cin >> data;
    Node *tail = NULL;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reversedLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *smallAns = reversedLinkedList(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

int main()
{
    Node *head = takeInput();
    head = reversedLinkedList(head);
    print(head);
}