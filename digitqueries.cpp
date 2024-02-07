#include<bits/stdc++.h>
using namespace std;
long long powerTen(int a){
    long long ans=1;
    while(a--)
    ans*=10;
    
    return ans;
}
int main (){
int t;long long res;
cin>>t;
while (t--){
   long long n;
   cin>>n;
   if(n<=9)
   {cout<<n<<endl;
   }else{
 int len =1;
   while(9*powerTen(len-1)*len<n-1){
    n-=9*powerTen(len-1)*len;
    len++;
   }
   string s=to_string(powerTen(len-1)+(n-1)/len);
  res=(s[(n-1)%len]-'0');
   cout<<res<<endl;
   }
  
}

return 0;
}