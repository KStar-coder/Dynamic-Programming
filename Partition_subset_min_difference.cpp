#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int totsum = 0;
    for (int i = 0; i < n; i++)
    {
        totsum += arr[i];
    }

    int k = totsum;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    // tabulation dp array
    for (int i = 1; i < n; i++)
    {
        for (int tgt = 1; tgt <= k; tgt++)
        {
            bool notTake = dp[i - 1][tgt];
            bool take = false;
            if (arr[i] <= tgt)
                take = dp[i - 1][tgt - arr[i]];

            dp[i][tgt] = take | notTake;
        }
    }

    // The last row of the dp array will say if that particular subset sum is possible or not
    int mini = 1e8;
    for (int s1 = 0; s1 <= totsum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            mini = min(mini, abs((totsum - s1) - s1)); // totsum-s1 = s2 which is the sum of the other half of the partition
        }
    }
    return mini;
}
