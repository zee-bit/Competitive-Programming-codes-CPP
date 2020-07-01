#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	vector<pair<int, int> > check(n + m - 1, pair<int, int> {0, 0});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)
				check[i + j].first++;
			else
				check[i + j].second++;
		}
	}
	int ans = 0, iter;
	// if (a[0][0] != a[n - 1][m - 1])
	// 	ans++;
	iter = (((n + m) % 2 == 0) ? ((n + m - 2) / 2) : ((n + m - 2) / 2) + 1);

	for (int i = 0; i < iter; i++)
		ans += min(check[i].first + check[n + m - 2 - i].first, check[i].second + check[n + m - 2 - i].second);
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