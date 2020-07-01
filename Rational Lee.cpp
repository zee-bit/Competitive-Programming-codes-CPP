#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll ans = 0;
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int>	w(k);
	for (int i = 0; i < k; i++)
		cin >> w[i];
	sort(a.begin(), a.end(), greater<int> ());
	sort(w.begin(), w.end());
	for (int i = 0; i < k; i++) {
		if (w[i] == 1)
			ans += a[i];
		ans += a[i];
		w[i]--;
	}
	int start = k;
	for (int i = 0; i < k; i++) {
		if (w[i] > 0) {
			ans += a[start + w[i] - 1];
			start += w[i];
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