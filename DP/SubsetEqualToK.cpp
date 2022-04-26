#include <bits/stdc++.h>
using namespace std;
// memoization
//  Time Complexity = O(N * target)
// Space Complexity = O(N * target) + O(N) auxillary space

bool f(int ind, int target, vector<int> &ans, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (target == ans[0]);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = f(ind - 1, target, ans, dp);
    bool taken = false;
    if (target >= ans[ind])
        taken = f(ind - 1, target - ans[ind], ans, dp);

    return dp[ind][target] = taken || notTaken;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    /*
    memoization
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(n-1,k,arr,dp);
    */
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (target >= arr[i])
                taken = dp[i - 1][target - arr[i]];

            dp[i][target] = taken | notTaken;
        }
    }

    return dp[n - 1][k];
}