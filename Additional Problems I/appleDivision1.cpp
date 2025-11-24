#include<bits/stdc++.h>
using namespace std;
int main (){
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
long long ans=INT_MAX;
for(int i=0;i<(1<<n);i++){
    long long a=0,b=0;
    for(int j=0;j<n;j++){
        if(i&(1<<j))
        a+=arr[j];
        else b+=arr[j];
    }
     ans=min(ans,abs(a-b));
}
cout<<ans;
return 0;
}