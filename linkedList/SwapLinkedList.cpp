#include <iostream>
#include "LinkedList.cpp"

Node *swapInput(Node *head, int m, int n)
{
    Node *swap1 = head;
    Node *swap2 = head;
    if (!head)
        return NULL;
    for (int i = 0; i < m - 1; i++)
        swap1 = swap1->next;
    Node *temp1 = swap1->next;
    for (int i = 0; i < n - 1; i++)
        swap2 = swap2->next;
    Node *temp2 = swap2->next;
    Node *next = temp2->next;
    //
    if ((m == 0 || n == 0) && (m - n == 1 || n - m == 1))
    {
        temp1->next = swap1;
        swap2->next = next;
        head = temp1;
    }
    else if (m == 0 || n == 0)
    {
        swap2->next = swap1;
        temp2->next = temp1;
        swap1->next = next;
        head = temp2;
    }
    else if (m - n == 1 || n - m == 1)
    {
        swap1->next = temp2;
        swap2->next = next;
        temp2->next = temp1;
    }
    else
    {
        swap1->next = temp2;
        swap2->next = temp1;
        temp2->next = temp1->next;
        temp1->next = next;
    }
    // swap1->next = temp2;
    // swap2->next = temp1;
    // temp1->next = temp2->next;
    // temp2->next = swap2;
    return head;
}

int main()
{
    Node *head = takeInput();
    int m, n;
    cin >> m >> n;
    head = swapInput(head, m, n);
    print(head);
}