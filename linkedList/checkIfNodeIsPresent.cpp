#include <iostream>
#include "LinkedList.cpp"

void push(Node **head, int a)
{
    if (head == NULL)
    {
        Node *newNode = new Node(a);
        *head = newNode;
    }

    Node *newNode = new Node(a);
    newNode->next = *head;
    *head = newNode;
}

bool search(Node *head, int a)
{
    if (head == NULL)
        return false;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == a)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int main()
{
    Node *head = NULL;
    int x = 1;
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, x) ? cout << "Yes" : cout << "No";
    return 0;
}
