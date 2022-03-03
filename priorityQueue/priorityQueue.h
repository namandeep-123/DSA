#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMin()
    {
        if (isEmpty())
            return 0;
        return pq[0];
    }
    int getSize()
    {
        return pq.size();
    }

    void insert(int data)
    {
        pq.push_back(data);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin()
    {
        if (isEmpty())
        {
            cout << "Min Heap is Empty";
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int left = 2 * parentIndex + 1;
        int right = 2 * parentIndex + 2;

        while (left < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[left])
                minIndex = left;
            if (right < pq.size() && pq[right] < pq[minIndex])
                minIndex = right;
            if (minIndex == parentIndex)
                break;
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            left = 2 * parentIndex + 1;
            right = 2 * parentIndex + 2;
        }
        return ans;
    }
};