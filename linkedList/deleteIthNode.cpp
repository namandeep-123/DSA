#include <iostream>
using namespace std;


class Node{
    public : 
        int data;
        Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
Node* deleteIthPosition(Node *head,int i){
    Node* temp = head;
    int count = 0;
    if(i == 0){
        Node *a = head;
        head = head -> next;
        delete a;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        Node *a = temp -> next;
        Node *b = a -> next;
        temp -> next = b;
        delete a;
    }
    return head;
}

Node* insertAtIthRecursively(Node *head,int i ,int data){
    if(i == 0){
        Node* newNode = new Node(data);
        newNode -> next = head->next;
        return newNode;
    }
    if(head == NULL){
        return NULL;
    } 
    Node* node = insertAtIthRecursively(head->next,i,data);
    head ->next = node;
    return head;
}

Node* insertAtIthPosition(Node *head,int i, int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    int count = 0;
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && count < i-1){
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}

void print(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp ->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* takeInput(){
    int data;
    cin >> data;
    Node* tail = NULL;
    Node* head = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
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

int main(){
    Node *head = takeInput();
    int i,data;
    cin >> i >>data;
    head = insertAtIthRecursively(head,i,data);
    print(head);
}