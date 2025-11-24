#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin>>N>>X;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
      sort(arr, arr + N);
    long long l = 0, h = N - 1;
    long long ans = 0;

    while (h >= l) {
       
        if (arr[l] + arr[h] <= X) {
            ans++;
            l++;
            h--;
        }
      
        else {
            ans++;
            h--;
        }
    }
    cout<<ans;

}