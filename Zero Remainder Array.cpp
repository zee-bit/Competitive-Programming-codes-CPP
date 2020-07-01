#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	// MY ORIGINAL SOLUTION (WRONG!!)

	// ll n, k;
	// cin >> n >> k;
	// vector<ll> a(n);
	// for (int i = 0; i < n; i++)
	// 	cin >> a[i];

	// vector<ll> d(n);
	// ll m;
	// for (int i = 0; i < n; i++) {
	// 	if (a[i] % k == 0)
	// 		d[i] = 0;
	// 	else
	// 		d[i] = k - (a[i] % k);
	// }
	// m = 0;
	// vector<ll> cnt(k, 0);
	// for (int i = 0; i < n; i++) {
	// 	if(d[i] == 0) continue;
	// 	++cnt[d[i]];
	// }

	// ll key;
	// for (int i = 0; i < k; i++)
	// 	if (cnt[i] > m) {
	// 		m = cnt[i];
	// 		key = i;
	// 	}

	// if (key == 0) {
	// 	cout << "0\n";
	// 	return;
	// }
	// cout << key + 1 + ((m - 1) * k) << "\n";

	// CORRECT SOLUTION (TUTORIAL)

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
	map<int, int> cnt;
	int mx = 0;
	for (auto &it : a) {
		if (it % k == 0) continue;
		++cnt[k - it % k];
		mx = max(mx, cnt[k - it % k]);
	}
	long long ans = 0;
	for (auto [key, value] : cnt) {
		if (value == mx) {
			ans = k * 1ll * (value - 1) + key + 1;
		}
	}
	cout << ans << endl;
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