#include <iostream>
#include <queue>
using namespace std;

void klargestelement(int a[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(a[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (pq.top() > a[i])
        {
            pq.pop();
            pq.push(a[i]);
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int a[] = {8, 5, 12, 10, 0, 1, 6, 9};
    klargestelement(a, 8, 4);
}