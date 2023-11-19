#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr)
{
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

bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k += arr[i];
    }
    if (k % 2 != 0) // k is odd
        return false;

    int tgt = k / 2;

    return subsetSumToK(n, tgt, arr);
}
