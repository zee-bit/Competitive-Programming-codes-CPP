#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), prefix(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	prefix[0] = a[0];
	for (int i = 1; i < n; i++)
		prefix[i] = prefix[i - 1] + a[i];

	ll b, lo = 0, mid, hi = n - 1, lim;
	while (m--) {
		cin >> b;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (prefix[mid] >= b) {
				lim = mid;
				hi = mid - 1;
			}
			else
				lo = mid + 1;
		}
		lo = lim;
		hi = n - 1;
		cout << lim + 1 << " " << b - (prefix[lim] - a[lim]) << "\n";
	}
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