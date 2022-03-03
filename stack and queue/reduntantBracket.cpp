#include <iostream>
#include <stack>
using namespace std;

bool reduntant(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;
        if (str[i] == ')')
        {
            while (s.top() != '(')
            {
                count++;
                s.pop();
            }
            if (count == 0)
                return true;
        }
        else
            s.push(str[i]);
    }
    return false;
}

int main()
{
    string str;
    cin >> str;
    cout << reduntant(str);
}