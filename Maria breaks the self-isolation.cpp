#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int > track;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		track[a[i]]++;
	}
	int ans = 0, newAns = 0;
	for(auto x:track) {
		if(x.second + ans + newAns >= x.first) {
			ans += x.second + newAns;
			newAns = 0;
		}
		else newAns += x.second;
	}
	cout << ans + 1 << "\n";
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) 
		solve();
	return 0;
}
