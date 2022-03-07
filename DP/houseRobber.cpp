#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> nums)
{
    cout << nums.size();
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[nums.size() - 1];
}
