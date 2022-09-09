#include <iostream>
#include "LinkedList.cpp"

Node *push(Node *head, int a)
{
    if (head == NULL)
    {
        Node *newNode = new Node(a);
        head = newNode;
        return head;
    }

    Node *newNode = new Node(a);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *deleteKey(Node *head, int key)
{
    if (head == NULL)
        return NULL;
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *prev = dummy;
    Node *cur = head;

    while (cur != NULL)
    {
        if (cur->data != key)
        {
            prev->next = cur;
            prev = cur;
        }
        cur = cur->next;
    }
    prev->next = cur;
    return dummy->next;
}
void printList(Node *head)
{
    Node *temp = head;
    while (!temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int key = 2;
    head = push(head, 7);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 8);
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 2);

    head = deleteKey(head, key);
    print(head);
    return 0;
}
