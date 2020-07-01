#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x, m, l, r;
	cin >> n >> x >> m;
	l = r = x;
	for (int i = 0; i < m; i++) {
		int L, R;
		cin >> L >> R;
		if (max(l, L) <= min(r, R)) {
			l = min(l, L);
			r = max(r, R);
		}
	}
	cout << r - l + 1 << "\n";
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