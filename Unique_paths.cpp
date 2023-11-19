#include <bits/stdc++.h>
using namespace std;

// MEMOIZATION
// int solve (int i, int j,vector<vector<int>> &dp)
// {
// 	// base case
// 	if (i==0 && j ==0)
// 	{
// 		return 1;

// 	}
// 	if (i<0 || j<0)
// 	{
// 		return 0;
// 	}
// 	if (dp[i][j] != -1)
// 		return dp[i][j];
// 	int up = solve (i-1,j,dp);
// 	int left = solve (i,j-1,dp);

// 	return dp[i][j] =   (up + left);
// }

// 	TABULATION

// int solve (int m, int n)
// {
// 	vector<vector<int>> dp (m, vector<int>(n, -1));
// 	int up = 0, left = 0;

// 	//base case in dp style
// 	for (int i = 0;i<m;i++)
// 	{
// 		for (int j=0;j<n;j++)
// 		{
// 			if (i==0 && j==0)
// 				dp[i][j] = 0;
// 			else {
// 				if (i>0)
// 					up = dp[i-1][j];
// 				if (j>0)
// 					left = dp[i][j-1];
// 			}
// 			dp[i][j] = up+left;
// 		}
// 	}
// 	return dp[m][n];
// }

int uniquePaths(int m, int n)
{
    // Write your code here.
    // vector<vector<int>> dp(m, vector<int>(n,-1));
    // return solve (m-1,n-1,dp);

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int up = 0, left = 0;
    // base case in dp style
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else
            {
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}