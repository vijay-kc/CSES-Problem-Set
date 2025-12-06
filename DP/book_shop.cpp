#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;  
    vector<long long> price(n);
    vector<long long> pages(n);

    for (long long i = 0; i < n; i++) {
        cin >> price[i];  
    }

    for (long long i = 0; i < n; i++) {
        cin >> pages[i];  
    }
    vector<long long>dp(x+1,0);
    for (long long i = 0; i < n; i++) {
        
        for (long long C = x; C > 0; C--) {
            
            if (price[i] > C)
                continue;
            dp[C] = max(dp[C], pages[i] + dp[C - price[i]]);
        }
    }
    cout<< dp[x];
    return 0;
}


//////////// gives memory overflow but currect

// long long solve(vector<long long>&price,vector<long long>&pages,int x,int i,vector<vector<long long>>&dp){
//    if (i == price.size()) return 0;
//    if(dp[i][x]!=-1)return dp[i][x];
//    long long ans=solve(price,pages,x,i+1,dp);
//     if(price[i]<=x){
//        ans=max(ans,pages[i]+solve(price,pages,x-price[i],i+1,dp));
//     }
//     return dp[i][x]=ans;
// }
// int main (){
//     long long n,x;
//     cin>>n>>x;
//     vector<long long>price(n);
//     vector<long long>pages(n);
//     for(long long i=0;i<n;i++){
//         cin>>price[i];
//     }
//     for(long long i=0;i<n;i++){
//         cin>>pages[i];
//     }
//     vector<vector<long long>> dp(n, vector<long long>(x + 1, -1));
//     cout<<solve(price,pages,x,0,dp);
// return 0;
// }
