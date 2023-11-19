#include <bits/stdc++.h>
using namespace std;
// Memoization
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0) // index 1 (2nd index) is not picked
        return nums[n];
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int picked = nums[n] + solve(nums, n - 2, dp);
    int notpicked = 0 + solve(nums, n - 1, dp);
    return dp[n] = max(picked, notpicked);
}
// Tabulation + space optimization
int solve2(vector<int> &nums, int n)
{
    // vector<int> dp(n+1,-1);

    // dp style base case
    // dp[0] = nums[0];
    int prev = nums[0];
    int curri = INT_MIN;
    // int negative = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;

        int notpick = 0 + prev;

        // swapping
        curri = max(pick, notpick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = solve(nums, n, dp);
    int ans2 = solve2(nums, n);
    return ans2;
}