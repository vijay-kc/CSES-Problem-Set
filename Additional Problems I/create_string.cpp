#include<bits/stdc++.h>
using namespace std;

void create(string str,int l,int r,set<string>&perm){
    if(l==r){
        perm.insert(str);
    }else{
        for(int i=l;i<=r;i++){
           swap(str[l],str[i]);
          create( str,l+1,r,perm);
           swap(str[l],str[i]);
        }
       
    }
}
int main (){
    string s;
    cin>>s;
    set<string>perm;
    create(s,0,s.size()-1,perm);
    cout<<perm.size()<<endl;
    for(auto x : perm){
         cout<<x<<endl;
        }
    return 0;
}