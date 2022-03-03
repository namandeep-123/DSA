#include <iostream>
#include "TreeNode.h"
#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the Number Of roots for " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter the " << i << "children for " << front->data << endl;
            int child;
            cin >> child;
            TreeNode<int> *rootChild = new TreeNode<int>(child);
            front->children.push_back(rootChild);
            pendingNodes.push(rootChild);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter the children of roots " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> printQueue;
    printQueue.push(root);
    while (!printQueue.empty())
    {
        TreeNode<int> *front = printQueue.front();
        printQueue.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
        }
        cout << endl;
        for (int i = 0; i < front->children.size(); i++)
        {
            printQueue.push(front->children[i]);
        }
    }
}

void printNode(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printNode(root->children[i]);
    }
}

// int numNodes(TreeNode<int> *root, int sum)
// {
//     sum += root->data;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         numNodes(root->children[i], sum);
//     }
//     return sum;
// }
int numNodes(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += numNodes(root->children[i]);
    }
    return sum;
}

int heightNode(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = heightNode(root->children[i]);
        ans = max(ans, temp);
    }
    return ans + 1;
}

void printLevelNode(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printLevelNode(root->children[i], k - 1);
    }
}

int maxNode(TreeNode<int> *root, int max)
{
    if (max < root->data)
        max = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        max = maxNode(root->children[i], max);
    }
    return max;
}

int countLeadNode(TreeNode<int> *root)
{
    int ans = 0;
    if (root->children.size() == 0)
        return 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeadNode(root->children[i]);
    }
    return ans;
}
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

bool containsX(TreeNode<int> *root, int item)
{
    bool ans = false;
    if (root->data == item)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = containsX(root->children[i], item);
    }
    return ans;
}

int countNodesGreaterThanX(TreeNode<int> *root, int item)
{
    int ans = 0;
    if (root == NULL)
        return 0;
    if (root->data > item)
        ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodesGreaterThanX(root->children[i], item);
    }
    return ans;
}

int sum(TreeNode<int> *node)
{
    int s = node->data;
    for (int i = 0; i < node->children.size(); i++)
    {
        s += node->children[i]->data;
    }
    return s;
}

TreeNode<int> *nodeWithMaxChild(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum1 = root->calcSum();
    TreeNode<int> *x;
    for (int i = 0; i < root->children.size(); i++)
    {
        x = nodeWithMaxChild(root->children[i]);
        int s = root->children[i]->calcSum();
        if (s > sum1)
        {
            ans = x;
        }
    }
    return ans;
}

int structurallyIdentical(TreeNode<int> *root, TreeNode<int> *root2)
{
    if (root->data != root2->data)
        return false;
    if (root->children.size() != root2->children.size())
        return false;
    int ans = true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool smallAns = structurallyIdentical(root->children[i], root2->children[i]);
        if (smallAns == false)
        {
            ans = smallAns;
            return ans;
        }
    }
    return ans;
}
TreeNode<int> *greaterThanN(TreeNode<int> *root, int n)
{
    TreeNode<int> *ans = NULL;
    if (root->data > n)
        ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *x = greaterThanN(root->children[i], n);
        if (x->data > n)
        {
            if (ans == NULL || x->data < ans->data)
            {
                ans = x;
            }
        }
    }
    return ans;
}
bool compareTreeNodes(TreeNode<int> *first, TreeNode<int> *second)
{
    if (first == NULL)
        return true;
    if (second == NULL)
        return false;
    if (first == NULL && second == NULL)
        return true;
    return first->data < second->data;
}

pair<TreeNode<int> *, TreeNode<int> *> secondLargestNumber(TreeNode<int> *root)
{
    pair<TreeNode<int> *, TreeNode<int> *> p;
    p.first = root;
    p.second = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> v = secondLargestNumber(root->children[i]);
        vector<TreeNode<int> *> nodes;
        nodes.push_back(p.first);
        nodes.push_back(p.second);
        nodes.push_back(v.first);
        nodes.push_back(v.second);
        sort(nodes.begin(), nodes.end(), compareTreeNodes);
        p.second = nodes[2];
        p.first = nodes[3];
    }
    return p;
}

void replaceWithDepth(TreeNode<int> *root, int k)
{
    if (k == 0)
        cout << 0 << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << k + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i], ++k);
    }
}

int main()
{
    // int n;
    // cin >> n;
    TreeNode<int> *root = takeInputLevelWise();
    // TreeNode<int> *root2 = takeInputLevelWise();
    int sum = 0;
    // printLevelWise(root);
    int max = 0;

    // cout << structurallyIdentical(root, root2);
    // TreeNode<int> *node = greaterThanN(root, n);
    // cout << node->data;
    // cout << nodeWithMaxChild(root)->data;
    // pair<TreeNode<int> *, TreeNode<int> *> c = secondLargestNumber(root);
    // cout << c.second->data;
    int k = 0;
    replaceWithDepth(root, k);
}