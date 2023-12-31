#include <bits/stdc++.h>
using namespace std;
// int solve (int day, int last, vector<vector<int>> &points,vector<vector<int>>&dp)
// {// we will start from the nth(last) day upto the 0th (first) day
//     // base case
//     if (day == 0) // we reach fro the last day to the first day
//     {
//         int maxi = 0;
//         for (int i=0;i<3;i++)
//         {

//             if (i!=last)
//             {
//                 maxi = max(maxi, points[0][i]);
//             }
//         }
//         return maxi;
//     }
//     if (dp[day][last]!=-1)
//         return dp[day][last];

//     // recursive calls
//     int maxi = 0;

//     for (int i=0;i<3;i++)
//     {
//         if (i!=last)
//         {
//             int point = points[day][i] + solve(day-1,i,points,dp);
//             maxi = max (maxi,point);
//         }
//     }
//     return dp[day][last] = maxi;
//}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // return solve(n-1,3,points,dp);

    // Tabulation

    // base case in dp style (day = 0 cases)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][3]));

    // for the remaining days
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(point, dp[day][last]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
