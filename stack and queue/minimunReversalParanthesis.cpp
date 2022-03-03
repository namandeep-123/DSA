#include <iostream>
#include <stack>
using namespace std;

int minimumReversal(string str)
{
    stack<int> s;
    int count = 0;
    if (str.length() % 2 != 0)
        return -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            s.push(str[i]);
        else if (!s.empty() && s.top() == '{')
            s.pop();
        else
            s.push(str[i]);
    }
    while (!s.empty())
    {
        int c1 = s.top();
        // cout << c1 << endl;
        s.pop();
        int c2 = s.top();
        // cout << c2 << endl;
        s.pop();
        count = c1 == c2 ? ++count : count += 2;
    }
    return count;
}

int main()
{

    string str;
    cin >> str;
    cout << minimumReversal(str);
}