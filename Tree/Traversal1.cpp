#include <stdlib.h>

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *get_BTNode(int data) {
  struct Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
  return newNode;
}

void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(struct Node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct Node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}

void BTree_traverse(struct Node *root) {
  if (root == NULL) {
    cout << endl
         << "Empty Tree"
         << " ";
  } else {
    cout << "\n In-order Tree Traversal: \n";
    inorder(root);
    cout << endl;
    cout << "\n Pre-order Tree Traversal: \n";
    preorder(root);
    cout << endl;
    cout << "\n Post-order Tree Traversal: \n";
    postorder(root);
  }
}

int main() {
  struct Node *root = NULL;
  
  root = get_BTNode(2);

  struct Node *L1_0 = get_BTNode(4);
  struct Node *L1_1 = get_BTNode(6);

  root->left = L1_0;
  root->right = L1_1;

  struct Node *L2_0 = get_BTNode(8);
  struct Node *L2_1 = get_BTNode(10);
  struct Node *L2_2 = get_BTNode(12);
  struct Node *L2_3 = get_BTNode(11);

  L1_0->left = L2_0;
  L1_0->right = L2_1;

  L1_1->left = L2_2;
  L1_1->right = L2_3;

  L2_0->left = get_BTNode(9);
  L2_0->right = get_BTNode(7);

  L2_1->left = get_BTNode(5);
  L2_1->right = get_BTNode(1);


  L2_2->left = get_BTNode(13);
  L2_2->right = get_BTNode(3);

  L2_3->left = get_BTNode(14);

  BTree_traverse(root);
  return 0;
}
