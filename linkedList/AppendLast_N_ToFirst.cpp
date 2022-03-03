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

int countLinkedList(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *mainLinkedList(Node *head, int count)
{
    Node *temp = head;
    for (int i = 0; i < count - 1; i++)
    {
        temp = temp->next;
    }
    Node *head2 = temp->next;
    temp->next = NULL;
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = head;
    return head2;
}

int main()
{
    Node *head = takeInput();
    int count = countLinkedList(head);
    int num;
    cin >> num;
    count -= num;
    head = mainLinkedList(head, count);
    print(head);
}