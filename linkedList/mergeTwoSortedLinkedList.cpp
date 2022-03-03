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

Node *sortTwoLists(Node *first, Node *second)
{
    if (!first && !second)
        return NULL;
    if (!first && second)
        return second;
    if (!second && first)
        return first;
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            if (finalHead == NULL)
            {
                finalHead = first;
                finalTail = first;
                first = first->next;
            }
            else
            {
                // cout << "first smaller : " << finalTail->data << " ";
                finalTail->next = first;
                finalTail = first;
                first = first->next;
            }
        }
        else
        {
            if (finalHead == NULL)
            {
                finalHead = second;
                finalTail = second;
                second = second->next;
            }
            else
            {
                finalTail->next = second;
                finalTail = second;
                second = second->next;
            }
        }
    }
    while (first != NULL)
    {
        finalTail->next = first;
        finalTail = first;
        first = first->next;
    }
    while (second != NULL)
    {
        finalTail->next = second;
        finalTail = second;
        second = second->next;
    }
    return finalHead;
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

int main()
{
    Node *head = takeInput();
    Node *head2 = takeInput();
    Node *finalHead = sortTwoLists(head, head2);
    print(finalHead);
}
