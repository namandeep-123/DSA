#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL, *prev = NULL;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *takeInputAtEnd()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
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

Node *takeInputAtStart()
{

    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
}
int main()
{
    // Node *head = takeInputAtEnd();
    Node *head = takeInputAtStart();
    print(head);
}