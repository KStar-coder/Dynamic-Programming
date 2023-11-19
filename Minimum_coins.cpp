#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &num, int x, vector<vector<int>> &dp)
{
    // base case
    if (i == 0)
    {
        if (x % num[0] == 0) // the coin is divisible by the target
        {
            return x / num[0];
        }
        else
            return 1e9;
    }

    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }

    // recursive cases
    int notpick = 0 + solve(i - 1, num, x, dp);
    int pick = INT_MAX;
    if (num[i] <= x)
        pick = 1 + solve(i, num, x - num[i], dp); // there is an infinite supply so we can take it again

    return dp[i][x] = min(pick, notpick);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();

    // MEMOIZATION:
    // vector<vector<int>>dp(n, vector<int>(x+1, -1));
    //  int ans = solve (n-1,num,x,dp);
    //  if (ans >= 1e9)
    //      return -1;
    //  else
    //      return ans;

    // TABULATION:
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    // base case
    for (int t = 0; t <= x; t++)
    {
        if (t % num[0] == 0)
            dp[0][t] == t / num[0];
        else
            dp[0][t] = 1e9;
    }
    // tabulation loops
    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= x; t++)
        {
            int nottake = 0 + dp[i - 1][t];
            int take = INT_MAX;
            if (num[i] <= t)
                take = 1 + dp[i][t - num[i]];

            dp[i][t] = min(take, nottake);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    else
        return ans;
}