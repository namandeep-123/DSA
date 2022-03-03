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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *merge_sort(Node *head, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if (!head && !head2)
        return NULL;
    if (!head && head2)
        return head2;
    if (head && !head2)
        return head;

    while (head != NULL && head2 != NULL)
    {

        if (head->data <= head2->data)
        {
            if (finalHead == NULL)
            {
                finalHead = head;
                finalTail = head;
                head = head->next;
            }
            else
            {
                finalTail->next = head;
                finalTail = head;
                head = head->next;
            }
        }
        else
        {
            if (finalHead == NULL)
            {
                finalHead = head2;
                finalTail = head2;
                head2 = head2->next;
            }
            else
            {
                finalTail->next = head2;
                finalTail = head2;
                head2 = head2->next;
            }
        }
    }
    while (head != NULL)
    {
        finalTail->next = head;
        finalTail = head;
        head = head->next;
    }

    while (head2 != NULL)
    {
        finalTail->next = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    return finalHead;
}

Node *merge_sort_recursion(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            fast = fast->next;
        }
        else
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    Node *head2 = slow->next;
    slow->next = NULL;

    // print(head);
    // print(head2);

    head = merge_sort_recursion(head);
    head2 = merge_sort_recursion(head2);

    head = merge_sort(head, head2);

    return head;
}

int main()
{
    Node *head = takeInput();
    head = merge_sort_recursion(head);
    print(head);
}