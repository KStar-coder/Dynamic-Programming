#include <bits/stdc++.h> 
using namespace std;
int solve (int i, int j, vector<int>&arr, vector<vector<int>>&dp)
{
    // base case 
    if (i==j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    //recursion for 'K' partitions

    int mini = 1e9;
    for (int k=i; k<j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr, dp) + solve(k+1,j,arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;

}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.

    //MEMOIZATION
    // vector<vector<int>>dp(N,vector<int>(N, -1));
    // return solve (1, N-1, arr, dp);

    //TABULATION
    vector<vector<int>>dp(N,vector<int>(N));

    // base case 
    for (int i=1; i<N; i++)
        dp[i][i] = 0;
    
    // tabulation loops 

    
    for (int i=N-1; i>=1; i--)
    {
        for (int j=i+1; j<N; j++)
        {
            
            int mini = 1e9;
            for (int k =i; k<j; k++)
            {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }

    }
    return dp[1][N-1];
}
