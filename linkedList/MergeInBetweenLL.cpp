#include <iostream>
#include "LinkedList.cpp"

Node *MergeIn(Node *list1, int a, int b, Node *list2)
{
    Node *temp = list1;
    Node *temp1 = list1;
    int i = 1;
    int j = 1;
    while (i < a)
    {
        temp = temp->next;
        i++;
    }
    // cout << temp->data << endl;
    while (j <= b + 1)
    {
        temp1 = temp1->next;
        j++;
    }
    cout << temp1->data << endl;
    Node *secondList = list2;
    while (secondList->next != NULL)
        secondList = secondList->next;
    temp->next = list2;
    secondList->next = temp1;
    return list1;
}

int main()
{
    Node *head = takeInput();
    int a, b;
    cin >> a >> b;
    Node *head2 = takeInput();
    head = MergeIn(head, a, b, head2);
    print(head);
}