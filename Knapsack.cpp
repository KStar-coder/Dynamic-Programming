#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &weight, vector<int> &value, int n, int w, vector<vector<int>> &dp)
{
    // base case
    if (i == 0)
    {
        if (weight[i] <= w)
            return value[i];
        else
            return 0;
    }

    if (dp[i][w] != -1)
        return dp[i][w];

    int notpick = solve(i - 1, weight, value, n, w, dp);
    int pick = INT_MIN;
    if (weight[i] <= w)
        pick = value[i] + solve(i - 1, weight, value, n, w - weight[i], dp);

    return dp[i][w] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    // MEMOIZATION :
    // vector<vector<int>>dp(n,vector<int>(maxWeight+1 ,-1));
    // return solve (n-1,weight, value,n,maxWeight,dp);

    // TABULATION: Paremeters = index and maxWeight
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // base case

    for (int w = weight[0]; w <= maxWeight; w++)
    {
        dp[0][w] == value[0];
    }

    // tabulation loops
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notpick = 0 + dp[i - 1][w];
            int pick = INT_MIN;
            if (weight[i] <= w)
                pick = value[i] + dp[i - 1][w - weight[i]];
            dp[i][w] = max(pick, notpick);
        }
    }
    return dp[n - 1][maxWeight];
}