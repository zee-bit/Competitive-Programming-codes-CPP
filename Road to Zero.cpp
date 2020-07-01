#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll x, y, a, b;
	cin >> x >> y >> a >> b;

	ll diff = abs(x - y);
	ll least = min(x, y);
	ll ans = 0;

	ans = min(diff * a + least * b, x * a + y * a);
	// ans = min(ans, first * a + last * a);
	// ans = min(ans, first * b + last * b);
	cout << ans << "\n";
}

int main() {
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