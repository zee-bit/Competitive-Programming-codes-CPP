#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> e(n);
	for (int i = 0; i < n; i++)
		cin >> e[i];
	sort(e.begin(), e.end());

	int ans = 0, sizeNow = 1;
	for (int i = 0; i < n; i++) {
		if (e[i] <= sizeNow) {
			ans++;
			sizeNow = 1;
		}
		else
			sizeNow++;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}