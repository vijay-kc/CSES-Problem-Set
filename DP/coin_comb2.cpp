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

    for (int c : coin) {           
        for (int i = c; i <= s; i++) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    cout << dp[s] << "\n";
    return 0;
}
