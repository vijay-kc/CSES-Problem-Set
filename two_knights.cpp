#include<iostream>
using namespace std;
int main (){
long long  n;
cin>>n;
cout<<0<<endl;
long long  ans;
for(long long i=2;i<=n;i++){
 ans=((i*i)*((i*i)-1)/2)-4*(i-1)*(i-2);
 cout<<ans<<endl;
}
return 0;
}