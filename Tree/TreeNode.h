#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    bool sumCalculated = false;
    int sum;
    TreeNode(int data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
    int calcSum()
    {
        if (sumCalculated)
            return sum;
        int s = data;
        sumCalculated = true;
        for (int i = 0; i < children.size(); i++)
        {
            s += children[i]->data;
        }
        return sum = s;
    }
};