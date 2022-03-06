#include <bits/stdc++.h>
using namespace std;

// DP

int knapsack3(int size, int totalWeight, int *weight, int *value)
{
    int m = totalWeight;
    int n = 5;
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }

    // Fill the 0th row with 0
    for (int j = 0; j <= n; j++)
    {
        ans[0][j] = 0;
    }
    // Fill the 0th row with 0
    for (int i = 0; i <= m; i++)
    {
        ans[i][0] = 0;
    }
    // fill the remaining row and col

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (j >= i)
            {
                int w = weight[i];
                int p = value[i];
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - w] + p);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
    }
    return ans[m][n];
}

// recursively + memoization
int knapsack2(int size, int totalWeight, int *weight, int *value, vector<vector<int>> ans)
{
    if (size == 0 || totalWeight < 0)
        return 0;
    if (ans[totalWeight][size] != -1)
        return ans[totalWeight][size];
    if (weight[0] > totalWeight)
        ans[totalWeight][size] = knapsack2(size - 1, totalWeight, weight + 1, value + 1, ans);
    else
    {
        int a = knapsack2(size - 1, totalWeight - weight[0], weight + 1, value + 1, ans) + value[0];
        int b = knapsack2(size - 1, totalWeight, weight + 1, value + 1, ans);
        ans[totalWeight][size] = max(a, b);
    }
    return ans[totalWeight][size];
}
// Recursively
int knapsack(int size, int totalWeight, int *weight, int *value)
{
    if (size == 0 || totalWeight < 0)
        return 0;
    if (weight[0] > totalWeight)
        return knapsack(size - 1, totalWeight, weight + 1, value + 1);
    int a = knapsack(size - 1, totalWeight - weight[0], weight + 1, value + 1) + value[0];
    int b = knapsack(size - 1, totalWeight, weight + 1, value + 1);
    return max(a, b);
}

int main()
{
    // 4
    // 1 2 4 5
    // 5 4 8 6
    // 5
    int n = 5;
    int w = 5;
    int weight[] = {1, 2, 4, 5, 2};
    int value[] = {5, 4, 8, 6, 20};
    vector<vector<int>> ans(w + 1, vector<int>(6, -1));
    cout << knapsack(n, w, weight, value) << endl;
    cout << knapsack2(n, w, weight, value, ans) << endl;
    cout << knapsack3(n, w, weight, value) << endl;
}