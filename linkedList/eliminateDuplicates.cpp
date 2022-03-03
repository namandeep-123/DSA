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

void duplicateRemove(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *a = temp->next;
        if (temp->data == a->data)
        {
            temp = temp->next;
        }
        else
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    Node *head = takeInput();
    duplicateRemove(head);
}