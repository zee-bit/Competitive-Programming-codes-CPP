// KEY IDEA : Maximmum GCD will be always of pair (n, floor(n/2))

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	cout << n / 2 << "\n";
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