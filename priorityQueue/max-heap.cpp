#include <iostream>
using namespace std;
// brute force
bool checkHeap(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int parentIndex = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n)
        {
            if (a[parentIndex] > a[leftChild])
                continue;
            else
                return false;
        }
        if (rightChild < n)
        {
            if (a[parentIndex] > a[rightChild])
                continue;
            else
                return true;
        }
    }
    return true;
}

// optimised

bool checkHeap2(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int parent = (i - 1) / 2;
        if (a[parent] < a[i])
            return false;
    }
    return true;
}
int main()
{
    int a[] = {42, 20, 18, 6, 14, 11, 9, 4};
    cout << checkHeap2(a, 8);
}