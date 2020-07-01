#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	if (n % 2 == 0 && n % 4 != 0) {
		cout << "-1\n";
		return ;
	}
	ll ans = -1;
	for (ll i = 1; i * i < n; i++) {
		if (n % i == 0 && ((n / i - i) % 2 == 0)) {
			ll j = n / i;
			ll x = (j - i) / 2;
			ans = x * x;
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