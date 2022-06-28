#include <bits/stdc++.h>
#define N 4
using namespace std;

void printSolution(vector<vector<int>> &matrix)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << matrix[i][j] << " ";
        printf("\n");
    }
}

bool isSafe(vector<vector<int>> &matrix, int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (matrix[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (matrix[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (matrix[i][j])
            return false;

    return true;
}

bool solveNQueenUtil(vector<vector<int>> &matrix, int col)
{

    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {

        if (isSafe(matrix, i, col))
        {
            matrix[i][col] = 1;

            if (solveNQueenUtil(matrix, col + 1))
                return true;

            matrix[i][col] = 0;
        }
    }

    return false;
}

bool solveNQueen()
{
    vector<vector<int>> matrix(N, vector<int>(N, 0));

    solveNQueenUtil(matrix, 0);
    printSolution(matrix);
    return true;
}

int main()
{
    solveNQueen();
    return 0;
}
