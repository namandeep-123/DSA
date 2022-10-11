#include <iostream>
#include "LinkedList.cpp"

void halfLinkedList(Node *head, Node **l1, Node **l2)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    *l1 = head;
    *l2 = slow->next;
    slow->next = NULL;
}
Node *mergeList(Node *l1, Node *l2)
{
    Node *head = NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->data <= l2->data)
    {
        head = l1;
        head->next = mergeList(l1->next, l2);
    }
    else
    {
        head = l2;
        head->next = mergeList(l1, l2->next);
    }

    return head;
}
void merge(Node **head)
{
    Node *start = *head;
    Node *l1, *l2;

    if (start == NULL || start->next == NULL)
        return;

    halfLinkedList(start, &l1, &l2);

    merge(&l1);
    merge(&l2);

    *head = mergeList(l1, l2);
    return;
}

int main()
{
    Node *head = takeInput();
    cout << "Before Merging:" << endl;
    print(head);
    cout << "After Merging : " << endl;

    merge(&head);
    print(head);
}