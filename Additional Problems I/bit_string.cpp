#include<iostream>
using namespace std;
int mod=1e9+7;
int main (){
long long  n;
cin>>n;
long long ans=1;
for(int i=1;i<=n;i++){
  ans=(ans*2)%mod;
}
cout<<ans;
return 0;
}