#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin >> s;
	ll ans = 0;
	int maxTillNow = 0, ctr = 0, len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '-') ctr++;
		else ctr--;
		if (ctr > maxTillNow) {
			maxTillNow = ctr;
			ans += i + 1;
		}
	}
	ans += len;
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