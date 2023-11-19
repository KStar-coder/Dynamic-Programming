#include <bits/stdc++.h>
using namespace std;
int solve(string s1, int i, string s2, int j, vector<vector<int>> &dp)
{
    // base case
    if (i < 0 || j < 0)
        return 0;

    // dp base case
    if (dp[i][j] != -1)
        return dp[i][j];

    // recursive cases
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + solve(s1, i - 1, s2, j - 1, dp);
    }
    else
        return dp[i][j] = 0 + max(solve(s1, i - 1, s2, j, dp), solve(s1, i, s2, j - 1, dp));
}

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    string s2;

    for (int i = n - 1; i >= 0; i--)
    {
        s2.push_back(s[i]);
    }
    // MEMOIZATION

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return solve (s,n-1,s2,n-1,dp);

    // TABULATION

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // tabulation base case
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    // tabulation loops

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string s = "sharma";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}
