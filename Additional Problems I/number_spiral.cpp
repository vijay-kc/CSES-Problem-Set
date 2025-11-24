#include <iostream>

using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long y, x;
        cin >> x>> y;

        if(x<y){
            if(y%2==1){
                long long r=y*y;
                cout<<r-x+1<<endl;
            }else{
                long long  r=(y-1)*(y-1)+1;
                cout<<r+x-1<<endl;
            }
        }else {if(x%2==0){
            long long  r=x*x;
            cout<<r-y+1<<endl;
        }else{
            long long  r=(x-1)*(x-1)+1;
            cout<<r+y-1<<endl;
        }
        }
    }

    return 0;
}
