#include <bits/stdc++.h>
using namespace std;

string uniqueCharacter(string s)
{
    string a = "";
    unordered_map<char, bool> map;
    for (int i = 0; i < s.length(); i++)
    {
        if (map.count(s[i]) > 0)
        {
            continue;
        }

        else
        {
            map[s[i]] = true;
            a += s[i];
        }
    }
    return a;
}

int main()
{
    string s;
    getline(cin, s);
    cout << uniqueCharacter(s);
}