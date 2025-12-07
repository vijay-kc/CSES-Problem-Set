#include <bits/stdc++.h>
using namespace std;

// int solveMemo(int n,int m,string &w1,string & w2,vector<vector<int>>&dp){
//     if(n<0)return m+1;
//     if(m<0)return n+1;
//     if(dp[n][m]!=-1)return dp[n][m];
//     if(w1[n]==w2[m])return dp[n][m]=solve(n-1,m-1,w1,w2,dp);
//     return dp[n][m]=min(1+solve(n-1,m-1,w1,w2,dp),min(1+solve(n,m-1,w1,w2,dp),1+solve(n-1,m,w1,w2,dp)));
// }
int solve(int n, int m, string &w1, string &w2, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (w1[i - 1] == w2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
            }
        }
    }
    return dp[n + 1][m + 1];
}
int main()
{
    string w1, w2;
    cin >> w1 >> w2;
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    // cout << solveMemo(n - 1, m - 1, w1, w2, dp);
    cout << solve(n - 1, m - 1, w1, w2, dp);
    return 0;
}