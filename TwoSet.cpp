#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%4 == 1 || n%4 == 2)    cout<<"NO"<<endl;
    else if(n%4 == 3){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
         for(int i = 2; i <= n/2; i += 2)
            cout<<i<<" "<<n-i<<" ";
         cout<<n<<endl<<n/2+1<<endl;
         for(int i = 1; i <= n/2; i += 2)
            cout<<i<<" "<<n-i<<" ";

        } else {
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i = 2; i <= n/2; i += 2)
                cout<<i<<" "<<n-i+1<<" ";
            cout<<endl<<n/2<<endl;
            for(int i = 1; i <= n/2; i += 2)
                cout<<i<<" "<<n-i+1<<" ";
           
    }
}