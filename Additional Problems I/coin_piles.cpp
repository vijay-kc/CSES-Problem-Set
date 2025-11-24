#include<iostream>
using namespace std;
int main (){
int t;
cin>>t;
while(t--){
    long long a,b;
    cin>>a>>b;
    // while(a>0||b>0){
    //     if(a>b){
    //         a-=2;
    //         b--;
    //     }else{
    //         b-=2;
    //         a--;
    //     }
    // }
    // if(a==0&&b==0){
    //     cout<<"YES"<<endl;
    // }else
    //    { cout<<"NO"<<endl;
    // }

    //TLE
    
    if(max(a,b)>2*min(a,b)){
       cout<<"NO"<<endl; 
    }
    else if((a+b)%3==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
return 0;
}