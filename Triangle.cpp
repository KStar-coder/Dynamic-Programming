#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> triangle, int n, vector<vector<int>> &dp)
{
    // base case
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    // dp base case
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // return solve (0,0,triangle,n,dp);

    // TABULATION
    vector<vector<int>> dp1(n, vector<int>(n, 0));

    // inseting the last row of the triangle array into the dp

    for (int j = 0; j < n; j++)
        dp1[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp1[i + 1][j];
            int diagonal = triangle[i][j] + dp1[i + 1][j + 1];
            dp1[i][j] = min(down, diagonal);
        }
    }
    return dp1[0][0];
}