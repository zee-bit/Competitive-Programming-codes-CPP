#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n), even, odd;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
		if (a[i] & 1)
			odd.push_back(i);
		else
			even.push_back(i);
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i + 1 < int(odd.size()); i += 2) {
		ans.push_back({odd[i] + 1, odd[i + 1] + 1});
	}
	for (int i = 0; i + 1 < int(even.size()); i += 2) {
		ans.push_back({even[i] + 1, even[i + 1] + 1});
	}
	for (int i = 0; ((i < int(ans.size())) && (i < n - 1)); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
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