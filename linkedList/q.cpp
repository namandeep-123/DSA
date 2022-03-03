#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *takeInput()
{
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
            head = newNode;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

node *reverseLL(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *smallAns = reverseLL(head->next);

    node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head1 = takeInput();
    node *result = reverseLL(head1);
    print(result);
    return 0;
}
