#include <bits/stdc++.h>
using namespace std;

int butATicket(int a[], int n, int k)
{
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        pq.push(a[i]);
    }
    int count = 0;
    while (!q.empty())
    {
        if (pq.top() == a[q.front()])
        {
            if (k == q.front())
                break;
            else
            {
                // cout << q.front() << endl;
                q.pop();
                count++;
                pq.pop();
            }
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return count + 1;
}

int main()
{
    int a[] = {8, 9, 8, 8, 12};
    cout << butATicket(a, 5, 3);
}