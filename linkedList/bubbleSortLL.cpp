#include <iostream>
#include "LinkedList.cpp"

Node *bubbleSort(Node *head, int count)
{
    Node *temp = head;
    for (int i = 0; i < count - 1; i++)
    {
        int val;
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (temp->data > temp->next->data)
            {
                val = temp->data;
                temp->data = temp->next->data;
                temp->next->data = val;
                temp = temp->next;
            }
        }
        temp = head;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    int count = countLinkedList(head);
    head = bubbleSort(head, count);
    print(head);
}