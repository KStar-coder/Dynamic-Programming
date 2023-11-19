#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> matrix, int n, int m, vector<vector<int>> &dp)
{
    // base cases

    // out of bounds base case
    if (j < 0 || j >= m)
        return -1e9;

    // reaching the first row of the matrix from the end
    if (i == 0)
        return matrix[0][j];

    // dp base case
    if (dp[i][j] != -1)
        return dp[i][j];

    // recursive cases
    int up = matrix[i][j] + f(i - 1, j, matrix, n, m, dp);
    int leftDiag = matrix[i][j] + f(i - 1, j - 1, matrix, n, m, dp);
    int rightDiag = matrix[i][j] + f(i - 1, j + 1, matrix, n, m, dp);

    return dp[i][j] = max(up, max(leftDiag, rightDiag));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    // MEMOIZATION

    // vector<vector<int>> dp(n, vector<int> (m, -1) ) ;
    // int maxi = -1e9;
    // for (int j=0;j<m;j++)
    // {
    //     maxi = max (maxi, f(n-1, j, matrix,n,m,dp));
    // }
    // return maxi;

    // TABULATION
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // here we will start from top of the matrix to the bottom

    // getting the elements of the first row in our dp array
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int down = matrix[i][j] + dp[i - 1][j];
            int leftDiag = matrix[i][j];
            if (j - 1 >= 0)
                leftDiag += dp[i - 1][j - 1];
            else
                leftDiag += -1e9;

            int rightDiag = matrix[i][j];
            if (j + 1 < m)
                rightDiag += dp[i - 1][j + 1];
            else
                rightDiag = -1e9;

            dp[i][j] = max(down, max(leftDiag, rightDiag));
        }
    }
    int maxi = -1e9;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}