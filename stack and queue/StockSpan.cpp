#include <bits/stdc++.h>
using namespace std;

void stockSpan(vector<int> v)
{
    stack<int> s;
    int span[8];
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] <= v[i])
        {
            s.pop();
        }
        span[i] = (s.empty()) ? i + 1 : i - s.top();
        s.push(i);
    }

    for (int i = 0; i < 8; i++)
    {
        cout << span[i] << " ";
    }
}

int main()
{
    vector<int> v = {60, 70, 80, 100, 90, 75, 80, 120};
    stockSpan(v);
}