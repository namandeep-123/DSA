#include <iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    Node(int data){
        this ->data = data;
        this -> next = NULL;
    }
};

Node* takeInput(){
    int data;
    cin >>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >>data;
    }
    return head;
}


void print(Node * head, int item){
    if (head == NULL) {
        cout << -1 << endl;
        return;
    }

    Node *temp = head;
    int i = 0;

    while(temp != NULL) {
        if (temp -> data == item) {
            cout << i << endl;
            return;
        }

        i++;
        temp = temp -> next;
    }

    cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i< t;i++){
    Node *head = takeInput();
    int item;
    cin >> item;
    print(head,item);
    }
}