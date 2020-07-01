#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b >= a)
		cout << b << "\n";
	else if (b < a && c <= d)
		cout << -1 << "\n";
	else {
		ll rem = a - b;
		ll slp = c - d;
		ll steps = (rem / slp) + (rem % slp != 0);
		cout << steps * c + b << "\n";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}