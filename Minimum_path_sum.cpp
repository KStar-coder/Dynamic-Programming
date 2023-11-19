#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return grid[i][j];

    // out of bounds
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int down = grid[i][j] + solve(i, j - 1, grid, dp);

    return dp[i][j] = min(up, down);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<vector<int>> dp1(n, vector<int>(m, 0));
    // return solve (n-1,m-1,grid,dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // base case in dp style
            if (i == 0 && j == 0)
                dp1[i][j] = grid[i][j];

            else
            {

                // up
                int up = grid[i][j];
                if (i > 0)
                    up += dp1[i - 1][j];

                else
                    up += 1e9;

                // left
                int left = grid[i][j];
                if (j > 0)
                    left += dp1[i][j - 1];

                else
                    left += 1e9;
                dp1[i][j] = min(left, up);
            }
        }
    }

    return dp1[n - 1][m - 1];
}