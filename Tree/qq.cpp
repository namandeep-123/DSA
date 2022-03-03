#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;

    TreeNode(int data)
    {
        this->data = data;
    }
};

bool compareTreeNodes(TreeNode *first, TreeNode *second)
{
    if (first == NULL)
        return true;
    if (second == NULL)
        return false;
    if (first == NULL && second == NULL)
        return true;
    return first->data < second->data;
}

int main()
{

    vector<TreeNode *> nodes;
    nodes.push_back(new TreeNode(2));
    nodes.push_back(new TreeNode(1));
    nodes.push_back(new TreeNode(10));
    nodes.push_back(new TreeNode(5));

    sort(nodes.begin(), nodes.end(), compareTreeNodes);

    for (TreeNode *node : nodes)
    {
        cout << node->data << " ";
    }
    cout << "Hi" << nodes[3]->data;
}