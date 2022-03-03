#include "BinaryTree.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    int minimum(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return INT_MAX;
        return min(root->data, min(minimum(root->left), minimum(root->right)));
    }
    BinaryTreeNode<int> *insertion(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (root->data > data)
        {
            root->left = insertion(root->left, data);
            return root;
        }
        else
        {
            root->right = insertion(root->right, data);
            return root;
        }
    }

    BinaryTreeNode<int> *deletion(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return NULL;

        if (root->data == data)
        {
            if (!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if (!root->left)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                int rightMin = minimum(root->right);
                root->data = rightMin;
                root->right = deletion(root->right, rightMin);
                return root;
            }
        }

        if (root->data > data)
        {
            root->left = deletion(root->left, data);
            return root;
        }
        else
        {
            root->right = deletion(root->right, data);
            return root;
        }
    }
    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":";
        if (root->left)
            cout << "L" << root->left->data;
        if (root->right)
            cout << "R" << root->right->data;
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    void insert(int data)
    {
        root = insertion(root, data);
    }
    void Delete(int data)
    {
        root = deletion(root, data);
    }
    void printTree()
    {
        printTree(root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return NULL;
        else if (node->data > data)
        {
            return hasData(data, root->left);
        }
        else
        {
            return hasData(data, root->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};