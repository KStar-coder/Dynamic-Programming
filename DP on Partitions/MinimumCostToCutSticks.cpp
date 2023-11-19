#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    // base case
    if (i > j) // i will surpass j
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // recursive cases for 'k' partitions
    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    cuts.insert(cuts.begin(), 0); // 0 at the first place
    cuts.push_back(n);            // length at the last place

    // MEMOIZATION
    // vector<vector<int>>dp(c+1, vector<int>(c+1, -1));// c+1 to accomodate i-1 and j+1
    // sort(cuts.begin(), cuts.end());
    // return solve (1, c, cuts, dp);

    // TABULATION
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    // base case : not required as all elements are initialised to 0

    // tabulation loops
    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}