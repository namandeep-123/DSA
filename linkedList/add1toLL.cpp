#include <iostream>
#include "LinkedList.cpp"

Node *add1ToNumber(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    int carry = 1;
    Node *temp = prev;
    Node *lastNode = new Node(0);
    while (temp != NULL)
    {
        if (temp->data == 9 && carry != 0)
        {
            temp->data = 0;
            lastNode = temp;
            temp = temp->next;
        }
        else
        {
            temp->data += 1;
            carry = 0;
            break;
        }
    }
    if (carry != 0)
    {
        Node *newNode = new Node(1);
        lastNode->next = newNode;
    }

    Node *current1 = prev;
    Node *prev2 = NULL;
    while (current1 != NULL)
    {
        Node *next = current1->next;
        current1->next = prev2;
        prev2 = current1;
        current1 = next;
    }
    return prev2;
}

int main()
{
    Node *head = takeInput();
    head = add1ToNumber(head);
    print(head);
}