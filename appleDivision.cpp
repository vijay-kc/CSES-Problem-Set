#include<bits/stdc++.h>
using namespace std;
int main (){
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
sort(arr.begin(),arr.end(),greater<int>());
int ansm=0,ansn=0;
ansm=arr[0];

for(int i=1;i<n;i++){
if(ansn<ansm)
ansn+=arr[i];
else ansm+=arr[i];
}
cout<<max(ansn,ansm)-min(ansn,ansm);
       
return 0;
}