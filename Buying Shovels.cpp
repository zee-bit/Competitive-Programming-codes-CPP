#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = n;
	for (int i = 1; (i * i <= n && i <= k); i++) {
		if (n % i == 0) {
			ans = min(ans, n / i);
			if (n / i <= k)
				ans = min(ans, i);
		}
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