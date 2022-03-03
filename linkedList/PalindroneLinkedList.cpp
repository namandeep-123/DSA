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

void mainLinkedList(Node *head, int mid)
{
    Node *temp = head;
    int i = 0;
    while (i < mid - 1)
    {
        i++;
        temp = temp->next;
    }
    // Node *head2 = temp->next;
    Node *current = temp->next;
    Node *prev = NULL;
    temp->next = NULL;
    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Node *temp2 = head;
    bool palindrone = false;
    while (temp2 != NULL)
    {

        if (temp2->data == prev->data)
        {
            prev = prev->next;
            temp2 = temp2->next;
            palindrone = true;
        }
        else
        {

            palindrone = false;
            break;
        }
    }
    cout << palindrone;
}

int main()
{
    Node *head = takeInput();
    int count = countLinkedList(head);
    int mid = count / 2;
    mainLinkedList(head, mid);
}