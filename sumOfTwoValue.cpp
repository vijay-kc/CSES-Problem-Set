#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> val(n);
	for (int i = 0; i < n; i++) { cin >> val[i]; }
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
	
		if (mp.count(x - val[i])) {
			cout << i + 1 << " " << mp[x - val[i]] << endl;
			return 0;
		}
	   mp[val[i]] = i + 1;
	}

	cout << "IMPOSSIBLE" << endl;
}