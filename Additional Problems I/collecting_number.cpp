#include<iostream>
using namespace std;
int main (){
long long n;
cin>>n;
long long arr[n];
for(long long  i=0;i<n;i++){
    cin>>arr[i];
}
long long  a=1,cnt=0;
while(a<=n){
    cnt++;
    for (long long i = 0; i < n; i++){
    if(arr[i]==a){
        a++;
     }
  }
}
cout<<cnt;
 
}