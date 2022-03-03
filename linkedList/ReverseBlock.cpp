#include <iostream>
#include "LinkedList.cpp"

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    if (head == 0 || n == 1 || n == 0)
        return head;
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *current = dummy, *prev = dummy, *nex = dummy;
    int count = 0;
    while (current->next != NULL)
    {
        current = current->next;
        count++;
    }
    while (count > 0)
    {
        int i;
        for (i = 0; i < n && nex != NULL; i++)
        {
            if (b[i] == 0)
                i++;
            current = prev->next;
            nex = current->next;
            for (int j = 0; j < b[i] - 1 && nex != NULL; j++)
            {
                current->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = current->next;
            }

            prev = current;
            count -= b[i];
            // cout << "count" << endl;

            // cout << dummy->next->data << endl;
            if (i == n - 1)
                count = 0;
        }
    }
    return dummy->next;
}

int main()
{
    Node *head = takeInput();
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    head = getListAfterReverseOperation(head, n, arr);
    print(head);
}