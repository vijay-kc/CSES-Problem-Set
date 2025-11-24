#include<bits/stdc++.h>
using namespace std;
int main (){

 long long n, m, k, index = 0, ans = 0;
    cin >> n >> m >> k;
    vector<long long> clients(n);
    vector<long long> apartments(m);
    for (int i = 0; i < n; i++) {
        cin >> clients[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }
    sort(clients.begin(), clients.end());
    sort(apartments.begin(), apartments.end());
    for (int i = 0; i < n; i++) {
        while (index < m) {
            if (apartments[index] + k < clients[i]) {
                index++;
            } else if (apartments[index] - k > clients[i]) {
                break;
            } else {
                index++, ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}