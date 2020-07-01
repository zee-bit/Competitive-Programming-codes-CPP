#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int ans = 0;
	map<int, int> offset;
	for (int i = 1; i <= n; i++) {
		int curr = a[b[i]] - i;
		if (curr < 0)
			curr += n;
		offset[curr]++;
	}
	for (auto &it : offset)
		ans = max(ans, it.second);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}