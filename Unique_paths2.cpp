/*
NOTE:  IN THIS CODE ONLY TABULATION DP WORKS IN CODE STUDIO (CODING NINJA)
*/
#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);
int solve(int i, int j, vector<vector<int>> mat, vector<vector<int>> &dp)
{
    // base cases
    if (i == 0 && j == 0) // reached the starting position from the end
    {
        return 1;
    }
    if (i < 0 || j < 0) // out of bounds
    {
        return 0;
    }

    // if the path is blocked
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
    {
        return 0;
    }

    // already present in the dp array
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // recursive cases
    int up = solve(i - 1, j, mat, dp);
    int left = solve(i, j - 1, mat, dp);
    dp[i][j] = (up + left) % mod;
    return dp[i][j];
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{

    // vector<vector<int>> dp (n , vector<int> (m,-1) );
    // return solve (n-1,m-1,mat,dp);
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];

                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = (left + up) % mod;
            }
        }
    }

    return dp[n - 1][m - 1];

    // Write your code here
}