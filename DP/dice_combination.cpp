#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
// int solve(int n, vector<int> &dp)
// {
//     if (n == 0)
//         return 1;
//     if (n < 0)
//         return 0;

//     if (dp[n] != -1)
//         return dp[n];
//     int ans = 0;
//     for (int i = 1; i <= 6; i++)
//     {
//         ans += solve(n - i, dp);
//         ans %= mod;
//     }
//     return dp[n] = ans;
// }

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << solve(n, dp);

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n];

    return 0;
}