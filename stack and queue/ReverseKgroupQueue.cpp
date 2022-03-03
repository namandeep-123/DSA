#include <iostream>
#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    int size = q.size();
    for (int i = 0; i < k; i++)
    {
        int n = q.front();
        // cout << n << endl;
        q.pop();
        s.push(n);
    }
    int a[10];
    int i = 0;
    while (!q.empty())
    {
        a[i] = q.front();
        i++;
        q.pop();
    }

    for (int i = 0; i < k; i++)
    {
        int n = s.top();
        s.pop();
        q.push(n);
    }
    int array = 0;
    for (int i = k; i < size; i++)
    {
        q.push(a[array]);
        array++;
    }
    return q;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n--)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}