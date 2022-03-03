#include <iostream>
#include <vector>
using namespace std;

int minPathCost3(vector<vector<int>> matrix, int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n));
    // fill the last cell
    ans[m - 1][n - 1] = matrix[m - 1][n - 1];
    // fill the last row
    for (int j = n - 2; j >= 0; j--)
    {
        ans[m - 1][j] = matrix[m - 1][j] + ans[m - 1][j + 1];
    }
    // fill the last column
    for (int i = m - 2; i >= 0; i--)
        ans[i][n - 1] = matrix[i][n - 1] + ans[i + 1][n - 1];

    // fill remaining cells
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            ans[i][j] = matrix[i][j] + min(ans[i + 1][j + 1], min(ans[i + 1][j], ans[i][j + 1]));

    return ans[0][0];
}

int minPathCost2(vector<vector<int>> matrix, int i, int j, int m, int n, int **ans)
{
    if (i == m - 1 && j == n - 1)
        return matrix[i][j];
    if (i >= m || j >= n)
        return INT_MAX;
    if (ans[i][j] != -1)
        return ans[i][j];

    int rightSide = minPathCost2(matrix, i, j + 1, m, n, ans);
    int DiagonalSide = minPathCost2(matrix, i + 1, j + 1, m, n, ans);
    int downSide = minPathCost2(matrix, i + 1, j, m, n, ans);

    int minimum = min(rightSide, min(DiagonalSide, downSide));
    ans[i][j] = matrix[i][j] + minimum;
    return ans[i][j];
}

int minPathCost(vector<vector<int>> matrix, int i, int j, int m, int n)
{
    if (i == m - 1 && j == n - 1)
        return matrix[i][j];
    if (i >= m || j >= n)
        return INT_MAX;

    int rightSide = minPathCost(matrix, i, j + 1, m, n);
    int DiagonalSide = minPathCost(matrix, i + 1, j + 1, m, n);
    int downSide = minPathCost(matrix, i + 1, j, m, n);

    int minimum = min(rightSide, min(DiagonalSide, downSide));
    return matrix[i][j] + minimum;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 5}, {2, 1, 6}, {3, 3, 6}};
    int m, n;
    cout << "Size";
    cin >> m >> n;
    int **ans = new int *[m];
    for (int i = 0; i < m; i++)
    {
        ans[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = -1;
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }

    cout << minPathCost2(matrix, 0, 0, m, n, ans);
    cout << minPathCost3(matrix, m, n);
}