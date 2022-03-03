#include <iostream>
#include "LinkedList.cpp"

Node *deleteNnodes(Node *head, int m, int n)
{
    Node *temp = head;
    while (temp != NULL)
    {
        for (int i = 1; i < m; i++)
        {
            if (temp == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        for (int i = 0; i < n; i++)
        {
            if (temp2 == NULL)
            {
                break;
            }
            Node *a = temp2;
            temp2 = temp2->next;
            delete a;
        }
        temp->next = temp2;
        temp = temp->next;
    }

    return head;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {

        Node *head = takeInput();
        int m, n;
        cin >> m >> n;
        head = deleteNnodes(head, m, n);
        print(head);
    }
}