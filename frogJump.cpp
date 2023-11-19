#include <bits/stdc++.h>
using namespace std;
// int f (int n, vector<int> heights, vector<int> &dp)
// {
//     //base case
//     if (n==0)
//         return 0;
//     if (dp[n]!=-1)
//         return dp[n];

//     int left = f(n-1, heights,dp) + abs (heights[n] - heights[n-1]);
//     int right = INT_MAX;
//     if (n > 1)
//         right = f(n-2, heights,dp) + abs (heights[n]-heights[n-2]);

//     return dp[n] = min (left,right);

// }

// bottom up DP : Tabulation

// int f (int n , vector<int> heights)
// {
//     vector<int> dp(n+1, -1);
//     //base case in dp style
//     dp[0]=0;

//     for (int i=1;i<n;i++)
//     {
//         int firstStep =  dp[i-1] + abs(heights[i] - heights[i-1]);
//         int secondStep =  INT_MAX;
//         if (i>1)
//         secondStep = dp[i-2] + abs (heights[i]- heights[i-2]);

//         dp[i] = min (firstStep, secondStep);
//     }
//     return dp[n-1];
// }

// bottom up DP : Space Optimization

int f(int n, vector<int> heights)
{
    vector<int> dp(n + 1, -1);
    // base case in dp style
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int firstStep = prev1 + abs(heights[i] - heights[i - 1]);
        int secondStep = INT_MAX;
        if (i > 1)
            secondStep = prev2 + abs(heights[i] - heights[i - 2]);

        int curri = min(firstStep, secondStep);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
}

int frogJump(int n, vector<int> &heights)
{
    // call for top down DP
    // return f(n-1, heights, dp);

    // call for bottom up DP
    return f(n, heights);
}
int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();
    int ans = frogJump(n, heights);
    cout << ans << endl;
    return 0;
}