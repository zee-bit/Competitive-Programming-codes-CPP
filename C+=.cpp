#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, n, ans = 0;
	cin >> a >> b >> n;
	while (true) {
		if (a > n || b > n) {
			cout << ans << "\n";
			return ;
		}
		else {
			if (a > b) {
				b += a;
				ans++;
			}
			else {
				a += b;
				ans++;
			}
		}
	}
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