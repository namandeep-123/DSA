#include <iostream>
#include <cmath>
using namespace std;

// Dynamic Programming

int balancedBT3(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    int mod = (int)(pow(10, 9) + 7);
    for (int i = 2; i <= n; i++)
    {
        int h1 = ans[i - 1];
        int h2 = ans[i - 2];
        int temp1 = (int)(((long)(h1)*h1) % mod);
        int temp2 = (int)((2 * (long)(h1)*h2) % mod);
        ans[i] = (int)((temp1 + temp2) % mod);
    }
    return ans[n];
}

// recursion  + memoization

int balancedBT2(int n, int *ans)
{
    if (n <= 1)
        return 1;
    if (ans[n] != -1)
        return ans[n];

    int mod = (int)(pow(10, 9) + 7);
    int h1 = balancedBT2(n - 1, ans);
    int h2 = balancedBT2(n - 2, ans);

    int temp1 = (int)(((long)(h1)*h1) % mod);
    int temp2 = (int)((2 * (long)(h1)*h2) % mod);

    int answer = (int)((temp1 + temp2) % mod);
    ans[n] = answer;
    return ans[n];
}

// Recursion
int balancedBT(int n)
{
    if (n <= 1)
        return 1;
    int mod = (int)(pow(10, 9)) + 7;
    int h1 = balancedBT(n - 1);
    int h2 = balancedBT(n - 2);

    int temp1 = (int)(long(h1) * h1) % mod;
    int temp2 = (int)(2 * long(h1) * h2) % mod;

    int ans = (int)((long(temp1) + temp2)) % mod;
    return ans;

    // return (h1 * h1) + (h1 * h2) + (h2 * h1);
}

int main()
{
    int height;
    cin >> height;
    int *ans = new int[height + 1];
    for (int i = 0; i <= height; i++)
        ans[i] = -1;
    cout << balancedBT2(height, ans);
}