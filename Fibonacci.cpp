#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long int
int fib(ll n, vector<ll> &dp)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    // if it is present in the dp array
    if (dp[n] != -1)
        return dp[n];

    // if it is not present in the dp array
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1); // creating a vector of size n+1

    // initialising the values of the vector with -1

    for (ll i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fib(n, dp) << endl;

    return 0;
}