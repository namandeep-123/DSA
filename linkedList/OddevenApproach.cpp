#include <iostream>
#include "LinkedList.cpp"
using namespace std;

Node *OddEvenApproach(Node *head)
{
    Node *temp = head;
    Node *odd = NULL;
    Node *odd_temp = NULL;
    Node *even = NULL;
    Node *even_temp = NULL;
    while (temp != NULL)
    {
        if (temp->data % 2 != 0)
        {
            if (odd == NULL)
            {
                odd = temp;
                odd_temp = temp;
            }
            else
            {
                odd_temp->next = temp;
                odd_temp = temp;
            }
            temp = temp->next;
        }
        else
        {
            if (even == NULL)
            {
                even = temp;
                even_temp = temp;
                temp = temp->next;
            }
            else
            {
                even_temp->next = temp;
                even_temp = temp;
                temp = temp->next;
            }
        }
    }

    if (!odd_temp)
        return even;
    if (!even_temp)
        return odd;

    odd_temp->next = even;
    even_temp->next = NULL;
    return odd;

    // if (odd_temp == NULL)
    // {
    //     return even;
    // }
    // else if (even_temp == NULL)
    // {
    //     return odd;
    // }
    // else
    // {

    //     odd_temp->next = even;
    //     even_temp->next = NULL;
    //     return odd;
    // }
    // print(even);
}

int main()
{
    Node *head = takeInput();
    head = OddEvenApproach(head);
    print(head);
}