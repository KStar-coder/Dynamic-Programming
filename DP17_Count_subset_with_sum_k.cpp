// count the number of subsets with sum k
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, vector<int> &num, vector<vector<int>> &dp)
{
    // base cases
    if (k == 0)
        return 1;
    if (n == 0)
        return num[0] == k;

    // dp base case
    if (dp[n][k] != -1)
        return dp[n][k];

    // recursive cases
    int notTake = solve(n - 1, k, num, dp);
    int take = 0;
    if (num[n] <= k)
        take = solve(n - 1, k - num[n], num, dp);

    return dp[n][k] = take + notTake;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    int n = num.size();
    // MEMOIZATION
    // vector<vector<int>>dp(n,vector<int>(tar+1, -1));
    // return solve (n-1,tar,num, dp);

    // TABULATION
    vector<vector<int>> dp1(n, vector<int>(tar + 1, 0));

    // base cases for tabulation
    for (int i = 0; i < n; i++)
    {
        dp1[i][0] == 1;
    }
    if (num[0] <= tar)
        dp1[0][num[0]] = 1;

    // tabulation loops

    for (int i = 1; i < n; i++)
    {
        for (int k = 0; k <= tar; k++)
        {
            int notTake = dp1[i - 1][k];
            int take = 0;
            if (num[i] <= k)
                take = dp1[i - 1][k - num[i]];

            dp1[i][k] = take + notTake;
        }
    }
    return dp1[n - 1][tar];
}