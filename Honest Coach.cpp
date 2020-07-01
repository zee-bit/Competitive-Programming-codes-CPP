#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, mi = 1e3;
	cin >> n;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s.begin(), s.end());

	for (int i = 1; i < n; i++)
		mi = min(mi, s[i] - s[i - 1]);
	cout << mi << "\n";
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