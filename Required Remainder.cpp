#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll x, y, n;
	cin >> x >> y >> n;
	ll rem = n % x;
	ll m = n / x;
	if (rem < y)
		m--;
	cout << (x * m) + y << "\n";

	//int val = (n / x) * x + y;
	//if (val > n)
	//    val = val - x;
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