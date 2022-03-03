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

void midPoint(Node *head)
{
    Node *temp = head;
    Node *slow = temp;
    Node *fast = temp->next;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            // cout << slow->data;
            // fast = NULL;
            slow = slow->next;
            fast = fast->next;
        }
        else
        {

            fast = fast->next->next;
            slow = slow->next;
        }
    }
    cout << slow->data;
}

int main()
{
    Node *head = takeInput();
    midPoint(head);
}