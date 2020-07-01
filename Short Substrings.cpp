#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s, ans = "";
	cin >> s;
	ans += s[0];
	int l = s.length();
	for (int i = 1; i < l - 1; i += 2)
		ans += s[i];
	ans += s[l - 1];
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