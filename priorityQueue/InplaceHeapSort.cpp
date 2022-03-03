#include <iostream>
using namespace std;

void heapify(int pq[], int n)
{
    // Build the heap in input Array
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
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

    // Remove Element
    int size = n;
    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;
        int parentIndex = 0;
        int left = 2 * parentIndex + 1;
        int right = 2 * parentIndex + 2;

        while (left < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[left])
                minIndex = left;
            if (right < size && pq[right] < pq[minIndex])
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
    }
}

int main()
{
    int a[] = {5, 7, 1, 8, 2};
    heapify(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}