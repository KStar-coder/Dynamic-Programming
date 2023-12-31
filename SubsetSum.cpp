// Subset sum equals
#include <bits/stdc++.h>
using namespace std;
bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> dp)
{
    // base case
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = solve(ind - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = solve(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    // MEMOIZATION

    // vector<vector<int>> dp(n,vector<int>(k+1, -1));
    // return solve(n-1,k,arr,dp);

    // TABULATION
    vector<vector<bool>> dp1(n, vector<bool>(k + 1, 0));

    // base case
    dp1[0][arr[0]] = true;

    // tabulation loops
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp1[ind - 1][target];
            bool take = false;

            if (arr[ind] <= target)
                take = dp1[ind - 1][target - arr[ind]];

            dp1[ind][target] = take | notTake;
        }
    }
    return dp1[n - 1][k];
}