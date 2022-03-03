#include <bits/stdc++.h>
using namespace std;

// DP

int lcs3(string s, string t)
{
    int m = s.length();
    int n = t.length();

    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }

    // fill the 0th row with 0
    for (int j = 0; j <= n; j++)
    {
        ans[0][j] = 0;
    }
    // fill the 0th column with 0
    for (int i = 0; i <= m; i++)
    {
        ans[i][0] = 0;
    }
    // fill the remaining column with longest common sequences;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                ans[i][j] = 1 + ans[i - 1][j - 1];
            }
            else
            {
                int a = ans[i - 1][j];
                int b = ans[i][j - 1];
                int c = ans[i - 1][j - 1];
                ans[i][j] = max(a, max(b, c));
            }
        }
    }
    return ans[m][n];
}

// recursively + memoization
int lcs2(string s, string t, vector<vector<int>> ans)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;
    if (ans[s.size()][t.size()] != -1)
        return ans[s.size()][t.size()];
    if (s[0] == t[0])
    {
        ans[s.size()][t.size()] = 1 + lcs2(s.substr(1), t.substr(1), ans);
        return ans[s.size()][t.size()];
    }
    else
    {
        int a = lcs2(s.substr(1), t, ans);
        int b = lcs2(s, t.substr(1), ans);
        int c = lcs2(s.substr(1), t.substr(1), ans);
        ans[s.size()][t.size()] = max(a, max(b, c));
        return ans[s.size()][t.size()];
    }
}

// recursively

int lcs(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
        return 0;
    if (s[0] == t[0])
        return 1 + lcs(s.substr(1), t.substr(1));
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));
        return max(a, max(b, c));
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    vector<vector<int>> ans(s.length() + 1, vector<int>(t.length() + 1, -1));
    cout << lcs2(s, t, ans);
    cout << lcs3(s, t);
}