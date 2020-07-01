#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	map<char, int> m;
	int l = 0, ans = 1e9, len = s.size();
	for (int r = 0; r < len; r++)
	{
		m[s[r]]++;
		while (m[s[l]] > 1)
		{
			m[s[l]]--;
			l++;
		}
		if (m.size() == 3)
			ans = min(ans, r - l + 1);
	}
	if (ans > 1e7)
		ans = 0;
	cout << ans << endl;
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