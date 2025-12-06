#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<long long> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s; i++) {
        for (int c : coin) {
            if (i - c >= 0)
                dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    cout << dp[s] << "\n";
}

// ------- give TLE and wrong

// #include <bits/stdc++.h>
// using namespace std;

// int mod = 1e9 + 7;
// int solve(int s, vector<long long> &coin, vector<long long> &dp)
// {
//     if (s < 0)
//         return 0;
//     if (s == 0)
//         return 1;
//     long long way = 0;
//     if (dp[s] != -1)
//         return dp[s];
//     for (auto c : coin)
//     {
//         if (s - c >= 0)
//             way = (way + solve(s - c, coin, dp)) % mod;
//     }
//     return dp[s] = way;
// }
// int main()
// {
//     long long n, s;
//     cin >> n >> s;
//     vector<long long> coin(n);
//     for (long long i = 0; i < n; i++)
//     {
//         cin >> coin[i];
//     }
//     vector<long long> dp(s + 1, -1);
//     cout << solve(s, coin, dp);
//     return 0;
// }
