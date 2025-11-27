#include <bits/stdc++.h>
using namespace std;

int inf = 1e9;
// int solve(int s, vector<int> &coin,vector<int>&dp)
// {
//     if (s < 0)
//         return inf;
//     if (s == 0)
//         return 0;
//     if(dp[s]!=-1)return dp[s];
//     int a=inf;
//     for(int i=0;i<coin.size();i++){
//         a=min(a,1+solve(s-coin[i],coin,dp));
//     }
//     return dp[s]=a;
// }
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    vector<int> dp(s + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= s; i++)
    {
        for (auto c : coin)
        {
            if (i - c >= 0)
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }

    if (dp[s] == inf)
        cout << -1;
    else
        cout << dp[s];
    return 0;
}