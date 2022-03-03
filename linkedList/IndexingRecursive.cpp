#include <iostream>
#include "LinkedList.cpp"

int indexing(Node *head, int i, int item)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == item)
    {
        return i;
    }
    return indexing(head->next, i + 1, item);
}

int main()
{
    Node *head = takeInput();
    int item;
    cin >> item;
    cout << indexing(head, 0, item);
}