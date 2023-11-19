#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
{
    // base case
    if (j1 < 0 || j2 < 0 || j1 > m || j2 > m) // out of bounds
        return -1e8;
    if (i == n - 1) // last row
    {
        if (j1 == j2) // Both robots land on the same box
            return grid[i][j1];
        else // Both robots land on different boxes
            return grid[i][j1] + grid[i][j2];

        // recursive cases
        // 3*3 = 9 possibilities
    }
    int maxi = 0;
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }

            val += solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid);
            maxi = max(val, maxi);
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();    // rows
    int m = grid[0].size(); // cols

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, n, m, grid);
}
int main()
{
    vector<vector<int>> grid = {
        {1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6}};

    // cout << cherryPickup(grid) << endl;

    // TABULATION
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // starting from the last row

    // base case and filling up from the last row
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // RECURSIVE CASES IN TABULATION FROM
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= +1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= +1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = grid[i][j1];
                        else
                            val = grid[i][j1] + grid[i][j2];

                        // handling the out of bound cases
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            val += -1e8;
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    cout << dp[0][0][m - 1] << endl;
    return 0;
}