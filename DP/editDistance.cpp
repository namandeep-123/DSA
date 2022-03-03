#include <bits/stdc++.h>
using namespace std;

// DP

int editDistance(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }

    // Fill the 0th row with 0
    for (int j = 0; j <= m; j++)
    {
        ans[0][j] = 0;
    }
    // Fill the 0th row with 0
    for (int i = 0; i <= n; i++)
    {
        ans[i][0] = 0;
    }
    // Fill the remaining row with shortest Distances
}

// recursively + memoisation

int editDistance2(string s, string t, vector<vector<int>> ans)
{
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 || t.size() == 0)
        return 0;
    if (ans[m][n] != -1)
        return ans[m][n];
    if (s[0] == t[0])
    {
        ans[m][n] = editDistance2(s.substr(1), t.substr(1), ans);
        return ans[m][n];
    }
    else
    {
        int a = 1 + editDistance2(s.substr(1), t, ans);
        int b = 1 + editDistance2(s, t.substr(1), ans);
        int c = 1 + editDistance2(s.substr(1), t.substr(1), ans);
        ans[m][n] = min(a, min(b, c));
        return ans[m][n];
    }
}

// recursively

int editDistance(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;
    if (s[0] == t[0])
        return editDistance(s.substr(1), t.substr(1));
    else
    {
        int a = 1 + editDistance(s.substr(1), t);
        int b = 1 + editDistance(s, t.substr(1));
        int c = 1 + editDistance(s.substr(1), t.substr(1));
        return min(a, min(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    vector<vector<int>> ans(s.size() + 1, vector<int>(t.size() + 1, -1));
    cout << editDistance(s, t) << endl;
    cout << editDistance2(s, t, ans) << endl;
}