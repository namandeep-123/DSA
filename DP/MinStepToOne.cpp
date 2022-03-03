#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming
int minStepToOne2(int n)
{
    vector<int> v;

    v.push_back(0);
    v.push_back(0);
    v.push_back(1);

    for (int i = 3; i <= n; i++)
    {
        int ans1 = v[i - 1] + 1;
        int ans2 = i % 2 == 0 ? v[i / 2] + 1 : INT_MAX;
        int ans3 = i % 3 == 0 ? v[i / 3] + 1 : INT_MAX;

        v.push_back(min(ans1, min(ans2, ans3)));
    }

    return v[n];
}
// memoization

int minStepHelper(int n, int *ans)
{
    if (n <= 1)
        return 0;
    int a, c = INT_MAX, b = INT_MAX;
    if (ans[n] != -1)
        return ans[n];
    a = minStepHelper(n - 1, ans);
    if (n % 2 == 0)
        b = minStepHelper(n / 2, ans);
    if (n % 3 == 0)
        c = minStepHelper(n / 3, ans);

    ans[n] = 1 + min(a, min(b, c));
    return ans[n];
}
int minStepToOne2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minStepHelper(n, ans);
    // if (n <= 1)
    //     return 0;
    // int a, c = INT_MAX, b = INT_MAX;
    // a = minStepToOne(n - 1);
    // if (n % 2 == 0)
    //     b = minStepToOne(n / 2);
    // if (n % 3 == 0)
    //     c = minStepToOne(n / 3);

    // return 1 + min(a, min(b, c));
}
// brute force
int minStepToOne(int n)
{
    if (n <= 1)
        return 0;
    int a, c = INT_MAX, b = INT_MAX;
    a = minStepToOne(n - 1);
    if (n % 2 == 0)
        b = minStepToOne(n / 2);
    if (n % 3 == 0)
        c = minStepToOne(n / 3);

    return 1 + min(a, min(b, c));
}

int main()
{
    int n;
    cin >> n;
    cout << minStepToOne2(n);
}