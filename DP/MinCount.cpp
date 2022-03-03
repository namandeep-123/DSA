#include <iostream>
using namespace std;

// Dynamic Programming

int solveMinCount3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            ans[i] = min(ans[i], 1 + ans[i - j * j]);
        }
    }
    return ans[n];
}

// recursion + memoisation

int solveMinCount2(int n, int *ans)
{
    if (n <= 3)
    {
        return n;
    }
    if (ans[n] != -1)
        return ans[n];
    int answer = n;
    for (int i = 1; i * i <= n; i++)
        answer = min(answer, 1 + solveMinCount2(n - i * i, ans));
    ans[n] = answer;
    return answer;
}

// recursion
int solveMinCount(int n)
{
    if (n <= 3)
    {
        return n;
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
        ans = min(ans, 1 + solveMinCount(n - i * i));
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    cout << solveMinCount3(n);
}