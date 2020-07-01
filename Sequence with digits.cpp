#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll multDig(ll a) {
	ll mi = 10, ma = -1;
	while (a > 0) {
		ll d = a % 10;
		mi = min(d, mi);
		ma = max(d, ma);
		a = a / 10;
	}
	return mi * ma;
}

void solve() {
	ll a, k;
	cin >> a >> k;
	for (ll i = 2 ; i <= k; i++) {
		if (multDig(a) == 0) {
			cout << a << "\n";
			return;
		}
		a = a + multDig(a);
	}
	cout << a << "\n";
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