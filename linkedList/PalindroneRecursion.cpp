#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *tail = NULL;
    Node *head = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int countLinkedList(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

bool palindroneRecursion(Node *head, Node *&head2, int index, int mid)
{
    if (index == mid - 1)
    {
        cout << "comparing " << head->data << " with " << head2->data << endl;
        bool ans = head->data == head2->data;
        head2 = head2->next;
        return ans;
    }
    // if (!palindroneRecursion(head->next, head2, index + 1, mid))
    //     return false;
    // if (head->data != head2->data)
    // {
    //     cout << "head 2 : -> " << head2->data << " ";
    //     cout << "head  : -> " << head->data << endl;
    //     return false;
    // }
    // head2 = head2->next;
    // return true;

    bool ans = palindroneRecursion(head->next, head2, index + 1, mid) and head->data == head2->data;
    cout << "comparing " << head->data << " with " << head2->data << endl;
    head2 = head2->next;

    return ans;
}

void mainLinkedList(Node *head, int mid)
{
    Node *temp = head;
    for (int i = 0; i < mid; i++)
    {
        // cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    Node *head2 = temp;
    // while (head2 != NULL)
    // {
    //     // cout << head2->data << " ";
    //     head2 = head2->next;
    // }

    // cout << head->data << " " << head2->data;
    cout << palindroneRecursion(head, head2, 0, mid);
}

int main()
{
    Node *head = takeInput();
    int count = countLinkedList(head);
    int mid = count / 2;
    mainLinkedList(head, mid);
}