#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
// #include "BinarySearchTree.h"
#include <queue>
#include <vector>
using namespace std;

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
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left)
        {
            cout << "L" << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
void printZigZag(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int levelEvenOdd = 0;
    while (!pendingNodes.empty())
    {
        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " ";
            if (levelEvenOdd % 2 != 0)
            {
                if (front->left)
                {
                    pendingNodes.push(front->left);
                }
                if (front->right)
                {
                    pendingNodes.push(front->right);
                }
            }
            else
            {
                if (front->right)
                {
                    pendingNodes.push(front->right);
                }
                if (front->left)
                {
                    pendingNodes.push(front->left);
                }
            }
        }
        cout << endl;
        levelEvenOdd++;
    }
}
// void printZigzag(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     queue<BinaryTreeNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     int levelEvenOdd = 0;
//     while (!pendingNodes.empty())
//     {
//         int sizeOfQueue = pendingNodes.size();
//         for (int index = 0; index < sizeOfQueue; index++)
//         {
//             BinaryTreeNode<int> *front = pendingNodes.front();
//             pendingNodes.pop();
//             cout << front->data << " ";
//             if (levelEvenOdd % 2 == 0)
//             {
//                 if (root->right)
//                     pendingNodes.push(root->right);
//                 if (root->left)
//                     pendingNodes.push(root->left);
//             }
//             else
//             {
//                 if (root->left)
//                     pendingNodes.push(root->left);
//                 if (root->right)
//                     pendingNodes.push(root->right);
//             }
//         }
//         cout << endl;
//         levelEvenOdd++;
//     }
// }
void printTreeLevelTransversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " ";

            if (front->left)
            {
                pendingNodes.push(front->left);
            }
            if (front->right)
            {
                pendingNodes.push(front->right);
            }
        }
        cout << endl;
    }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;

        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

bool isNodePresent(BinaryTreeNode<int> *root, int nodeData)
{
    if (root == NULL)
        return false;
    if (root->data == nodeData)
        return true;
    return false || isNodePresent(root->left, nodeData) || isNodePresent(root->right, nodeData);
}
int heightOfNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfNode(root->left), heightOfNode(root->right));
}

BinaryTreeNode<int> *invertImage(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    BinaryTreeNode<int> *n = root->left;
    root->left = root->right;
    root->right = n;
    invertImage(root->left);
    invertImage(root->right);
    return root;
}

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

BinaryTreeNode<int> *builderHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = pre[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lpreS = preS + 1;
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootIndex + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = builderHelper(in, pre, linS, linE, lpreS, lpreE);
    root->right = builderHelper(in, pre, rinS, rinE, rpreS, rpreE);
    return root;
}

BinaryTreeNode<int> *PreInTree(int *in, int *pre, int size)
{
    return builderHelper(in, pre, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int> *posBuilderHelper(int *in, int *pos, int inS, int inE, int posS, int posE)
{
    if (posS > posE || inS > inE)
    {
        return NULL;
    }
    int rootData = pos[posE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lposS = posS;
    int lposE = linE - linS + lposS;
    int rposS = lposE + 1;
    int rposE = posE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = posBuilderHelper(in, pos, linS, linE, lposS, lposE);
    root->right = posBuilderHelper(in, pos, rinS, rinE, rposS, rposE);
    return root;
}

BinaryTreeNode<int> *PosInTree(int *in, int *pos, int size)
{
    return posBuilderHelper(in, pos, 0, size - 1, 0, size - 1);
}

pair<int, int> diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = diameter(root->left);
    pair<int, int> rightAns = diameter(root->right);
    int ld = leftAns.second;
    int rd = rightAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;
    int height = 1 + max(lh, rh);
    int Diameter1 = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = Diameter1;
    return p;
}

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MIN;
        p.second = INT_MAX;
        return p;
    }
    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);
    int Lmax = leftAns.first;
    int Lmin = leftAns.second;
    int Rmax = rightAns.first;
    int Rmin = rightAns.second;
    int maxLR = max(Lmax, Rmax);
    int minLR = min(Lmin, Rmin);
    if (root->data > maxLR)
        maxLR = root->data;
    if (root->data < minLR)
        minLR = root->data;
    pair<int, int> p;
    p.first = maxLR;
    p.second = minLR;
    return p;
}
int sumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftAns = sumOfNodes(root->left);
    int rightAns = sumOfNodes(root->right);
    int sum = leftAns + rightAns + root->data;
    return sum;
}

bool balanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int leftHeight = heightOfNode(root->left);
    int rightHeight = heightOfNode(root->right);
    int heightOfRoot;
    if (leftHeight > rightHeight)
        heightOfRoot = leftHeight - rightHeight;
    else
        heightOfRoot = rightHeight - leftHeight;
    if (heightOfRoot <= 1)
    {
        bool leftAns = balanced(root->left);
        bool rightAns = balanced(root->right);
        if (leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
pair<int, bool> balanceByOn(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> leftAns = balanceByOn(root->left);
    pair<int, bool> rightAns = balanceByOn(root->right);
    int lh = leftAns.first;
    int rh = rightAns.first;
    bool lb = leftAns.second;
    bool rb = rightAns.second;
    int height = 1 + max(lh, rh);
    pair<int, bool> p;
    if (lb && rb)
    {
        int heightOfRoot;
        if (lh > rh)
            heightOfRoot = lh - rh;
        else
            heightOfRoot = rh - lh;
        if (heightOfRoot <= 1)
        {
            if (lh - rh <= 1)
            {
                p.first = height;
                p.second = true;
            }
            else
            {
                p.first = height;
                p.second = false;
            }
        }
    }
    else
    {
        p.first = height;
        p.second = false;
    }
    return p;
}
bool balanced2ndApproach(BinaryTreeNode<int> *root)
{
    pair<int, bool> p = balanceByOn(root);
    return p.second;
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool option = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);
    return option;
}

BinaryTreeNode<int> *deleteLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    if (!root->left && !root->right)
    {
        delete root;
        return NULL;
    }
    BinaryTreeNode<int> *leftAns = deleteLeafNodes(root->left);
    root->left = leftAns;
    BinaryTreeNode<int> *rightAns = deleteLeafNodes(root->right);
    root->right = rightAns;
    return root;
}
class isBstReturn
{
public:
    bool ans;
    int minimum;
    int maximum;
};

isBstReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBstReturn output;
        output.ans = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBstReturn leftOutput = isBST2(root->left);
    isBstReturn right_output = isBST2(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, right_output.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, right_output.maximum));
    bool answer = (root->data > leftOutput.maximum) && (root->data < right_output.minimum) && leftOutput.ans && right_output.ans;
    isBstReturn output;
    output.ans = answer;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    bool isLeftOk = isBST3(root->left, min, root->data - 1);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

void findPathInBST(BinaryTreeNode<int> *root, vector<int> &s, int data)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == data)
    {
        s.push_back(root->data);
        return;
    }
    if (root->data > data)
    {
        findPathInBST(root->left, s, data);
        s.push_back(root->data);
    }
    if (root->data < data)
    {
        findPathInBST(root->right, s, data);
        s.push_back(root->data);
    }
}

vector<int> *nodeToRootPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        vector<int> *a = new vector<int>();
        a->push_back(root->data);
        return a;
    }
    vector<int> *leftOutput = nodeToRootPath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = nodeToRootPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

BinaryTreeNode<int> *createDuplicate(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;

    BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int>(root->data);

    BinaryTreeNode<int> *leftOutput = createDuplicate(root->left);
    BinaryTreeNode<int> *rightOutput = createDuplicate(root->right);

    root->left = duplicate;
    duplicate->left = leftOutput;
    return root;
}

void makingArray(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    ans.push_back(root->data);
    makingArray(root->left, ans);
    makingArray(root->right, ans);
}
class pairr
{
public:
    int maximum;
    int minimum;
    int height;
    bool isBST;
};

pairr larger(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pairr p;
        p.maximum = INT_MIN;
        p.minimum = INT_MAX;
        p.height = 0;
        p.isBST = true;
        return p;
    }
    pairr leftOutput = larger(root->left);
    pairr rightOutput = larger(root->right);
    int maxi = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    int mini = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    pairr p;
    bool option = ((root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST);
    if (option)
        p.height = 1 + max(leftOutput.height, rightOutput.height);
    else
        p.height = max(leftOutput.height, rightOutput.height);

    p.isBST = option;
    p.maximum = maxi;
    p.minimum = mini;
    return p;
}
int largestBst(BinaryTreeNode<int> *root)
{
    pairr p = larger(root);
    return p.height;
}

void printDepth1(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printDepth1(root->left, k - 1);
    printDepth1(root->right, k - 1);
}

int allDistanceFromNodesFromK(BinaryTreeNode<int> *root, int target, int k)
{
    if (!root)
        return -1;
    if (root->data == target)
    {
        printDepth1(root, k);
        return 0;
    }
    int ld = allDistanceFromNodesFromK(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            allDistanceFromNodesFromK(root->right, target, k - ld - 2);
        return ld + 1;
    }
    int rd = allDistanceFromNodesFromK(root->right, target, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            allDistanceFromNodesFromK(root->left, target, k - rd - 2);
        return rd + 1;
    }
    return -1;
}

class isMaxBST
{
public:
    int maximum;
    int minimum;
    bool isBST;
    int maxBSTsum;
};

isMaxBST maxSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isMaxBST p;
        p.maximum = INT_MIN;
        p.minimum = INT_MAX;
        p.isBST = true;
        p.maxBSTsum = 0;
        return p;
    }

    isMaxBST leftOutput = maxSum(root->left);
    isMaxBST rightOutput = maxSum(root->right);

    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maxBSTSum = root->data + leftOutput.maxBSTsum + rightOutput.maxBSTsum;
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    isMaxBST p;
    if (isBSTFinal)
    {
        p.maxBSTsum = root->data + leftOutput.maxBSTsum + rightOutput.maxBSTsum;
    }
    else
    {
        p.maxBSTsum = max(leftOutput.maxBSTsum, rightOutput.maxBSTsum);
    }
    p.maximum = maximum;
    p.minimum = minimum;
    p.isBST = isBSTFinal;
    return p;
}

int main()
{
    // int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
    // int pos[] = {4, 5, 2, 8, 9, 6, 7, 3, 1};
    // int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    isMaxBST p = maxSum(root);
    cout << "total" << p.maxBSTsum << endl;
    // allDistanceFromNodesFromK(root, 3, 1);
    // cout << largestBst << endl;
    // int t;
    // cin >> t;
    // vector<int> ans;
    // makingArray(root, ans);
    // sort(ans.begin(), ans.end());
    // int i = 0, j = ans.size() - 1;
    // while (i < j)
    // {
    //     int pairSum = ans[i] + ans[j];
    //     if (pairSum == t)
    //     {
    //         cout << ans[i] << " " << ans[j] << endl;
    //         i++;
    //         j--;
    //     }
    //     else if (pairSum > t)
    //     {
    //         j--;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
    // printTreeLevelTransversal(createDuplicate(root));
    // isBstReturn a = isBST2(root);
    // cout << "is BST ? " << isBST3(root) << endl;
    // vector<int> *a = nodeToRootPath(root, 8);
    // for (int i = 0; i < a->size(); i++)
    // {
    //     cout << a->at(i) << " ";
    // }
    // delete a;
    // vector<int> ans;
    // findPathInBST(root, ans, 2);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // pair<int, int> p = minMax(root);
    // cout << "Max " << p.first << endl;
    // cout << "Min " << p.second << endl;
    // printTreeLevelTransversal(deleteLeafNodes(root));
    // {int nodeData;
    // cin >> nodeData;
    // if (isNodePresent(root, nodeData))
    //     cout << "true";
    // else
    //     cout << "false";}
    // printTreeLevelWise(invertImage(root));
    // inorder(root);

    delete root;
    // BST b;
    // b.insert(10);
    // b.insert(5);
    // b.insert(20);
    // b.insert(7);
    // b.insert(3);
    // b.printTree();
    // b.Delete(10);
    // b.Delete(100);
    // b.printTree();
}
