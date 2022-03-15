#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            str.push(i);
        else if (s[i] == ')')
        {
            if (!str.empty())
                str.pop();
            else
                s[i] = '*';
        }
    }
    while (!str.empty())
    {
        s[str.top()] = '*';
        str.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}